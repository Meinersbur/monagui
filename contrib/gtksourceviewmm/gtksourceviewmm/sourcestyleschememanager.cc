// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtksourceviewmm/sourcestyleschememanager.h>
#include <gtksourceviewmm/private/sourcestyleschememanager_p.h>

/* sourcestylescheme.hg
 *
 * Copyright (C) 2004-2005 Jae Jang
 * Copyright (C) 2005-2006 Rob Page
 * Copyright (C)2006 Dodji Seketeli
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

namespace gtksourceview
{


void SourceStyleSchemeManager::reset_search_path()
{
  gtk_source_style_scheme_manager_set_search_path(gobj(), NULL);
}

}


namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<gtksourceview::SourceStyleSchemeManager> wrap(GtkSourceStyleSchemeManager* object, bool take_copy)
{
  return Glib::RefPtr<gtksourceview::SourceStyleSchemeManager>( dynamic_cast<gtksourceview::SourceStyleSchemeManager*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace gtksourceview
{


/* The *_Class implementation: */

const Glib::Class& SourceStyleSchemeManager_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SourceStyleSchemeManager_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_source_style_scheme_manager_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void SourceStyleSchemeManager_Class::class_init_function(void* g_class, void* class_data)
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


Glib::ObjectBase* SourceStyleSchemeManager_Class::wrap_new(GObject* object)
{
  return new SourceStyleSchemeManager((GtkSourceStyleSchemeManager*)object);
}


/* The implementation: */

GtkSourceStyleSchemeManager* SourceStyleSchemeManager::gobj_copy()
{
  reference();
  return gobj();
}

SourceStyleSchemeManager::SourceStyleSchemeManager(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

SourceStyleSchemeManager::SourceStyleSchemeManager(GtkSourceStyleSchemeManager* castitem)
:
  Glib::Object((GObject*)(castitem))
{}

SourceStyleSchemeManager::~SourceStyleSchemeManager()
{}


SourceStyleSchemeManager::CppClassType SourceStyleSchemeManager::sourcestyleschememanager_class_; // initialize static member

GType SourceStyleSchemeManager::get_type()
{
  return sourcestyleschememanager_class_.init().get_type();
}

GType SourceStyleSchemeManager::get_base_type()
{
  return gtk_source_style_scheme_manager_get_type();
}


SourceStyleSchemeManager::SourceStyleSchemeManager()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(sourcestyleschememanager_class_.init()))
{
  

}

Glib::RefPtr<SourceStyleSchemeManager> SourceStyleSchemeManager::create()
{
  return Glib::RefPtr<SourceStyleSchemeManager>( new SourceStyleSchemeManager() );
}
Glib::RefPtr<SourceStyleSchemeManager> SourceStyleSchemeManager::get_default()
{

  Glib::RefPtr<SourceStyleSchemeManager> retvalue = Glib::wrap(gtk_source_style_scheme_manager_get_default());

  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}


void SourceStyleSchemeManager::set_search_path(const Glib::StringArrayHandle& path)
{
gtk_source_style_scheme_manager_set_search_path(gobj(), const_cast<gchar**>((path).data())); 
}

Glib::StringArrayHandle SourceStyleSchemeManager::get_search_path() const
{
  return Glib::StringArrayHandle(gtk_source_style_scheme_manager_get_search_path(const_cast<GtkSourceStyleSchemeManager*>(gobj())));
}

void SourceStyleSchemeManager::append_search_path(const Glib::ustring& path)
{
gtk_source_style_scheme_manager_append_search_path(gobj(), path.c_str()); 
}

void SourceStyleSchemeManager::prepend_search_path(const Glib::ustring& path)
{
gtk_source_style_scheme_manager_prepend_search_path(gobj(), path.c_str()); 
}

Glib::RefPtr<SourceStyleScheme> SourceStyleSchemeManager::get_scheme(const Glib::ustring& scheme_id)
{

  Glib::RefPtr<SourceStyleScheme> retvalue = Glib::wrap(gtk_source_style_scheme_manager_get_scheme(gobj(), scheme_id.c_str()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;

}

Glib::RefPtr<const SourceStyleScheme> SourceStyleSchemeManager::get_scheme(const Glib::ustring& scheme_id) const
{
  return const_cast<SourceStyleSchemeManager*>(this)->get_scheme(scheme_id);
}

void SourceStyleSchemeManager::force_rescan()
{
gtk_source_style_scheme_manager_force_rescan(gobj()); 
}

Glib::StringArrayHandle SourceStyleSchemeManager::get_scheme_ids() const
{
  return Glib::StringArrayHandle(gtk_source_style_scheme_manager_get_scheme_ids(const_cast<GtkSourceStyleSchemeManager*>(gobj())));
}


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace gtksourceview


