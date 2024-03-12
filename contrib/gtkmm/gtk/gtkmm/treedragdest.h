// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_TREEDRAGDEST_H
#define _GTKMM_TREEDRAGDEST_H


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

#include <glibmm/interface.h>
#include <gtkmm/treemodel.h>
#include <gtkmm/selectiondata.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkTreeDragDestIface GtkTreeDragDestIface;
typedef struct _GtkSelectionData GtkSelectionData;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkTreeDragDest GtkTreeDragDest;
typedef struct _GtkTreeDragDestClass GtkTreeDragDestClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class TreeDragDest_Class; } // namespace Gtk
namespace Gtk
{

/**
 * @ingroup TreeView
 */

class TreeDragDest : public Glib::Interface
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef TreeDragDest CppObjectType;
  typedef TreeDragDest_Class CppClassType;
  typedef GtkTreeDragDest BaseObjectType;
  typedef GtkTreeDragDestIface BaseClassType;

private:
  friend class TreeDragDest_Class;
  static CppClassType treedragdest_class_;

  // noncopyable
  TreeDragDest(const TreeDragDest&);
  TreeDragDest& operator=(const TreeDragDest&);

protected:
  TreeDragDest(); // you must derive from this class

  /** Called by constructors of derived classes. Provide the result of 
   * the Class init() function to ensure that it is properly 
   * initialized.
   * 
   * @param interface_class The Class object for the derived type.
   */
  explicit TreeDragDest(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface. 
  explicit TreeDragDest(GtkTreeDragDest* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~TreeDragDest();

  static void add_interface(GType gtype_implementer);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkTreeDragDest*       gobj()       { return reinterpret_cast<GtkTreeDragDest*>(gobject_); }

  ///Provides access to the underlying C GObject.  
  const GtkTreeDragDest* gobj() const { return reinterpret_cast<GtkTreeDragDest*>(gobject_); }

private:


public:

  
  /** Asks the Gtk::TreeDragDest to insert a row before the path @a dest,
   * deriving the contents of the row from @a selection_data. If @a dest is
   * outside the tree so that inserting before it is impossible, <tt>false</tt>
   * will be returned. Also, <tt>false</tt> may be returned if the new row is
   * not created for some model-specific reason.  Should robustly handle
   * a @a dest no longer found in the model!
   * @param dest Row to drop in front of.
   * @param selection_data Data to drop.
   * @return Whether a new row was created before position @a dest.
   */
  bool drag_data_received(const TreeModel::Path& dest, const SelectionData& selection_data);              

  
  /** Determines whether a drop is possible before the given @a dest_path,
   * at the same depth as @a dest_path. i.e., can we drop the data in
   *  @a selection_data at that location. @a dest_path does not have to
   * exist; the return value will almost certainly be <tt>false</tt> if the
   * parent of @a dest_path doesn't exist, though.
   * @param dest_path Destination row.
   * @param selection_data The data being dragged.
   * @return <tt>true</tt> if a drop is possible before @a dest_path.
   */
  bool row_drop_possible(const TreeModel::Path& dest_path, const SelectionData& selection_data) const;
                             
protected:
  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual bool drag_data_received_vfunc(const TreeModel::Path& dest, const SelectionData& selection_data);
#endif //GLIBMM_VFUNCS_ENABLED


  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual bool row_drop_possible_vfunc(const TreeModel::Path& dest, const SelectionData& selection_data) const;
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

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::TreeDragDest
   */
  Glib::RefPtr<Gtk::TreeDragDest> wrap(GtkTreeDragDest* object, bool take_copy = false);

} // namespace Glib


#endif /* _GTKMM_TREEDRAGDEST_H */

