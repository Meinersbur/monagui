// Generated by gtkmmproc -- DO NOT MODIFY!


#include <giomm/filenamecompleter.h>
#include <giomm/private/filenamecompleter_p.h>

// -*- Mode: C++; indent-tabs-mode: nil; c-basic-offset: 2 -*-

/* Copyright (C) 2007 The gtkmm Development Team
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

#include <giomm/file.h>
#include <gio/gio.h>

namespace Gio {


} // namespace Gio

namespace
{


static const Glib::SignalProxyInfo FilenameCompleter_signal_got_completion_data_info =
{
  "got_completion_data",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gio::FilenameCompleter> wrap(GFilenameCompleter* object, bool take_copy)
{
  return Glib::RefPtr<Gio::FilenameCompleter>( dynamic_cast<Gio::FilenameCompleter*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

const Glib::Class& FilenameCompleter_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FilenameCompleter_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_filename_completer_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void FilenameCompleter_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  klass->got_completion_data = &got_completion_data_callback;
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
}

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void FilenameCompleter_Class::got_completion_data_callback(GFilenameCompleter* self)
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
        obj->on_got_completion_data();
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
  if(base && base->got_completion_data)
    (*base->got_completion_data)(self);
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


Glib::ObjectBase* FilenameCompleter_Class::wrap_new(GObject* object)
{
  return new FilenameCompleter((GFilenameCompleter*)object);
}


/* The implementation: */

GFilenameCompleter* FilenameCompleter::gobj_copy()
{
  reference();
  return gobj();
}

FilenameCompleter::FilenameCompleter(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

FilenameCompleter::FilenameCompleter(GFilenameCompleter* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


FilenameCompleter::~FilenameCompleter()
{}


FilenameCompleter::CppClassType FilenameCompleter::filenamecompleter_class_; // initialize static member

GType FilenameCompleter::get_type()
{
  return filenamecompleter_class_.init().get_type();
}

GType FilenameCompleter::get_base_type()
{
  return g_filename_completer_get_type();
}


FilenameCompleter::FilenameCompleter()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(filenamecompleter_class_.init()))
{
  

}

Glib::RefPtr<FilenameCompleter> FilenameCompleter::create()
{
  return Glib::RefPtr<FilenameCompleter>( new FilenameCompleter() );
}
std::string FilenameCompleter::get_completion_suffix(const std::string& initial_text) const
{
  return Glib::convert_return_gchar_ptr_to_stdstring(g_filename_completer_get_completion_suffix(const_cast<GFilenameCompleter*>(gobj()), initial_text.c_str()));
}

Glib::StringArrayHandle FilenameCompleter::get_completions(const std::string& initial_text) const
{
  return Glib::StringArrayHandle(g_filename_completer_get_completions(const_cast<GFilenameCompleter*>(gobj()), initial_text.c_str()));
}

void FilenameCompleter::set_dirs_only(bool dirs_only)
{
g_filename_completer_set_dirs_only(gobj(), static_cast<int>(dirs_only)); 
}


Glib::SignalProxy0< void > FilenameCompleter::signal_got_completion_data()
{
  return Glib::SignalProxy0< void >(this, &FilenameCompleter_signal_got_completion_data_info);
}


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void Gio::FilenameCompleter::on_got_completion_data()
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->got_completion_data)
    (*base->got_completion_data)(gobj());
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gio


