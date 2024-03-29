// Generated by gtkmmproc -- DO NOT MODIFY!


#include <pangomm/layoutline.h>
#include <pangomm/private/layoutline_p.h>

// -*- c++ -*-
/* $Id: layoutline.ccg,v 1.3 2006/05/30 17:14:21 murrayc Exp $ */

/*
 *
 * Copyright 1998-2002 The gtkmm Development Team
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

#include <pangomm/layout.h>
#include <pango/pangocairo.h>

namespace Pango {

Rectangle LayoutLine::get_ink_extents() const
{
  Rectangle ink_rect;
  pango_layout_line_get_extents(const_cast<PangoLayoutLine*>(gobj()), ink_rect.gobj(), 0);
  return ink_rect;
}

Rectangle LayoutLine::get_logical_extents() const
{
  Rectangle logical_rect;
  pango_layout_line_get_extents(const_cast<PangoLayoutLine*>(gobj()), 0, logical_rect.gobj());
  return logical_rect;
}

Rectangle LayoutLine::get_pixel_ink_extents() const
{
  Rectangle ink_rect;
  pango_layout_line_get_pixel_extents(const_cast<PangoLayoutLine*>(gobj()), ink_rect.gobj(), 0);
  return ink_rect;
}

Rectangle LayoutLine::get_pixel_logical_extents() const
{
  Rectangle logical_rect;
  pango_layout_line_get_pixel_extents(const_cast<PangoLayoutLine*>(gobj()), 0, logical_rect.gobj());
  return logical_rect;
}

int LayoutLine::index_to_x(int index, bool trailing) const
{
  int x_pos;
  pango_layout_line_index_to_x(const_cast<PangoLayoutLine*>(gobj()), index, trailing, &x_pos);
  return x_pos;
}

Glib::ArrayHandle<std::pair<int,int> > LayoutLine::get_x_ranges(int start_index, int end_index) const
{
  int* ranges = 0;
  int n_ranges = 0;
  pango_layout_line_get_x_ranges(const_cast<PangoLayoutLine*>(gobj()), start_index, end_index, &ranges, &n_ranges);
  return Glib::ArrayHandle<std::pair<int,int> >(reinterpret_cast<std::pair<int,int>*>(ranges), n_ranges, Glib::OWNERSHIP_SHALLOW);
}

void LayoutLine::show_in_cairo_context(const Cairo::RefPtr<Cairo::Context>& context)
{
  pango_cairo_show_layout_line(context->cobj(), gobj());
}

void LayoutLine::add_to_cairo_context(const Cairo::RefPtr<Cairo::Context>& context)
{
  pango_cairo_layout_line_path(context->cobj(), gobj());
}

} /* namespace Pango */

namespace
{
} // anonymous namespace


/* Why reinterpret_cast<LayoutLine*>(gobject) is needed:
 *
 * A LayoutLine instance is in fact always a PangoLayoutLine instance.
 * Unfortunately, PangoLayoutLine cannot be a member of LayoutLine,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because LayoutLine does not have any member data, and
 * it is impossible to derive from it.  This is ensured by not implementing
 * the (protected) default constructor.  The ctor is protected rather than
 * private just to avoid a compile warning.
 */

namespace Glib
{

Glib::RefPtr<Pango::LayoutLine> wrap(PangoLayoutLine* object, bool take_copy)
{
  if(take_copy && object)
    pango_layout_line_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::RefPtr<Pango::LayoutLine>(reinterpret_cast<Pango::LayoutLine*>(object));
}

} // namespace Glib


namespace Pango
{


void LayoutLine::reference() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  pango_layout_line_ref(reinterpret_cast<PangoLayoutLine*>(const_cast<LayoutLine*>(this)));
}

void LayoutLine::unreference() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  pango_layout_line_unref(reinterpret_cast<PangoLayoutLine*>(const_cast<LayoutLine*>(this)));
}

PangoLayoutLine* LayoutLine::gobj()
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<PangoLayoutLine*>(this);
}

const PangoLayoutLine* LayoutLine::gobj() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const PangoLayoutLine*>(this);
}

PangoLayoutLine* LayoutLine::gobj_copy() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  PangoLayoutLine *const gobject = reinterpret_cast<PangoLayoutLine*>(const_cast<LayoutLine*>(this));
  pango_layout_line_ref(gobject);
  return gobject;
}


bool LayoutLine::x_to_index(int x_pos, int& index, int& trailing) const
{
  return pango_layout_line_x_to_index(const_cast<PangoLayoutLine*>(gobj()), x_pos, &index, &trailing);
}

void LayoutLine::get_extents(Rectangle& ink_rect, Rectangle& logical_rect) const
{
pango_layout_line_get_extents(const_cast<PangoLayoutLine*>(gobj()), (ink_rect).gobj(), (logical_rect).gobj()); 
}

void LayoutLine::get_pixel_extents(Rectangle& ink_rect, Rectangle& logical_rect) const
{
pango_layout_line_get_pixel_extents(const_cast<PangoLayoutLine*>(gobj()), (ink_rect).gobj(), (logical_rect).gobj()); 
}

 Glib::RefPtr<Pango::Layout> LayoutLine::get_layout()
{
  Glib::RefPtr<Pango::Layout> ref_ptr(Glib::wrap(gobj()->layout));

  if(ref_ptr)
    ref_ptr->reference();

  return ref_ptr;
}

Glib::RefPtr<const Pango::Layout> LayoutLine::get_layout() const
{
  Glib::RefPtr<const Pango::Layout> ref_ptr(Glib::wrap(gobj()->layout));

  if(ref_ptr)
    ref_ptr->reference();

  return ref_ptr;
}
 
 int LayoutLine::get_length() const
{
  return gobj()->length;
}
 
 int LayoutLine::get_start_index() const
{
  return gobj()->start_index;
}
 

} // namespace Pango


