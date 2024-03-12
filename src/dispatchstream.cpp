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
*/

#include "dispatchstream.h"

DispatchStream::DispatchStream() :
    std::ostream(&buf),
    buf(this) {
    //ctor
}


DispatchStream::~DispatchStream() {
    //dtor
}


std::string DispatchStream::pop() {
    return buf.pop();
}


DispatchStream::DispatchStreamBuf::DispatchStreamBuf(DispatchStream *owner) {
    //ctor
    this->owner = owner;
}


std::string DispatchStream::DispatchStreamBuf::pop() {
    std::string result = str();
    str("");
    return result;
}


int DispatchStream::DispatchStreamBuf::sync() {
    owner->signal_sync();
    return 0;
}
