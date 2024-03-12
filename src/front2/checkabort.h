#ifndef CHECKABORT_H
#define CHECKABORT_H
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
To check whether the current Mona computation should be aborted (usually because the user pressed "Cancel").
Raises an exception if positive.
*/

#include "printline.h"

#include <exception>
#include <string>


class ScannerException: public std::exception {
public:
    ScannerException(const std::string &desc, Pos &pos): exception(), desc(desc), pos(pos) {}
    ~ScannerException() throw() {}

    char const *what() const throw() { return desc.c_str(); }

private:
    const std::string desc;
    Pos pos;
};


/**
Check AST error
*/
class TypeException: public std::exception {
public:
    TypeException(const std::string &desc, Pos &pos): exception(), desc(desc), pos(pos) {}
    ~TypeException() throw() {}

    char const *what() const throw() { return desc.c_str(); }

private:
    const std::string desc;
    Pos pos;
};


/**
Code generation error
*/
class CodeException: public std::exception {
public:
    CodeException(const std::string &desc, Pos &pos): exception(), desc(desc), pos(pos) {}
    ~CodeException() throw() {}

    char const *what() const throw() { return desc.c_str(); }

private:
    const std::string desc;
    Pos pos;
};


class AbortException: public std::exception {
public:
    AbortException(): exception() {}
    ~AbortException() throw() {}

    char const *what() const throw() { return "Process aborted"; }

private:
};


void checkAbort();

#endif // CHECKABORT_H
