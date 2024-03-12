// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GDKMM_DEVICE_H
#define _GDKMM_DEVICE_H


#include <glibmm.h>

/* $Id$ */

/* Copyright (C) 2002-2004 The gtkmm Development Team
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

#include <gdkmm/window.h>
#include <gdkmm/event.h>
#include <gdk/gdkinput.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GdkDevice GdkDevice;
typedef struct _GdkDeviceClass GdkDeviceClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdk
{ class Device_Class; } // namespace Gdk
namespace Gdk
{

/** @addtogroup gdkmmEnums Enums and Flags */

/**
 * @ingroup gdkmmEnums
 */
enum InputMode
{
  MODE_DISABLED,
  MODE_SCREEN,
  MODE_WINDOW
};

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gdk::InputMode> : public Glib::Value_Enum<Gdk::InputMode>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdk
{

/**
 * @ingroup gdkmmEnums
 */
enum InputSource
{
  SOURCE_MOUSE,
  SOURCE_PEN,
  SOURCE_ERASER,
  SOURCE_CURSOR
};

} // namespace Gdk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gdk::InputSource> : public Glib::Value_Enum<Gdk::InputSource>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdk
{


/** A Gdk::Device instance contains a detailed description of an extended input device.
 */

class Device : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef Device CppObjectType;
  typedef Device_Class CppClassType;
  typedef GdkDevice BaseObjectType;
  typedef GdkDeviceClass BaseClassType;

private:  friend class Device_Class;
  static CppClassType device_class_;

private:
  // noncopyable
  Device(const Device&);
  Device& operator=(const Device&);

protected:
  explicit Device(const Glib::ConstructParams& construct_params);
  explicit Device(GdkDevice* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~Device();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GdkDevice*       gobj()       { return reinterpret_cast<GdkDevice*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GdkDevice* gobj() const { return reinterpret_cast<GdkDevice*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GdkDevice* gobj_copy();

private:


protected:
  Device();

public:

  
  void set_source(InputSource source);
  
  bool set_mode(InputMode mode);
  
  void set_key(guint index_, guint keyval, ModifierType modifiers);
  
  void set_axis_use(guint index_, AxisUse use);
  
  void get_state(const Glib::RefPtr<Window>& window, double& axes, ModifierType& mask);
  
  /** Obtains the motion history for a device; given a starting and
   * ending timestamp, return all events in the motion history for
   * the device in the given range of time. Some windowing systems
   * do not support motion history, in which case, <tt>false</tt> will
   * be returned. (This is not distinguishable from the case where
   * motion history is supported and no events were found.)
   * @param window The window with respect to which which the event coordinates will be reported.
   * @param start Starting timestamp for range of events to return.
   * @param stop Ending timestamp for the range of events to return.
   * @param events Location to store a newly-allocated array of Gdk::TimeCoord, or <tt>0</tt>.
   * @param n_events Location to store the length of @a events, or <tt>0</tt>.
   * @return <tt>true</tt> if the windowing system supports motion history and
   * at least one event was found.
   */
  bool get_history(const Glib::RefPtr<Window>& window, guint32 start, guint32 stop, GdkTimeCoord**& events, int& n_events);
  
  /** Interprets an array of double as axis values for a given device,
   * and locates the value in the array for a given axis use.
   * @param axes Pointer to an array of axes.
   * @param use The use to look for.
   * @param value Location to store the found value.
   * @return <tt>true</tt> if the given axis use was found, otherwise <tt>false</tt>.
   */
  bool get_axis(double& axes, AxisUse use, double& value) const;

  /** Gets the name of this device.
   * @result The name of this device.
   */
   Glib::ustring get_name() const;
   
  /** Gets the type of this device.
   * @result The type of this device.
   */
   InputSource get_source() const;
 
  /** Gets the mode of this device.
   * @result The mode of this device.
   */
   InputMode get_mode() const;
     
  /** Discover whether the pointer follows device motion.
   * @result true if the pointer follows device motion.
   */
   bool get_has_cursor() const;
 
  //TODO: Add suitable accessor for the information in these fields. For now, people must use gobj() and access them directly.
  //gint num_axes	the length of the axes array.
  //GdkDeviceAxis *axes	an array of GdkDeviceAxis, describing the axes of this device.
  //
  //gint num_keys	the length of the keys array.
  //GdkDeviceKey *keys	an array of GdkDeviceKey, describing the mapped macro buttons of this device.      


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

} // namespace Gdk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::Device
   */
  Glib::RefPtr<Gdk::Device> wrap(GdkDevice* object, bool take_copy = false);
}


#endif /* _GDKMM_DEVICE_H */

