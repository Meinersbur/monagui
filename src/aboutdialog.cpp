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
A simple "about" dialog showing who brought you MonaGUI
*/

#include "aboutdialog.h"

#include "app.h"


AboutDialogPtr AboutDialog::create() {
    AboutDialog *aboutDialog = NULL;
    boost::filesystem::path gladefile = app_lookup_datafile("glade", "about.glade");

    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file(gladefile.file_string());
    builder->get_widget_derived("AboutDialog", aboutDialog);
    if (!aboutDialog) {
        throw UnexpectedException("About Dialog not loaded");
    }

    AboutDialogPtr result(aboutDialog);
    return result;
}


AboutDialog::AboutDialog(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& /*glade*/):
    Gtk::AboutDialog(cobject) {
    //ctor
}


AboutDialog::~AboutDialog() {
    //dtor
}
