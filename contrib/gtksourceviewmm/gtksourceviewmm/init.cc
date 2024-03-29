/* init.h
 * 
 * Copyright (C) 2005-2006 The gtksourceviewmm development team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#define Gsv gtksourceview
#include "init.h"
namespace Gsv
{

void
init ()
{
    static bool s_init = false ;
    if (!s_init) {
        Glib::init () ;
        Gsv::wrap_init () ;
        s_init = true ;
    }
}

}
