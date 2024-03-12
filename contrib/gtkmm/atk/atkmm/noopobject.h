// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _ATKMM_NOOPOBJECT_H
#define _ATKMM_NOOPOBJECT_H


#include <glibmm.h>

/* $Id$ */

/* Copyright (C) 1998-2002 The gtkmm Development Team
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

#include <atkmm/object.h>
#include <atkmm/component.h>
#include <atkmm/action.h>
#include <atkmm/editabletext.h>
#include <atkmm/image.h>
#include <atkmm/selection.h>
#include <atkmm/table.h>
#include <atkmm/value.h>
#include <atkmm/hypertext.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _AtkNoOpObject AtkNoOpObject;
typedef struct _AtkNoOpObjectClass AtkNoOpObjectClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Atk
{ class NoOpObject_Class; } // namespace Atk
namespace Atk
{

/** An Atk::NoOpObject is an Atk::Object which purports to implement all ATK interfaces.
 * It is the type of Atk::Object which is created if an accessible object is requested for an object type for which no
 * factory type is specified.
 */

class NoOpObject
:
  public Atk::Object,
  public Atk::Component,
  public Atk::Action,
  public Atk::EditableText,
  public Atk::Image,
  public Atk::Selection,
  public Atk::Table,
  public Atk::Text,
  public Atk::Hypertext,
  public Atk::Value
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef NoOpObject CppObjectType;
  typedef NoOpObject_Class CppClassType;
  typedef AtkNoOpObject BaseObjectType;
  typedef AtkNoOpObjectClass BaseClassType;

private:  friend class NoOpObject_Class;
  static CppClassType noopobject_class_;

private:
  // noncopyable
  NoOpObject(const NoOpObject&);
  NoOpObject& operator=(const NoOpObject&);

protected:
  explicit NoOpObject(const Glib::ConstructParams& construct_params);
  explicit NoOpObject(AtkNoOpObject* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~NoOpObject();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  AtkNoOpObject*       gobj()       { return reinterpret_cast<AtkNoOpObject*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const AtkNoOpObject* gobj() const { return reinterpret_cast<AtkNoOpObject*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  AtkNoOpObject* gobj_copy();

private:

  
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  friend class Atk::Object_Class;
#endif


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

protected:
  //GTK+ Virtual Functions (override these to change behaviour):
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

  //Default Signal Handlers::
#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


};

} // namespace Atk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Atk::NoOpObject
   */
  Glib::RefPtr<Atk::NoOpObject> wrap(AtkNoOpObject* object, bool take_copy = false);
}


#endif /* _ATKMM_NOOPOBJECT_H */
