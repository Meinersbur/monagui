// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtkmm/cellrendererpixbuf.h>
#include <gtkmm/private/cellrendererpixbuf_p.h>

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
#include <gtk/gtkcellrendererpixbuf.h>

namespace Gtk
{

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_Base CellRendererPixbuf::_property_renderable()
{
  return property_pixbuf();
}
#else
Glib::ustring CellRendererPixbuf::_property_renderable()
{
  return "pixbuf";
}
#endif //GLIBMM_PROPERTIES_ENABLED

} //namespace Gtk

namespace
{
} // anonymous namespace


namespace Glib
{

Gtk::CellRendererPixbuf* wrap(GtkCellRendererPixbuf* object, bool take_copy)
{
  return dynamic_cast<Gtk::CellRendererPixbuf *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& CellRendererPixbuf_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &CellRendererPixbuf_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_cell_renderer_pixbuf_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void CellRendererPixbuf_Class::class_init_function(void* g_class, void* class_data)
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


Glib::ObjectBase* CellRendererPixbuf_Class::wrap_new(GObject* o)
{
  return manage(new CellRendererPixbuf((GtkCellRendererPixbuf*)(o)));

}


/* The implementation: */

CellRendererPixbuf::CellRendererPixbuf(const Glib::ConstructParams& construct_params)
:
  Gtk::CellRenderer(construct_params)
{
  }

CellRendererPixbuf::CellRendererPixbuf(GtkCellRendererPixbuf* castitem)
:
  Gtk::CellRenderer((GtkCellRenderer*)(castitem))
{
  }

CellRendererPixbuf::~CellRendererPixbuf()
{
  destroy_();
}

CellRendererPixbuf::CppClassType CellRendererPixbuf::cellrendererpixbuf_class_; // initialize static member

GType CellRendererPixbuf::get_type()
{
  return cellrendererpixbuf_class_.init().get_type();
}

GType CellRendererPixbuf::get_base_type()
{
  return gtk_cell_renderer_pixbuf_get_type();
}


CellRendererPixbuf::CellRendererPixbuf()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::CellRenderer(Glib::ConstructParams(cellrendererpixbuf_class_.init()))
{
  

}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixbuf> > CellRendererPixbuf::property_pixbuf() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixbuf> >(this, "pixbuf");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixbuf> > CellRendererPixbuf::property_pixbuf() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixbuf> >(this, "pixbuf");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixbuf> > CellRendererPixbuf::property_pixbuf_expander_open() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixbuf> >(this, "pixbuf-expander-open");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixbuf> > CellRendererPixbuf::property_pixbuf_expander_open() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixbuf> >(this, "pixbuf-expander-open");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixbuf> > CellRendererPixbuf::property_pixbuf_expander_closed() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixbuf> >(this, "pixbuf-expander-closed");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixbuf> > CellRendererPixbuf::property_pixbuf_expander_closed() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixbuf> >(this, "pixbuf-expander-closed");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<Glib::ustring> CellRendererPixbuf::property_stock_id() 
{
  return Glib::PropertyProxy<Glib::ustring>(this, "stock-id");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<Glib::ustring> CellRendererPixbuf::property_stock_id() const
{
  return Glib::PropertyProxy_ReadOnly<Glib::ustring>(this, "stock-id");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<guint> CellRendererPixbuf::property_stock_size() 
{
  return Glib::PropertyProxy<guint>(this, "stock-size");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<guint> CellRendererPixbuf::property_stock_size() const
{
  return Glib::PropertyProxy_ReadOnly<guint>(this, "stock-size");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<Glib::ustring> CellRendererPixbuf::property_stock_detail() 
{
  return Glib::PropertyProxy<Glib::ustring>(this, "stock-detail");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<Glib::ustring> CellRendererPixbuf::property_stock_detail() const
{
  return Glib::PropertyProxy_ReadOnly<Glib::ustring>(this, "stock-detail");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< Glib::RefPtr<Gio::Icon> > CellRendererPixbuf::property_gicon() 
{
  return Glib::PropertyProxy< Glib::RefPtr<Gio::Icon> >(this, "gicon");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::Icon> > CellRendererPixbuf::property_gicon() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gio::Icon> >(this, "gicon");
}
#endif //GLIBMM_PROPERTIES_ENABLED


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gtk

