// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_TOOLBUTTON_H
#define _GTKMM_TOOLBUTTON_H


#include <glibmm.h>

/* $Id$ */

/* box.h
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

#include <gtkmm/toolitem.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkToolButton GtkToolButton;
typedef struct _GtkToolButtonClass GtkToolButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class ToolButton_Class; } // namespace Gtk
namespace Gtk
{

/** A Gtk::ToolItem subclass that displays buttons.
 * 
 * A ToolButton is are Gtk::ToolItem containing a button.
 * @ingroup Widgets
 */

class ToolButton : public ToolItem
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef ToolButton CppObjectType;
  typedef ToolButton_Class CppClassType;
  typedef GtkToolButton BaseObjectType;
  typedef GtkToolButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~ToolButton();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class ToolButton_Class;
  static CppClassType toolbutton_class_;

  // noncopyable
  ToolButton(const ToolButton&);
  ToolButton& operator=(const ToolButton&);

protected:
  explicit ToolButton(const Glib::ConstructParams& construct_params);
  explicit ToolButton(GtkToolButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkToolButton*       gobj()       { return reinterpret_cast<GtkToolButton*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkToolButton* gobj() const { return reinterpret_cast<GtkToolButton*>(gobject_); }


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
  virtual void on_clicked();
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


private:

public:

  /** Creates a new ToolButton.
   */
  ToolButton();
 
  /** Creates a new ToolButton from a StockID.
   *
   * The ToolButton will be created according to the @a stock_id properties.
   * 
   * @param stock_id The StockID which determines the look of the ToolButton.
   */
  explicit ToolButton(const Gtk::StockID& stock_id);

  /** Creates a new ToolButton with a label.
   *
   * The ToolButton will have the label @a label.
   *
   * @param label The string used to display the label for this ToolButton.
   */
  explicit ToolButton(const Glib::ustring& label);

  /** Creates a new ToolButton with an image.
   *
   * The ToolButton will have the label @a label and an image widget @a icon_widget.
   *
   * @param icon_widget The widget placed as the ToolButton's icon.
   * @param label The string used to display the label for this ToolButton.
   */
  explicit ToolButton(Widget& icon_widget, const Glib::ustring& label = Glib::ustring());

  
  /** Sets @a label as the label used for the tool button. The "label" property
   * only has an effect if not overridden by a non-<tt>0</tt> "label_widget" property.
   * If both the "label_widget" and "label" properties are <tt>0</tt>, the label
   * is determined by the "stock_id" property. If the "stock_id" property is also
   * <tt>0</tt>, @a button will not have a label.
   * 
   * @newin2p4
   * @param label A string that will be used as label, or <tt>0</tt>.
   */
  void set_label(const Glib::ustring& label);
  
  /** Return value: The label, or <tt>0</tt>
   * @return The label, or <tt>0</tt>
   * 
   * @newin2p4.
   */
  Glib::ustring get_label() const;
  
  /** If set, an underline in the label property indicates that the next character
   * should be used for the mnemonic accelerator key in the overflow menu. For
   * example, if the label property is "_Open" and @a use_underline is <tt>true</tt>,
   * the label on the tool button will be "Open" and the item on the overflow
   * menu will have an underlined 'O'.
   * 
   * Labels shown on tool buttons never have mnemonics on them; this property
   * only affects the menu item on the overflow menu.
   * 
   * @newin2p4
   * @param use_underline Whether the button label has the form "_Open".
   */
  void set_use_underline(bool use_underline = true);
  
  /** Return value: <tt>true</tt> if underscores in the label property are used as
   * @return <tt>true</tt> if underscores in the label property are used as
   * mnemonics on menu items on the overflow menu.
   * 
   * @newin2p4.
   */
  bool get_use_underline() const;
  
  /** Sets the name of the stock item. See the ToolButton::ToolButton(const Gtk::StockID& stock_id, IconSize size) constructor.
   *     The stock_id property only has an effect if not
   *     overridden by "label" and "icon_widget" properties.
   * 
   *     @a newin2p4
   * @param stock_id A name of a stock item, or <tt>0</tt>.
   */
  void set_stock_id(const Gtk::StockID& stock_id);
  
  /** Return value: the name of the stock item for @a button.
   * @return The name of the stock item for @a button.
   * 
   * @newin2p4.
   */
  Glib::ustring get_stock_id() const;
  
  /** Sets the icon for the tool button from a named themed icon.
   * See the docs for Gtk::IconTheme for more details.
   * The "icon_name" property only has an effect if not
   * overridden by non-<tt>0</tt> "label", "icon_widget" and "stock_id"
   * properties.
   * 
   * @newin2p8
   * @param icon_name The name of the themed icon.
   */
  void set_icon_name(const Glib::ustring& icon_name);
  
  /** Returns: the icon name or <tt>0</tt> if the tool button has
   * @return The icon name or <tt>0</tt> if the tool button has
   * no themed icon
   * 
   * @newin2p8.
   */
  Glib::ustring get_icon_name() const;
  
  /** Sets @a icon as the widget used as icon on @a button. If @a icon_widget is
   * <tt>0</tt> the icon is determined by the "stock_id" property. If the
   * "stock_id" property is also <tt>0</tt>, @a button will not have an icon.
   * 
   * @newin2p4
   * @param icon_widget The widget used as icon, or <tt>0</tt>.
   */
  void set_icon_widget(Widget& icon_widget);
  
  /** Return the widget used as icon widget on @a button. See
   * set_icon_widget().
   * @return The widget used as icon on @a button, or <tt>0</tt>.
   * 
   * @newin2p4.
   */
  Widget* get_icon_widget();
  
  /** Return the widget used as icon widget on @a button. See
   * set_icon_widget().
   * @return The widget used as icon on @a button, or <tt>0</tt>.
   * 
   * @newin2p4.
   */
  const Widget* get_icon_widget() const;
  
  /** Sets @a label_widget as the widget that will be used as the label
   * for @a button. If @a label_widget is <tt>0</tt> the "label" property is used
   * as label. If "label" is also <tt>0</tt>, the label in the stock item
   * determined by the "stock_id" property is used as label. If
   * "stock_id" is also <tt>0</tt>, @a button does not have a label.
   * 
   * @newin2p4
   * @param label_widget The widget used as label, or <tt>0</tt>.
   */
  void set_label_widget(Widget& label_widget);
  
  /** Return value: The widget used as label on @a button, or <tt>0</tt>.
   * @return The widget used as label on @a button, or <tt>0</tt>.
   * 
   * @newin2p4.
   */
  Widget* get_label_widget();
  
  /** Return value: The widget used as label on @a button, or <tt>0</tt>.
   * @return The widget used as label on @a button, or <tt>0</tt>.
   * 
   * @newin2p4.
   */
  const Widget* get_label_widget() const;

 /** This signal is emitted when the tool button is clicked with the mouse
  * or activated with the keyboard.
  * @deprecated This is an "action" key-binding signal that you should rarely need to use.
  *
   * @par Prototype:
   * <tt>void on_my_%clicked()</tt>
   */

  Glib::SignalProxy0< void > signal_clicked();


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Text to show in the item.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Glib::ustring> property_label() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Text to show in the item.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::ustring> property_label() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** If set
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_use_underline() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** If set
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_use_underline() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Widget to use as the item label.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Gtk::Widget*> property_label_widget() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Widget to use as the item label.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Gtk::Widget*> property_label_widget() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The stock icon displayed on the item.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Glib::ustring> property_stock_id() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The stock icon displayed on the item.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::ustring> property_stock_id() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Icon widget to display in the item.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Gtk::Widget> property_icon_widget() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Icon widget to display in the item.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Gtk::Widget> property_icon_widget() const;
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
   * @relates Gtk::ToolButton
   */
  Gtk::ToolButton* wrap(GtkToolButton* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_TOOLBUTTON_H */

