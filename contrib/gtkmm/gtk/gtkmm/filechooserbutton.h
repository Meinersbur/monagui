// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_FILECHOOSERBUTTON_H
#define _GTKMM_FILECHOOSERBUTTON_H


#include <glibmm.h>

/* $Id: filechooserbutton.hg,v 1.7 2005/12/12 08:14:21 murrayc Exp $ */

/* filechooserbutton.h
 * 
 * Copyright (C) 2003 The gtkmm Development Team
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

#include <gtkmm/box.h>
#include <gtkmm/filechooserdialog.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkFileChooserButton GtkFileChooserButton;
typedef struct _GtkFileChooserButtonClass GtkFileChooserButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class FileChooserButton_Class; } // namespace Gtk
namespace Gtk
{

/** A button to launch a file chooser dialog.
 * 
 * This widget lets the user select a file. It implements the FileChooser interface. Visually, it is a file name with a 
 * button to bring up a FileChooserDialog. The user can then use that dialog to change the file associated with that 
 * button. This widget does not support setting the "select_multiple" property to true.
 *
 * The FileChooserButton supports the FileChooserActions FILE_CHOOSER_ACTION_OPEN and FILE_CHOOSER_ACTION_SELECT_FOLDER.
 *
 * The FileChooserButton will ellipsize the label, and will thus request little horizontal space. To give the button more 
 * space, you should call size_request(), set_width_chars(), or pack the button in such a way that other interface 
 * elements give space to the widget.
 *
 * The FileChooserButton widget looks like this:
 * @image html filechooserbutton1.png
 *
 * @ingroup Widgets
 */

class FileChooserButton
  : public HBox,
    public FileChooser
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef FileChooserButton CppObjectType;
  typedef FileChooserButton_Class CppClassType;
  typedef GtkFileChooserButton BaseObjectType;
  typedef GtkFileChooserButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~FileChooserButton();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class FileChooserButton_Class;
  static CppClassType filechooserbutton_class_;

  // noncopyable
  FileChooserButton(const FileChooserButton&);
  FileChooserButton& operator=(const FileChooserButton&);

protected:
  explicit FileChooserButton(const Glib::ConstructParams& construct_params);
  explicit FileChooserButton(GtkFileChooserButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkFileChooserButton*       gobj()       { return reinterpret_cast<GtkFileChooserButton*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkFileChooserButton* gobj() const { return reinterpret_cast<GtkFileChooserButton*>(gobject_); }


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

  /** Creates a new file-selecting button widget with the default title.
   * @param title The title of the browse dialog.
   * @param action The open mode for the widget.
   * @param backend The name of the Gtk::FileSystem backend to use.
   */
  explicit FileChooserButton(FileChooserAction action = FILE_CHOOSER_ACTION_OPEN);
  
  /** Creates a new file-selecting button widget.
   *
   * @param title The title of the browse dialog.
   * @param action The open mode for the widget.
   */
  explicit FileChooserButton(const Glib::ustring& title, FileChooserAction action = FILE_CHOOSER_ACTION_OPEN);
  
  /** Creates a new file-selecting button widget using backend.
   *
   * @param title The title of the browse dialog.
   * @param action The open mode for the widget.
   * @param backend The name of the Gtk::FileSystem backend to use.
   */ 
  explicit FileChooserButton(const Glib::ustring& title, FileChooserAction action, const Glib::ustring& backend);
  
  /** Creates a new file-selecting button widget which uses dialog as its file-picking window.
   *
   * @param dialog The dialog to use.
   */
  explicit FileChooserButton(FileChooserDialog& dialog);
  
  
  /** Retrieves the title of the browse dialog used by @a button. The returned value
   * should not be modified or freed.
   * @return A pointer to the browse dialog's title.
   * 
   * @newin2p6.
   */
  Glib::ustring get_title() const;
  
  /** Modifies the @a title of the browse dialog used by @a button.
   * 
   * @newin2p6
   * @param title The new browse dialog title.
   */
  void set_title(const Glib::ustring& title);
 
  
  /** Retrieves the width in characters of the @a button widget's entry and/or label.
   * @return An integer width (in characters) that the button will use to size itself.
   * 
   * @newin2p6.
   */
  int get_width_chars() const;
  
  /** Sets the width (in characters) that @a button will use to @a n_chars.
   * 
   * @newin2p6
   * @param n_chars The new width, in characters.
   */
  void set_width_chars(int n_chars);

  
  /** Return value: <tt>true</tt> if the button grabs focus when it is clicked with
   * @return <tt>true</tt> if the button grabs focus when it is clicked with
   * the mouse.
   * 
   * @newin2p10.
   */
  bool get_focus_on_click() const;
  
  /** Sets whether the button will grab focus when it is clicked with the mouse.
   * Making mouse clicks not grab focus is useful in places like toolbars where
   * you don't want the keyboard focus removed from the main area of the
   * application.
   * 
   * @newin2p10
   * @param focus_on_click Whether the button grabs focus when clicked with the mouse.
   */
  void set_focus_on_click(gboolean focus_on_click = true);   

  //I'm no totally convinced that this is only a key-binding signal. murrayc:
  

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether the button grabs focus when it is clicked with the mouse.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_focus_on_click() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether the button grabs focus when it is clicked with the mouse.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_focus_on_click() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The title of the file chooser dialog.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Glib::ustring> property_title() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The title of the file chooser dialog.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::ustring> property_title() const;
#endif //#GLIBMM_PROPERTIES_ENABLED
                                          
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The desired width of the button widget
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<int> property_width_chars() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The desired width of the button widget
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<int> property_width_chars() const;
#endif //#GLIBMM_PROPERTIES_ENABLED
    

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
   * @relates Gtk::FileChooserButton
   */
  Gtk::FileChooserButton* wrap(GtkFileChooserButton* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_FILECHOOSERBUTTON_H */

