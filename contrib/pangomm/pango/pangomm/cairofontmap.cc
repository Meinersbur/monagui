// Generated by gtkmmproc -- DO NOT MODIFY!


#include <pangomm/cairofontmap.h>
#include <pangomm/private/cairofontmap_p.h>

// -*- c++ -*-
/* $Id: cairofontmap.ccg,v 1.1 2006/05/30 17:14:21 murrayc Exp $ */

/* 
 *
 * Copyright 2001      The gtkmm Development Team
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

#include <pangomm/context.h>
#include <pango/pangocairo.h>

namespace Pango
{

} /* namespace Pango */


namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Pango::CairoFontMap> wrap(PangoCairoFontMap* object, bool take_copy)
{
  return Glib::RefPtr<Pango::CairoFontMap>( dynamic_cast<Pango::CairoFontMap*> (Glib::wrap_auto_interface<Pango::CairoFontMap> ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Pango
{


/* The *_Class implementation: */

const Glib::Interface_Class& CairoFontMap_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &CairoFontMap_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = pango_cairo_font_map_get_type();
  }

  return *this;
}

void CairoFontMap_Class::iface_init_function(void* g_iface, void*)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != 0); 

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
}

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


Glib::ObjectBase* CairoFontMap_Class::wrap_new(GObject* object)
{
  return new CairoFontMap((PangoCairoFontMap*)(object));
}


/* The implementation: */

CairoFontMap::CairoFontMap()
:
  Glib::Interface(cairofontmap_class_.init())
{}

CairoFontMap::CairoFontMap(PangoCairoFontMap* castitem)
:
  Glib::Interface((GObject*)(castitem))
{}

CairoFontMap::CairoFontMap(const Glib::Interface_Class& interface_class)
: Glib::Interface(interface_class)
{
}

CairoFontMap::~CairoFontMap()
{}

// static
void CairoFontMap::add_interface(GType gtype_implementer)
{
  cairofontmap_class_.init().add_interface(gtype_implementer);
}

CairoFontMap::CppClassType CairoFontMap::cairofontmap_class_; // initialize static member

GType CairoFontMap::get_type()
{
  return cairofontmap_class_.init().get_type();
}

GType CairoFontMap::get_base_type()
{
  return pango_cairo_font_map_get_type();
}


void CairoFontMap::set_default()
{
pango_cairo_font_map_set_default(gobj()); 
}

Cairo::FontType CairoFontMap::get_font_type() const
{
  return static_cast<Cairo::FontType>(pango_cairo_font_map_get_font_type(const_cast<PangoCairoFontMap*>(gobj())));
}

void CairoFontMap::set_resolution(double dpi)
{
pango_cairo_font_map_set_resolution(gobj(), dpi); 
}

double CairoFontMap::get_resolution() const
{
  return pango_cairo_font_map_get_resolution(const_cast<PangoCairoFontMap*>(gobj()));
}

Glib::RefPtr<Context> CairoFontMap::create_context()
{
  return Glib::wrap(pango_cairo_font_map_create_context(gobj()));
}


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Pango


