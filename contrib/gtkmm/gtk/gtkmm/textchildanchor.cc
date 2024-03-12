// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtkmm/textchildanchor.h>
#include <gtkmm/private/textchildanchor_p.h>

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

#include <gtk/gtktextchild.h>
namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gtk::TextChildAnchor> wrap(GtkTextChildAnchor* object, bool take_copy)
{
  return Glib::RefPtr<Gtk::TextChildAnchor>( dynamic_cast<Gtk::TextChildAnchor*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& TextChildAnchor_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &TextChildAnchor_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_text_child_anchor_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void TextChildAnchor_Class::class_init_function(void* g_class, void* class_data)
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


Glib::ObjectBase* TextChildAnchor_Class::wrap_new(GObject* object)
{
  return new TextChildAnchor((GtkTextChildAnchor*)object);
}


/* The implementation: */

GtkTextChildAnchor* TextChildAnchor::gobj_copy()
{
  reference();
  return gobj();
}

TextChildAnchor::TextChildAnchor(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

TextChildAnchor::TextChildAnchor(GtkTextChildAnchor* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


TextChildAnchor::~TextChildAnchor()
{}


TextChildAnchor::CppClassType TextChildAnchor::textchildanchor_class_; // initialize static member

GType TextChildAnchor::get_type()
{
  return textchildanchor_class_.init().get_type();
}

GType TextChildAnchor::get_base_type()
{
  return gtk_text_child_anchor_get_type();
}


TextChildAnchor::TextChildAnchor()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Glib::Object(Glib::ConstructParams(textchildanchor_class_.init()))
{
  

}

Glib::RefPtr<TextChildAnchor> TextChildAnchor::create()
{
  return Glib::RefPtr<TextChildAnchor>( new TextChildAnchor() );
}
Glib::ListHandle<Widget*> TextChildAnchor::get_widgets()
{
  return Glib::ListHandle<Widget*>(gtk_text_child_anchor_get_widgets(gobj()), Glib::OWNERSHIP_SHALLOW);
}

Glib::ListHandle<const Widget*> TextChildAnchor::get_widgets() const
{
  return Glib::ListHandle<const Widget*>(gtk_text_child_anchor_get_widgets(const_cast<GtkTextChildAnchor*>(gobj())), Glib::OWNERSHIP_SHALLOW);
}

bool TextChildAnchor::get_deleted() const
{
  return gtk_text_child_anchor_get_deleted(const_cast<GtkTextChildAnchor*>(gobj()));
}


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace Gtk


