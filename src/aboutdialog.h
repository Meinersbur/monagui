#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H
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

#include "global.h"

#include <gtkmm.h>


class AboutDialog;
typedef boost::shared_ptr<AboutDialog> AboutDialogPtr;

class AboutDialog: public Gtk::AboutDialog
{
    public:
        static AboutDialogPtr create();
        AboutDialog(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& glade);
        virtual ~AboutDialog();
};

#endif // ABOUTDIALOG_H
