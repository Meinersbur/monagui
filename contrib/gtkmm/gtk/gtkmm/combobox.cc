// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtkmm/combobox.h>
#include <gtkmm/private/combobox_p.h>

// -*- c++ -*-
/* $Id: combobox.ccg,v 1.9 2006/05/10 20:59:27 murrayc Exp $ */

/* 
 *
 * Copyright 2003 The gtkmm Development Team
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

#include <gtkmm/liststore.h>
#include <gtkmm/cellrenderertext.h>
#include <gtkmm/treeview_private.h> //For SignalProxy_RowSeparator.
#include <gtk/gtkcombobox.h>
#include <gtk/gtkcelllayout.h>

namespace Gtk
{

void ComboBox::unset_active()
{
  gtk_combo_box_set_active(gobj(), -1 /* see GTK+ docs */);
}

TreeModel::iterator ComboBox::get_active()
{
  Gtk::TreeModel::iterator iter;

  Glib::RefPtr<Gtk::TreeModel> model = get_model();
  if(model)
  {
    gtk_combo_box_get_active_iter(gobj(), iter.gobj());

    //It must be given the model, because the C++ wrapper has extra information.
    iter.set_model_gobject(model->gobj());
  }
  
  return iter;
}

TreeModel::const_iterator ComboBox::get_active() const
{
  Gtk::TreeModel::iterator iter;

  Glib::RefPtr<const Gtk::TreeModel> model = get_model();
  if(model)
  {
    gtk_combo_box_get_active_iter(const_cast<GtkComboBox*>(gobj()), iter.gobj());

    //It must be given the model, because the C++ wrapper has extra information.
    iter.set_model_gobject(const_cast<GtkTreeModel*>(model->gobj()));
  }

  return iter;
}


void ComboBox::unset_model()
{
  gtk_combo_box_set_model(gobj(), 0);
}


void ComboBox::set_row_separator_func(const SlotRowSeparator& slot)
{
  //Create a copy of the slot. A pointer to this will be passed through the callback's data parameter.
  //It will be deleted when SignalProxy_RowSeparator_gtk_callback_destroy() is called.
  SlotRowSeparator* slot_copy = new SlotRowSeparator(slot);

  gtk_combo_box_set_row_separator_func(gobj(),
      &TreeView_Private::SignalProxy_RowSeparator_gtk_callback, slot_copy,
      &TreeView_Private::SignalProxy_RowSeparator_gtk_callback_destroy);
}

void ComboBox::unset_row_separator_func()
{
  gtk_combo_box_set_row_separator_func(gobj(), 0, 0, 0 /* See C docs. */);
}

} // namespace Gtk


namespace
{


static const Glib::SignalProxyInfo ComboBox_signal_changed_info =
{
  "changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

Gtk::ComboBox* wrap(GtkComboBox* object, bool take_copy)
{
  return dynamic_cast<Gtk::ComboBox *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& ComboBox_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ComboBox_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_combo_box_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  CellLayout::add_interface(get_type());

  }

  return *this;
}

void ComboBox_Class::class_init_function(void* g_class, void* class_data)
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
void ComboBox_Class::changed_callback(GtkComboBox* self)
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


Glib::ObjectBase* ComboBox_Class::wrap_new(GObject* o)
{
  return manage(new ComboBox((GtkComboBox*)(o)));

}


/* The implementation: */

ComboBox::ComboBox(const Glib::ConstructParams& construct_params)
:
  Gtk::Bin(construct_params)
{
  }

ComboBox::ComboBox(GtkComboBox* castitem)
:
  Gtk::Bin((GtkBin*)(castitem))
{
  }

ComboBox::~ComboBox()
{
  destroy_();
}

ComboBox::CppClassType ComboBox::combobox_class_; // initialize static member

GType ComboBox::get_type()
{
  return combobox_class_.init().get_type();
}

GType ComboBox::get_base_type()
{
  return gtk_combo_box_get_type();
}


ComboBox::ComboBox()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Bin(Glib::ConstructParams(combobox_class_.init()))
{
  

}

ComboBox::ComboBox(const Glib::RefPtr<TreeModel>& model)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Bin(Glib::ConstructParams(combobox_class_.init(), "model", Glib::unwrap(model), static_cast<char*>(0)))
{
  

}

void ComboBox::set_wrap_width(int width)
{
gtk_combo_box_set_wrap_width(gobj(), width); 
}

int ComboBox::get_wrap_width() const
{
  return gtk_combo_box_get_wrap_width(const_cast<GtkComboBox*>(gobj()));
}

void ComboBox::set_row_span_column(int row_span)
{
gtk_combo_box_set_row_span_column(gobj(), row_span); 
}

int ComboBox::get_row_span_column() const
{
  return gtk_combo_box_get_row_span_column(const_cast<GtkComboBox*>(gobj()));
}

void ComboBox::set_column_span_column(int column_span)
{
gtk_combo_box_set_column_span_column(gobj(), column_span); 
}

int ComboBox::get_column_span_column() const
{
  return gtk_combo_box_get_column_span_column(const_cast<GtkComboBox*>(gobj()));
}

bool ComboBox::get_add_tearoffs() const
{
  return gtk_combo_box_get_add_tearoffs(const_cast<GtkComboBox*>(gobj()));
}

void ComboBox::set_add_tearoffs(bool add_tearoffs)
{
gtk_combo_box_set_add_tearoffs(gobj(), static_cast<int>(add_tearoffs)); 
}

Glib::ustring ComboBox::get_title() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(gtk_combo_box_get_title(const_cast<GtkComboBox*>(gobj())));
}

