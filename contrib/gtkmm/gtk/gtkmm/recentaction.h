// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_RECENTACTION_H
#define _GTKMM_RECENTACTION_H


#include <glibmm.h>

/* $Id: recentaction.hg,v 1.5 2004/07/01 08:55:45 murrayc Exp $ */

/* Copyright (C) 2003 The gtkmm Development Team
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

#include <gtkmm/action.h>
#include <gtkmm/recentchooser.h>
#include <gtkmm/recentmanager.h>
#include <gtkmm/stockid.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkRecentAction GtkRecentAction;
typedef struct _GtkRecentActionClass GtkRecentActionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class RecentAction_Class; } // namespace Gtk
namespace Gtk
{

/** An action of which represents a list of recently used files.
 *
 * A Gtk::RecentAction represents a list of recently used files, 
 * which can be shown by widgets such as Gtk::RecentChooserDialog or 
 * Gtk::RecentChooserMenu.
 * To construct a submenu showing recently used files, use a 
 * Gtk::RecentAction as the action for a <menuitem>. To construct a menu 
 * toolbutton showing the recently used files in the popup menu, use a 
 * Gtk::RecentAction as the action for a <toolitem> element.
 *
 * See also the methods in the RecentChooser base class.
 *
 * @newin2p12
 *
 * @ingroup RecentFiles
 */

class RecentAction
  : public Gtk::Action,
    public Gtk::RecentChooser
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef RecentAction CppObjectType;
  typedef RecentAction_Class CppClassType;
  typedef GtkRecentAction BaseObjectType;
  typedef GtkRecentActionClass BaseClassType;

private:  friend class RecentAction_Class;
  static CppClassType recentaction_class_;

private:
  // noncopyable
  RecentAction(const RecentAction&);
  RecentAction& operator=(const RecentAction&);

protected:
  explicit RecentAction(const Glib::ConstructParams& construct_params);
  explicit RecentAction(GtkRecentAction* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~RecentAction();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkRecentAction*       gobj()       { return reinterpret_cast<GtkRecentAction*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkRecentAction* gobj() const { return reinterpret_cast<GtkRecentAction*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkRecentAction* gobj_copy();

private:

  
protected:
  RecentAction();

//Make sure that we use NULL instead of empty strings for the constructors:
 

  //Note that the order of the parameters is not the same as gtk_recent_action_new(), because 
  //a) we want to be consistent with Action, ToggleAction, etc.
  //b) this allows us to use the StockID parameter to distinguish the create() overloads.
  explicit RecentAction(const Glib::ustring& name, const StockID& stock_id = StockID(), const Glib::ustring& label = Glib::ustring(), const Glib::ustring& tooltip = Glib::ustring());
  explicit RecentAction(const Glib::ustring& name, const StockID& stock_id, const Glib::ustring& label, const Glib::ustring& tooltip, const Glib::RefPtr<RecentManager>& manager);

public:
  //Note that gtk_recent_action_new() does not allow name to be NULL, which suggests that we should not have a default constructor,
  //but it's OK to set the name later:
  
  static Glib::RefPtr<RecentAction> create();


  static Glib::RefPtr<RecentAction> create(const Glib::ustring& name, const Glib::ustring& label = Glib::ustring(), const Glib::ustring& tooltip = Glib::ustring());
  
  static Glib::RefPtr<RecentAction> create(const Glib::ustring& name, const Gtk::StockID& stock_id, const Glib::ustring& label =  Glib::ustring(), const Glib::ustring& tooltip =  Glib::ustring());

  
  static Glib::RefPtr<RecentAction> create(const Glib::ustring& name, const Gtk::StockID& stock_id, const Glib::ustring& label, const Glib::ustring& tooltip, const Glib::RefPtr<RecentManager>& manager);


  /** Return value: <tt>true</tt> if numbers should be shown.
   * @return <tt>true</tt> if numbers should be shown.
   * 
   * @newin2p12.
   */
  bool get_show_numbers();
  
  /** Sets whether a number should be added to the items shown by the
   * widgets representing @a action. The numbers are shown to provide
   * a unique character for a mnemonic to be used inside the menu item's
   * label. Only the first ten items get a number to avoid clashes.
   * 
   * @newin2p12
   * @param show_numbers <tt>true</tt> if the shown items should be numbered.
   */
  void set_show_numbers(bool show_numbers = true);

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether the items should be displayed with a number.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_show_numbers() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Whether the items should be displayed with a number.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_show_numbers() const;
#endif //#GLIBMM_PROPERTIES_ENABLED
          

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
   * @relates Gtk::RecentAction
   */
  Glib::RefPtr<Gtk::RecentAction> wrap(GtkRecentAction* object, bool take_copy = false);
}


#endif /* _GTKMM_RECENTACTION_H */
