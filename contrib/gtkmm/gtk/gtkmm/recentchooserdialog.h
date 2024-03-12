// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_RECENTCHOOSERDIALOG_H
#define _GTKMM_RECENTCHOOSERDIALOG_H


#include <glibmm.h>

/* recentchooserdialog.h
 *
 * Copyright (C) 2006 The gtkmm Development Team
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

#include <gtkmm/dialog.h>
#include <gtkmm/recentchooser.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkRecentChooserDialog GtkRecentChooserDialog;
typedef struct _GtkRecentChooserDialogClass GtkRecentChooserDialogClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class RecentChooserDialog_Class; } // namespace Gtk
namespace Gtk
{

/** RecentChooserDialog is a dialog box suitable for displaying the recently
 * used documents. This widget works by putting a RecentChooserWidget inside
 * a Dialog. It exposes the RecentChooser interface, so you can use
 * all the RecentChooser functions on the recent chooser dialog as well as
 * those for Dialog.
 *
 * Note that RecentChooserDialog does not have any methods of its own.
 * Instead, you should use the functions that work on a RecentChooser.
 *
 * A RecentChooserDialog looks like this:
 * @image html recentchooserdialog1.png
 *
 * @newin2p10
 *
 * @ingroup RecentFiles
 */

class RecentChooserDialog
  : public Dialog,
    public RecentChooser
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef RecentChooserDialog CppObjectType;
  typedef RecentChooserDialog_Class CppClassType;
  typedef GtkRecentChooserDialog BaseObjectType;
  typedef GtkRecentChooserDialogClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~RecentChooserDialog();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class RecentChooserDialog_Class;
  static CppClassType recentchooserdialog_class_;

  // noncopyable
  RecentChooserDialog(const RecentChooserDialog&);
  RecentChooserDialog& operator=(const RecentChooserDialog&);

protected:
  explicit RecentChooserDialog(const Glib::ConstructParams& construct_params);
  explicit RecentChooserDialog(GtkRecentChooserDialog* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkRecentChooserDialog*       gobj()       { return reinterpret_cast<GtkRecentChooserDialog*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkRecentChooserDialog* gobj() const { return reinterpret_cast<GtkRecentChooserDialog*>(gobject_); }


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
  
  explicit RecentChooserDialog(Gtk::Window& parent, const Glib::ustring& title);
  explicit RecentChooserDialog(const Glib::ustring& title);

  
  explicit RecentChooserDialog(Gtk::Window& parent, const Glib::ustring& title, const Glib::RefPtr<RecentManager>& recent_manager);
  explicit RecentChooserDialog(const Glib::ustring& title, const Glib::RefPtr<RecentManager>& recent_manager);


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
   * @relates Gtk::RecentChooserDialog
   */
  Gtk::RecentChooserDialog* wrap(GtkRecentChooserDialog* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_RECENTCHOOSERDIALOG_H */

