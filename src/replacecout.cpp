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
While a variable of this type is in scope, all input to inOriginal are redirected to the stream inRedirect
*/

#include "replacecout.h"


ScopedRedirect::ScopedRedirect(std::ostream &inOriginal, std::ostream &inRedirect):
    mOriginal(inOriginal),
    mReplacementBuffer(inRedirect.rdbuf()),
    mOldBuffer(inOriginal.rdbuf(inRedirect.rdbuf())) {
}


ScopedRedirect::~ScopedRedirect() {
    std::streambuf *old = mOriginal.rdbuf(mOldBuffer);
    assert(old == mReplacementBuffer && "Multiple redirects must be perfectly nested");
}
