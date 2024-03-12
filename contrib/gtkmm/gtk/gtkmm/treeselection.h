// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_TREESELECTION_H
#define _GTKMM_TREESELECTION_H


#include <glibmm.h>

/* $Id$ */

/* Copyright(C) 1998-1999 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or(at your option) any later version.
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


#include <gtkmm/enums.h>
#include <gtkmm/treemodel.h>
#include <gtkmm/treeiter.h>
#include <gtkmm/treepath.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkTreeSelection GtkTreeSelection;
typedef struct _GtkTreeSelectionClass GtkTreeSelectionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class TreeSelection_Class; } // namespace Gtk
namespace Gtk
{

class TreeView;
class TreeModel;
class TreePath;

/** Typedefed as Gtk::TreeView::Selection.
 * This is a helper object to manage the selection for a Gtk::TreeView widget.
 *
 * It is automatically created when a new Gtk::TreeView widget is created, and
 * cannot exist independently of this widget.  The primary reason this class
 * exists is for cleanliness of code and API. That is, there is no conceptual
 * reason all these methods could not be methods on the Gtk::TreeView widget
 * instead of a separate class.
 *
 * The Gtk::TreeSelection object can be obtained from a Gtk::TreeView by
 * calling Gtk::TreeView::get_selection().  It can be manipulated to check the
 * selection status of the tree, as well as to select and deselect individual
 * rows.  Selection is done completely view-side. As a result, multiple views
 * of the same model can have completely different selections.  Additionally,
 * you cannot change the selection of a row on the model that is not currently
 * displayed by the view without expanding its parents first.
 *
 * When monitoring the selection of a view, it's important to remember that the
 * "changed" signal is mostly a hint. That is, it may only emit one signal when
 * a range of rows is selected. Additionally, it may on occasion emit a
 * "changed" signal when nothing has happened.
 *
 * @ingroup TreeView
 */

