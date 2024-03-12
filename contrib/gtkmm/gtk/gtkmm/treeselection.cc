// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtkmm/treeselection.h>
#include <gtkmm/private/treeselection_p.h>

// -*- c++ -*-
/* $Id$ */

/* Copyright 1998-2002 The gtkmm Development Team
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

#include <gtkmm/treeview.h>
#include <gtk/gtktreeselection.h>


static void proxy_foreach_selection_iter_callback(GtkTreeModel* model, GtkTreePath*, GtkTreeIter* iter, void* data)
{
  typedef Gtk::TreeSelection::SlotForeachIter SlotType;
  SlotType& slot = *static_cast<SlotType*>(data);

  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  try
  {
  #endif //GLIBMM_EXCEPTIONS_ENABLED
    slot(Gtk::TreeModel::iterator(model, iter));
  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
  #endif //GLIBMM_EXCEPTIONS_ENABLED
}

static void proxy_foreach_selection_path_callback(GtkTreeModel*, GtkTreePath* path, GtkTreeIter*, void* data)
{
  typedef Gtk::TreeSelection::SlotForeachPath SlotType;
  SlotType& slot = *static_cast<SlotType*>(data);

  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  try
  {
  #endif //GLIBMM_EXCEPTIONS_ENABLED
    slot(Gtk::TreeModel::Path(path, true));
  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
  #endif //GLIBMM_EXCEPTIONS_ENABLED
}

static void proxy_foreach_selection_path_and_iter_callback(GtkTreeModel* model, GtkTreePath* path,
                                                    GtkTreeIter* iter, void* data)
{
  typedef Gtk::TreeSelection::SlotForeachPathAndIter SlotType;
  SlotType& slot = *static_cast<SlotType*>(data);

  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  try
  {
  #endif //GLIBMM_EXCEPTIONS_ENABLED
    slot(Gtk::TreeModel::Path(path, true), Gtk::TreeModel::iterator(model, iter));
  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
  #endif //GLIBMM_EXCEPTIONS_ENABLED
}


static gboolean SignalProxy_Select_gtk_callback(GtkTreeSelection*, GtkTreeModel* model, GtkTreePath* path,
                                          gboolean path_currently_selected, void* data)
{
  const Gtk::TreeSelection::SlotSelect* the_slot = static_cast<Gtk::TreeSelection::SlotSelect*>(data);

  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  try
  {
  #endif //GLIBMM_EXCEPTIONS_ENABLED
    return (*the_slot)(Glib::wrap(model, true),   // take copy
                         Gtk::TreePath(path, true), // take copy
                         path_currently_selected);
  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }

  return 0;
  #endif //GLIBMM_EXCEPTIONS_ENABLED
}

static void SignalProxy_Select_gtk_callback_destroy(void* data)
{
  delete static_cast<Gtk::TreeSelection::SlotSelect*>(data);
}


namespace Gtk
{

void TreeSelection::set_select_function(const SlotSelect& slot)
{
  // Create a copy of the slot.  A pointer to this will be passed
  // through the callback's data parameter.  It will be deleted
  // when SignalProxy_Select_gtk_callback_destroy() is called.
  SlotSelect* slot_copy = new SlotSelect(slot);

  gtk_tree_selection_set_select_function(gobj(),
      &SignalProxy_Select_gtk_callback, slot_copy,
      &SignalProxy_Select_gtk_callback_destroy);
}

Glib::RefPtr<TreeModel> TreeSelection::get_model()
{
  GtkTreeView *const tree_view = gtk_tree_selection_get_tree_view(gobj());
  return Glib::wrap(gtk_tree_view_get_model(tree_view), true);
}

Glib::RefPtr<const TreeModel> TreeSelection::get_model() const
{
  GtkTreeView *const tree_view = gtk_tree_selection_get_tree_view(const_cast<GtkTreeSelection*>(gobj()));
  return Glib::wrap(gtk_tree_view_get_model(tree_view), true);
}

TreeModel::iterator TreeSelection::get_selected()
{
  TreeModel::iterator iter;
  GtkTreeModel* model_gobject = 0;

  gtk_tree_selection_get_selected(gobj(), &model_gobject, iter.gobj());

  iter.set_model_gobject(model_gobject);
  return iter;
}

TreeModel::iterator TreeSelection::get_selected(Glib::RefPtr<TreeModel>& model)
{
  TreeModel::iterator iter;
  GtkTreeModel* model_gobject = 0;

  gtk_tree_selection_get_selected(gobj(), &model_gobject, iter.gobj());

  model = Glib::wrap(model_gobject, true);

  iter.set_model_refptr(model);
  return iter;
}

void TreeSelection::selected_foreach_iter(const SlotForeachIter& slot) const
{
  SlotForeachIter slot_copy (slot);
  gtk_tree_selection_selected_foreach(const_cast<GtkTreeSelection*>(gobj()), &proxy_foreach_selection_iter_callback, &slot_copy);
}

void TreeSelection::selected_foreach_path(const SlotForeachPath& slot) const
{
  SlotForeachPath slot_copy (slot);
  gtk_tree_selection_selected_foreach(const_cast<GtkTreeSelection*>(gobj()), &proxy_foreach_selection_path_callback, &slot_copy);
}

void TreeSelection::selected_foreach(const SlotForeachPathAndIter& slot) const
{
  SlotForeachPathAndIter slot_copy (slot);
  gtk_tree_selection_selected_foreach(const_cast<GtkTreeSelection*>(gobj()), &proxy_foreach_selection_path_and_iter_callback, &slot_copy);
}

TreeSelection::ListHandle_Path TreeSelection::get_selected_rows() const
{
  return ListHandle_Path(gtk_tree_selection_get_selected_rows(
      const_cast<GtkTreeSelection*>(gobj()), 0), Glib::OWNERSHIP_DEEP);
}

TreeSelection::ListHandle_Path TreeSelection::get_selected_rows(Glib::RefPtr<TreeModel>& model)
{
  GtkTreeModel* model_gobject = 0;

  const ListHandle_Path result (gtk_tree_selection_get_selected_rows(
      const_cast<GtkTreeSelection*>(gobj()), &model_gobject), Glib::OWNERSHIP_DEEP);

  model = Glib::wrap(model_gobject, true);
  return result;
}

} // namespace Gtk


namespace
{


static const Glib::SignalProxyInfo TreeSelection_signal_changed_info =
{
  "changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gtk::TreeSelection> wrap(GtkTreeSelection* object, bool take_copy)
{
  return Glib::RefPtr<Gtk::TreeSelection>( dynamic_cast<Gtk::TreeSelection*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& TreeSelection_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &TreeSelection_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_tree_selection_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void TreeSelection_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  klass->changed = &changed_callback;
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
}

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void TreeSelection_Class::changed_callback(GtkTreeSelection* self)
{
  Glib::ObjectBase *const obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    CppObjectType *const obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
      #endif //GLIBMM_EXCEPTIONS_ENABLED
        // Call the virtual member method, which derived classes might override.
        obj->on_changed();
        return;
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
      #endif //GLIBMM_EXCEPTIONS_ENABLED
    }
  }
  
  BaseClassType *const base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->changed)
    (*base->changed)(self);
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


Glib::ObjectBase* TreeSelection_Class::wrap_new(GObject* object)
{
  return new TreeSelection((GtkTreeSelection*)object);
}


/* The implementation: */

