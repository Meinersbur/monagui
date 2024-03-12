// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_EDITABLE_H
#define _GTKMM_EDITABLE_H


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
#include <gtk/gtkeditable.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkEditable GtkEditable;
typedef struct _GtkEditableClass GtkEditableClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class Editable_Class; } // namespace Gtk
namespace Gtk
{

/** Base class for text-editing widgets.
 *
 * The Gtk::Editable class is a base class for widgets for editing text,
 * such as Gtk::Entry. It cannot be instantiated by itself. The editable
 * class contains functions for generically manipulating an editable widget,
 * a large number of action signals used for key bindings, and several
 * signals that an application can connect to to modify the behavior of a
 * widget.
 *
 */

class Editable : public Glib::Interface
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef Editable CppObjectType;
  typedef Editable_Class CppClassType;
  typedef GtkEditable BaseObjectType;
  typedef GtkEditableClass BaseClassType;

private:
  friend class Editable_Class;
  static CppClassType editable_class_;

  // noncopyable
  Editable(const Editable&);
  Editable& operator=(const Editable&);

protected:
  Editable(); // you must derive from this class

  /** Called by constructors of derived classes. Provide the result of 
   * the Class init() function to ensure that it is properly 
   * initialized.
   * 
   * @param interface_class The Class object for the derived type.
   */
  explicit Editable(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface. 
  explicit Editable(GtkEditable* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~Editable();

  static void add_interface(GType gtype_implementer);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkEditable*       gobj()       { return reinterpret_cast<GtkEditable*>(gobject_); }

  ///Provides access to the underlying C GObject.  
  const GtkEditable* gobj() const { return reinterpret_cast<GtkEditable*>(gobject_); }

private:


public:
  
  /** Removes the contents of the currently selected content in the editable and
   * puts it on the clipboard.
   */
  void cut_clipboard();
  
  /** Copies the contents of the currently selected content in the editable and
   * puts it on the clipboard.
   */
  void copy_clipboard();
  
  /** Pastes the content of the clipboard to the current position of the
   * cursor in the editable.
   */
  void paste_clipboard();
  
  /** Deletes the currently selected text of the editable.
   * This call will not do anything if there is no selected text.
   */
  void delete_selection();
  
  /** Determines if the user can edit the text in the editable
   * widget or not.
   * @param is_editable <tt>true</tt> if the user is allowed to edit the text
   * in the widget.
   */
  void set_editable(bool is_editable = true);
  
  /** Retrieves whether @a editable is editable. See
   * set_editable().
   * @return <tt>true</tt> if @a editable is editable.
   */
  bool get_editable() const;

  
  /** Appends @a new_text_length characters of @a new_text to the contents of the widget,
   * at position @a position. Note that this position is in characters, not in bytes.
   * @param new_text The text to append.
   * @param new_text_length The text to append.
   * @param position Position text will be inserted at.
   */
  void insert_text(const Glib::ustring& text, int length, int& position);
  
  /** Deletes the content of the editable between @a start_pos and @a end_pos.
   * Note that positions are specified in characters, not bytes.
   * @param start_pos Start position.
   * @param end_pos End position.
   */
  void delete_text(int start_pos, int end_pos);

  
  /** Retreives the content of the editable between @a start and @a end.
   * Note that positions are specified in characters, not bytes.
   * @param start Start of text.
   * @param end End of text.
   * @return A pointer to the contents of the widget as a
   * string. This string is allocated by the Gtk::Editable
   * implementation and should be freed by the caller.
   */
  Glib::ustring get_chars(int start_pos, int end_pos) const;

  
  /** Selects the text between @a start and @a end. Both @a start and @a end are
   * relative to the start of the content. Note that positions are specified
   * in characters, not bytes.
   * @param start Start of region.
   * @param end End of region.
   */
  void select_region(int start_pos, int end_pos);
  
  /** Retrieves the selection bound of the editable. @a start_pos will be filled
   * with the start of the selection and @a end_pos with end. If no text was selected
   * both will be identical and <tt>false</tt> will be returned. Note that positions are
   * specified in characters, not bytes.
   * @param start_pos Beginning of selection.
   * @param end_pos End of selection.
   * @return <tt>true</tt> if an area is selected, <tt>false</tt> otherwise.
   */
  bool get_selection_bounds(int& start_pos, int& end_pos) const;

  
  /** Sets the cursor position in the editable to the given value.
   * @param position The position of the cursor. The cursor is displayed
   * before the character with the given (base 0) index in the editable. 
   * The value must be less than or equal to the number of characters 
   * in the editable. A value of -1 indicates that the position should
   * be set after the last character of the editable. Note that this 
   * position is in characters, not in bytes.
   */
  void set_position(int position);
  
  /** Retrieves the current position of the cursor relative to the start
   * of the content of the editable. Note that this position is in characters,
   * not in bytes.
   * @return The cursor position.
   */
  int get_position() const;

  
  Glib::SignalProxy2< void,const Glib::ustring&,int* > signal_insert_text();

    
  /**
   * @par Prototype:
   * <tt>void on_my_%delete_text(int start_pos, int end_pos)</tt>
   */

  Glib::SignalProxy2< void,int,int > signal_delete_text();

  
  /**
   * @par Prototype:
   * <tt>void on_my_%changed()</tt>
   */

  Glib::SignalProxy0< void > signal_changed();


protected:


  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void delete_text_vfunc(int start_pos, int end_pos);
#endif //GLIBMM_VFUNCS_ENABLED


  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual Glib::ustring get_chars_vfunc(int start_pos, int end_pos) const;
#endif //GLIBMM_VFUNCS_ENABLED


  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void select_region_vfunc(int start_pos, int end_pos);
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual bool get_selection_bounds_vfunc(int& start_pos, int& end_pos) const;
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void set_position_vfunc(int position);
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual int get_position_vfunc() const;
#endif //GLIBMM_VFUNCS_ENABLED


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

protected:
  //GTK+ Virtual Functions (override these to change behaviour):
#ifdef GLIBMM_VFUNCS_ENABLED
virtual void insert_text_vfunc(const Glib::ustring& text, int& position);

#endif //GLIBMM_VFUNCS_ENABLED

  //Default Signal Handlers::
#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  virtual void on_insert_text(const Glib::ustring& text, int* position);
  virtual void on_delete_text(int start_pos, int end_pos);
  virtual void on_changed();
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
   * @relates Gtk::Editable
   */
  Glib::RefPtr<Gtk::Editable> wrap(GtkEditable* object, bool take_copy = false);

} // namespace Glib


#endif /* _GTKMM_EDITABLE_H */