void ComboBox::set_title(const Glib::ustring& title)
{
gtk_combo_box_set_title(gobj(), title.c_str()); 
}

bool ComboBox::get_focus_on_click() const
{
  return gtk_combo_box_get_focus_on_click(const_cast<GtkComboBox*>(gobj()));
}

void ComboBox::set_focus_on_click(bool focus_on_click)
{
gtk_combo_box_set_focus_on_click(gobj(), static_cast<int>(focus_on_click)); 
}

int ComboBox::get_active_row_number() const
{
  return gtk_combo_box_get_active(const_cast<GtkComboBox*>(gobj()));
}

void ComboBox::set_active(int index)
{
gtk_combo_box_set_active(gobj(), index); 
}

void ComboBox::set_active(const TreeModel::iterator& iter)
{
gtk_combo_box_set_active_iter(gobj(), const_cast<GtkTreeIter*>((iter).gobj())); 
}

Glib::RefPtr<TreeModel> ComboBox::get_model()
{

  Glib::RefPtr<TreeModel> retvalue = Glib::wrap(gtk_combo_box_get_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;

}

Glib::RefPtr<const TreeModel> ComboBox::get_model() const
{
  return const_cast<ComboBox*>(this)->get_model();
}

void ComboBox::set_model(const Glib::RefPtr<TreeModel>& model)
{
gtk_combo_box_set_model(gobj(), Glib::unwrap(model)); 
}

void ComboBox::set_button_sensitivity(SensitivityType sensitivity)
{
gtk_combo_box_set_button_sensitivity(gobj(), ((GtkSensitivityType)(sensitivity))); 
}

SensitivityType ComboBox::get_button_sensitivity() const
{
  return ((SensitivityType)(gtk_combo_box_get_button_sensitivity(const_cast<GtkComboBox*>(gobj()))));
}

void ComboBox::popup()
{
gtk_combo_box_popup(gobj()); 
}

void ComboBox::popdown()
{
gtk_combo_box_popdown(gobj()); 
}

#ifdef GTKMM_ATKMM_ENABLED
Glib::RefPtr<Atk::Object> ComboBox::get_popup_accessible()
{
  return Glib::wrap(gtk_combo_box_get_popup_accessible(gobj()));
}


#endif // GTKMM_ATKMM_ENABLED
#ifdef GTKMM_ATKMM_ENABLED
Glib::RefPtr<const Atk::Object> ComboBox::get_popup_accessible() const
{
  return const_cast<ComboBox*>(this)->get_popup_accessible();
}


#endif // GTKMM_ATKMM_ENABLED


Glib::SignalProxy0< void > ComboBox::signal_changed()
{
  return Glib::SignalProxy0< void >(this, &ComboBox_signal_changed_info);
}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< Glib::RefPtr<TreeModel> > ComboBox::property_model() 
{
  return Glib::PropertyProxy< Glib::RefPtr<TreeModel> >(this, "model");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> > ComboBox::property_model() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<TreeModel> >(this, "model");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<int> ComboBox::property_wrap_width() 
{
  return Glib::PropertyProxy<int>(this, "wrap-width");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<int> ComboBox::property_wrap_width() const
{
  return Glib::PropertyProxy_ReadOnly<int>(this, "wrap-width");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<int> ComboBox::property_row_span_column() 
{
  return Glib::PropertyProxy<int>(this, "row-span-column");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<int> ComboBox::property_row_span_column() const
{
  return Glib::PropertyProxy_ReadOnly<int>(this, "row-span-column");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<int> ComboBox::property_column_span_column() 
{
  return Glib::PropertyProxy<int>(this, "column-span-column");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<int> ComboBox::property_column_span_column() const
{
  return Glib::PropertyProxy_ReadOnly<int>(this, "column-span-column");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<int> ComboBox::property_active() 
{
  return Glib::PropertyProxy<int>(this, "active");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<int> ComboBox::property_active() const
{
  return Glib::PropertyProxy_ReadOnly<int>(this, "active");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> ComboBox::property_add_tearoffs() 
{
  return Glib::PropertyProxy<bool>(this, "add-tearoffs");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> ComboBox::property_add_tearoffs() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "add-tearoffs");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> ComboBox::property_has_frame() 
{
  return Glib::PropertyProxy<bool>(this, "has-frame");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> ComboBox::property_has_frame() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "has-frame");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> ComboBox::property_focus_on_click() 
{
  return Glib::PropertyProxy<bool>(this, "focus-on-click");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> ComboBox::property_focus_on_click() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "focus-on-click");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<Glib::ustring> ComboBox::property_tearoff_title() 
{
  return Glib::PropertyProxy<Glib::ustring>(this, "tearoff-title");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<Glib::ustring> ComboBox::property_tearoff_title() const
{
  return Glib::PropertyProxy_ReadOnly<Glib::ustring>(this, "tearoff-title");
}
#endif //GLIBMM_PROPERTIES_ENABLED


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void Gtk::ComboBox::on_changed()
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


