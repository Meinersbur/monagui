#ifndef EDITORWIN_H
#define EDITORWIN_H
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
The main editor window
*/

#include "global.h"
#include "monacall.h"
#include "completionitem.h"

#include <boost/noncopyable.hpp>

#include <gtkmm.h>


class EditorWindow;
typedef boost::shared_ptr<EditorWindow> EditorWindowPtr;

class EditorWindow : public Gtk::Window, boost::noncopyable {
public:
    static EditorWindowPtr create();
    static EditorWindowPtr createFromBuilder(const Glib::RefPtr<Gtk::Builder>& builder, const Glib::ustring &name);
    virtual ~EditorWindow() {}

    virtual void addError(ustring msg) = 0;
    virtual void addError(ustring msg, int line, int column) = 0;

    virtual MonaPtr getMonaCursor(const Gtk::TextIter &position) = 0;
    virtual MonaPtr getMonaValid() = 0;

    virtual void insertCompletion(const Glib::RefPtr<CompletionItem> &item) = 0;
    virtual void insertCompletion(const Glib::RefPtr<CompletionItem> &item, const Gtk::TextIter &position) = 0;

protected:
    EditorWindow(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder>& glade);
};

#endif // EDITORWIN_H
