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
Object that stores one item from the ErrorView
*/

#include "statusmsg.h"


StatusMsg::StatusMsg() {
    //ctor
}


StatusMsg::StatusMsg(ustring msg) {
    //ctor
    this->msg = msg;
    pos = -1;
    line = -1;
    column = -1;
    length = 0;
}


StatusMsg::~StatusMsg() {
    //dtor
}
