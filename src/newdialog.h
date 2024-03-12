#ifndef NEWWIN_H
#define NEWWIN_H
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

#include "global.h"

#include <gtkmm.h>

#include <boost/noncopyable.hpp>


class NewDialog;
typedef boost::shared_ptr<NewDialog> NewDialogPtr;

class NewDialog: public Gtk::Dialog, boost::noncopyable {
public:
    static NewDialogPtr create();
    static NewDialogPtr createFromBuilder(const Glib::RefPtr<Gtk::Builder>& builder, const Glib::ustring &name);
    virtual ~NewDialog() {}

    virtual bool get_StringMode() = 0;
    virtual bool get_TreeMode() = 0;
    virtual bool get_Finite() = 0;
    virtual bool get_Tutorial() = 0;

protected:
    NewDialog(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& glade);
};

#endif // NEWWIN_H
