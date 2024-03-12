// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_FONTSELECTION_H
#define _GTKMM_FONTSELECTION_H


#include <glibmm.h>

/* $Id: fontselection.hg,v 1.2 2003/01/22 23:04:19 murrayc Exp $ */

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


#include <gtkmm/dialog.h>
#include <gtkmm/box.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkFontSelection GtkFontSelection;
typedef struct _GtkFontSelectionClass GtkFontSelectionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class FontSelection_Class; } // namespace Gtk
#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkFontSelectionDialog GtkFontSelectionDialog;
typedef struct _GtkFontSelectionDialogClass GtkFontSelectionDialogClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class FontSelectionDialog_Class; } // namespace Gtk
namespace Gtk
{

class Button;
class Entry;
class RadioButton;


/** A widget for selecting fonts.
 *
 * The Gtk::FontSelection widget lists the available fonts, styles and
 * sizes, allowing the user to select a font. It is used in the
 * Gtk::FontSelectionDialog widget to provide a dialog box for selecting
 * fonts. 
 * 
 * @ingroup Widgets
 */

class FontSelection : public VBox
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef FontSelection CppObjectType;
  typedef FontSelection_Class CppClassType;
  typedef GtkFontSelection BaseObjectType;
  typedef GtkFontSelectionClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~FontSelection();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class FontSelection_Class;
  static CppClassType fontselection_class_;

  // noncopyable
  FontSelection(const FontSelection&);
  FontSelection& operator=(const FontSelection&);

protected:
  explicit FontSelection(const Glib::ConstructParams& construct_params);
  explicit FontSelection(GtkFontSelection* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkFontSelection*       gobj()       { return reinterpret_cast<GtkFontSelection*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkFontSelection* gobj() const { return reinterpret_cast<GtkFontSelection*>(gobject_); }


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
  FontSelection();

  
  /** Gets the currently-selected font name.  Note that this can be a different
   * string than what you set with set_font_name(), as
   * the font selection widget may normalize font names and thus return a string
   * with a different structure.  For example, "Helvetica Italic Bold 12" could be
   * normalized to "Helvetica Bold Italic 12".  Use pango_font_description_equal()
   * if you want to compare two font descriptions.
   * @return A string with the name of the current font, or #<tt>0</tt> if no font
   * is selected.  You must free this string with Glib::free().
   */
  Glib::ustring get_font_name() const;
  
  /** Sets the currently-selected font.  Note that the @a fontsel needs to know the
   * screen in which it will appear for this to work; this can be guaranteed by
   * simply making sure that the @a fontsel is inserted in a toplevel window before
   * you call this function.
   * @param fontname A font name like "Helvetica 12" or "Times Bold 18".
   * @return #<tt>true</tt> if the font could be set successfully; #<tt>false</tt> if no such
   * font exists or if the @a fontsel doesn't belong to a particular screen yet.
   */
  bool set_font_name(const Glib::ustring& fontname);
  
  /** The text returned is the preview text used to show how the selected
   * font looks.
   * @return Pointer to the preview text string. This string
   * points to internally allocated storage in the widget and must not
   * be freed, modified or stored.
   */
  Glib::ustring get_preview_text() const;
  
  /** The @a text is used to show how the selected font looks.
   * @param text A pointer to a string.
   */
  void set_preview_text(const Glib::ustring& fontname);

  // Font page
   Entry* get_font_entry();
  const Entry* get_font_entry() const;
    Entry* get_font_style_entry();
  const Entry* get_font_style_entry() const;
    Entry* get_size_entry();
  const Entry* get_size_entry() const;
 
   RadioButton* get_pixels_button();
  const RadioButton* get_pixels_button() const;
    RadioButton* get_points_button();
  const RadioButton* get_points_button() const;
    Button* get_filter_button();
  const Button* get_filter_button() const;
 
   Entry* get_preview_entry();
  const Entry* get_preview_entry() const;
 
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The string that represents this font.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Glib::ustring> property_font_name() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The string that represents this font.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::ustring> property_font_name() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The text to display in order to demonstrate the selected font.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Glib::ustring> property_preview_text() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The text to display in order to demonstrate the selected font.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::ustring> property_preview_text() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


};

/** A dialog box for selecting fonts.
 *
 * The Gtk::FontSelectionDialog widget is a dialog box for selecting a font. 
 *
 * A FontSelectionDialog looks like this:
 * @image html fontselectiondialog1.png
 *
 * @ingroup Dialogs
 */

class FontSelectionDialog : public Dialog
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef FontSelectionDialog CppObjectType;
  typedef FontSelectionDialog_Class CppClassType;
  typedef GtkFontSelectionDialog BaseObjectType;
  typedef GtkFontSelectionDialogClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~FontSelectionDialog();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class FontSelectionDialog_Class;
  static CppClassType fontselectiondialog_class_;

  // noncopyable
  FontSelectionDialog(const FontSelectionDialog&);
  FontSelectionDialog& operator=(const FontSelectionDialog&);

protected:
  explicit FontSelectionDialog(const Glib::ConstructParams& construct_params);
  explicit FontSelectionDialog(GtkFontSelectionDialog* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkFontSelectionDialog*       gobj()       { return reinterpret_cast<GtkFontSelectionDialog*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkFontSelectionDialog* gobj() const { return reinterpret_cast<GtkFontSelectionDialog*>(gobject_); }


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

  FontSelectionDialog();
  explicit FontSelectionDialog(const Glib::ustring& title);

  
  /** Sets the currently selected font.
   * @param fontname A pointer to a string.
   * @return <tt>true</tt> if the font selected in @a fsd is now the
   *  @a fontname specified. <tt>false</tt> otherwise.
   */
  bool set_font_name(const Glib::ustring& fontname);
  
  /** Gets the currently-selected font name.  Note that this can be a different
   * string than what you set with set_font_name(), as
   * the font selection widget may normalize font names and thus return a string
   * with a different structure.  For example, "Helvetica Italic Bold 12" could be
   * normalized to "Helvetica Bold Italic 12".  Use pango_font_description_equal()
   * if you want to compare two font descriptions.
   * @return A string with the name of the current font, or #<tt>0</tt> if no font
   * is selected.  You must free this string with Glib::free().
   */
  Glib::ustring get_font_name() const;
  
  /** The text returned is the preview text used to show how the selected
   * font looks.
   * @return Pointer to the preview text string. This string
   * points to internally allocated storage in the widget and must not
   * be freed, modified or stored.
   */
  Glib::ustring get_preview_text() const;
  
  /** The @a text is used to show how the selected font looks.
   * @param text A pointer to a string.
   */
  void set_preview_text(const Glib::ustring& fontname);

   FontSelection* get_font_selection();
  const FontSelection* get_font_selection() const;
    Button* get_ok_button();
  const Button* get_ok_button() const;
    Button* get_apply_button();
  const Button* get_apply_button() const;
    Button* get_cancel_button();
  const Button* get_cancel_button() const;
 

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
   * @relates Gtk::FontSelection
   */
  Gtk::FontSelection* wrap(GtkFontSelection* object, bool take_copy = false);
} //namespace Glib


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::FontSelectionDialog
   */
  Gtk::FontSelectionDialog* wrap(GtkFontSelectionDialog* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_FONTSELECTION_H */

