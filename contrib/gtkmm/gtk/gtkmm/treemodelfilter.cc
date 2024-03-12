// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtkmm/treemodelfilter.h>
#include <gtkmm/private/treemodelfilter_p.h>

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

#include <gtk/gtktreemodelfilter.h>


static gboolean SignalProxy_Visible_gtk_callback(GtkTreeModel* model, GtkTreeIter* iter, gpointer data)
{
  Gtk::TreeModelFilter::SlotVisible* the_slot = static_cast<Gtk::TreeModelFilter::SlotVisible*>(data);

  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  try
  {
  #endif //GLIBMM_EXCEPTIONS_ENAB
    return (*the_slot)( Gtk::TreeModel::const_iterator(model, iter) );
  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
  #endif //GLIBMM_EXCEPTIONS_ENABLED

  return FALSE; //An arbitary default, just to avoid the compiler warning.
}

static void SignalProxy_Visible_gtk_callback_destroy(void* data)
{
  delete static_cast<Gtk::TreeModelFilter::SlotVisible*>(data);
}


static void SignalProxy_Modify_gtk_callback(GtkTreeModel* model, GtkTreeIter* iter, GValue* value, gint column, gpointer data)
{
  Gtk::TreeModelFilter::SlotModify* the_slot = static_cast<Gtk::TreeModelFilter::SlotModify*>(data);

  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  try
  {
  #endif //GLIBMM_EXCEPTIONS_ENABLED
    //Initialize the input parameter with the appropriate type for this column.
    //Then the C++ handler can just use operator==() without calling init on the value output arg:
    Glib::ValueBase cppValue;
    GType column_type = gtk_tree_model_get_column_type(model, column);
    cppValue.init(column_type);
    
    (*the_slot)( Gtk::TreeModel::const_iterator(model, iter), cppValue, column );

    //GTK+ has already done this for us: g_value_init(value, column_type);

    //If the C++ handler has inited value with an inappropriate GType, then this will fail,
    //but they should not do that because it makes no sense.
    g_value_copy(cppValue.gobj() /* source */, value /* destination */);
  #ifdef GLIBMM_EXCEPTIONS_ENABLED  
  }
  catch(...)
  {
    Glib::exception_handlers_invoke();
  }
  #endif //GLIBMM_EXCEPTIONS_ENABLED
}

static void SignalProxy_Modify_gtk_callback_destroy(void* data)
{
  delete static_cast<Gtk::TreeModelFilter::SlotModify*>(data);
}


typedef Gtk::TreeModel::Path Path; //So that the generated method implemenations can use this a return type.

namespace Gtk
{

TreeModelFilter::TreeModelFilter(const Glib::RefPtr<TreeModel>& child_model)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(treemodelfilter_class_.init(), "child_model",child_model->gobj(), static_cast<char*>(0)))
{
}

TreeModelFilter::TreeModelFilter(const Glib::RefPtr<TreeModel>& child_model, const TreeModel::Path& virtual_root)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(treemodelfilter_class_.init(), "child_model",child_model->gobj(),"virtual_root",(virtual_root.empty() ? 0 : const_cast<GtkTreePath*>((virtual_root).gobj())) , static_cast<char*>(0)))
{
}

void TreeModelFilter::set_visible_func(const SlotVisible& slot)
{
  // Create a copy of the slot.  A pointer to this will be passed
  // through the callback's data parameter.  It will be deleted
  // when SignalProxy_Visible_gtk_callback_destroy() is called.
  SlotVisible* slot_copy = new SlotVisible(slot);

  gtk_tree_model_filter_set_visible_func(gobj(),
      &SignalProxy_Visible_gtk_callback, slot_copy,
      &SignalProxy_Visible_gtk_callback_destroy);
}


TreeModel::iterator TreeModelFilter::convert_child_iter_to_iter(const iterator& child_iter) const
{
  TreeIter filter_iter (const_cast<TreeModelFilter*>(this));

  gtk_tree_model_filter_convert_child_iter_to_iter(
      const_cast<GtkTreeModelFilter*>(gobj()), filter_iter.gobj(),
      const_cast<GtkTreeIter*>(child_iter.gobj()));

  return filter_iter;
}

TreeModel::iterator TreeModelFilter::convert_iter_to_child_iter(const iterator& filter_iter) const
{
  GtkTreeModel *const child_model = gtk_tree_model_filter_get_model(const_cast<GtkTreeModelFilter*>(gobj()));

  TreeIter child_iter (dynamic_cast<TreeModel*>(Glib::wrap_auto((GObject*) child_model, false)));

  gtk_tree_model_filter_convert_iter_to_child_iter(
      const_cast<GtkTreeModelFilter*>(gobj()), child_iter.gobj(),
      const_cast<GtkTreeIter*>(filter_iter.gobj()));

  return child_iter;
}

