#define Gsv gtksourceview
// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtksourceviewmm/sourcecompletioncontext.h>
#include <gtksourceviewmm/private/sourcecompletioncontext_p.h>

/* sourcecompletioncontext.cc
 *
 * Copyright (C) 2009, 2010, 2011 Krzesimir Nowak
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

#include <gtksourceview/gtksourcecompletioncontext.h>

#include <gtksourceviewmm/vectorutils.h>

namespace Gsv
{

Gtk::TextIter SourceCompletionContext::get_iter() const
{
  Gtk::TextIter iter;
  gtk_source_completion_context_get_iter(const_cast<GtkSourceCompletionContext*>(gobj()), iter.gobj());
  return iter;
}

} // namespace Gsv

namespace
{


static const Glib::SignalProxyInfo SourceCompletionContext_signal_cancelled_info =
{
  "cancelled",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gsv::SourceCompletionContext> wrap(GtkSourceCompletionContext* object, bool take_copy)
{
  return Glib::RefPtr<Gsv::SourceCompletionContext>( dynamic_cast<Gsv::SourceCompletionContext*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gsv
{


/* The *_Class implementation: */

const Glib::Class& SourceCompletionContext_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SourceCompletionContext_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_source_completion_context_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void SourceCompletionContext_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->cancelled = &cancelled_callback;
}


void SourceCompletionContext_Class::cancelled_callback(GtkSourceCompletionContext* self)
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
        obj->on_cancelled();
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
  if(base && base->cancelled)
    (*base->cancelled)(self);
}


Glib::ObjectBase* SourceCompletionContext_Class::wrap_new(GObject* object)
{
  return new SourceCompletionContext((GtkSourceCompletionContext*)object);
}


/* The implementation: */

GtkSourceCompletionContext* SourceCompletionContext::gobj_copy()
{
  reference();
  return gobj();
}

SourceCompletionContext::SourceCompletionContext(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

SourceCompletionContext::SourceCompletionContext(GtkSourceCompletionContext* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


SourceCompletionContext::~SourceCompletionContext()
{}


SourceCompletionContext::CppClassType SourceCompletionContext::sourcecompletioncontext_class_; // initialize static member

GType SourceCompletionContext::get_type()
{
  return sourcecompletioncontext_class_.init().get_type();
}


GType SourceCompletionContext::get_base_type()
{
  return gtk_source_completion_context_get_type();
}


void SourceCompletionContext::add_proposals(const Glib::RefPtr<SourceCompletionProvider>& provider, const std::vector<Glib::RefPtr<SourceCompletionProposal> >& proposals, bool finished)
{
gtk_source_completion_context_add_proposals(gobj(), Glib::unwrap(provider), Glib::ListHandler<Glib::RefPtr<SourceCompletionProposal> >::vector_to_list(proposals).data(), static_cast<int>(finished)); 
}

SourceCompletionActivation SourceCompletionContext::get_activation() const
{
  return ((SourceCompletionActivation)(gtk_source_completion_context_get_activation(const_cast<GtkSourceCompletionContext*>(gobj()))));
}


Glib::SignalProxy0< void > SourceCompletionContext::signal_cancelled()
{
  return Glib::SignalProxy0< void >(this, &SourceCompletionContext_signal_cancelled_info);
}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<SourceCompletionActivation> SourceCompletionContext::property_activation() 
{
  return Glib::PropertyProxy<SourceCompletionActivation>(this, "activation");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<SourceCompletionActivation> SourceCompletionContext::property_activation() const
{
  return Glib::PropertyProxy_ReadOnly<SourceCompletionActivation>(this, "activation");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SourceCompletion> > SourceCompletionContext::property_completion() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SourceCompletion> >(this, "completion");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<Gtk::TextIter> SourceCompletionContext::property_iter() 
{
  return Glib::PropertyProxy<Gtk::TextIter>(this, "iter");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<Gtk::TextIter> SourceCompletionContext::property_iter() const
{
  return Glib::PropertyProxy_ReadOnly<Gtk::TextIter>(this, "iter");
}
#endif //GLIBMM_PROPERTIES_ENABLED


void Gsv::SourceCompletionContext::on_cancelled()
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->cancelled)
    (*base->cancelled)(gobj());
}


} // namespace Gsv

