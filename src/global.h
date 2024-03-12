#ifndef GLOBAL_H
#define GLOBAL_H
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
Definitions required by all files of the project; must be included first into every file
*/

#ifdef HAVE_CONFIG_H
# include "guiconfig.h"
#endif  // HAVE_CONFIG_H


// Boost configuration
#define BOOST_SYSTEM_NO_DEPRECATED
#define BOOST_FILESYSTEM_VERSION 2
#define BOOST_FILESYSTEM_NO_DEPRECATED
#undef CLOCK_THREAD_CPUTIME_ID


// General macros
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define lengthof(expr) (sizeof(expr)/sizeof(expr[0]))

// like assert(), but always executes argument
#ifdef NDEBUG
#define assertSuccess(expr) (expr)
#else
#define assertSuccess(expr) assert(expr)
#endif


// Mona includes its own (modified) copy of dlmalloc; To avoid using multiple malloc implementations in deferent files, we use the same here
extern "C" {
#include "mem.h"
}

// Let it define TRUE and FALSE before Glib does to avoid redefined warnings
extern "C" {
#include "bdd.h"
}


// Decide for one namespace
#ifndef GTKMM3
#define Gsv gtksourceview
#else
#define gtksourceview Gsv
#endif


// Common headers
#include <assert.h>
#include <exception>
#include <boost/shared_ptr.hpp>
#include <glibmm/refptr.h>
#include <glibmm/ustring.h>
using Glib::ustring;
using std::string;


// Common exceptions
class UnexpectedException: public std::exception {
public:
    UnexpectedException(const char *desc);

    char const *what() const throw();

private:
    const char *desc;
};


class DescriptiveException: public std::exception {
public:
    DescriptiveException(const char *desc) {
        this->desc = desc;
    }

    char const *what() const throw() {
        return desc;
    }

private:
    const char *desc;
};

#endif // GLOBAL_H
