// Generated by gtkmmproc -- DO NOT MODIFY!

#ifndef GTKMM_DISABLE_DEPRECATED


#include <gtkmm/fileselection.h>
#include <gtkmm/private/fileselection_p.h>

// -*- c++ -*-
/* $Id$ */

/* Copyright 1998-2002 The gtkmm Development Team
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

#include <gtk/gtkfilesel.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>


namespace Gtk
{

FileSelection::FileSelection()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Dialog(Glib::ConstructParams(fileselection_class_.init(), "title",(char*) 0, static_cast<char*>(0)))
{}

} // namespace Gtk


namespace
{
} // anonymous namespace


namespace Glib
{

Gtk::FileSelection* wrap(GtkFileSelection* object, bool take_copy)
{
  return dynamic_cast<Gtk::FileSelection *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& FileSelection_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FileSelection_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_file_selection_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void FileSelection_Class::class_init_function(void* g_class, void* class_data)
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


Glib::ObjectBase* FileSelection_Class::wrap_new(GObject* o)
{
  return new FileSelection((GtkFileSelection*)(o)); //top-level windows can not be manage()ed.

}


/* The implementation: */

FileSelection::FileSelection(const Glib::ConstructParams& construct_params)
:
  Gtk::Dialog(construct_params)
{
  }

FileSelection::FileSelection(GtkFileSelection* castitem)
:
  Gtk::Dialog((GtkDialog*)(castitem))
{
  }

FileSelection::~FileSelection()
{
  destroy_();
}

FileSelection::CppClassType FileSelection::fileselection_class_; // initialize static member

GType FileSelection::get_type()
{
  return fileselection_class_.init().get_type();
}

GType FileSelection::get_base_type()
{
  return gtk_file_selection_get_type();
}


FileSelection::FileSelection(const Glib::ustring& title)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Dialog(Glib::ConstructParams(fileselection_class_.init(), "title", title.c_str(), static_cast<char*>(0)))
{
  

}

void FileSelection::set_filename(const std::string& filename)
{
gtk_file_selection_set_filename(gobj(), (filename).c_str()); 
}

std::string FileSelection::get_filename() const
{
  return std::string(gtk_file_selection_get_filename(const_cast<GtkFileSelection*>(gobj())));
}

void FileSelection::complete(const Glib::ustring& pattern)
{
gtk_file_selection_complete(gobj(), pattern.c_str()); 
}

void FileSelection::show_fileop_buttons()
{
gtk_file_selection_show_fileop_buttons(gobj()); 
}

void FileSelection::hide_fileop_buttons()
{
gtk_file_selection_hide_fileop_buttons(gobj()); 
}

Glib::ArrayHandle<std::string> FileSelection::get_selections() const
{
  return Glib::ArrayHandle<std::string>(gtk_file_selection_get_selections(const_cast<GtkFileSelection*>(gobj())), Glib::OWNERSHIP_DEEP);
}

void FileSelection::set_select_multiple(bool select_multiple)
{
gtk_file_selection_set_select_multiple(gobj(), static_cast<int>(select_multiple)); 
}

bool FileSelection::get_select_multiple() const
{
  return gtk_file_selection_get_select_multiple(const_cast<GtkFileSelection*>(gobj()));
}

 TreeView* FileSelection::get_dir_list()
{
  return Glib::wrap((GtkTreeView*)(gobj()->dir_list));
}

const TreeView* FileSelection::get_dir_list() const
{
  return Glib::wrap((GtkTreeView*)(gobj()->dir_list));
}
 
 TreeView* FileSelection::get_file_list()
{
  return Glib::wrap((GtkTreeView*)(gobj()->file_list));
}

const TreeView* FileSelection::get_file_list() const
{
  return Glib::wrap((GtkTreeView*)(gobj()->file_list));
}
 
 OptionMenu* FileSelection::get_history_pulldown()
{
  return Glib::wrap((GtkOptionMenu*)(gobj()->history_pulldown));
}

const OptionMenu* FileSelection::get_history_pulldown() const
{
  return Glib::wrap((GtkOptionMenu*)(gobj()->history_pulldown));
}
 
 Entry* FileSelection::get_selection_entry()
{
  return Glib::wrap((GtkEntry*)(gobj()->selection_entry));
}

const Entry* FileSelection::get_selection_entry() const
{
  return Glib::wrap((GtkEntry*)(gobj()->selection_entry));
}
 
 Label* FileSelection::get_selection_text()
{
  return Glib::wrap((GtkLabel*)(gobj()->selection_text));
}

const Label* FileSelection::get_selection_text() const
{
  return Glib::wrap((GtkLabel*)(gobj()->selection_text));
}
 
 VBox* FileSelection::get_main_vbox()
{
  return Glib::wrap((GtkVBox*)(gobj()->main_vbox));
}

const VBox* FileSelection::get_main_vbox() const
{
  return Glib::wrap((GtkVBox*)(gobj()->main_vbox));
}
 
 Button* FileSelection::get_ok_button()
{
  return Glib::wrap((GtkButton*)(gobj()->ok_button));
}

const Button* FileSelection::get_ok_button() const
{
  return Glib::wrap((GtkButton*)(gobj()->ok_button));
}
 
 Button* FileSelection::get_cancel_button()
{
  return Glib::wrap((GtkButton*)(gobj()->cancel_button));
}

const Button* FileSelection::get_cancel_button() const
{
  return Glib::wrap((GtkButton*)(gobj()->cancel_button));
}
 
 Button* FileSelection::get_help_button()
{
  return Glib::wrap((GtkButton*)(gobj()->help_button));
}

const Button* FileSelection::get_help_button() const
{
  return Glib::wrap((GtkButton*)(gobj()->help_button));
}
 
 HButtonBox* FileSelection::get_button_area()
{
  return Glib::wrap((GtkHButtonBox*)(gobj()->button_area));
}

const HButtonBox* FileSelection::get_button_area() const
{
  return Glib::wrap((GtkHButtonBox*)(gobj()->button_area));
}
 
 HBox* FileSelection::get_action_area()
{
  return Glib::wrap((GtkHBox*)(gobj()->action_area));
}

const HBox* FileSelection::get_action_area() const
{
  return Glib::wrap((GtkHBox*)(gobj()->action_area));
}
 

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> FileSelection::property_show_fileops() 
{
  return Glib::PropertyProxy<bool>(this, "show-fileops");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> FileSelection::property_show_fileops() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "show-fileops");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<std::string> FileSelection::property_filename() 
{
  return Glib::PropertyProxy<std::string>(this, "filename");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<std::string> FileSelection::property_filename() const
{
  return Glib::PropertyProxy_ReadOnly<std::string>(this, "filename");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> FileSelection::property_select_multiple() 
{
  return Glib::PropertyProxy<bool>(this, "select-multiple");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> FileSelection::property_select_multiple() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "select-multiple");
}
#endif //GLIBMM_PROPERTIES_ENABLED


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gtk

#endif // GTKMM_DISABLE_DEPRECATED


