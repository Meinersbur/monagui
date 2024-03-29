/* Copyright (C) 2004 The glibmm Development Team
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
#include <iostream>


int main(int, char**)
{
  Glib::init();

  const std::string filepath = "./example.ini";

  Glib::KeyFile keyfile;

#ifdef GLIBMM_EXCEPTIONS_ENABLED
  // An exception will be thrown if the file is not there, or if the file is incorrectly formatted:
  try
  {
    keyfile.load_from_file(filepath);
  }
  catch(const Glib::Error& ex)
  {
    std::cerr << "Exception while loading key file: " << ex.what() << std::endl;
    return 1;
  }

  // Try to get a value that is not in the file:
  // An exception will be thrown if the value is not in the file:
  try
  {
    const Glib::ustring value = keyfile.get_value("somegroup", "somekey");
    std::cout << "somekey value=" << value << std::endl;
  }
  catch(const Glib::KeyFileError& ex)
  {
    std::cerr << "Exception while getting value: " << ex.what() << std::endl;
  }

  // Try to get a value that is in the file:
  // An exception will be thrown if the value is not in the file:
  try
  {
    const Glib::ustring value = keyfile.get_value("First Group", "Welcome");
    std::cout << "Welcome value=" << value << std::endl;
  }
  catch(const Glib::KeyFileError& ex)
  {
    std::cerr << "Exception while getting value: " << ex.what() << std::endl;
  }

  // Try to get a list of integers that is in the file:
  // An exception will be thrown if the value is not in the file:
  try
  {
    const std::vector<int> values = keyfile.get_integer_list("Another Group", "Numbers");

    for(std::vector<int>::const_iterator p = values.begin(); p != values.end(); ++p)
      std::cout << "Number list value: item=" << *p << std::endl;
  }
  catch(const Glib::KeyFileError& ex)
  {
    std::cerr << "Exception while getting list value: " << ex.what() << std::endl;
  }
#else /* !GLIBMM_EXCEPTIONS_ENABLED */
  std::auto_ptr<Glib::Error> ex;

  if(!keyfile.load_from_file(filepath, Glib::KeyFileFlags(), ex))
  {
    std::cerr << "Exception while loading key file: " << ex->what() << std::endl;
    return 1;
  }

  // Try to get a value that is not in the file:
  {
    const Glib::ustring value = keyfile.get_value("somegroup", "somekey", ex);
    if (!ex.get())
      std::cout << "somekey value=" << value << std::endl;
    else
      std::cerr << "Exception while getting value: " << ex->what() << std::endl;
  }

  // Try to get a value that is in the file:
  {
    const Glib::ustring value = keyfile.get_value("First Group", "Welcome", ex);
    if (!ex.get())
      std::cout << "Welcome value=" << value << std::endl;
    else
      std::cerr << "Exception while getting value: " << ex->what() << std::endl;
  }

  // Try to get a list of integers that is in the file:
  {
    const std::vector<int> values = keyfile.get_integer_list("Another Group", "Numbers", ex);
    if (!ex.get())
    {
      for(std::vector<int>::const_iterator p = values.begin(); p != values.end(); ++p)
        std::cout << "Number list value: item=" << *p << std::endl;
    }
    else
      std::cerr << "Exception while getting list value: " << ex->what() << std::endl;
  }
#endif /* !GLIBMM_EXCEPTIONS_ENABLED */

  return 0;
}

