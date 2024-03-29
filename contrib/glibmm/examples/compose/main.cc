/* Copyright (C) 2007 The glibmm Development Team
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

#include <glibmm.h>
#include <iomanip>
#include <iostream>
#include <locale>

namespace
{

void show_examples()
{
  using Glib::ustring;

  const double a = 3456.78;
  const double b = 7890.12;
  const int    i = int(a / (a + b) * 40.0);

  std::cout
    << ustring::compose("%1 is lower than %2.", a, b)
    << std::endl
    << ustring::compose("%2 is greater than %1.", a, b)
    << std::endl
    << ustring::compose("%1 € are %3 %% of %2 €.", a, b,
                        ustring::format(std::fixed, std::setprecision(1), a / b * 100.0))
    << std::endl
    << ustring::compose("a : b = [%1|%2]",
                        ustring::format(std::setfill(L'a'), std::setw(i), ""),
                        ustring::format(std::setfill(L'b'), std::setw(40 - i), ""))
    << std::endl;
}

} // anonymous namespace

int main(int, char**)
{
  std::locale::global(std::locale(""));
  std::cout.imbue(std::locale());
  Glib::init();

  show_examples();

  return 0;
}
