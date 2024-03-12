// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _ATKMM_SELECTION_H
#define _ATKMM_SELECTION_H


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


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _AtkSelectionIface AtkSelectionIface;
  typedef struct _AtkSelection      AtkSelection;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _AtkSelection AtkSelection;
typedef struct _AtkSelectionClass AtkSelectionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Atk
{ class Selection_Class; } // namespace Atk
namespace Atk
{

class Object;

/** The ATK interface implemented by container objects whose Atk::Object children can be selected.
 * This should be implemented by UI components with children which are exposed by Atk::Object::ref_child and
 * Atk::Object::get_n_children, if the use of the parent UI component ordinarily involves selection of one or
 * more of the objects corresponding to those AtkObject children - for example, selectable lists.
 *
 * Note that other types of "selection" (for instance text selection) are accomplished a other ATK interfaces -
 * Atk::Selection is limited to the selection/deselection of children. 
 */

class Selection : public Glib::Interface
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef Selection CppObjectType;
  typedef Selection_Class CppClassType;
  typedef AtkSelection BaseObjectType;
  typedef AtkSelectionIface BaseClassType;

private:
  friend class Selection_Class;
  static CppClassType selection_class_;

  // noncopyable
  Selection(const Selection&);
  Selection& operator=(const Selection&);

protected:
  Selection(); // you must derive from this class

  /** Called by constructors of derived classes. Provide the result of 
   * the Class init() function to ensure that it is properly 
   * initialized.
   * 
   * @param interface_class The Class object for the derived type.
   */
  explicit Selection(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface. 
  explicit Selection(AtkSelection* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~Selection();

  static void add_interface(GType gtype_implementer);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  AtkSelection*       gobj()       { return reinterpret_cast<AtkSelection*>(gobject_); }

  ///Provides access to the underlying C GObject.  
  const AtkSelection* gobj() const { return reinterpret_cast<AtkSelection*>(gobject_); }

private:


public:
  
  /** Adds the specified accessible child of the object to the
   * object's selection.
   * @param i A <tt>int</tt> specifying the child index.
   * @return <tt>true</tt> if success, <tt>false</tt> otherwise.
   */
  bool add_selection(int i);
  
  /** Clears the selection in the object so that no children in the object
   * are selected.
   * @return <tt>true</tt> if success, <tt>false</tt> otherwise.
   */
  bool clear_selection();
  
  /** Gets a reference to the accessible object representing the specified 
   * selected child of the object.
   * @note callers should not rely on <tt>0</tt> or on a zero value for
   * indication of whether AtkSelectionIface is implemented, they should
   * use type checking/interface checking macros or the
   * atk_get_accessible_value() convenience method.
   * @param i A <tt>int</tt> specifying the index in the selection set.  (e.g. the
   * ith selection as opposed to the ith child).
   * @return An Atk::Object representing the selected accessible , or <tt>0</tt>
   * if @a selection does not implement this interface.
   */
  Glib::RefPtr<Atk::Object> get_selection(int i);
  
  /** Gets the number of accessible children currently selected.
   * @note callers should not rely on <tt>0</tt> or on a zero value for
   * indication of whether AtkSelectionIface is implemented, they should
   * use type checking/interface checking macros or the
   * atk_get_accessible_value() convenience method.
   * @return A <tt>int</tt> representing the number of items selected, or 0
   * if @a selection does not implement this interface.
   */
  int get_selection_count() const;
  
  /** Determines if the current child of this object is selected
   * @note callers should not rely on <tt>0</tt> or on a zero value for
   * indication of whether AtkSelectionIface is implemented, they should
   * use type checking/interface checking macros or the
   * atk_get_accessible_value() convenience method.
   * @param i A <tt>int</tt> specifying the child index.
   * @return A <tt>bool</tt> representing the specified child is selected, or 0
   * if @a selection does not implement this interface.
   */
  bool is_child_selected(int i) const;
  
  /** Removes the specified child of the object from the object's selection.
   * @param i A <tt>int</tt> specifying the index in the selection set.  (e.g. the
   * ith selection as opposed to the ith child).
   * @return <tt>true</tt> if success, <tt>false</tt> otherwise.
   */
  bool remove_selection(int i);
  
  /** Causes every child of the object to be selected if the object
   * supports multiple selections.
   * @return <tt>true</tt> if success, <tt>false</tt> otherwise.
   */
  bool select_all_selection();

  
  /**
   * @par Prototype:
   * <tt>void on_my_%selection_changed()</tt>
   */

  Glib::SignalProxy0< void > signal_selection_changed();


protected:
  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual bool add_selection_vfunc(int i);
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual bool clear_selection_vfunc();
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual Glib::RefPtr<Atk::Object> get_selection_vfunc(int i);
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual int get_selection_count_vfunc() const;
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual bool is_child_selected_vfunc(int i) const;
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual bool remove_selection_vfunc(int i);
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual bool select_all_selection_vfunc();
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
  virtual void on_selection_changed();
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
   * @relates Atk::Selection
   */
  Glib::RefPtr<Atk::Selection> wrap(AtkSelection* object, bool take_copy = false);

} // namespace Glib


#endif /* _ATKMM_SELECTION_H */