GtkTreeSelection* TreeSelection::gobj_copy()
{
  reference();
  return gobj();
}

TreeSelection::TreeSelection(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

TreeSelection::TreeSelection(GtkTreeSelection* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


TreeSelection::~TreeSelection()
{}


TreeSelection::CppClassType TreeSelection::treeselection_class_; // initialize static member

GType TreeSelection::get_type()
{
  return treeselection_class_.init().get_type();
}

GType TreeSelection::get_base_type()
{
  return gtk_tree_selection_get_type();
}


void TreeSelection::set_mode(SelectionMode type)
{
gtk_tree_selection_set_mode(gobj(), ((GtkSelectionMode)(type))); 
}

SelectionMode TreeSelection::get_mode() const
{
  return ((SelectionMode)(gtk_tree_selection_get_mode(const_cast<GtkTreeSelection*>(gobj()))));
}

TreeView* TreeSelection::get_tree_view()
{
  return Glib::wrap(gtk_tree_selection_get_tree_view(gobj()));
}

const TreeView* TreeSelection::get_tree_view() const
{
  return const_cast<TreeSelection*>(this)->get_tree_view();
}

int TreeSelection::count_selected_rows() const
{
  return gtk_tree_selection_count_selected_rows(const_cast<GtkTreeSelection*>(gobj()));
}

void TreeSelection::select(const TreeModel::Path& path)
{
gtk_tree_selection_select_path(gobj(), const_cast<GtkTreePath*>((path).gobj())); 
}

void TreeSelection::select(const TreeModel::iterator& iter)
{
gtk_tree_selection_select_iter(gobj(), const_cast<GtkTreeIter*>((iter).gobj())); 
}

void TreeSelection::select(const TreeModel::Row& row)
{
gtk_tree_selection_select_iter(gobj(), const_cast<GtkTreeIter*>((row).gobj())); 
}

void TreeSelection::select(const TreeModel::Path& start_path, const TreeModel::Path& end_path)
{
gtk_tree_selection_select_range(gobj(), const_cast<GtkTreePath*>((start_path).gobj()), const_cast<GtkTreePath*>((end_path).gobj())); 
}

void TreeSelection::unselect(const TreeModel::Path& path)
{
gtk_tree_selection_unselect_path(gobj(), const_cast<GtkTreePath*>((path).gobj())); 
}

void TreeSelection::unselect(const TreeModel::Path& start_path, const TreeModel::Path& end_path)
{
gtk_tree_selection_unselect_range(gobj(), const_cast<GtkTreePath*>((start_path).gobj()), const_cast<GtkTreePath*>((end_path).gobj())); 
}

void TreeSelection::unselect(const TreeModel::iterator& iter)
{
gtk_tree_selection_unselect_iter(gobj(), const_cast<GtkTreeIter*>((iter).gobj())); 
}

bool TreeSelection::is_selected(const TreeModel::Path& path) const
{
  return gtk_tree_selection_path_is_selected(const_cast<GtkTreeSelection*>(gobj()), const_cast<GtkTreePath*>((path).gobj()));
}

bool TreeSelection::is_selected(const TreeModel::iterator& iter) const
{
  return gtk_tree_selection_iter_is_selected(const_cast<GtkTreeSelection*>(gobj()), const_cast<GtkTreeIter*>((iter).gobj()));
}

void TreeSelection::select_all()
{
gtk_tree_selection_select_all(gobj()); 
}

void TreeSelection::unselect_all()
{
gtk_tree_selection_unselect_all(gobj()); 
}


Glib::SignalProxy0< void > TreeSelection::signal_changed()
{
  return Glib::SignalProxy0< void >(this, &TreeSelection_signal_changed_info);
}


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void Gtk::TreeSelection::on_changed()
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->changed)
    (*base->changed)(gobj());
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gtk


