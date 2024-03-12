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
Application specific configuration
*/

#include "app.h"


#define DATADIRNAME share


boost::filesystem::path executable_path;


void set_executable_dir(int argc, const char *argv0) {
    if (argc < 1 || argv0 == NULL) {
        executable_path.clear();
        return;
    }

    boost::filesystem::path reldir(argv0);
    if (reldir.empty()) {
        executable_path.clear();
        return;
    }

    executable_path = boost::filesystem::complete(reldir);
}


boost::filesystem::path app_lookup_datafile(ustring category, ustring filename) {
#define CHECK_DIR /* */\
    if (filename.empty()) {\
	/* Look for a directory */\
        if (boost::filesystem::is_directory(filepath)) {\
            return filepath;\
        }\
    } else {\
        /* Look for a file */\
        filepath /= filename;\
        if (boost::filesystem::exists(filepath) && !boost::filesystem::is_directory(filepath)) {\
            return filepath;\
        }\
    }

    // ${Dir containing executable}/../${category}/${filename}
    {
        assert(!executable_path.empty());
        boost::filesystem::path exebase = executable_path.parent_path();
        boost::filesystem::path filepath = exebase.parent_path();
        filepath /= category;
        CHECK_DIR
    }

    // If current we are in dir ".libs" (libtool)
    // ${Dir containing executable}/../../${category}/${filename}
    {
        if (executable_path.parent_path().filename()  == ".libs") {
#ifdef DEBUG
            fprintf(stderr, ".libs\n");
#endif
            boost::filesystem::path exebase = executable_path.parent_path();
            boost::filesystem::path filepath = exebase.parent_path().parent_path();
            filepath /= category;
            CHECK_DIR
        }
    }

    // Siblings of descendant "bin" directory
    {
        assert(!executable_path.empty()); // File path must have been set
        boost::filesystem::path exebase = executable_path.parent_path();
        while (true) {
            if (exebase.empty()) {
                exebase = executable_path.parent_path();
                break;
            }

            if (exebase.filename() == "bin") {
                exebase = exebase.parent_path();
                break;
            }

            exebase = exebase.parent_path();
        }

        if (!exebase.empty() && boost::filesystem::is_directory(exebase)) {
            assert(exebase.is_complete());

            boost::filesystem::path filepath = exebase;
            filepath /= category;
            CHECK_DIR
        }
    }

    // ~/.local/share/monagui/${category}/${filename}
    {
        boost::filesystem::path filepath("~");
        filepath /= ".local";
        filepath /= TOSTRING(DATADIRNAME);
        filepath /= PACKAGE;
        filepath /= category;
        CHECK_DIR
    }

    // 2. ~/share/monagui/${category}/${filename}
    {
        boost::filesystem::path filepath("~");
        filepath /= TOSTRING(DATADIRNAME);
        filepath /= PACKAGE;
        filepath /= category;
        CHECK_DIR
    }

    // 3. ${PREFIX}/share/monagui/${category}/${filename}
    {
        boost::filesystem::path filepath(PKGDATADIR);
        filepath /= category;
        CHECK_DIR
    }

    // 4. /usr/local/share/monagui/${category}/${filename}
    {
        boost::filesystem::path filepath("/");
        filepath /= "usr";
        filepath /= "local";
        filepath /= TOSTRING(DATADIRNAME);
        filepath /= PACKAGE;
        filepath /= category;
        CHECK_DIR
    }

    // 5. /usr/share/monagui/${category}/${filename}
    {
        boost::filesystem::path filepath("/");
        filepath /= "usr";
        filepath /= TOSTRING(DATADIRNAME);
        filepath /= PACKAGE;
        filepath /= category;
        CHECK_DIR
    }

    // 6. Not found
    throw UnexpectedException("Data file not found");
}
