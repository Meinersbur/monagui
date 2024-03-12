#include "utils.h"
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

#include "utils.h"

#include <execinfo.h>


void read_all_lines(std::istream &stream, ustring &strout) {
    ustring tmp((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
    //return str; // Rely on Return Value Optimization
    strout.swap(tmp);
}


void print_stacktrace(size_t alloc_size) {
    if (!alloc_size) {
        alloc_size = 1;
    }

    void *alloc_ptr = (void *)malloc(alloc_size);
    if (alloc_ptr == NULL) {
        fprintf(stderr, "\n Malloc fails");
        return;
    }

    void *syms[128];
    size_t num_frames = backtrace(syms, sizeof (syms)/ sizeof(void *));

    char **names = backtrace_symbols(syms, num_frames);
    for (size_t icnt=0; icnt < num_frames; icnt += 1) {
        fprintf(stderr, "%s\n", names[icnt]);
    }

    free(names);
    free(alloc_ptr);
}