class TreeSelection : public Glib::Object
{
   
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef TreeSelection CppObjectType;
  typedef TreeSelection_Class CppClassType;
  typedef GtkTreeSelection BaseObjectType;
  typedef GtkTreeSelectionClass BaseClassType;

private:  friend class TreeSelection_Class;
  static CppClassType treeselection_class_;

private:
  // noncopyable
  TreeSelection(const TreeSelection&);
  TreeSelection& operator=(const TreeSelection&);

protected:
  explicit TreeSelection(const Glib::ConstructParams& construct_params);
  explicit TreeSelection(GtkTreeSelection* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~TreeSelection();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkTreeSelection*       gobj()       { return reinterpret_cast<GtkTreeSelection*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkTreeSelection* gobj() const { return reinterpret_cast<GtkTreeSelection*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkTreeSelection* gobj_copy();

private:

   
protected:
  

public:
  
  /** Sets the selection mode of the @a selection.  If the previous type was
   * Gtk::SELECTION_MULTIPLE, then the anchor is kept selected, if it was
   * previously selected.
   * @param type The selection mode.
   */
  void set_mode(SelectionMode type);
  
  /** Gets the selection mode for @a selection. See
   * set_mode().
   * @return The current selection mode.
   */
  SelectionMode get_mode() const;

  /** For instance, bool on_select_function(const Glib::RefPtr<TreeModel>& model, const TreeModel::Path& path, bool path_currently_selected)
   * The select function should return true if the state of the node may be toggled,
   * and false if the state of the node should be left unchanged.
   */
  typedef sigc::slot<bool, const Glib::RefPtr<TreeModel>&, const TreeModel::Path&, bool> SlotSelect;

  /** Sets the selection callback slot. If set, this function is called before any node is selected or unselected,
   * giving some control over which nodes are selected.
   *
   * The select function should return true if the state of the node may be toggled, and FALSE if the state of the node
   * should be left unchanged.
   *
   * @param slot The selection function.
   */
  void set_select_function(const SlotSelect& slot);

   // This would be our SignalProxy_Select* data.

  
  /** Return value: A Gtk::TreeView
   * @return A Gtk::TreeView.
   */
  TreeView* get_tree_view();
  
  /** Return value: A Gtk::TreeView
   * @return A Gtk::TreeView.
   */
  const TreeView* get_tree_view() const;

  /** Shortcut for get_tree_view()->get_model().
   * @return The TreeModel associated with this TreeSelection.
   */
  Glib::RefPtr<TreeModel> get_model(); // convenience function, not in GTK+
  Glib::RefPtr<const TreeModel> get_model() const; // convenience function, not in GTK+

  //TODO: Add TreeModel::const_iterator get_selected() const, when we have a real const_iterator.
  
  /** Get the currently selected row.
   * @return The currently selected row.
   * @note
   * This method won't work if the selection mode is <tt>Gtk::SELECTION_MULTIPLE</tt>.
   * Use get_selected_rows() for multiple selections.
   */
  TreeModel::iterator get_selected();

  /** Get the currently selected row.
   * @return The currently selected row. Or end() if no rows were selected.
   * @retval model The current TreeModel.
   * @note
   * This method won't work if the selection mode is <tt>Gtk::SELECTION_MULTIPLE</tt>.
   * Use get_selected_rows() for multiple selections.
   */
  TreeModel::iterator get_selected(Glib::RefPtr<TreeModel>& model);

  typedef Glib::ListHandle<TreeModel::Path, TreePath_Traits> ListHandle_Path;

  /** Creates a list of paths of all selected rows.
   * Additionally, if you are planning on modifying the model after calling this function,
   * you may want to convert the returned list into a list of GtkTreeRowReferences.
   *
   * @returns a standard container containing a Gtk::Model::Path for each selected row.
   */
  ListHandle_Path get_selected_rows() const;

  /** Creates a list of paths of all selected rows.
   * Additionally, if you are planning on modifying the model after calling this function,
   * you may want to convert the returned list into a list of GtkTreeRowReferences.
   *
   * @retval model The current TreeModel.
   * @returns a standard container containing a Gtk::Model::Path for each selected row.
   */
  ListHandle_Path get_selected_rows(Glib::RefPtr<TreeModel>& model);

  
  /** Return value: The number of rows selected.
   * @return The number of rows selected.
   * 
   * @newin2p2.
   */
  int count_selected_rows() const;

  //TODO: Consider deprecating these selected_foreach() methods, because get_selected_rows() should be enough.

  //TODO: SlotForEachIter should take a const_iterator, when we have a real const iterator.
  /** For example,
   * void on_foreach(const Gtk::TreeModel::iterator& iter);
   *
   * Note that you cannot modify the tree or selection from within the callback function.
   * As a result, get_selected_rows() might be more useful.
   */
  typedef sigc::slot<void, const TreeModel::iterator&> SlotForeachIter;

  /** Calls a callback slot for each selected node.
   * Note that you cannot modify the tree or selection from within the callback function.
   * As a result, get_selected_rows() might be more useful.
   *
   * @param slot The function to call for each selected node.
   */
  void selected_foreach_iter(const SlotForeachIter& slot) const;

  /** For example,
   * void on_foreach(const Gtk::TreeModel::Path& path);
   *
   * Note that you cannot modify the tree or selection from within the callback function.
   * As a result, get_selected_rows() might be more useful.
   */
  typedef sigc::slot<void, const TreeModel::Path&> SlotForeachPath;

  /** Calls a callback slot for each selected node.
   * Note that you cannot modify the tree or selection from within the callback function.
   * As a result, get_selected_rows() might be more useful.
   *
   * @param slot The function to call for each selected node.
   */
  void selected_foreach_path(const SlotForeachPath& slot) const;
  

  /** For example,
   * void on_foreach(const Gtk::TreeModel::Path& path, const Gtk::TreeModel::iterator& iter);
   *
   * Note that you cannot modify the tree or selection from within the callback function.
   * As a result, get_selected_rows() might be more useful.
   */
  typedef sigc::slot<void, const TreeModel::Path&, const TreeModel::iterator&> SlotForeachPathAndIter;

  /** Calls a callback slot for each selected node.
   * Note that you cannot modify the tree or selection from within the callback function.
   * As a result, get_selected_rows() might be more useful.
   *
   * @param slot The function to call for each selected node.
   */
  void selected_foreach(const SlotForeachPathAndIter& slot) const;

  
  /** Select the row at @a path.
   * @param path The Gtk::TreePath to be selected.
   */
  void select(const TreeModel::Path& path);
  
  /** Selects the specified iterator.
   * @param iter The Gtk::TreeIter to be selected.
   */
  void select(const TreeModel::iterator& iter);
  
  /** Selects the specified iterator.
   * @param iter The Gtk::TreeIter to be selected.
   */
  void select(const TreeModel::Row& row);
  
  /** Selects a range of nodes, determined by @a start_path and @a end_path inclusive.
   *  @a selection must be set to Gtk::SELECTION_MULTIPLE mode.
   * @param start_path The initial node of the range.
   * @param end_path The final node of the range.
   */
  void select(const TreeModel::Path& start_path, const TreeModel::Path& end_path);

  
  /** Unselects the row at @a path.
   * @param path The Gtk::TreePath to be unselected.
   */
  void unselect(const TreeModel::Path& path);
  
  /** Unselects a range of nodes, determined by @a start_path and @a end_path
   * inclusive.
   * 
   * @newin2p2
   * @param start_path The initial node of the range.
   * @param end_path The initial node of the range.
   */
  void unselect(const TreeModel::Path& start_path, const TreeModel::Path& end_path);
  
  /** Unselects the specified iterator.
   * @param iter The Gtk::TreeIter to be unselected.
   */
  void unselect(const TreeModel::iterator& iter);

  
  /** Return value: <tt>true</tt> if @a path is selected.
   * @param path A Gtk::TreePath to check selection on.
   * @return <tt>true</tt> if @a path is selected.
   */
  bool is_selected(const TreeModel::Path& path) const;
  
  /** Return value: <tt>true</tt>, if @a iter is selected
   * @param iter A valid Gtk::TreeIter.
   * @return <tt>true</tt>, if @a iter is selected.
   */
  bool is_selected(const TreeModel::iterator& iter) const;
  
  
  /** Selects all the nodes. @a selection must be set to Gtk::SELECTION_MULTIPLE
   * mode.
   */
  void select_all();
  
  /** Unselects all the nodes.
   */
  void unselect_all();
  
  
  /**
   * @par Prototype:
   * <tt>void on_my_%changed()</tt>
   */

  Glib::SignalProxy0< void > signal_changed();


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
   * @relates Gtk::TreeSelection
   */
  Glib::RefPtr<Gtk::TreeSelection> wrap(GtkTreeSelection* object, bool take_copy = false);
}


#endif /* _GTKMM_TREESELECTION_H */