void TreeModelFilter::set_modify_func(const TreeModelColumnRecord& columns, const SlotModify& slot)
{
  // Create a copy of the slot.  A pointer to this will be passed
  // through the callback's data parameter.  It will be deleted
  // when SignalProxy_Modify_gtk_callback_destroy() is called.
  SlotModify* slot_copy = new SlotModify(slot);

  gtk_tree_model_filter_set_modify_func(gobj(),
    columns.size(), const_cast<GType*>(columns.types()),
    &SignalProxy_Modify_gtk_callback, slot_copy,
    &SignalProxy_Modify_gtk_callback_destroy);
}

void TreeModelFilter::set_value_impl(const iterator& /* row */, int /* column */, const Glib::ValueBase& /* value */)
{
  g_warning("Attempt to set a value of a row in a TreeModelFilter instead of in the child model.");
}


} // namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gtk::TreeModelFilter> wrap(GtkTreeModelFilter* object, bool take_copy)
{
  return Glib::RefPtr<Gtk::TreeModelFilter>( dynamic_cast<Gtk::TreeModelFilter*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& TreeModelFilter_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &TreeModelFilter_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_tree_model_filter_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  TreeModel::add_interface(get_type());

  }

  return *this;
}

void TreeModelFilter_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
}

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


Glib::ObjectBase* TreeModelFilter_Class::wrap_new(GObject* object)
{
  return new TreeModelFilter((GtkTreeModelFilter*)object);
}


/* The implementation: */

GtkTreeModelFilter* TreeModelFilter::gobj_copy()
{
  reference();
  return gobj();
}

TreeModelFilter::TreeModelFilter(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

TreeModelFilter::TreeModelFilter(GtkTreeModelFilter* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


TreeModelFilter::~TreeModelFilter()
{}


TreeModelFilter::CppClassType TreeModelFilter::treemodelfilter_class_; // initialize static member

GType TreeModelFilter::get_type()
{
  return treemodelfilter_class_.init().get_type();
}

GType TreeModelFilter::get_base_type()
{
  return gtk_tree_model_filter_get_type();
}


Glib::RefPtr<TreeModelFilter> TreeModelFilter::create(const Glib::RefPtr<TreeModel>& child_model)
{
  return Glib::RefPtr<TreeModelFilter>( new TreeModelFilter(child_model) );
}
Glib::RefPtr<TreeModelFilter> TreeModelFilter::create(const Glib::RefPtr<TreeModel>& child_model, const TreeModel::Path& virtual_root)
{
  return Glib::RefPtr<TreeModelFilter>( new TreeModelFilter(child_model, virtual_root) );
}
void TreeModelFilter::set_visible_column(const TreeModelColumnBase& column)
{
gtk_tree_model_filter_set_visible_column(gobj(), (column).index()); 
}

void TreeModelFilter::set_visible_column(int column)
{
gtk_tree_model_filter_set_visible_column(gobj(), column); 
}

Glib::RefPtr<TreeModel> TreeModelFilter::get_model()
{

  Glib::RefPtr<TreeModel> retvalue = Glib::wrap(gtk_tree_model_filter_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;

}

Glib::RefPtr<const TreeModel> TreeModelFilter::get_model() const
{
  return const_cast<TreeModelFilter*>(this)->get_model();
}

#ifndef GTKMM_DISABLE_DEPRECATED

Path TreeModelFilter::convert_child_path_to_path(const Path& child_path)
{
  return Gtk::TreePath(gtk_tree_model_filter_convert_child_path_to_path(gobj(), const_cast<GtkTreePath*>((child_path).gobj())), false);
}

#endif // GTKMM_DISABLE_DEPRECATED

#ifndef GTKMM_DISABLE_DEPRECATED

Path TreeModelFilter::convert_path_to_child_path(const Path& filter_path)
{
  return Gtk::TreePath(gtk_tree_model_filter_convert_path_to_child_path(gobj(), const_cast<GtkTreePath*>((filter_path).gobj())), false);
}

#endif // GTKMM_DISABLE_DEPRECATED

Path TreeModelFilter::convert_child_path_to_path(const Path& child_path) const
{
  return Gtk::TreePath(gtk_tree_model_filter_convert_child_path_to_path(const_cast<GtkTreeModelFilter*>(gobj()), const_cast<GtkTreePath*>((child_path).gobj())), false);
}

Path TreeModelFilter::convert_path_to_child_path(const Path& filter_path) const
{
  return Gtk::TreePath(gtk_tree_model_filter_convert_path_to_child_path(const_cast<GtkTreeModelFilter*>(gobj()), const_cast<GtkTreePath*>((filter_path).gobj())), false);
}

void TreeModelFilter::refilter()
{
gtk_tree_model_filter_refilter(gobj()); 
}

void TreeModelFilter::clear_cache()
{
gtk_tree_model_filter_clear_cache(gobj()); 
}


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gtk


