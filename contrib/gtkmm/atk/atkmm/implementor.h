// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _ATKMM_IMPLEMENTOR_H
#define _ATKMM_IMPLEMENTOR_H


#include <glibmm.h>

/* $Id$ */

/* Copyright (C) 2002 The gtkmm Development Team
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

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _AtkImplementorIface AtkImplementorIface;
  typedef struct _AtkImplementor      AtkImplementor;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _AtkImplementor AtkImplementor;
typedef struct _AtkImplementorClass AtkImplementorClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Atk
{ class Implementor_Class; } // namespace Atk
namespace Atk
{


class Implementor : public Glib::Interface
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef Implementor CppObjectType;
  typedef Implementor_Class CppClassType;
  typedef AtkImplementor BaseObjectType;
  typedef AtkImplementorIface BaseClassType;

private:
  friend class Implementor_Class;
  static CppClassType implementor_class_;

  // noncopyable
  Implementor(const Implementor&);
  Implementor& operator=(const Implementor&);

protected:
  Implementor(); // you must derive from this class

  /** Called by constructors of derived classes. Provide the result of 
   * the Class init() function to ensure that it is properly 
   * initialized.
   * 
   * @param interface_class The Class object for the derived type.
   */
  explicit Implementor(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface. 
  explicit Implementor(AtkImplementor* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~Implementor();

  static void add_interface(GType gtype_implementer);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  AtkImplementor*       gobj()       { return reinterpret_cast<AtkImplementor*>(gobject_); }

  ///Provides access to the underlying C GObject.  
  const AtkImplementor* gobj() const { return reinterpret_cast<AtkImplementor*>(gobject_); }

private:


protected:
  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual Glib::RefPtr<Object> ref_accessibile_vfunc();
#endif //GLIBMM_VFUNCS_ENABLED


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
   * @relates Atk::Implementor
   */
  Glib::RefPtr<Atk::Implementor> wrap(AtkImplementor* object, bool take_copy = false);

} // namespace Glib


#endif /* _ATKMM_IMPLEMENTOR_H */

