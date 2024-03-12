#ifndef REPLACECOUT_H
#define REPLACECOUT_H
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

#include "global.h"


// Found on http://stackoverflow.com/questions/4753153/redirecting-stdcout
class ScopedRedirect {
public:
    ScopedRedirect(std::ostream &inOriginal, std::ostream &inRedirect);

    ~ScopedRedirect();

private:
    ScopedRedirect(const ScopedRedirect &);
    ScopedRedirect &operator=(const ScopedRedirect &);

    std::ostream &mOriginal;
    std::streambuf *mReplacementBuffer;
    std::streambuf *mOldBuffer;
};

#endif // REPLACECOUT_H
