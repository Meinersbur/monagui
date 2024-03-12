// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKSOURCEVIEWMM_SOURCECOMPLETIONINFO_H
#define _GTKSOURCEVIEWMM_SOURCECOMPLETIONINFO_H


#include <glibmm.h>

/* sourcecompletioninfo.h
 *
 * Copyright (C) 2009, 2010 Krzesimir Nowak
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
#include <gtkmm/textview.h>
#include <gtkmm/window.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkSourceCompletionInfo GtkSourceCompletionInfo;
typedef struct _GtkSourceCompletionInfoClass GtkSourceCompletionInfoClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gsv
{ class SourceCompletionInfo_Class; } // namespace Gsv
namespace Gsv
{

/** Calltips object
 *
 * This object can be used to show a calltip or help for the current completion
 * proposal.
 *
 * @newin{2,10}
 */

class SourceCompletionInfo : public Gtk::Window
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef SourceCompletionInfo CppObjectType;
  typedef SourceCompletionInfo_Class CppClassType;
  typedef GtkSourceCompletionInfo BaseObjectType;
  typedef GtkSourceCompletionInfoClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~SourceCompletionInfo();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class SourceCompletionInfo_Class;
  static CppClassType sourcecompletioninfo_class_;

  // noncopyable
  SourceCompletionInfo(const SourceCompletionInfo&);
  SourceCompletionInfo& operator=(const SourceCompletionInfo&);

protected:
  explicit SourceCompletionInfo(const Glib::ConstructParams& construct_params);
  explicit SourceCompletionInfo(GtkSourceCompletionInfo* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkSourceCompletionInfo*       gobj()       { return reinterpret_cast<GtkSourceCompletionInfo*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkSourceCompletionInfo* gobj() const { return reinterpret_cast<GtkSourceCompletionInfo*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  virtual void on_before_show();


private:


public:
  /** Creates new SourceCompletionInfo popup window.
   *
   * @return The new SourceCompletionInfo.
   *
   * @newin{2,10}
   */
  SourceCompletionInfo();

 
  /** Moves the SourceCompletionInfo to @a iter. Moving will respect the
   * Gdk::Gravity setting of the info window and will ensure the line at @a iter
   * is not occluded by the window.
   *
   * @param view A Gtk::TextView on which the info window should be positioned.
   * @param iter A Gtk::TextIter.
   *
   * @newin{2,10}
   */
  void move_to_iter(const Gtk::TextView& view, const Gtk::TextIter& iter);

  /** Moves the Gtk::SourceCompletionInfo to the cursor position. Moving will
   * respect the Gdk::Gravity setting of the info window and will ensure the
   * line at cursor position is not occluded by the window.
   *
   * @param view A Gtk::TextView on which the info window should be positioned.
   *
   * @newin{2,10}
   */
  void move_to_iter(const Gtk::TextView& view);

  
  /** Sets the content widget of the info window.
   *
   * If @a widget does not fit within the size requirements of the window,
   * a Gtk::ScrolledWindow will automatically be created and added to
   * the window.
   *
   * @param widget A Gtk::Widget.
   *
   * @newin{2,10}
   */
  void set_widget(Gtk::Widget& widget);

  
  /** Get the current content widget.
   *
   * @return The current content widget.
   *
   * @newin{2,10}
   */
  Gtk::Widget* get_widget();

  
  /** Get the current content widget.
   *
   * @return The current content widget.
   *
   * @newin{2,10}
   */
  const Gtk::Widget* get_widget() const;

  /** Emited before any "show" management.
   *
   * You can connect to this signal if you want to change some properties or
   * position before the real "show".
   *
   * @newin{2,10}
   *
   * @par Prototype:
   * <tt>void on_my_%before_show()</tt>
   */

  Glib::SignalProxy0< void > signal_before_show();


};

} /* namespace Gsv */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gsv::SourceCompletionInfo
   */
  Gsv::SourceCompletionInfo* wrap(GtkSourceCompletionInfo* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKSOURCEVIEWMM_SOURCECOMPLETIONINFO_H */
