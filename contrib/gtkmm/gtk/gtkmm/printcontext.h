// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_PRINTCONTEXT_H
#define _GTKMM_PRINTCONTEXT_H


#include <glibmm.h>

/* Copyright (C) 2006 The gtkmm Development Team
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

#include <cairomm/context.h>

#include <pangomm/fontmap.h>
#include <pangomm/context.h>
#include <pangomm/layout.h>

#include <gtkmm/pagesetup.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkPrintContext GtkPrintContext;
typedef struct _GtkPrintContextClass GtkPrintContextClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class PrintContext_Class; } // namespace Gtk
namespace Gtk
{

/** A PrintContext encapsulates context information that is required when
 * drawing pages for printing, such as the cairo context and important 
 * parameters like page size and resolution. It also lets you easily
 * create Pango::Layout and Pango::Context objects that match the font metrics 
 * of the cairo surface.
 * 
 * PrintContext objects gets passed to the begin-print, end-print, 
 * request-page-setup and draw-page signals on the PrintOperation.
 *
 * @newin2p10
 *
 * @ingroup Printing
 */

class PrintContext : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef PrintContext CppObjectType;
  typedef PrintContext_Class CppClassType;
  typedef GtkPrintContext BaseObjectType;
  typedef GtkPrintContextClass BaseClassType;

private:  friend class PrintContext_Class;
  static CppClassType printcontext_class_;

private:
  // noncopyable
  PrintContext(const PrintContext&);
  PrintContext& operator=(const PrintContext&);

protected:
  explicit PrintContext(const Glib::ConstructParams& construct_params);
  explicit PrintContext(GtkPrintContext* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~PrintContext();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkPrintContext*       gobj()       { return reinterpret_cast<GtkPrintContext*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkPrintContext* gobj() const { return reinterpret_cast<GtkPrintContext*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkPrintContext* gobj_copy();

private:


public:

   
  /** Obtains the cairo context that is associated with the
   * Gtk::PrintContext.
   * @return The cairo context of @a context
   * 
   * @newin2p10.
   */
  Cairo::RefPtr<Cairo::Context> get_cairo_context();
  
  /** Obtains the cairo context that is associated with the
   * Gtk::PrintContext.
   * @return The cairo context of @a context
   * 
   * @newin2p10.
   */
  Cairo::RefPtr<const Cairo::Context> get_cairo_context() const;

  
  /** Obtains the Gtk::PageSetup that determines the page
   * dimensions of the Gtk::PrintContext.
   * @return The page setup of @a context
   * 
   * @newin2p10.
   */
  Glib::RefPtr<PageSetup> get_page_setup();
  
  /** Obtains the Gtk::PageSetup that determines the page
   * dimensions of the Gtk::PrintContext.
   * @return The page setup of @a context
   * 
   * @newin2p10.
   */
  Glib::RefPtr<const PageSetup> get_page_setup() const;

  
  /** Obtains the width of the Gtk::PrintContext, in pixels.
   * @return The width of @a context
   * 
   * @newin2p10.
   */
  double get_width() const;
  
  /** Obtains the height of the Gtk::PrintContext, in pixels.
   * @return The height of @a context
   * 
   * @newin2p10.
   */
  double get_height() const;

  
  /** Obtains the horizontal resolution of the Gtk::PrintContext,
   * in dots per inch.
   * @return The horizontal resolution of @a context
   * 
   * @newin2p10.
   */
  double get_dpi_x() const;
  
  /** Obtains the vertical resolution of the Gtk::PrintContext,
   * in dots per inch.
   * @return The vertical resolution of @a context
   * 
   * @newin2p10.
   */
  double get_dpi_y() const;

  
  /** Return value: the font map of @a context
   * @return The font map of @a context
   * 
   * @newin2p10.
   */
  Glib::RefPtr<Pango::FontMap> get_pango_fontmap();
  
  /** Return value: the font map of @a context
   * @return The font map of @a context
   * 
   * @newin2p10.
   */
  Glib::RefPtr<const Pango::FontMap> get_pango_fontmap() const;

  
  /** Creates a new Pango::Context that can be used with the
   * Gtk::PrintContext.
   * @return A new Pango context for @a context
   * 
   * @newin2p10.
   */
  Glib::RefPtr<Pango::Context> create_pango_context();
  
  /** Creates a new Pango::Layout that is suitable for use
   * with the Gtk::PrintContext.
   * @return A new Pango layout for @a context
   * 
   * @newin2p10.
   */
  Glib::RefPtr<Pango::Layout> create_pango_layout();

  
  /** Sets a new cairo context on a print context. 
   * 
   * This function is intended to be used when implementing
   * an internal print preview, it is not needed for printing,
   * since GTK+ itself creates a suitable cairo context in that
   * case.
   * 
   * @newin2p10
   * @param cr The cairo context.
   * @param dpi_x The horizontal resolution to use with @a cr.
   * @param dpi_y The vertical resolution to use with @a cr.
   */
  void set_cairo_context(const Cairo::RefPtr<Cairo::Context>& cr, double dpi_x, double dpi_y);


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

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::PrintContext
   */
  Glib::RefPtr<Gtk::PrintContext> wrap(GtkPrintContext* object, bool take_copy = false);
}


#endif /* _GTKMM_PRINTCONTEXT_H */

