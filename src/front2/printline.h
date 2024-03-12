#ifndef HEADER_A620678FB61019F1
#define HEADER_A620678FB61019F1

/*
 * MONA
 * Copyright (C) 1997-2008 BRICS.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the  Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
 * USA.
 */
/*
Modified for MonaGUI
Copyright 2011 Michael Kruse
*/

#ifndef __PRINTLINE_H
#define __PRINTLINE_H

#include "deque.h"


class FileSource: public DequeGCA<char *> {};

class Pos {
public:
    Pos() {
        line = -1;
        col = -1;
        fileName = NULL;
        first_offset = -1;
        last_line = -1;
        last_column = -1;
        last_offset = -1;
    }

    Pos (const char *filename, int first_offset, int first_line, int first_column, int last_offset, int last_line, int last_column) {
        this->fileName = filename;
        this->first_offset = first_offset;
        this->line = first_line;
        this->col = first_column;
        this->last_offset = last_offset;
        this->last_line = last_line;
        this->last_column = last_column;
    }

    void printsource() const;

    int line, col;
    const char *fileName;
    int first_offset;

    int last_line;
    int last_column;
    int last_offset;
};

extern const Pos dummyPos;

#endif

#endif // header guard 
