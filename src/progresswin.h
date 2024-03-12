#ifndef PROGRESSWINDOW_H
#define PROGRESSWINDOW_H
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
The window with a progressbar which shows up when Mona is working
*/

#include "global.h"

#include <gtkmm.h>

#include <boost/noncopyable.hpp>


class ProgressWindow;
typedef boost::shared_ptr<ProgressWindow> ProgressWindowPtr;

class ProgressWindow: public virtual Gtk::Window, boost::noncopyable {
public:
    static ProgressWindowPtr create();
    virtual ~ProgressWindow() {}

    virtual void reset() = 0;
    virtual void appendOutstr(const std::string &str) = 0;
    virtual void setProgress(const ustring &phase, double progress, const ustring &info) = 0;

    Glib::Dispatcher signal_abort;

protected:
    ProgressWindow() {}
};

#endif // PROGRESSWINDOW_H
