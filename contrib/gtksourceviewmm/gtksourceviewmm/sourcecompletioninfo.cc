#define Gsv gtksourceview
// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtksourceviewmm/sourcecompletioninfo.h>
#include <gtksourceviewmm/private/sourcecompletioninfo_p.h>

/* sourcecompletioninfo.cc
 *
 * Copyright (C) 2009, 2010 Krzesimir Nowak
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

#include <gtksourceview/gtksourcecompletioninfo.h>

namespace Gsv
{

SourceCompletionInfo::SourceCompletionInfo() :
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Window(Glib::ConstructParams(sourcecompletioninfo_class_.init(), "type",GTK_WINDOW_POPUP, static_cast<char*>(0)))
{}

void
SourceCompletionInfo::move_to_iter(const Gtk::TextView& view)
{
  gtk_source_completion_info_move_to_iter(gobj(), const_cast<GtkTextView*>(view.gobj()), 0);
}

} // namespace Gsv

namespace
{


static const Glib::SignalProxyInfo SourceCompletionInfo_signal_before_show_info =
{
  "before-show",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

Gsv::SourceCompletionInfo* wrap(GtkSourceCompletionInfo* object, bool take_copy)
{
  return dynamic_cast<Gsv::SourceCompletionInfo *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gsv
{


/* The *_Class implementation: */

const Glib::Class& SourceCompletionInfo_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SourceCompletionInfo_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_source_completion_info_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void SourceCompletionInfo_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


  klass->before_show = &before_show_callback;
}


void SourceCompletionInfo_Class::before_show_callback(GtkSourceCompletionInfo* self)
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
        obj->on_before_show();
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
  if(base && base->before_show)
    (*base->before_show)(self);
}


Glib::ObjectBase* SourceCompletionInfo_Class::wrap_new(GObject* o)
{
  return manage(new SourceCompletionInfo((GtkSourceCompletionInfo*)(o)));

}


/* The implementation: */

SourceCompletionInfo::SourceCompletionInfo(const Glib::ConstructParams& construct_params)
:
  Gtk::Window(construct_params)
{
  }

SourceCompletionInfo::SourceCompletionInfo(GtkSourceCompletionInfo* castitem)
:
  Gtk::Window((GtkWindow*)(castitem))
{
  }

SourceCompletionInfo::~SourceCompletionInfo()
{
  destroy_();
}

SourceCompletionInfo::CppClassType SourceCompletionInfo::sourcecompletioninfo_class_; // initialize static member

GType SourceCompletionInfo::get_type()
{
  return sourcecompletioninfo_class_.init().get_type();
}


GType SourceCompletionInfo::get_base_type()
{
  return gtk_source_completion_info_get_type();
}


void SourceCompletionInfo::move_to_iter(const Gtk::TextView& view, const Gtk::TextIter& iter)
{
gtk_source_completion_info_move_to_iter(gobj(), const_cast<GtkTextView*>((view).gobj()), const_cast<GtkTextIter*>((iter).gobj())); 
}

void SourceCompletionInfo::set_widget(Gtk::Widget& widget)
{
gtk_source_completion_info_set_widget(gobj(), (widget).gobj()); 
}

Gtk::Widget* SourceCompletionInfo::get_widget()
{
  return Glib::wrap(gtk_source_completion_info_get_widget(gobj()));
}

const Gtk::Widget* SourceCompletionInfo::get_widget() const
{
  return const_cast<SourceCompletionInfo*>(this)->get_widget();
}


Glib::SignalProxy0< void > SourceCompletionInfo::signal_before_show()
{
  return Glib::SignalProxy0< void >(this, &SourceCompletionInfo_signal_before_show_info);
}


void Gsv::SourceCompletionInfo::on_before_show()
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->before_show)
    (*base->before_show)(gobj());
}


} // namespace Gsv

