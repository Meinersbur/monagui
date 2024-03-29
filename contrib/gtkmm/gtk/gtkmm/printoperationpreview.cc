// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtkmm/printoperationpreview.h>
#include <gtkmm/private/printoperationpreview_p.h>

// -*- c++ -*-
/* Copyright (C) 2006 The gtkmm Development Team
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

#include <gtk/gtkprintoperationpreview.h>

namespace
{


static void PrintOperationPreview_signal_ready_callback(GtkPrintOperationPreview* self, GtkPrintContext* p0,void* data)
{
  using namespace Gtk;
  typedef sigc::slot< void,const Glib::RefPtr<PrintContext>& > SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
    #endif //GLIBMM_EXCEPTIONS_ENABLED
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
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

static const Glib::SignalProxyInfo PrintOperationPreview_signal_ready_info =
{
  "ready",
  (GCallback) &PrintOperationPreview_signal_ready_callback,
  (GCallback) &PrintOperationPreview_signal_ready_callback
};


static void PrintOperationPreview_signal_got_page_size_callback(GtkPrintOperationPreview* self, GtkPrintContext* p0,GtkPageSetup* p1,void* data)
{
  using namespace Gtk;
  typedef sigc::slot< void,const Glib::RefPtr<PrintContext>&,const Glib::RefPtr<PageSetup>& > SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
    #endif //GLIBMM_EXCEPTIONS_ENABLED
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, Glib::wrap(p1, true)
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

static const Glib::SignalProxyInfo PrintOperationPreview_signal_got_page_size_info =
{
  "got_page_size",
  (GCallback) &PrintOperationPreview_signal_got_page_size_callback,
  (GCallback) &PrintOperationPreview_signal_got_page_size_callback
};


} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gtk::PrintOperationPreview> wrap(GtkPrintOperationPreview* object, bool take_copy)
{
  return Glib::RefPtr<Gtk::PrintOperationPreview>( dynamic_cast<Gtk::PrintOperationPreview*> (Glib::wrap_auto_interface<Gtk::PrintOperationPreview> ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Interface_Class& PrintOperationPreview_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &PrintOperationPreview_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = gtk_print_operation_preview_get_type();
  }

  return *this;
}

void PrintOperationPreview_Class::iface_init_function(void* g_iface, void*)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != 0); 

#ifdef GLIBMM_VFUNCS_ENABLED
  klass->render_page = &render_page_vfunc_callback;
  klass->end_preview = &end_preview_vfunc_callback;
  klass->is_selected = &is_selected_vfunc_callback;
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  klass->ready = &ready_callback;
  klass->got_page_size = &got_page_size_callback;
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
}

#ifdef GLIBMM_VFUNCS_ENABLED
void PrintOperationPreview_Class::render_page_vfunc_callback(GtkPrintOperationPreview* self, gint page_nr)
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
        obj->render_page_vfunc(page_nr
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
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->render_page)
    (*base->render_page)(self, page_nr);

}
void PrintOperationPreview_Class::end_preview_vfunc_callback(GtkPrintOperationPreview* self)
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
        obj->end_preview_vfunc();
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
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->end_preview)
    (*base->end_preview)(self);

}
gboolean PrintOperationPreview_Class::is_selected_vfunc_callback(GtkPrintOperationPreview* self, gint page_nr)
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
        return static_cast<int>(obj->is_selected_vfunc(page_nr
));
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
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->is_selected)
    return (*base->is_selected)(self, page_nr);


  typedef gboolean RType;
  return RType();
}
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void PrintOperationPreview_Class::ready_callback(GtkPrintOperationPreview* self, GtkPrintContext* p0)
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
        obj->on_ready(Glib::wrap(p0, true)
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
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->ready)
    (*base->ready)(self, p0);
}
void PrintOperationPreview_Class::got_page_size_callback(GtkPrintOperationPreview* self, GtkPrintContext* p0, GtkPageSetup* p1)
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
        obj->on_got_page_size(Glib::wrap(p0, true)
, Glib::wrap(p1, true)
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
        g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)    );

  // Call the original underlying C function:
  if(base && base->got_page_size)
    (*base->got_page_size)(self, p0, p1);
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


Glib::ObjectBase* PrintOperationPreview_Class::wrap_new(GObject* object)
{
  return new PrintOperationPreview((GtkPrintOperationPreview*)(object));
}


/* The implementation: */

PrintOperationPreview::PrintOperationPreview()
:
  Glib::Interface(printoperationpreview_class_.init())
{}

PrintOperationPreview::PrintOperationPreview(GtkPrintOperationPreview* castitem)
:
  Glib::Interface((GObject*)(castitem))
{}

PrintOperationPreview::PrintOperationPreview(const Glib::Interface_Class& interface_class)
: Glib::Interface(interface_class)
{
}

PrintOperationPreview::~PrintOperationPreview()
{}

// static
void PrintOperationPreview::add_interface(GType gtype_implementer)
{
  printoperationpreview_class_.init().add_interface(gtype_implementer);
}

PrintOperationPreview::CppClassType PrintOperationPreview::printoperationpreview_class_; // initialize static member

GType PrintOperationPreview::get_type()
{
  return printoperationpreview_class_.init().get_type();
}

GType PrintOperationPreview::get_base_type()
{
  return gtk_print_operation_preview_get_type();
}


void PrintOperationPreview::render_page(int page_nr)
{
gtk_print_operation_preview_render_page(gobj(), page_nr); 
}

void PrintOperationPreview::end_preview()
{
gtk_print_operation_preview_end_preview(gobj()); 
}

bool PrintOperationPreview::is_selected(int page_nr) const
{
  return gtk_print_operation_preview_is_selected(const_cast<GtkPrintOperationPreview*>(gobj()), page_nr);
}


Glib::SignalProxy1< void,const Glib::RefPtr<PrintContext>& > PrintOperationPreview::signal_ready()
{
  return Glib::SignalProxy1< void,const Glib::RefPtr<PrintContext>& >(this, &PrintOperationPreview_signal_ready_info);
}


Glib::SignalProxy2< void,const Glib::RefPtr<PrintContext>&,const Glib::RefPtr<PageSetup>& > PrintOperationPreview::signal_got_page_size()
{
  return Glib::SignalProxy2< void,const Glib::RefPtr<PrintContext>&,const Glib::RefPtr<PageSetup>& >(this, &PrintOperationPreview_signal_got_page_size_info);
}


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void Gtk::PrintOperationPreview::on_ready(const Glib::RefPtr<PrintContext>& context)
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->ready)
    (*base->ready)(gobj(),Glib::unwrap(context));
}
void Gtk::PrintOperationPreview::on_got_page_size(const Glib::RefPtr<PrintContext>& context, const Glib::RefPtr<PageSetup>& page_setup)
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->got_page_size)
    (*base->got_page_size)(gobj(),Glib::unwrap(context),Glib::unwrap(page_setup));
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
void Gtk::PrintOperationPreview::render_page_vfunc(int page_nr) 
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->render_page)
    (*base->render_page)(gobj(),page_nr);
}
void Gtk::PrintOperationPreview::end_preview_vfunc() 
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->end_preview)
    (*base->end_preview)(gobj());
}
bool Gtk::PrintOperationPreview::is_selected_vfunc(int page_nr) const
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->is_selected)
    return (*base->is_selected)(const_cast<GtkPrintOperationPreview*>(gobj()),page_nr);

  typedef bool RType;
  return RType();
}
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gtk


