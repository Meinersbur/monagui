// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKSOURCEVIEWMM_SOURCEVIEW_H
#define _GTKSOURCEVIEWMM_SOURCEVIEW_H


#include <glibmm.h>

/* sourceview.hg
 * 
 * Copyright (C) 2004-2005 Jae Jang
 * Copyright (C) 2005-2006 Rob Page
 * Copyright (C) 2005-2006 Dodji Seketeli
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

/// \file
/// \brief SourceView class

#include <gtkmm/textview.h>
#include <gtksourceviewmm/sourcebuffer.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkSourceView GtkSourceView;
typedef struct _GtkSourceViewClass GtkSourceViewClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace gtksourceview
{ class SourceView_Class; } // namespace gtksourceview
namespace gtksourceview
{

/** @addtogroup gtksourceviewmmEnums Enums and Flags */

/**
 * @ingroup gtksourceviewmmEnums
 */
enum SourceSmartHomeEndType
{
  SOURCE_SMART_HOME_END_DISABLED,
  SOURCE_SMART_HOME_END_BEFORE,
  SOURCE_SMART_HOME_END_AFTER,
  SOURCE_SMART_HOME_END_ALWAYS
};

} // namespace gtksourceview


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<gtksourceview::SourceSmartHomeEndType> : public Glib::Value_Enum<gtksourceview::SourceSmartHomeEndType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace gtksourceview
{


/// \brief Multi-line source editing widget.
///
/// It displays a Gtk::SourceBuffer.

class SourceView : public Gtk::TextView
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef SourceView CppObjectType;
  typedef SourceView_Class CppClassType;
  typedef GtkSourceView BaseObjectType;
  typedef GtkSourceViewClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~SourceView();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class SourceView_Class;
  static CppClassType sourceview_class_;

  // noncopyable
  SourceView(const SourceView&);
  SourceView& operator=(const SourceView&);

protected:
  explicit SourceView(const Glib::ConstructParams& construct_params);
  explicit SourceView(GtkSourceView* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  GtkSourceView*       gobj()       { return reinterpret_cast<GtkSourceView*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const GtkSourceView* gobj() const { return reinterpret_cast<GtkSourceView*>(gobject_); }


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
  virtual void on_redo();
  virtual void on_undo();
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


private:


public:
  //_CTOR_DEFAULT(gtk_source_view_new_val) ;
  //_WRAP_CTOR (SourceView (const Glib::RefPtr<SourceBuffer> &buffer), gtk_source_view_new_with_buffer)

  /// \brief default constructor
  explicit SourceView () ;

  /// \brief constructor.
  ///
  /// create an instance of SourceView displaying a given buffer
  /// \param buffer the buffer to display in the SourceView
  explicit SourceView (const Glib::RefPtr<SourceBuffer> &buffer) ;


  static Glib::RefPtr<SourceView> create();

  
  static Glib::RefPtr<SourceView> create(const Glib::RefPtr<SourceBuffer> & buffer);


  /// \brief get the source buffer associated to the current instance
  ///
  /// \return the source buffer associated to the current instance
  Glib::RefPtr<const SourceBuffer> get_source_buffer () const ;

  /// \brief get the source buffer associated to the current instance
  ///
  /// \return the source buffer associated to the current instance
  Glib::RefPtr<SourceBuffer> get_source_buffer () ;

  /// \brief set the source buffer to be displayed by the SourceView
  ///
  /// \param source_buffer the source buffer to set
  void set_source_buffer (const Glib::RefPtr<SourceBuffer> &source_buffer) ;

  /// \brief display line numbers beside the text, or not
  ///
  /// \param show if true, line numbers will be displayed beside test text.
  
  /** If <tt>true</tt> line numbers will be displayed beside the text.
   * @param show Whether line numbers should be displayed.
   */
  void set_show_line_numbers(bool show=true);

  /// \brief test whether line numbers are displayed beside the text
  ///
  /// \return true if line numbers are displayed beside the text, false otherwise
  
  /** Return value: <tt>true</tt> if the line numbers are displayed.
   * @return <tt>true</tt> if the line numbers are displayed.
   */
  bool get_show_line_numbers() const;

  /// \brief set tabs width
  ///
  /// \param width the new tab width
  
  /** Sets the width of tabulation in characters.
   * @param width Width of tab in characters.
   */
  void set_tab_width(guint width);

  /// \brief get tab width
  ///
  /// \return the tab width
  
  /** Return value: width of tab.
   * @return Width of tab.
   */
  guint get_tab_width() const;

  /// \brief set automatic text indention or not
  ///
  /// \param enable if true, automatic text indentation is activated
  
  /** If <tt>true</tt> auto indentation of text is enabled.
   * @param enable Whether to enable auto indentation.
   */
  void set_auto_indent(bool enable=true);

  /// \brief test whether automatic text indentation is activated
  ///
  /// \return true if automatic text indentation is activated, false otherwise
  
  /** Return value: <tt>true</tt> if auto indentation is enabled.
   * @return <tt>true</tt> if auto indentation is enabled.
   */
  bool get_auto_indent() const;

  /// \brief activate (or de-activate) the replacement of any inserted tabulator character by a group of space character
  ///
  /// \param enable if true, any tabulator character inserted is replaced by a group of space character
  
  /** If <tt>true</tt> any tabulator character inserted is replaced by a group
   * of space characters.
   * @param enable Whether to insert spaces instead of tabs.
   */
  void set_insert_spaces_instead_of_tabs(bool enable=true);

  /// \brief test whether the replacement of any inserted tabulator character by a group of space character is activated
  ///
  /// \return true if the replacement of any inserted tabulator character by a group of space character is activated, false otherwise
  
  /** Return value: <tt>true</tt> if spaces are inserted instead of tabs.
   * @return <tt>true</tt> if spaces are inserted instead of tabs.
   */
  bool get_insert_spaces_instead_of_tabs() const;

  /// \brief activate (or de-activate) the display of a margin
  ///
  /// \param show if true, activate the display of a margin
  
  /** If <tt>true</tt> a right margin is displayed
   * @param show Whether to show a right margin.
   */
  void set_show_right_margin(bool show = true);

  /// \brief test if a margin is displayed
  ///
  /// \return true if a margin is displayed, false otherwise
  
  /** Return value: <tt>true</tt> if the right margin is shown.
   * @return <tt>true</tt> if the right margin is shown.
   */
  bool get_show_right_margin() const;

  /// \brief do highlight the currently selected line, or not
  ///
  /// \param highlight if true, do highlight the currently selected line
  
  /** If @a show is <tt>true</tt> the current line is highlighted.
   * @param show Whether to highlight the current line.
   */
  void set_highlight_current_line(bool highlight=true);

  /// \brief test if the currently selected line is to be hightlighted
  ///
  /// \return true if the currently selected line is to be highlighted, false otherwise
  
  /** Return value: <tt>true</tt> if the current line is highlighted.
   * @return <tt>true</tt> if the current line is highlighted.
   */
  bool get_highlight_current_line() const;
  
  /// \brief  set the position of the right margin
  ///
  /// \param margin the position (in pixels) of the right margin
  
  /** Sets the position of the right margin in the given @a view.
   * @param pos The width in characters where to position the right margin.
   * @param pos The width in characters where to position the right margin.
   */
  void set_right_margin_position(guint margin);

  /// \brief get the position of the right margin
  ///
  /// \return the position of the right margin
  
  /** Gets the position of the right margin in the given @a view.
   * @return The position of the right margin.
   */
  guint get_right_margin_position() const;

  /// \brief activate whether if HOME and END keys will move to the first/last non space character of the line before moving to the start/end
  ///
  /// if true, HOME and END keys will move to the first/last non space character of the line before moving to the start/end
  
  /** Set the desired movement of the cursor when HOME and END keys
   * are pressed.
   * @param smart_he The desired behavior among Gtk::SourceSmartHomeEndType.
   */
  void set_smart_home_end(SourceSmartHomeEndType smart_he);

  /// \brief test whether if HOME and END keys will move to the first/last non space character of the line before moving to the start/end
  ///
  /// \return true if HOME and END keys will move to the first/last non space character of the line before moving to the start/end, false otherwise
  
  /** Return value: a Gtk::SourceSmartHomeEndType
   * @return A Gtk::SourceSmartHomeEndType.
   */
  SourceSmartHomeEndType get_smart_home_end() const;

  /// \brief if true line marks will be displayed beside the text.
  ///
  /// \param show whether line marks should be displayed.
  
  /** If <tt>true</tt> line marks will be displayed beside the text.
   * 
   * @newin2p2
   * @param show Whether line marks should be displayed.
   */
  void set_show_line_marks(bool show = true);

  /// \brief Returns whether line marks are displayed beside the text.
  ///
  /// \return true if the line marks are displayed.
  
  /** Return value: <tt>true</tt> if the line marks are displayed.
   * @return <tt>true</tt> if the line marks are displayed.
   * 
   * @newin2p2.
   */
  bool get_show_line_marks() const;

  /// If true, when the tab key is pressed and there is a
  /// selection, the selected text is indented of one level instead of being
  /// replaced with the \t characters. Shift+Tab unindents the selection.
  /// \param show true if the selection is indented when tab is pressed.
  
  /** If <tt>true</tt>, when the tab key is pressed and there is a selection, the
   * selected text is indented of one level instead of being replaced with
   * the \t characters. Shift+Tab unindents the selection.
   * 
   * Since: 1.8
   * @param enable Whether to indent a block when tab is pressed.
   */
  void set_indent_on_tab(bool show = true);

  /// Returns whether when the tab key is pressed the current selection
  /// should get indented instead of replaced with the \t character.
  ///
  /// \return true if the selection is indented when tab is pressed.
  
  /** Return value: <tt>true</tt> if the selection is indented when tab is pressed.
   * @return <tt>true</tt> if the selection is indented when tab is pressed.
   * 
   * Since: 1.8.
   */
  bool get_indent_on_tab() const;

  /// \brief Sets the number of spaces to use for each step of indent.
  ///
  /// If width is
  /// -1, the value of the GtkSourceView::tab-width property will be used.
  ///
  /// \param width indent width in characters
  
  /** Sets the number of spaces to use for each step of indent.
   * If @a width is -1, the value of the GtkSourceView::tab-width property
   * will be used.
   * @param width Indent width in characters.
   */
  void set_indent_width(gint width);

  /// \brief Set Returns the number of spaces to use for each step of indent.
  ///
  /// See SourceView::set_indent_width(gint) for details.
  ///
  /// \return indent width.
  
  /** Return value: indent width.
   * @return Indent width.
   */
  gint get_indent_width() const;

  /// \brief Set the priority for the given mark category.
  ///
  /// When there are multiple
  /// marks on the same line, marks of categories with higher priorities will
  /// be drawn on top.
  /// \param category a mark category.
  /// \param priority the priority of #category
  
  /** Set the @a priority for the given mark @a category. When there are
   * multiple marks on the same line, marks of categories with
   * higher priorities will be drawn on top.
   * 
   * @newin2p2
   * @param category A mark category.
   * @param priority The priority for the category.
   */
  void set_mark_category_priority(const Glib::ustring& category, gint priority);

  /// \brief Gets the priority which is associated with the given category.
  ///
  /// \param category a mark category.
  /// \return the priority or if category exists but no priority was set,
  /// it defaults to 0.
  
  /** Gets the priority which is associated with the given @a category.
   * @param category A mark category.
   * @return The priority or if @a category
   * exists but no priority was set, it defaults to 0.
   * 
   * @newin2p2.
   */
  gint get_mark_category_priority(const Glib::ustring& category) const;

  /// \brief Associates a given pixbuf with a given mark category.
  /// If pixbuf is NULL, the pixbuf is unset.
  ///
  /// \param category a mark category.
  /// \param pixbuf the pixbuf to associate the mark category to.
  
  /** Associates a given @a pixbuf with a given mark @a category.
   * If @a pixbuf is #<tt>0</tt>, the pixbuf is unset.
   * 
   * @newin2p2
   * @param category A mark category.
   * @param pixbuf A Gdk::Pixbuf or #<tt>0</tt>.
   */
  void set_mark_category_pixbuf(const Glib::ustring& category, const Glib::RefPtr<Gdk::Pixbuf>& pixbuf);
  /// \brief Gets the pixbuf which is associated with the given mark category.
  ///
  /// \param category a mark category.
  /// \return the associated GdkPixbuf, or NULL if not found.
  
  /** Gets the pixbuf which is associated with the given mark @a category.
   * @param category A mark category.
   * @return The associated Gdk::Pixbuf, or <tt>0</tt> if not found.
   * 
   * @newin2p2.
   */
  Glib::RefPtr<Gdk::Pixbuf> get_mark_category_pixbuf(const Glib::ustring& category);

  /// \brief Gets the pixbuf which is associated with the given mark category.
  ///
  /// \param category a mark category.
  /// \return the associated GdkPixbuf, or NULL if not found.
  
  /** Gets the pixbuf which is associated with the given mark @a category.
   * @param category A mark category.
   * @return The associated Gdk::Pixbuf, or <tt>0</tt> if not found.
   * 
   * @newin2p2.
   */
  Glib::RefPtr<const Gdk::Pixbuf> get_mark_category_pixbuf(const Glib::ustring& category) const;

  
  /**
   * @par Prototype:
   * <tt>void on_my_%redo()</tt>
   */

  Glib::SignalProxy0< void > signal_redo();

  
  /**
   * @par Prototype:
   * <tt>void on_my_%undo()</tt>
   */

  Glib::SignalProxy0< void > signal_undo();


  /// \brief Whether to display line numbers
  ///
  /// default value is false
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether to display line numbers.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_show_line_numbers() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether to display line numbers.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_show_line_numbers() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  /// \brief Whether to display line mark pixbufs
  ///
  /// default value is false.
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether to display line mark pixbufs.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_show_line_marks() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether to display line mark pixbufs.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_show_line_marks() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  /// \brief Width of an tab character expressed in number of spaces.
  ///
  /// Allowed values are [1,32]
  /// Default value is 8
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Width of a tab character expressed in spaces.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<guint> property_tab_width() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Width of a tab character expressed in spaces.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<guint> property_tab_width() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  /// \brief Width of an indentation step expressed in number of spaces.
  ///
  /// Allowed values are [-1,32]
  /// Default value is -1
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Number of spaces to use for each step of indent.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<int> property_indent_width() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Number of spaces to use for each step of indent.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<int> property_indent_width() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  /// \brief Whether to enable auto indentation.
  ///
  /// Default value is false
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether to enable auto indentation.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_auto_indent() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether to enable auto indentation.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_auto_indent() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  /// \brief Whether to insert spaces instead of tabs.
  ///
  /// Default value is false
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether to insert spaces instead of tabs.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_insert_spaces_instead_of_tabs() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether to insert spaces instead of tabs.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_insert_spaces_instead_of_tabs() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  /// \brief Whether to display the right margin.
  ///
  /// Default value is false
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether to display the right margin.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_show_right_margin() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether to display the right margin.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_show_right_margin() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  /// \brief Position of the right margin.
  ///
  /// Allowed values are [1,200]
  /// Default value is 80
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Position of the right margin.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<guint> property_right_margin_position() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Position of the right margin.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<guint> property_right_margin_position() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  /// \brief Set the behavior of the HOME and END keys.
  ///
  /// Default value is GTK_SOURCE_SMART_HOME_END_DISABLED
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** HOME and END keys move to first/last non whitespace characters on line before going to the start/end of the line.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<SourceSmartHomeEndType> property_smart_home_end() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** HOME and END keys move to first/last non whitespace characters on line before going to the start/end of the line.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<SourceSmartHomeEndType> property_smart_home_end() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  /// \brief Whether to highlight the current line.
  ///
  /// Default value is false
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether to highlight the current line.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_highlight_current_line() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether to highlight the current line.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_highlight_current_line() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  /// \brief Whether to indent the selected text when the tab key is
  /// pressed.
  ///
  /// Default value is true.
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether to indent the selected text when the tab key is pressed.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_indent_on_tab() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether to indent the selected text when the tab key is pressed.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_indent_on_tab() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


};

} /* namespace gtksourceview */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates gtksourceview::SourceView
   */
  gtksourceview::SourceView* wrap(GtkSourceView* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKSOURCEVIEWMM_SOURCEVIEW_H */

