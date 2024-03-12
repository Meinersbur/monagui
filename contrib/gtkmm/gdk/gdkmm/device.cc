// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gdkmm/device.h>
#include <gdkmm/private/device_p.h>

// -*- c++ -*-
/* $Id$ */

/* Copyright 2002 The gtkmm Development Team
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

#include <gdk/gdkinput.h>

namespace Gdk
{


} // namespace Gdk


namespace
{
} // anonymous namespace

// static
GType Glib::Value<Gdk::InputMode>::value_type()
{
  return gdk_input_mode_get_type();
}

// static
GType Glib::Value<Gdk::InputSource>::value_type()
{
  return gdk_input_source_get_type();
}


namespace Glib
{

Glib::RefPtr<Gdk::Device> wrap(GdkDevice* object, bool take_copy)
{
  return Glib::RefPtr<Gdk::Device>( dynamic_cast<Gdk::Device*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gdk
{


/* The *_Class implementation: */

const Glib::Class& Device_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Device_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gdk_device_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void Device_Class::class_init_function(void* g_class, void* class_data)
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


Glib::ObjectBase* Device_Class::wrap_new(GObject* object)
{
  return new Device((GdkDevice*)object);
}


/* The implementation: */

GdkDevice* Device::gobj_copy()
{
  reference();
  return gobj();
}

Device::Device(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

Device::Device(GdkDevice* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


Device::~Device()
{}


Device::CppClassType Device::device_class_; // initialize static member

GType Device::get_type()
{
  return device_class_.init().get_type();
}

GType Device::get_base_type()
{
  return gdk_device_get_type();
}


Device::Device()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(device_class_.init()))
{
  

}

void Device::set_source(InputSource source)
{
gdk_device_set_source(gobj(), ((GdkInputSource)(source))); 
}

bool Device::set_mode(InputMode mode)
{
  return gdk_device_set_mode(gobj(), ((GdkInputMode)(mode)));
}

void Device::set_key(guint index_, guint keyval, ModifierType modifiers)
{
gdk_device_set_key(gobj(), index_, keyval, ((GdkModifierType)(modifiers))); 
}

void Device::set_axis_use(guint index_, AxisUse use)
{
gdk_device_set_axis_use(gobj(), index_, ((GdkAxisUse)(use))); 
}

void Device::get_state(const Glib::RefPtr<Window>& window, double& axes, ModifierType& mask)
{
gdk_device_get_state(gobj(), Glib::unwrap(window), &(axes), ((GdkModifierType*) &(mask))); 
}

bool Device::get_history(const Glib::RefPtr<Window>& window, guint32 start, guint32 stop, GdkTimeCoord**& events, int& n_events)
{
  return gdk_device_get_history(gobj(), Glib::unwrap(window), start, stop, &(events), &n_events);
}

bool Device::get_axis(double& axes, AxisUse use, double& value) const
{
  return gdk_device_get_axis(const_cast<GdkDevice*>(gobj()), &(axes), ((GdkAxisUse)(use)), &(value));
}

 Glib::ustring Device::get_name() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(gobj()->name);
}
 
 InputSource Device::get_source() const
{
  return ((InputSource)(gobj()->source));
}
 
 InputMode Device::get_mode() const
{
  return ((InputMode)(gobj()->mode));
}
 
 bool Device::get_has_cursor() const
{
  return gobj()->has_cursor;
}
 

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gdk


