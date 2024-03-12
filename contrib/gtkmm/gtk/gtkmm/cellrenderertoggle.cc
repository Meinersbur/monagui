// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtkmm/cellrenderertoggle.h>
#include <gtkmm/private/cellrenderertoggle_p.h>

// -*- c++ -*-
/* $Id$ */

/* 
 *
 * Copyright 1998-2002 The gtkmm Development Team
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

#include <gtk/gtkcellrenderertoggle.h>

namespace Gtk
{

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_Base CellRendererToggle::_property_renderable()
{
  return property_active();
}
#else
Glib::ustring CellRendererToggle::_property_renderable()
{
  return "active";
}
#endif //#GLIBMM_PROPERTIES_ENABLED

} //namespace Gtk

namespace
{


static void CellRendererToggle_signal_toggled_callback(GtkCellRendererToggle* self, const gchar* p0,void* data)
{
  using namespace Gtk;
  typedef sigc::slot< void,const Glib::ustring& > SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
    #endif //GLIBMM_EXCEPTIONS_ENABLED
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::convert_const_gchar_ptr_to_ustring(p0)
);
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
    #endif //GLIBMM_EXCEPTIONS_ENABLED
  }
}

static const Glib::SignalProxyInfo CellRendererToggle_signal_toggled_info =
{
  "toggled",
  (GCallback) &CellRendererToggle_signal_toggled_callback,
  (GCallback) &CellRendererToggle_signal_toggled_callback
};


} // anonymous namespace


namespace Glib
{

Gtk::CellRendererToggle* wrap(GtkCellRendererToggle* object, bool take_copy)
{
  return dynamic_cast<Gtk::CellRendererToggle *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& CellRendererToggle_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CellRendererToggle_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_cell_renderer_toggle_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void CellRendererToggle_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  klass->toggled = &toggled_callback;
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
}

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void CellRendererToggle_Class::toggled_callback(GtkCellRendererToggle* self, const gchar* p0)
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
        obj->on_toggled(Glib::convert_const_gchar_ptr_to_ustring(p0)
);
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
  if(base && base->toggled)
    (*base->toggled)(self, p0);
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


Glib::ObjectBase* CellRendererToggle_Class::wrap_new(GObject* o)
{
  return manage(new CellRendererToggle((GtkCellRendererToggle*)(o)));

}


/* The implementation: */

CellRendererToggle::CellRendererToggle(const Glib::ConstructParams& construct_params)
:
  Gtk::CellRenderer(construct_params)
{
  }

CellRendererToggle::CellRendererToggle(GtkCellRendererToggle* castitem)
:
  Gtk::CellRenderer((GtkCellRenderer*)(castitem))
{
  }

CellRendererToggle::~CellRendererToggle()
{
  destroy_();
}

CellRendererToggle::CppClassType CellRendererToggle::cellrenderertoggle_class_; // initialize static member

GType CellRendererToggle::get_type()
{
  return cellrenderertoggle_class_.init().get_type();
}

GType CellRendererToggle::get_base_type()
{
  return gtk_cell_renderer_toggle_get_type();
}


CellRendererToggle::CellRendererToggle()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::CellRenderer(Glib::ConstructParams(cellrenderertoggle_class_.init()))
{
  

}

bool CellRendererToggle::get_radio() const
{
  return gtk_cell_renderer_toggle_get_radio(const_cast<GtkCellRendererToggle*>(gobj()));
}

void CellRendererToggle::set_radio(bool radio)
{
gtk_cell_renderer_toggle_set_radio(gobj(), static_cast<int>(radio)); 
}

bool CellRendererToggle::get_active() const
{
  return gtk_cell_renderer_toggle_get_active(const_cast<GtkCellRendererToggle*>(gobj()));
}

void CellRendererToggle::set_active(bool setting)
{
gtk_cell_renderer_toggle_set_active(gobj(), static_cast<int>(setting)); 
}


Glib::SignalProxy1< void,const Glib::ustring& > CellRendererToggle::signal_toggled()
{
  return Glib::SignalProxy1< void,const Glib::ustring& >(this, &CellRendererToggle_signal_toggled_info);
}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> CellRendererToggle::property_activatable() 
{
  return Glib::PropertyProxy<bool>(this, "activatable");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> CellRendererToggle::property_activatable() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "activatable");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> CellRendererToggle::property_active() 
{
  return Glib::PropertyProxy<bool>(this, "active");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> CellRendererToggle::property_active() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "active");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> CellRendererToggle::property_radio() 
{
  return Glib::PropertyProxy<bool>(this, "radio");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> CellRendererToggle::property_radio() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "radio");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<int> CellRendererToggle::property_indicator_size() 
{
  return Glib::PropertyProxy<int>(this, "indicator-size");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<int> CellRendererToggle::property_indicator_size() const
{
  return Glib::PropertyProxy_ReadOnly<int>(this, "indicator-size");
}
#endif //GLIBMM_PROPERTIES_ENABLED


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void Gtk::CellRendererToggle::on_toggled(const Glib::ustring& path)
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->toggled)
    (*base->toggled)(gobj(),path.c_str());
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gtk


