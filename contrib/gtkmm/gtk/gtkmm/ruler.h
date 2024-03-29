// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_RULER_H
#define _GTKMM_RULER_H


#include <glibmm.h>

/* $Id$ */

/* ruler.h
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

#include <gtkmm/widget.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkRuler GtkRuler;
typedef struct _GtkRulerClass GtkRulerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class Ruler_Class; } // namespace Gtk
#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkVRuler GtkVRuler;
typedef struct _GtkVRulerClass GtkVRulerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class VRuler_Class; } // namespace Gtk
#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkHRuler GtkHRuler;
typedef struct _GtkHRulerClass GtkHRulerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class HRuler_Class; } // namespace Gtk
namespace Gtk
{

/** Base class for horizontal or vertical rulers.
 *
 * NOTE this widget is considered too specialized/little-used for GTK+, and will in the future be moved to some other package. If your application needs this widget, feel free to use it, as the widget does work and is useful in some applications; it's just not of general interest. However, we are not accepting new features for the widget, and it will eventually move out of the GTK+ distribution.
 * Rulers are used to show the mouse pointer's location in a window. The ruler can either be horizontal or vertical. Within the ruler a small triangle indicates the location of the mouse relative to the horixontal or vertical ruler.

 * This is an abstract base for Gtk::HRuler and
 * Gtk::VRuler.  Users should only instantiate those types.
 *
 * @ingroup Widgets
 */

class Ruler : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Ruler CppObjectType;
  typedef Ruler_Class CppClassType;
  typedef GtkRuler BaseObjectType;
  typedef GtkRulerClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~Ruler();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class Ruler_Class;
  static CppClassType ruler_class_;

  // noncopyable
  Ruler(const Ruler&);
  Ruler& operator=(const Ruler&);

protected:
  explicit Ruler(const Glib::ConstructParams& construct_params);
  explicit Ruler(GtkRuler* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkRuler*       gobj()       { return reinterpret_cast<GtkRuler*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkRuler* gobj() const { return reinterpret_cast<GtkRuler*>(gobject_); }


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


private:

protected:
  Ruler();

public:
  

  MetricType get_metric() const; 

  /** Sets the desired metric of the ruler.  The possible choices are:
   * <ul><li>Gtk::PIXELS
   * <li>Gtk::INCHES
   * <li>Gtk::CENTIMETERS
   * </ul>The default metric is Gtk::PIXELS.
   */
  
  void set_metric(MetricType metric = PIXELS);
  
  /** Gets the units used for a Gtk::Ruler. See set_metric().
   * @return The units currently used for @a ruler.
   */
  MetricType get_metric();

   double get_range_lower() const;
    double get_range_upper() const;
 
  /** sets the range of the ruler.
   * <i>upper</i> and <i>lower</i> arguments denote the extents of the Ruler.
   * <i>max_size</i> is the largest number displayed by the ruler.
   * <i>position</i> gives the initial value of the ruler.
   * Rulers do not have sane defaults so this function should always be called.
   */
  
  /** This sets the range of the ruler.
   * @param lower The lower limit of the ruler.
   * @param upper The upper limit of the ruler.
   * @param position The mark on the ruler.
   * @param max_size The maximum size of the ruler used when calculating the space to
   * leave for the text.
   */
  void set_range(double lower, double upper, double position, double max_size);
  
  /** Retrieves values indicating the range and current position of a Gtk::Ruler.
   * See set_range().
   * @param lower Location to store lower limit of the ruler, or <tt>0</tt>.
   * @param upper Location to store upper limit of the ruler, or <tt>0</tt>.
   * @param position Location to store the current position of the mark on the ruler, or <tt>0</tt>.
   * @param max_size Location to store the maximum size of the ruler used when calculating
   * the space to leave for the text, or <tt>0</tt>.
   */
  void get_range(double& lower, double& upper, double& position, double& max_size);

  /// draw tick marks on the ruler
  
  void draw_ticks();

  /// draw a position indicator on the ruler
  
  void draw_pos();

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void draw_ticks_vfunc();
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void draw_pos_vfunc();
#endif //GLIBMM_VFUNCS_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Lower limit of ruler.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<double> property_lower() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Lower limit of ruler.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<double> property_lower() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Upper limit of ruler.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<double> property_upper() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Upper limit of ruler.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<double> property_upper() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Position of mark on the ruler.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<double> property_position() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Position of mark on the ruler.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<double> property_position() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Maximum size of the ruler.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<double> property_max_size() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Maximum size of the ruler.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<double> property_max_size() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


};


/** Vertical Ruler
 *
 * @ingroup Widgets
 */

class VRuler : public Ruler
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef VRuler CppObjectType;
  typedef VRuler_Class CppClassType;
  typedef GtkVRuler BaseObjectType;
  typedef GtkVRulerClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~VRuler();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class VRuler_Class;
  static CppClassType vruler_class_;

  // noncopyable
  VRuler(const VRuler&);
  VRuler& operator=(const VRuler&);

protected:
  explicit VRuler(const Glib::ConstructParams& construct_params);
  explicit VRuler(GtkVRuler* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkVRuler*       gobj()       { return reinterpret_cast<GtkVRuler*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkVRuler* gobj() const { return reinterpret_cast<GtkVRuler*>(gobject_); }


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


private:

public:
  VRuler();
  

};


/** Horizontal Ruler
 *
 * @ingroup Widgets
 */

class HRuler : public Ruler
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef HRuler CppObjectType;
  typedef HRuler_Class CppClassType;
  typedef GtkHRuler BaseObjectType;
  typedef GtkHRulerClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~HRuler();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class HRuler_Class;
  static CppClassType hruler_class_;

  // noncopyable
  HRuler(const HRuler&);
  HRuler& operator=(const HRuler&);

protected:
  explicit HRuler(const Glib::ConstructParams& construct_params);
  explicit HRuler(GtkHRuler* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkHRuler*       gobj()       { return reinterpret_cast<GtkHRuler*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkHRuler* gobj() const { return reinterpret_cast<GtkHRuler*>(gobject_); }


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


private:

public:
  HRuler();
  

};

} /* namespace Gtk */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Ruler
   */
  Gtk::Ruler* wrap(GtkRuler* object, bool take_copy = false);
} //namespace Glib


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::VRuler
   */
  Gtk::VRuler* wrap(GtkVRuler* object, bool take_copy = false);
} //namespace Glib


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::HRuler
   */
  Gtk::HRuler* wrap(GtkHRuler* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_RULER_H */

