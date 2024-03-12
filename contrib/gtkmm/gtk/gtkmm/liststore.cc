// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtkmm/liststore.h>
#include <gtkmm/private/liststore_p.h>

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

#include <gtk/gtkliststore.h>


namespace Gtk
{

ListStore::ListStore(const TreeModelColumnRecord& columns)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(liststore_class_.init()))
{
  gtk_list_store_set_column_types(gobj(), columns.size(), const_cast<GType*>(columns.types()));
}

void ListStore::set_column_types(const TreeModelColumnRecord& columns)
{
   gtk_list_store_set_column_types(gobj(), columns.size(), const_cast<GType*>(columns.types()));
}
  

TreeModel::iterator ListStore::erase(const iterator& iter)
{
  g_assert(iter.get_gobject_if_not_end() != 0);

  iterator next(iter);
  ++next;

  GtkTreeIter tmp = *iter.gobj();
  gtk_list_store_remove(gobj(), &tmp);

  return next;
}

TreeModel::iterator ListStore::insert(const iterator& iter)
{
  iterator new_pos(this);

  // get_gobject_if_not_end() returns 0 if iter is an end iterator, which
  // is in turn interpreted by gtk_list_store_insert_before() as a request to
  // insert at the end of the list.

  gtk_list_store_insert_before(
      gobj(), new_pos.gobj(),
      const_cast<GtkTreeIter*>(iter.get_gobject_if_not_end()));

  // GtkTreeIter::stamp should always have a value if it's valid.
  // For end iterators, we need to remember the iter's parent, and
  // this is what setup_end_iterator() does.

  if(new_pos.gobj()->stamp == 0)
    new_pos.setup_end_iterator(iter);

  return new_pos;
}

TreeModel::iterator ListStore::insert_after(const iterator& iter)
{
  iterator new_pos(this);

  // get_gobject_if_not_end() returns 0 if iter is an end iterator, which
  // is in turn interpreted by gtk_list_store_insert_after() as a request to
  // insert at the beginning of the list.

  gtk_list_store_insert_after(
      gobj(), new_pos.gobj(),
      const_cast<GtkTreeIter*>(iter.get_gobject_if_not_end()));

  // GtkTreeIter::stamp should always have a value if it's valid.
  // For end iterators, we need to remember the iter's parent, and
  // this is what setup_end_iterator() does.

  if(new_pos.gobj()->stamp == 0)
    new_pos.setup_end_iterator(iter);

  return new_pos;
}

TreeModel::iterator ListStore::prepend()
{
  iterator new_pos(this);
  gtk_list_store_prepend(gobj(), new_pos.gobj());
  return new_pos;
}

TreeModel::iterator ListStore::append()
{
  iterator new_pos(this);
  gtk_list_store_append(gobj(), new_pos.gobj());
  return new_pos;
}

void ListStore::move(const iterator& source, const iterator& destination)
{
  gtk_list_store_move_before(gobj(),
      const_cast<GtkTreeIter*>(source.get_gobject_if_not_end()),
      const_cast<GtkTreeIter*>(destination.get_gobject_if_not_end()));
}

void ListStore::reorder(const Glib::ArrayHandle<int>& new_order)
{
  gtk_list_store_reorder(gobj(), const_cast<int*>(new_order.data()));
}

void ListStore::set_value_impl(const iterator& row, int column, const Glib::ValueBase& value)
{
  gtk_list_store_set_value(
      gobj(), const_cast<GtkTreeIter*>(row.gobj()),
      column, const_cast<GValue*>(value.gobj()));
}

} // namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gtk::ListStore> wrap(GtkListStore* object, bool take_copy)
{
  return Glib::RefPtr<Gtk::ListStore>( dynamic_cast<Gtk::ListStore*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& ListStore_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ListStore_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_list_store_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  TreeModel::add_interface(get_type());
  TreeSortable::add_interface(get_type());
  TreeDragSource::add_interface(get_type());
  TreeDragDest::add_interface(get_type());

  }

  return *this;
}

void ListStore_Class::class_init_function(void* g_class, void* class_data)
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


Glib::ObjectBase* ListStore_Class::wrap_new(GObject* object)
{
  return new ListStore((GtkListStore*)object);
}


/* The implementation: */

GtkListStore* ListStore::gobj_copy()
{
  reference();
  return gobj();
}

ListStore::ListStore(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

ListStore::ListStore(GtkListStore* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


ListStore::~ListStore()
{}


ListStore::CppClassType ListStore::liststore_class_; // initialize static member

GType ListStore::get_type()
{
  return liststore_class_.init().get_type();
}

GType ListStore::get_base_type()
{
  return gtk_list_store_get_type();
}


ListStore::ListStore()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(liststore_class_.init()))
{
  

}

Glib::RefPtr<ListStore> ListStore::create(const TreeModelColumnRecord& columns)
{
  return Glib::RefPtr<ListStore>( new ListStore(columns) );
}
void ListStore::iter_swap(const iterator& a, const iterator& b)
{
gtk_list_store_swap(gobj(), const_cast<GtkTreeIter*>((a).gobj()), const_cast<GtkTreeIter*>((b).gobj())); 
}

void ListStore::clear()
{
gtk_list_store_clear(gobj()); 
}

bool ListStore::iter_is_valid(const iterator& iter) const
{
  return gtk_list_store_iter_is_valid(const_cast<GtkListStore*>(gobj()), const_cast<GtkTreeIter*>((iter).gobj()));
}


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gtk

