#ifndef UTILS_H
#define UTILS_H
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
Anything that cannot be categorized any better
*/

#include "global.h"


void read_all_lines(std::istream &stream, ustring &strout);


template<class T>
T *cpymalloc(const T &source) {
    T *dest = (T *) malloc(sizeof(source));
    memcpy(dest, &source, sizeof(*dest));
    return dest;
}


template<class T>
void cpyfree(T &dest, T *&source) {
    memcpy(&dest, source, sizeof(dest));
    free(source);
    source = NULL;
}


template<class T>
void zero (T &dest) {
    memset(&dest, 0, sizeof(dest));
}


void print_stacktrace(size_t alloc_size = 20);

#endif // UTILS_H
