#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H
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
Window showing the result of a Mona run
*/

#include "global.h"
#include "monacall.h"

#include <gtkmm.h>

#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>


class ResultWindow;
typedef boost::shared_ptr<ResultWindow> ResultWindowPtr;

class ResultWindow: public Gtk::Window, boost::noncopyable {
public:
    static ResultWindowPtr create(MonaPtr mona, const boost::filesystem::path &sourcePath);
    static ResultWindowPtr create();
    static ResultWindowPtr createFromBuilder(const Glib::RefPtr<Gtk::Builder>& builder, const Glib::ustring &name);
    virtual ~ResultWindow() {}

protected:
    ResultWindow(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& glade);
};

#endif // RESULTWINDOW_H
