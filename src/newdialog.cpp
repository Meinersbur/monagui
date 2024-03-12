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
The dialog to choose what type of document to create
*/

#include "newdialog.h"

#include "app.h"
#include "gtkutils.h"


class NewDialogImpl: public NewDialog {
public:
    NewDialogImpl(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& glade);
    virtual ~NewDialogImpl();

private:
    virtual bool get_StringMode();
    virtual bool get_TreeMode();
    virtual bool get_Finite();
    virtual bool get_Tutorial();

    void updateUi();

    void on_status_change();

    Gtk::RadioButton *stringRadio;
    Gtk::RadioButton *treeRadio;
    Gtk::CheckButton *finiteCheckbox;
    Gtk::CheckButton *tutorialCheckbox;
};


// NewDialog //////////////////////////////////////////////////////////////////

NewDialogPtr NewDialog::create() {
    boost::filesystem::path gladefile = app_lookup_datafile("glade", "newfile.glade");

    GtkBuilderPtr builder = Gtk::Builder::create_from_file(gladefile.file_string());
    NewDialogPtr result = NewDialog::createFromBuilder(builder, "NewDialog");
    return result;
}


NewDialogPtr NewDialog::createFromBuilder(const Glib::RefPtr<Gtk::Builder>& builder, const Glib::ustring &name) {
    NewDialogImpl *impl;
    builder->get_widget_derived(name, impl);
    NewDialogPtr result(impl);
    return result;
}


NewDialog::NewDialog(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& /*glade*/):
    Gtk::Dialog(cobject) {
    // abstract ctor
}


// NewDialogImpl //////////////////////////////////////////////////////////////

NewDialogImpl::NewDialogImpl(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& glade):
    NewDialog(cobject, glade) {
    // ctor
    getWidgetOrFail(stringRadio, glade, "StringRadio");
    getWidgetOrFail(treeRadio, glade, "TreeRadio");
    getWidgetOrFail(finiteCheckbox, glade, "FiniteCheckbox");
    getWidgetOrFail(tutorialCheckbox, glade, "TutorialCheckbox");

    stringRadio->signal_toggled().connect(sigc::mem_fun(this, &NewDialogImpl::on_status_change));
    treeRadio->signal_toggled().connect(sigc::mem_fun(this, &NewDialogImpl::on_status_change));
    finiteCheckbox->signal_toggled().connect(sigc::mem_fun(this, &NewDialogImpl::on_status_change));

    updateUi();
}


NewDialogImpl::~NewDialogImpl() {
    // dtor
}


bool NewDialogImpl::get_StringMode() {
    return !get_TreeMode();
}


bool NewDialogImpl::get_TreeMode() {
    return treeRadio->get_active();
}


bool NewDialogImpl::get_Finite() {
    return finiteCheckbox->get_active();
}


bool NewDialogImpl::get_Tutorial() {
    return tutorialCheckbox->get_active();
}


void NewDialogImpl::updateUi() {
    if (get_StringMode() && !get_Finite()) {
        tutorialCheckbox->show();
    } else {
        tutorialCheckbox->hide();
    }
}


void NewDialogImpl::on_status_change() {
    updateUi();
}
