// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GDKMM_DISPLAYMANAGER_H
#define _GDKMM_DISPLAYMANAGER_H


#include <glibmm.h>

/* $Id: displaymanager.hg,v 1.8 2006/04/12 11:11:24 murrayc Exp $ */

/* displaymanager.h
 *
 * Copyright (C) 2002 The gtkmm Development Team
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

#include <glibmm/object.h>
#include <gdkmm/display.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GdkDisplayManager GdkDisplayManager;
typedef struct _GdkDisplayManagerClass GdkDisplayManagerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gdk
{ class DisplayManager_Class; } // namespace Gdk
namespace Gdk
{

/** The purpose of the GdkDisplayManager singleton object is to offer notification when displays appear or disappear or the
 * default display changes.
 */

class DisplayManager : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef DisplayManager CppObjectType;
  typedef DisplayManager_Class CppClassType;
  typedef GdkDisplayManager BaseObjectType;
  typedef GdkDisplayManagerClass BaseClassType;

private:  friend class DisplayManager_Class;
  static CppClassType displaymanager_class_;

private:
  // noncopyable
  DisplayManager(const DisplayManager&);
  DisplayManager& operator=(const DisplayManager&);

protected:
  explicit DisplayManager(const Glib::ConstructParams& construct_params);
  explicit DisplayManager(GdkDisplayManager* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~DisplayManager();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GdkDisplayManager*       gobj()       { return reinterpret_cast<GdkDisplayManager*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GdkDisplayManager* gobj() const { return reinterpret_cast<GdkDisplayManager*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GdkDisplayManager* gobj_copy();

private:

protected:

public:

  
  /** 
   * @return The singleton Gdk::DisplayManager object.
   * the global Gdk::DisplayManager singleton; gdk_parse_pargs(),
   * gdk_init(), or gdk_init_check() must have been called first.
   * 
   * @newin2p2.
   */
  static Glib::RefPtr<DisplayManager> get();
  
  /** Gets the default Gdk::Display.
   * @return A Gdk::Display, or <tt>0</tt> if there is no default
   * display.
   * 
   * @newin2p2.
   */
  Glib::RefPtr<Display> get_default_display();
  
  /** Gets the default Gdk::Display.
   * @return A Gdk::Display, or <tt>0</tt> if there is no default
   * display.
   * 
   * @newin2p2.
   */
  Glib::RefPtr<const Display> get_default_display() const;

  
  /** Sets @a display as the default display.
   * 
   * @newin2p2
   * @param display A Gdk::Display.
   */
  void set_default_display(const Glib::RefPtr<Display>& display);

  
  /** List all currently open displays.
   * 
   *  @a newin2p2
   * @return A list of Gdk::Display objects.
   */
  Glib::SListHandle< Glib::RefPtr<Display> > list_displays();

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The default display for GDK.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< Glib::RefPtr<Display> > property_default_display() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The default display for GDK.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Display> > property_default_display() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  
  /** The display_opened signal is emitted when a display is opened.
   *
   * @newin2p2
   *
   * @param display the opened display
   *
   * @par Prototype:
   * <tt>void on_my_%display_opened(const Glib::RefPtr<Display>& display)</tt>
   */

  Glib::SignalProxy1< void,const Glib::RefPtr<Display>& > signal_display_opened();


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
  virtual void on_display_opened(const Glib::RefPtr<Display>& display);
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


};

} /* namespace Gdk */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::DisplayManager
   */
  Glib::RefPtr<Gdk::DisplayManager> wrap(GdkDisplayManager* object, bool take_copy = false);
}


#endif /* _GDKMM_DISPLAYMANAGER_H */

