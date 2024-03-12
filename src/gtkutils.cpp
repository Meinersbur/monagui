/*
 * MonaGUI
 * Copyright 2011 Michael Kruse
 *
 * This file is part of MonaGUI.
 *
 * MonaGUI is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, version 2 of the license.
 *
 * MonaGUI is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * MonaGUI. If not, see http://www.gnu.org/licenses/.
 */
/**
Unspecific utility functions and defintions for use with gtkmm and gtksourceviewmm
*/

#include "gtkutils.h"


Glib::RefPtr<Gtk::FileFilter> createFileFilter() {
#ifdef GTKMM3
    return Gtk::FileFilter()::create();
#else
    return Glib::RefPtr< Gtk::FileFilter > (new Gtk::FileFilter());
#endif
}


void gtk_dialogAddFileFilter(Gtk::FileChooserDialog &dialog, Glib::RefPtr<Gtk::FileFilter> &filter) {
#ifdef GTKMM3
    dialog.add_filter(filter);
#else
    dialog.add_filter(*(filter.operator->()));
#endif
}


GsvSourceCompletionPtr SourceView_getCompletion(Glib::RefPtr<Gsv::SourceView> self) {
    GsvSourceCompletionPtr retvalue = Glib::wrap(gtk_source_view_get_completion(self->gobj()));
    if(retvalue) {
        retvalue->reference(); //The function does not do a ref for us.
    }
    return retvalue;
}


GsvSourceCompletionPtr SourceView_getCompletion(Gsv::SourceView *self) {
    GtkSourceCompletion *completion = gtk_source_view_get_completion(self->gobj());
    assert(completion);
    GsvSourceCompletionPtr retvalue = Glib::wrap(completion);
    if(retvalue) {
        retvalue->reference();    //The function does not do a ref for us.
    }
    return retvalue;
}


void SourceView_show_completion(Gsv::SourceView *sourceView) {
    GtkSourceView *view = sourceView->gobj();
    GtkSourceViewClass *klass = GTK_SOURCE_VIEW_GET_CLASS(view);
    klass->show_completion(view);
}


// From Nemiver 0.7.3
Glib::RefPtr<Gsv::SourceLanguage> get_language_from_mime_type(Glib::RefPtr<Gsv::SourceLanguageManager> lang_manager, ustring mime_type) {
    Glib::RefPtr<Gsv::SourceLanguage> lang ;
    std::vector<std::string> lang_ids = lang_manager->get_language_ids();
    for ( std::vector<std::string>::const_iterator it = lang_ids.begin(); it != lang_ids.end (); ++it) {
        Glib::RefPtr<Gsv::SourceLanguage> candidate = lang_manager->get_language(*it);
        std::vector<Glib::ustring> mime_types = candidate->get_mime_types();
        std::vector<Glib::ustring>::const_iterator mime_it;
        for (mime_it = mime_types.begin(); mime_it != mime_types.end(); ++mime_it) {
            if (*mime_it == mime_type) {
                // one of the mime types associated with this language matches
                // the mime type of our file, so use this language
                lang = candidate;
                break;  // no need to look at further mime types
            }
        }
        // we found a matching language, so stop looking for other languages
        if (lang) { break; }
    }
    return lang;
}


