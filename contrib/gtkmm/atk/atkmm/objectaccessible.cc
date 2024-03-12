// Generated by gtkmmproc -- DO NOT MODIFY!


#include <atkmm/objectaccessible.h>
#include <atkmm/private/objectaccessible_p.h>

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

#include <atk/atkgobjectaccessible.h>
namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Atk::ObjectAccessible> wrap(AtkGObjectAccessible* object, bool take_copy)
{
  return Glib::RefPtr<Atk::ObjectAccessible>( dynamic_cast<Atk::ObjectAccessible*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Atk
{


/* The *_Class implementation: */

const Glib::Class& ObjectAccessible_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ObjectAccessible_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(atk_gobject_accessible_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void ObjectAccessible_Class::class_init_function(void* g_class, void* class_data)
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


Glib::ObjectBase* ObjectAccessible_Class::wrap_new(GObject* object)
{
  return new ObjectAccessible((AtkGObjectAccessible*)object);
}


/* The implementation: */

AtkGObjectAccessible* ObjectAccessible::gobj_copy()
{
  reference();
  return gobj();
}

ObjectAccessible::ObjectAccessible(const Glib::ConstructParams& construct_params)
:
  Atk::Object(construct_params)
{

}

ObjectAccessible::ObjectAccessible(AtkGObjectAccessible* castitem)
:
  Atk::Object((AtkObject*)(castitem))
{}


ObjectAccessible::~ObjectAccessible()
{}


ObjectAccessible::CppClassType ObjectAccessible::objectaccessible_class_; // initialize static member

GType ObjectAccessible::get_type()
{
  return objectaccessible_class_.init().get_type();
}

GType ObjectAccessible::get_base_type()
{
  return atk_gobject_accessible_get_type();
}


Glib::RefPtr<Glib::Object> ObjectAccessible::get_object()
{

  Glib::RefPtr<Glib::Object> retvalue = Glib::wrap(atk_gobject_accessible_get_object(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;

}

Glib::RefPtr<const Glib::Object> ObjectAccessible::get_object() const
{
  return const_cast<ObjectAccessible*>(this)->get_object();
}

Glib::RefPtr<Atk::Object> ObjectAccessible::for_object(const Glib::RefPtr<Glib::Object>& obj)
{

  Glib::RefPtr<Atk::Object> retvalue = Glib::wrap(atk_gobject_accessible_for_object(Glib::unwrap(obj)));

  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}


Glib::RefPtr<const Atk::Object> ObjectAccessible::for_object(const Glib::RefPtr<const Glib::Object>& obj)
{

  Glib::RefPtr<const Atk::Object> retvalue = Glib::wrap(atk_gobject_accessible_for_object(const_cast<GObject*>(Glib::unwrap<Glib::Object>(obj))));

  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Atk


