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
Executable entry point
*/

#include "global.h"
#include "app.h"
#include "editorwin.h"
#include "front2/parser_h.h"

#include <gtkmm.h>
#include <gtksourceviewmm.h>


void exception_caught_in_main(char const *msg = NULL) throw() {
    try {
        if (!msg) {
            msg = "Unknown exception caught in main()";
        }

        std::cerr.clear();
        std::cerr << msg << std::endl;
    } catch (...) {
        // Do nothing
    }
}


int main(int argc, char *argv[]) {
#ifndef DEBUG
    try {
#endif
        Glib::thread_init();

        Gtk::Main kit(argc, argv);
        Gsv::init();

        set_executable_dir(argc, argv[0]);

        {
            EditorWindowPtr editWindow = EditorWindow::create();
            kit.run(*editWindow.get());
        } // Ensure that editWindow is destroyed before Gtk::Main

        return 0;
#ifndef DEBUG
    } catch (const Glib::Exception &x) {
        exception_caught_in_main(Glib::locale_from_utf8(x.what()).c_str());
    } catch (const std::exception &x) {
        exception_caught_in_main(x.what());
    } catch (...) {
        exception_caught_in_main();
    }
    return -1;
#endif
}

