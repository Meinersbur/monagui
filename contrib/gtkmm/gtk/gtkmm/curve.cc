// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtkmm/curve.h>
#include <gtkmm/private/curve_p.h>

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

#include <gtk/gtkcurve.h>
#include <gtk/gtkgamma.h>

namespace Gtk
{

Glib::ArrayHandle<float> Curve::get_vector(int veclen) const
{
  float *const pdata = static_cast<float*>(g_malloc(veclen * sizeof(float)));
  gtk_curve_get_vector(const_cast<GtkCurve*>(gobj()), veclen, pdata);

  return Glib::ArrayHandle<float>(pdata, veclen, Glib::OWNERSHIP_SHALLOW);
}

void Curve::set_vector(const Glib::ArrayHandle<float>& array)
{
  gtk_curve_set_vector(gobj(), array.size(), const_cast<float*>(array.data()));
}

} /* namespace Gtk */


namespace
{


static const Glib::SignalProxyInfo Curve_signal_curve_type_changed_info =
{
  "curve_type_changed",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

Gtk::Curve* wrap(GtkCurve* object, bool take_copy)
{
  return dynamic_cast<Gtk::Curve *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& Curve_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Curve_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_curve_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void Curve_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  klass->curve_type_changed = &curve_type_changed_callback;
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
}

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void Curve_Class::curve_type_changed_callback(GtkCurve* self)
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
        obj->on_curve_type_changed();
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
  if(base && base->curve_type_changed)
    (*base->curve_type_changed)(self);
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


Glib::ObjectBase* Curve_Class::wrap_new(GObject* o)
{
  return manage(new Curve((GtkCurve*)(o)));

}


/* The implementation: */

Curve::Curve(const Glib::ConstructParams& construct_params)
:
  Gtk::DrawingArea(construct_params)
{
  }

Curve::Curve(GtkCurve* castitem)
:
  Gtk::DrawingArea((GtkDrawingArea*)(castitem))
{
  }

Curve::~Curve()
{
  destroy_();
}

Curve::CppClassType Curve::curve_class_; // initialize static member

GType Curve::get_type()
{
  return curve_class_.init().get_type();
}

GType Curve::get_base_type()
{
  return gtk_curve_get_type();
}


Curve::Curve()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::DrawingArea(Glib::ConstructParams(curve_class_.init()))
{
  

}

void Curve::reset()
{
gtk_curve_reset(gobj()); 
}

void Curve::set_gamma(float gamma)
{
gtk_curve_set_gamma(gobj(), gamma); 
}

void Curve::set_range(float min_x, float max_x, float min_y, float max_y)
{
gtk_curve_set_range(gobj(), min_x, max_x, min_y, max_y); 
}

void Curve::get_vector(int veclen, float* data) const
{
gtk_curve_get_vector(const_cast<GtkCurve*>(gobj()), veclen, data); 
}

void Curve::set_curve_type(CurveType type)
{
gtk_curve_set_curve_type(gobj(), ((GtkCurveType)(type))); 
}


Glib::SignalProxy0< void > Curve::signal_curve_type_changed()
{
  return Glib::SignalProxy0< void >(this, &Curve_signal_curve_type_changed_info);
}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<CurveType> Curve::property_curve_type() 
{
  return Glib::PropertyProxy<CurveType>(this, "curve-type");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<CurveType> Curve::property_curve_type() const
{
  return Glib::PropertyProxy_ReadOnly<CurveType>(this, "curve-type");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<float> Curve::property_min_x() 
{
  return Glib::PropertyProxy<float>(this, "min-x");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<float> Curve::property_min_x() const
{
  return Glib::PropertyProxy_ReadOnly<float>(this, "min-x");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<float> Curve::property_max_x() 
{
  return Glib::PropertyProxy<float>(this, "max-x");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<float> Curve::property_max_x() const
{
  return Glib::PropertyProxy_ReadOnly<float>(this, "max-x");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<float> Curve::property_min_y() 
{
  return Glib::PropertyProxy<float>(this, "min-y");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<float> Curve::property_min_y() const
{
  return Glib::PropertyProxy_ReadOnly<float>(this, "min-y");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<float> Curve::property_max_y() 
{
  return Glib::PropertyProxy<float>(this, "max-y");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<float> Curve::property_max_y() const
{
  return Glib::PropertyProxy_ReadOnly<float>(this, "max-y");
}
#endif //GLIBMM_PROPERTIES_ENABLED


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void Gtk::Curve::on_curve_type_changed()
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->curve_type_changed)
    (*base->curve_type_changed)(gobj());
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gtk


namespace Glib
{

Gtk::GammaCurve* wrap(GtkGammaCurve* object, bool take_copy)
{
  return dynamic_cast<Gtk::GammaCurve *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& GammaCurve_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &GammaCurve_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_gamma_curve_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void GammaCurve_Class::class_init_function(void* g_class, void* class_data)
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


Glib::ObjectBase* GammaCurve_Class::wrap_new(GObject* o)
{
  return manage(new GammaCurve((GtkGammaCurve*)(o)));

}


/* The implementation: */

GammaCurve::GammaCurve(const Glib::ConstructParams& construct_params)
:
  Gtk::VBox(construct_params)
{
  }

GammaCurve::GammaCurve(GtkGammaCurve* castitem)
:
  Gtk::VBox((GtkVBox*)(castitem))
{
  }

GammaCurve::~GammaCurve()
{
  destroy_();
}

GammaCurve::CppClassType GammaCurve::gammacurve_class_; // initialize static member

GType GammaCurve::get_type()
{
  return gammacurve_class_.init().get_type();
}

GType GammaCurve::get_base_type()
{
  return gtk_gamma_curve_get_type();
}

GammaCurve::GammaCurve()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::VBox(Glib::ConstructParams(gammacurve_class_.init()))
{
  

}


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gtk


