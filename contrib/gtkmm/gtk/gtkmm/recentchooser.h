// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_RECENTCHOOSER_H
#define _GTKMM_RECENTCHOOSER_H


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

#include <gtk/gtkrecentchooser.h>
#include <glibmm/interface.h>
#include <gtkmm/recentinfo.h>
#include <gtkmm/recentfilter.h>
#include <gtkmm/recentmanager.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkRecentChooser GtkRecentChooser;
typedef struct _GtkRecentChooserClass GtkRecentChooserClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class RecentChooser_Class; } // namespace Gtk
namespace Gtk
{

/** @addtogroup gtkmmEnums Enums and Flags */

/**
 * @ingroup gtkmmEnums
 */
enum RecentSortType
{
  RECENT_SORT_NONE,
  RECENT_SORT_MRU,
  RECENT_SORT_LRU,
  RECENT_SORT_CUSTOM
};

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::RecentSortType> : public Glib::Value_Enum<Gtk::RecentSortType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{


/** Exception class for Gtk::RecentChooser errors.
 */
class RecentChooserError : public Glib::Error
{
public:
  enum Code
  {
    NOT_FOUND,
    INVALID_URI
  };

  RecentChooserError(Code error_code, const Glib::ustring& error_message);
  explicit RecentChooserError(GError* gobject);
  Code code() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

#ifdef GLIBMM_EXCEPTIONS_ENABLED
  static void throw_func(GError* gobject);
#else
  //When not using exceptions, we just pass the Exception object around without throwing it:
  static std::auto_ptr<Glib::Error> throw_func(GError* gobject);
#endif //GLIBMM_EXCEPTIONS_ENABLED

  friend void wrap_init(); // uses throw_func()
#endif
};

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::RecentChooserError::Code> : public Glib::Value_Enum<Gtk::RecentChooserError::Code>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{


/** RecentChooser is an interface that can be implemented by widgets
 * displaying the list of recently used files.  In GTK+, the main objects
 * that implement this interface are RecentChooserWidget, RecentChooserDialog
 * and RecentChooserMenu.
 *
 * @newin2p10
 *
 * @ingroup RecentFiles
 */

class RecentChooser : public Glib::Interface
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef RecentChooser CppObjectType;
  typedef RecentChooser_Class CppClassType;
  typedef GtkRecentChooser BaseObjectType;
  typedef GtkRecentChooserIface BaseClassType;

private:
  friend class RecentChooser_Class;
  static CppClassType recentchooser_class_;

  // noncopyable
  RecentChooser(const RecentChooser&);
  RecentChooser& operator=(const RecentChooser&);

protected:
  RecentChooser(); // you must derive from this class

  /** Called by constructors of derived classes. Provide the result of 
   * the Class init() function to ensure that it is properly 
   * initialized.
   * 
   * @param interface_class The Class object for the derived type.
   */
  explicit RecentChooser(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface. 
  explicit RecentChooser(GtkRecentChooser* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~RecentChooser();

  static void add_interface(GType gtype_implementer);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkRecentChooser*       gobj()       { return reinterpret_cast<GtkRecentChooser*>(gobject_); }

  ///Provides access to the underlying C GObject.  
  const GtkRecentChooser* gobj() const { return reinterpret_cast<GtkRecentChooser*>(gobject_); }

private:

public:

  
  /** Whether to show recently used resources marked registered as private.
   * 
   * @newin2p10
   * @param show_private <tt>true</tt> to show private items, <tt>false</tt> otherwise.
   */
  void set_show_private(bool show_private = true);
  
  /** Return value: <tt>true</tt> if the recent chooser should show private items,
   * @return <tt>true</tt> if the recent chooser should show private items,
   * <tt>false</tt> otherwise.
   * 
   * @newin2p10.
   */
  bool get_show_private() const;
  
  /** Sets whether @a chooser should display the recently used resources that
   * it didn't find.  This only applies to local resources.
   * 
   * @newin2p10
   * @param show_not_found Whether to show the local items we didn't find.
   */
  void set_show_not_found(bool show_not_found = true);
  
  /** Retrieves whether @a chooser should show the recently used resources that
   * were not found.
   * @return <tt>true</tt> if the resources not found should be displayed, and
   * <tt>false</tt> otheriwse.
   * 
   * @newin2p10.
   */
  bool get_show_not_found() const;
  
  /** Sets whether @a chooser can select multiple items.
   * 
   * @newin2p10
   * @param select_multiple <tt>true</tt> if @a chooser can select more than one item.
   */
  void set_select_multiple(bool select_multiple = true);
  
  /** Gets whether @a chooser can select multiple items.
   * @return <tt>true</tt> if @a chooser can select more than one item.
   * 
   * @newin2p10.
   */
  bool get_select_multiple() const;
  
  /** Sets the number of items that should be returned by
   * get_items() and get_uris().
   * 
   * @newin2p10
   * @param limit A positive integer, or -1 for all items.
   */
  void set_limit(int limit);
  void unset_limit();
  
  /** Gets the number of items returned by get_items()
   * and get_uris().
   * @return A positive integer, or -1 meaning that all items are
   * returned.
   * 
   * @newin2p10.
   */
  int get_limit() const;
  
  /** Sets whether only local resources, that is resources using the file:// URI
   * scheme, should be shown in the recently used resources selector.  If
   *  @a local_only is <tt>true</tt> (the default) then the shown resources are guaranteed
   * to be accessible through the operating system native file system.
   * 
   * @newin2p10
   * @param local_only <tt>true</tt> if only local files can be shown.
   */
  void set_local_only(bool local_only = true);
  
  /** Gets whether only local resources should be shown in the recently used
   * resources selector.  See set_local_only()
   * @return <tt>true</tt> if only local resources should be shown.
   * 
   * @newin2p10.
   */
  bool get_local_only() const;
  
  /** Sets whether to show a tooltips containing the full path of each
   * recently used resource in a Gtk::RecentChooser widget.
   * 
   * @newin2p10
   * @param show_tips <tt>true</tt> if tooltips should be shown.
   */
  void set_show_tips(bool show_tips = true);
  
  /** Gets whether @a chooser should display tooltips containing the full path
   * of a recently user resource.
   * @return <tt>true</tt> if the recent chooser should show tooltips,
   * <tt>false</tt> otherwise.
   * 
   * @newin2p10.
   */
  bool get_show_tips() const;

  // Deprecated in GTK+ 2.12. murrayc:
  

  /** Sets whether @a chooser should show an icon near the resource when
   * displaying it.
   * 
   * @newin2p10
   * @param show_icons Whether to show an icon near the resource.
   */
  void set_show_icons(bool show_icons = true);
  
  /** Retrieves whether @a chooser should show an icon near the resource.
   * @return <tt>true</tt> if the icons should be displayed, <tt>false</tt> otherwise.
   * 
   * @newin2p10.
   */
  bool get_show_icons() const;
  
  /** Changes the sorting order of the recently used resources list displayed by
   *  @a chooser.
   * 
   * @newin2p10
   * @param sort_type Sort order that the chooser should use.
   */
  void set_sort_type(RecentSortType sort_type);
  
  /** Gets the value set by set_sort_type().
   * @return The sorting order of the @a chooser.
   * 
   * @newin2p10.
   */
  RecentSortType get_sort_type() const;


  /** This callback should return -1 if b compares before a, 0 if they compare
   * equal and 1 if a compares after b.
   * For instance, int on_sort_compare(const Glib::RefPtr<Gtk::RecentInfo>& a, const Gtk::RecentInfo& b);
   */
  typedef sigc::slot<int, const Glib::RefPtr<RecentInfo>&, const Glib::RefPtr<RecentInfo>&> SlotCompare;
  

  /** Sets the comparison function used when sorting the list of recently
   * used resources and the sort type is #RECENT_SORT_CUSTOM.
   */
  void set_sort_func(const SlotCompare& slot);

  // TODO: Return type should be void since it will never return false but
  // throwing RecentChooserError instead
  
  /** Sets @a uri as the current URI for @a chooser.
   * @param uri A URI.
   * @return <tt>true</tt> if the URI was found.
   * 
   * @newin2p10.
   */
#ifdef GLIBMM_EXCEPTIONS_ENABLED
  bool set_current_uri(const Glib::ustring& uri);
#else
  bool set_current_uri(const Glib::ustring& uri, std::auto_ptr<Glib::Error>& error);
#endif //GLIBMM_EXCEPTIONS_ENABLED

  
  /** Gets the URI currently selected by @a chooser.
   * @return A newly allocated string holding a URI.
   * 
   * @newin2p10.
   */
  Glib::ustring get_current_uri() const;
  
  /** Gets the Gtk::RecentInfo currently selected by @a chooser.
   * @return A Gtk::RecentInfo.  Use Gtk::RecentInfo::unref() when
   * when you have finished using it.
   * 
   * @newin2p10.
   */
  Glib::RefPtr<RecentInfo> get_current_item();
  
  /** Gets the Gtk::RecentInfo currently selected by @a chooser.
   * @return A Gtk::RecentInfo.  Use Gtk::RecentInfo::unref() when
   * when you have finished using it.
   * 
   * @newin2p10.
   */
  Glib::RefPtr<const RecentInfo> get_current_item() const;
  // TODO: Same here
  
  /** Selects @a uri inside @a chooser.
   * @param uri A URI.
   * @return <tt>true</tt> if @a uri was found.
   * 
   * @newin2p10.
   */
#ifdef GLIBMM_EXCEPTIONS_ENABLED
  bool select_uri(const Glib::ustring& uri);
#else
  bool select_uri(const Glib::ustring& uri, std::auto_ptr<Glib::Error>& error);
#endif //GLIBMM_EXCEPTIONS_ENABLED

  
  /** Unselects @a uri inside @a chooser.
   * 
   * @newin2p10
   * @param uri A URI.
   */
  void unselect_uri(const Glib::ustring& uri);
  
  /** Selects all the items inside @a chooser, if the @a chooser supports
   * multiple selection.
   * 
   * @newin2p10
   */
  void select_all();
  
  /** Unselects all the items inside @a chooser.
   * 
   * @newin2p10
   */
  void unselect_all();

  typedef Glib::ListHandle<RecentInfo, RecentInfoTraits> ListHandle_RecentInfos;
  

  /** Gets the list of recently used resources in form of Gtk::RecentInfo objects.
   * 
   * The return value of this function is affected by the "sort-type" and
   * "limit" properties of @a chooser.
   * @return A newly allocated list of Gtk::RecentInfo objects.  You should
   * use Gtk::RecentInfo::unref() on every item of the list, and then free
   * the list itself using Glib::list_free().
   * 
   * @newin2p10.
   */
  ListHandle_RecentInfos get_items() const;

  /** Gets the URI of the recently used resources.
   *
   * The return value of this function is affected by the "sort-type" and
   * "limit" properties of the recent chooser.
   */
  Glib::StringArrayHandle get_uris() const;
  

  /** Adds @a filter to the list of Gtk::RecentFilter objects held by @a chooser.
   * 
   * If no previous filter objects were defined, this function will call
   * set_filter().
   * 
   * @newin2p10
   * @param filter A Gtk::RecentFilter.
   */
  void add_filter(const RecentFilter& filter);
  
  /** Removes @a filter from the list of Gtk::RecentFilter objects held by @a chooser.
   * 
   * @newin2p10
   * @param filter A Gtk::RecentFilter.
   */
  void remove_filter(const RecentFilter& filter);
  
  /** Gets the Gtk::RecentFilter objects held by @a chooser.
   * @return A singly linked list of Gtk::RecentFilter objects.  You
   * should just free the returned list using Glib::slist_free().
   * 
   * @newin2p10.
   */
  Glib::SListHandle<RecentFilter*> list_filters();
  
  /** Gets the Gtk::RecentFilter objects held by @a chooser.
   * @return A singly linked list of Gtk::RecentFilter objects.  You
   * should just free the returned list using Glib::slist_free().
   * 
   * @newin2p10.
   */
  Glib::SListHandle<const RecentFilter*> list_filters() const;
  
  /** Sets @a filter as the current Gtk::RecentFilter object used by @a chooser
   * to affect the displayed recently used resources.
   * 
   * @newin2p10
   * @param filter A Gtk::RecentFilter.
   */
  void set_filter(const RecentFilter& filter);
  
  /** Gets the Gtk::RecentFilter object currently used by @a chooser to affect
   * the display of the recently used resources.
   * @return A Gtk::RecentFilter object.
   * 
   * @newin2p10.
   */
  RecentFilter* get_filter();
  
  /** Gets the Gtk::RecentFilter object currently used by @a chooser to affect
   * the display of the recently used resources.
   * @return A Gtk::RecentFilter object.
   * 
   * @newin2p10.
   */
  const RecentFilter* get_filter() const;

  /** This signal is emitted when there is a change in the set of
   * selected recently used resources.  This can happen when a user
   * modifies the selection with the mouse or the keyboard, or when
   * explicitely calling functions to change the selection.
   *
   * @par Prototype:
   * <tt>void on_my_%selection_changed()</tt>
   */

  Glib::SignalProxy0< void > signal_selection_changed();


  /** This signal is emitted when the user "activates" a recent item
   * in the recent chooser.  This can happen by double-clicking on an item
   * in the recently used resources list, or by pressing
   * <keycap>Enter</keycap>.
   *
   * @par Prototype:
   * <tt>void on_my_%item_activated()</tt>
   */

  Glib::SignalProxy0< void > signal_item_activated();


  //Not wrapped because it's write-only and construct-only: _WRAP_PROPERTY("recent-manager", Glib::RefPtr<RecentManager>)
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_show_private() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_show_private() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_show_tips() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_show_tips() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_show_icons() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_show_icons() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_show_not_found() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_show_not_found() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_select_multiple() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_select_multiple() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_local_only() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_local_only() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<int> property_limit() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<int> property_limit() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<RecentSortType> property_sort_type() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<RecentSortType> property_sort_type() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<RecentFilter*> property_filter() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<RecentFilter*> property_filter() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


protected:
 

  // TODO: How to wrap those vfuncs?

  //__CONVERSION(`ListHandle_RecentInfos', `GList*', `($3).data()')
  //__CONVERSION(`Glib::SListHandle<RecentFilter*>', `GSList*', `($3).data()')

  //_WRAP_VFUNC(bool set_current_uri(const Glib::ustring& uri), "set_current_uri", errthrow)
  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual Glib::ustring get_current_uri_vfunc() const;
#endif //GLIBMM_VFUNCS_ENABLED


  //_WRAP_VFUNC(bool select_uri(const Glib::ustring& uri), "select_uri", errthrow)
  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void unselect_uri_vfunc(const Glib::ustring& uri);
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void select_all_vfunc();
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void unselect_all_vfunc();
#endif //GLIBMM_VFUNCS_ENABLED

  //_WRAP_VFUNC(ArrayHandle_RecentInfos get_items() const, "get_items")
  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual Glib::RefPtr<RecentManager> get_recent_manager_vfunc();
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void add_filter_vfunc(const RecentFilter& filter);
#endif //GLIBMM_VFUNCS_ENABLED

  #ifdef GLIBMM_VFUNCS_ENABLED
  virtual void remove_filter_vfunc(const RecentFilter& filter);
#endif //GLIBMM_VFUNCS_ENABLED

  //_WRAP_VFUNC(Glib::SListHandle<RecentFilter*> list_filters(), "list_filters")
  //_WRAP_VFUNC(void set_sort_func(const SlotCompare& slot), "set_sort_func")


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
   * @relates Gtk::RecentChooser
   */
  Glib::RefPtr<Gtk::RecentChooser> wrap(GtkRecentChooser* object, bool take_copy = false);

} // namespace Glib


#endif /* _GTKMM_RECENTCHOOSER_H */

