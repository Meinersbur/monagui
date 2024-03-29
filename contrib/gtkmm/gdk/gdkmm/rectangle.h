// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GDKMM_RECTANGLE_H
#define _GDKMM_RECTANGLE_H


#include <glibmm.h>

/* $Id$ */

/* rectangle.h
 *
 * Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <gdk/gdk.h>


namespace Gdk
{

/** Gdk::Rectangle is a structure holding the position and size of a rectangle.
 * The intersection of two rectangles can be computed with intersect(). To find the union of two rectangles use union().
 */
class Rectangle
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Rectangle CppObjectType;
  typedef GdkRectangle BaseObjectType;

  static GType get_type() G_GNUC_CONST;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  Rectangle();

  explicit Rectangle(const GdkRectangle* gobject); // always takes a copy

  ///Provides access to the underlying C instance.
  GdkRectangle*       gobj()       { return &gobject_; }

  ///Provides access to the underlying C instance.
  const GdkRectangle* gobj() const { return &gobject_; }

protected:
  GdkRectangle gobject_;

private:
  
public:
//_CUSTOM_DEFAULT_CTOR
//Rectangle();
  Rectangle(int x, int y, int width, int height);

  Rectangle& join(const Rectangle& src2);
  Rectangle& intersect(const Rectangle& src2);
  Rectangle& intersect(const Rectangle& src2, bool& rectangles_intersect);

  bool has_zero_area() const;

   int get_x() const;
    void set_x(const int& value);
    int get_y() const;
    void set_y(const int& value);
    int get_width() const;
    void set_width(const int& value);
    int get_height() const;
    void set_height(const int& value);
 

};

} // namespace Gdk


namespace Glib
{

/** @relates Gdk::Rectangle
 * @param object The C instance
 * @result A C++ instance that wraps this C instance.
 */
Gdk::Rectangle& wrap(GdkRectangle* object);

/** @relates Gdk::Rectangle
 * @param object The C instance
 * @result A C++ instance that wraps this C instance.
 */
const Gdk::Rectangle& wrap(const GdkRectangle* object);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class Value<Gdk::Rectangle> : public Glib::Value_Boxed<Gdk::Rectangle>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GDKMM_RECTANGLE_H */

