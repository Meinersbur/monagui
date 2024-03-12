#ifndef DISPATCHSTREAM_H
#define DISPATCHSTREAM_H
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
A stream that triggers a Glib::Dispatcher event when it receives new input
The received input can be queried using the pop() method
*/

#include "global.h"

#include <glibmm.h>

#include <iostream>
#include <sstream>


// Based on http://stackoverflow.com/questions/2212776/overload-handling-of-stdendl#2212940
class DispatchStream: public std::ostream {
public:
    DispatchStream();
    virtual ~DispatchStream();

    Glib::Dispatcher signal_sync;

    std::string pop();

private:
    class DispatchStreamBuf: public std::stringbuf {
    public:
        DispatchStreamBuf(DispatchStream *owner);

        std::string pop();

    protected:
    private:
        DispatchStream *owner;

        virtual int sync();
    };

    DispatchStreamBuf buf;
};

#endif // DISPATCHSTREAM_H
