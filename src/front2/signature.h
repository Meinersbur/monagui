#ifndef HEADER_E8610CDE7930AA78
#define HEADER_E8610CDE7930AA78

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

#ifndef __SIGNATURE_H
#define __SIGNATURE_H

#include "ident.h"

class Signature {
public:
  Signature();
  Signature(IdentList &idents);
  ~Signature();

  void make(IdentList &idents);
  void dump(char *to);
  int operator==(const Signature &);

  unsigned  size;
  int      *sign;
  int       hashvalue;
};

#endif

#endif // header guard 
