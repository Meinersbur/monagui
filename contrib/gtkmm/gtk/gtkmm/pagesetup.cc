// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtkmm/pagesetup.h>
#include <gtkmm/private/pagesetup_p.h>

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

#include <gtk/gtkpagesetup.h>
#include <gtk/gtktypebuiltins.h>

namespace Gtk
{

#ifdef GLIBMM_EXCEPTIONS_ENABLED
Glib::RefPtr<PageSetup> PageSetup::create_from_key_file(const Glib::KeyFile& key_file)
#else
Glib::RefPtr<PageSetup> PageSetup::create_from_key_file(const Glib::KeyFile& key_file, std::auto_ptr<Glib::Error>& error)
#endif //GLIBMM_EXCEPTIONS_ENABLED
{
  Glib::RefPtr<PageSetup> result = PageSetup::create();

  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  result->load_from_key_file(key_file);
  #else
  result->load_from_key_file(key_file, error);
  #endif //GLIBMM_EXCEPTIONS_ENABLED

  return result;
}

#ifdef GLIBMM_EXCEPTIONS_ENABLED
Glib::RefPtr<PageSetup> PageSetup::create_from_key_file(const Glib::KeyFile& key_file, const Glib::ustring& group_name)
#else
Glib::RefPtr<PageSetup> PageSetup::create_from_key_file(const Glib::KeyFile& key_file, const Glib::ustring& group_name, std::auto_ptr<Glib::Error>& error)
#endif //GLIBMM_EXCEPTIONS_ENABLED
{
  Glib::RefPtr<PageSetup> result = PageSetup::create();

  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  result->load_from_key_file(key_file, group_name);
  #else
  result->load_from_key_file(key_file, group_name, error);
  #endif //GLIBMM_EXCEPTIONS_ENABLED

  return result;
}

#ifdef GLIBMM_EXCEPTIONS_ENABLED
Glib::RefPtr<PageSetup> PageSetup::create_from_file(const std::string& file_name)
#else
Glib::RefPtr<PageSetup> PageSetup::create_from_file(const std::string& file_name, std::auto_ptr<Glib::Error>& error)
#endif //GLIBMM_EXCEPTIONS_ENABLED
{
  Glib::RefPtr<PageSetup> result = PageSetup::create();

  #ifdef GLIBMM_EXCEPTIONS_ENABLED
  result->load_from_file(file_name);
  #else
  result->load_from_file(file_name, error);
  #endif //GLIBMM_EXCEPTIONS_ENABLED

  return result;
}

#ifndef GTKMM_DISABLE_DEPRECATED
void PageSetup::save_to_key_file(Glib::KeyFile& key_file)
{
  gtk_page_setup_to_key_file(gobj(), (key_file).gobj(), 0); 
}
#endif //GTKMM_DISABLE_DEPRECATED

void PageSetup::save_to_key_file(Glib::KeyFile& key_file) const
{
  gtk_page_setup_to_key_file(const_cast<GtkPageSetup*>(gobj()), (key_file).gobj(), 0); 
}

#ifdef GLIBMM_EXCEPTIONS_ENABLED
bool PageSetup::load_from_key_file(const Glib::KeyFile& key_file)
#else
bool PageSetup::load_from_key_file(const Glib::KeyFile& key_file, std::auto_ptr<Glib::Error>& error)
#endif //GLIBMM_EXCEPTIONS_ENABLED
{
  GError* gerror = 0;
  bool retvalue = gtk_page_setup_load_key_file(gobj(), const_cast<GKeyFile*>((key_file).gobj()), NULL, &(gerror));
#ifdef GLIBMM_EXCEPTIONS_ENABLED
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
#else
  if(gerror)
    error = ::Glib::Error::throw_exception(gerror);
#endif //GLIBMM_EXCEPTIONS_ENABLED

  return retvalue;
}

} //namespace

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gtk::PageSetup> wrap(GtkPageSetup* object, bool take_copy)
{
  return Glib::RefPtr<Gtk::PageSetup>( dynamic_cast<Gtk::PageSetup*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& PageSetup_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &PageSetup_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_page_setup_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void PageSetup_Class::class_init_function(void* g_class, void* class_data)
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


Glib::ObjectBase* PageSetup_Class::wrap_new(GObject* object)
{
  return new PageSetup((GtkPageSetup*)object);
}


/* The implementation: */

GtkPageSetup* PageSetup::gobj_copy()
{
  reference();
  return gobj();
}

PageSetup::PageSetup(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

PageSetup::PageSetup(GtkPageSetup* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


PageSetup::~PageSetup()
{}


PageSetup::CppClassType PageSetup::pagesetup_class_; // initialize static member

GType PageSetup::get_type()
{
  return pagesetup_class_.init().get_type();
}

GType PageSetup::get_base_type()
{
  return gtk_page_setup_get_type();
}


PageSetup::PageSetup()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(pagesetup_class_.init()))
{
  

}

Glib::RefPtr<PageSetup> PageSetup::create()
{
  return Glib::RefPtr<PageSetup>( new PageSetup() );
}
Glib::RefPtr<PageSetup> PageSetup::copy() const
{
  return Glib::wrap(gtk_page_setup_copy(const_cast<GtkPageSetup*>(gobj())));
}

#ifdef GLIBMM_EXCEPTIONS_ENABLED
bool PageSetup::load_from_file(const std::string& file_name)
#else
bool PageSetup::load_from_file(const std::string& file_name, std::auto_ptr<Glib::Error>& error)
#endif //GLIBMM_EXCEPTIONS_ENABLED
{
  GError* gerror = 0;
  bool retvalue = gtk_page_setup_load_file(gobj(), file_name.c_str(), &(gerror));
#ifdef GLIBMM_EXCEPTIONS_ENABLED
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
#else
  if(gerror)
    error = ::Glib::Error::throw_exception(gerror);
#endif //GLIBMM_EXCEPTIONS_ENABLED

  return retvalue;

}

#ifdef GLIBMM_EXCEPTIONS_ENABLED
bool PageSetup::load_from_key_file(const Glib::KeyFile& key_file, const Glib::ustring& group_name)
#else
bool PageSetup::load_from_key_file(const Glib::KeyFile& key_file, const Glib::ustring& group_name, std::auto_ptr<Glib::Error>& error)
#endif //GLIBMM_EXCEPTIONS_ENABLED
{
  GError* gerror = 0;
  bool retvalue = gtk_page_setup_load_key_file(gobj(), const_cast<GKeyFile*>((key_file).gobj()), group_name.c_str(), &(gerror));
#ifdef GLIBMM_EXCEPTIONS_ENABLED
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
#else
  if(gerror)
    error = ::Glib::Error::throw_exception(gerror);
#endif //GLIBMM_EXCEPTIONS_ENABLED

  return retvalue;

}

PageOrientation PageSetup::get_orientation() const
{
  return (PageOrientation)gtk_page_setup_get_orientation(const_cast<GtkPageSetup*>(gobj()));
}

void PageSetup::set_orientation(PageOrientation orientation)
{
gtk_page_setup_set_orientation(gobj(), ((GtkPageOrientation)(orientation))); 
}

PaperSize PageSetup::get_paper_size()
{
  return Glib::wrap(gtk_page_setup_get_paper_size(gobj()), true);
}

const PaperSize PageSetup::get_paper_size() const
{
  return const_cast<PageSetup*>(this)->get_paper_size();
}

void PageSetup::set_paper_size(const PaperSize& paper_size)
{
gtk_page_setup_set_paper_size(gobj(), const_cast<GtkPaperSize*>((paper_size).gobj())); 
}

double PageSetup::get_top_margin(Unit unit) const
{
  return gtk_page_setup_get_top_margin(const_cast<GtkPageSetup*>(gobj()), ((GtkUnit)(unit)));
}

void PageSetup::set_top_margin(double margin, Unit unit)
{
gtk_page_setup_set_top_margin(gobj(), margin, ((GtkUnit)(unit))); 
}

double PageSetup::get_bottom_margin(Unit unit) const
{
  return gtk_page_setup_get_bottom_margin(const_cast<GtkPageSetup*>(gobj()), ((GtkUnit)(unit)));
}

void PageSetup::set_bottom_margin(double margin, Unit unit)
{
gtk_page_setup_set_bottom_margin(gobj(), margin, ((GtkUnit)(unit))); 
}

double PageSetup::get_left_margin(Unit unit) const
{
  return gtk_page_setup_get_left_margin(const_cast<GtkPageSetup*>(gobj()), ((GtkUnit)(unit)));
}

void PageSetup::set_left_margin(double margin, Unit unit)
{
gtk_page_setup_set_left_margin(gobj(), margin, ((GtkUnit)(unit))); 
}

double PageSetup::get_right_margin(Unit unit) const
{
  return gtk_page_setup_get_right_margin(const_cast<GtkPageSetup*>(gobj()), ((GtkUnit)(unit)));
}

void PageSetup::set_right_margin(double margin, Unit unit)
{
gtk_page_setup_set_right_margin(gobj(), margin, ((GtkUnit)(unit))); 
}

void PageSetup::set_paper_size_and_default_margins(const PaperSize& paper_size)
{
gtk_page_setup_set_paper_size_and_default_margins(gobj(), const_cast<GtkPaperSize*>((paper_size).gobj())); 
}

double PageSetup::get_paper_width(Unit unit) const
{
  return gtk_page_setup_get_paper_width(const_cast<GtkPageSetup*>(gobj()), ((GtkUnit)(unit)));
}

double PageSetup::get_paper_height(Unit unit) const
{
  return gtk_page_setup_get_paper_height(const_cast<GtkPageSetup*>(gobj()), ((GtkUnit)(unit)));
}

double PageSetup::get_page_width(Unit unit) const
{
  return gtk_page_setup_get_page_width(const_cast<GtkPageSetup*>(gobj()), ((GtkUnit)(unit)));
}

double PageSetup::get_page_height(Unit unit) const
{
  return gtk_page_setup_get_page_height(const_cast<GtkPageSetup*>(gobj()), ((GtkUnit)(unit)));
}

#ifdef GLIBMM_EXCEPTIONS_ENABLED
bool PageSetup::save_to_file(const std::string& file_name) const
#else
bool PageSetup::save_to_file(const std::string& file_name, std::auto_ptr<Glib::Error>& error) const
#endif //GLIBMM_EXCEPTIONS_ENABLED
{
  GError* gerror = 0;
  bool retvalue = gtk_page_setup_to_file(const_cast<GtkPageSetup*>(gobj()), file_name.c_str(), &(gerror));
#ifdef GLIBMM_EXCEPTIONS_ENABLED
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
#else
  if(gerror)
    error = ::Glib::Error::throw_exception(gerror);
#endif //GLIBMM_EXCEPTIONS_ENABLED

  return retvalue;

}

#ifndef GTKMM_DISABLE_DEPRECATED

void PageSetup::save_to_key_file(Glib::KeyFile& key_file, const Glib::ustring& group_name)
{
gtk_page_setup_to_key_file(gobj(), (key_file).gobj(), group_name.c_str()); 
}

#endif // GTKMM_DISABLE_DEPRECATED

void PageSetup::save_to_key_file(Glib::KeyFile& key_file, const Glib::ustring& group_name) const
{
gtk_page_setup_to_key_file(const_cast<GtkPageSetup*>(gobj()), (key_file).gobj(), group_name.c_str()); 
}


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gtk


