// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtkmm/arrow.h>
#include <gtkmm/private/arrow_p.h>

// -*- c++ -*-
/* $Id$ */

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
#include <gtk/gtkarrow.h>

namespace Gtk
{

/*
#define MIN_ARROW_SIZE  11

Arrow::Arrow(ArrowType arrow_type, ShadowType shadow_type)
  _CONSTRUCT()
{

  GtkArrow *arrow=gobj();

  GTK_WIDGET (arrow)->requisition.width = MIN_ARROW_SIZE + GTK_MISC (arrow)->xpad * 2;
  GTK_WIDGET (arrow)->requisition.height = MIN_ARROW_SIZE + GTK_MISC (arrow)->ypad * 2;

  arrow->arrow_type = arrow_type;
  arrow->shadow_type = shadow_type;
}

*/

} /* namespace Gtk */


namespace
{
} // anonymous namespace


namespace Glib
{

Gtk::Arrow* wrap(GtkArrow* object, bool take_copy)
{
  return dynamic_cast<Gtk::Arrow *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& Arrow_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Arrow_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_arrow_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void Arrow_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
}

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


Glib::ObjectBase* Arrow_Class::wrap_new(GObject* o)
{
  return manage(new Arrow((GtkArrow*)(o)));

}


/* The implementation: */

Arrow::Arrow(const Glib::ConstructParams& construct_params)
:
  Gtk::Misc(construct_params)
{
  }

Arrow::Arrow(GtkArrow* castitem)
:
  Gtk::Misc((GtkMisc*)(castitem))
{
  }

Arrow::~Arrow()
{
  destroy_();
}

Arrow::CppClassType Arrow::arrow_class_; // initialize static member

GType Arrow::get_type()
{
  return arrow_class_.init().get_type();
}

GType Arrow::get_base_type()
{
  return gtk_arrow_get_type();
}


Arrow::Arrow(ArrowType arrow_type, ShadowType shadow_type)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Misc(Glib::ConstructParams(arrow_class_.init(), "arrow_type", ((GtkArrowType)(arrow_type)), "shadow_type", ((GtkShadowType)(shadow_type)), static_cast<char*>(0)))
{
  

}

void Arrow::set(ArrowType arrow_type, ShadowType shadow_type)
{
gtk_arrow_set(gobj(), ((GtkArrowType)(arrow_type)), ((GtkShadowType)(shadow_type))); 
}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<ArrowType> Arrow::property_arrow_type() 
{
  return Glib::PropertyProxy<ArrowType>(this, "arrow-type");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<ArrowType> Arrow::property_arrow_type() const
{
  return Glib::PropertyProxy_ReadOnly<ArrowType>(this, "arrow-type");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<ShadowType> Arrow::property_shadow_type() 
{
  return Glib::PropertyProxy<ShadowType>(this, "shadow-type");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<ShadowType> Arrow::property_shadow_type() const
{
  return Glib::PropertyProxy_ReadOnly<ShadowType>(this, "shadow-type");
}
#endif //GLIBMM_PROPERTIES_ENABLED


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gtk


