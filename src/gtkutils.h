#ifndef GTKUTILS_H
#define GTKUTILS_H
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

#include "global.h"

#include <gtkmm.h>
#include <gtksourceviewmm.h>


typedef Glib::RefPtr<Gtk::Builder> GtkBuilderPtr;
typedef Glib::RefPtr<Gsv::SourceBuffer> GsvSourceBufferPtr;
typedef Glib::RefPtr<Gsv::SourceLanguageManager> GsvSourceLanguageManagerPtr;
typedef Glib::RefPtr<Gsv::SourceLanguage> GsvSourceLanguagePtr;
typedef Glib::RefPtr<Gio::File> GioFilePtr;
typedef Glib::RefPtr<Gio::FileInputStream> GioFileInputStreamPtr;
typedef Glib::RefPtr<Gsv::SourceCompletion> GsvSourceCompletionPtr;
typedef Glib::RefPtr<Gsv::SourceView> GsvSourceViewPtr;
typedef Glib::RefPtr<Gtk::Action> GtkActionPtr;
typedef Glib::RefPtr<Glib::Object> GlibObjectPtr;
typedef Glib::RefPtr<Gtk::UIManager> GtkUIManagerPtr;
typedef Glib::RefPtr<Gtk::FileFilter> GtkFileFilterPtr;


GtkFileFilterPtr createFileFilter();
void gtk_dialogAddFileFilter(Gtk::FileChooserDialog &dialog, Glib::RefPtr<Gtk::FileFilter> &filter);
Glib::RefPtr<Gsv::SourceCompletion> SourceView_getCompletion(Glib::RefPtr<Gsv::SourceView> self);
Glib::RefPtr<Gsv::SourceCompletion> SourceView_getCompletion(Gsv::SourceView *self);
void SourceView_show_completion(Gsv::SourceView *sourceView);
Glib::RefPtr<Gsv::SourceLanguage> get_language_from_mime_type(Glib::RefPtr<Gsv::SourceLanguageManager> lang_manager, Glib::ustring mime_type);


template <class T_Widget>
void getWidgetOrFail(T_Widget*& widget, const Glib::RefPtr<Gtk::Builder>& glade, const Glib::ustring &name) {
    widget = NULL;
    glade->get_widget(name, widget);
    assert(widget);
    if (!widget) {
        throw UnexpectedException("Widget not found in glade file.");
    }
}


template <class T>
bool idle_resetRef(boost::shared_ptr<T> ref) {
    ref.reset(); // This is not strictly necessary; ref will go out of scope anyway
    // Just to make the purpose of this method explicit
    return false;
}

#endif // GTKUTILS_H
