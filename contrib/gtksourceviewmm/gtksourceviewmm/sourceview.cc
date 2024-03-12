// Generated by gtkmmproc -- DO NOT MODIFY!


#include <gtksourceviewmm/sourceview.h>
#include <gtksourceviewmm/private/sourceview_p.h>

/* GtkSourceView::SourceView
 *
 * Copyright (C) 2004-2005 Jae Jang
 * Copyright (C) 2005-2006 Rob Page
 * Copyright (C) 2006 Dodji Seketeli
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
#include <gtksourceviewmm/sourceview.h>
#include <gtksourceview/gtksourceview.h>
#include <gtksourceview/gtksourceview-typebuiltins.h>

namespace gtksourceview
{

SourceView::SourceView() :
    // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::TextView(Glib::ConstructParams(sourceview_class_.init()))
{
    GtkSourceBuffer *buffer = gtk_source_buffer_new (NULL) ;
    gtk_text_view_set_buffer (GTK_TEXT_VIEW (gobject_), GTK_TEXT_BUFFER (buffer));
}

SourceView::SourceView(const Glib::RefPtr<SourceBuffer> &a_buffer) :
    // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::TextView(Glib::ConstructParams(sourceview_class_.init()))
{
    if (a_buffer) {
        set_buffer (a_buffer) ;
    } else {
        GtkSourceBuffer *buffer = gtk_source_buffer_new (NULL) ;
        gtk_text_view_set_buffer (GTK_TEXT_VIEW (gobject_), GTK_TEXT_BUFFER (buffer)) ;
    }
}

Glib::RefPtr<const SourceBuffer>
SourceView::get_source_buffer () const
{
    Glib::RefPtr<SourceBuffer> buffer ;
    buffer = Glib::wrap (GTK_SOURCE_BUFFER (get_buffer ()->gobj ()), true);
    return buffer ;
}

Glib::RefPtr<SourceBuffer>
SourceView::get_source_buffer ()
{
    Glib::RefPtr<SourceBuffer> buffer ;
    buffer = Glib::wrap (GTK_SOURCE_BUFFER (get_buffer ()->gobj ()), true) ;
    return buffer ;

}

void
SourceView::set_source_buffer (const Glib::RefPtr<SourceBuffer> &source_buffer)
{
    set_buffer (source_buffer) ;
}

}//end namespace gtksourceview


namespace
{


static const Glib::SignalProxyInfo SourceView_signal_redo_info =
{
  "redo",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


static const Glib::SignalProxyInfo SourceView_signal_undo_info =
{
  "undo",
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback,
  (GCallback) &Glib::SignalProxyNormal::slot0_void_callback
};


} // anonymous namespace

// static
GType Glib::Value<gtksourceview::SourceSmartHomeEndType>::value_type()
{
  return gtk_source_smart_home_end_type_get_type();
}


namespace Glib
{

gtksourceview::SourceView* wrap(GtkSourceView* object, bool take_copy)
{
  return dynamic_cast<gtksourceview::SourceView *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace gtksourceview
{


/* The *_Class implementation: */

const Glib::Class& SourceView_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SourceView_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_source_view_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}

void SourceView_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  klass->redo = &redo_callback;
  klass->undo = &undo_callback;
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
}

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void SourceView_Class::redo_callback(GtkSourceView* self)
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
        obj->on_redo();
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
  if(base && base->redo)
    (*base->redo)(self);
}
void SourceView_Class::undo_callback(GtkSourceView* self)
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
        obj->on_undo();
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
  if(base && base->undo)
    (*base->undo)(self);
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


Glib::ObjectBase* SourceView_Class::wrap_new(GObject* o)
{
  return manage(new SourceView((GtkSourceView*)(o)));

}


/* The implementation: */

SourceView::SourceView(const Glib::ConstructParams& construct_params)
:
  Gtk::TextView(construct_params)
{
  }

SourceView::SourceView(GtkSourceView* castitem)
:
  Gtk::TextView((GtkTextView*)(castitem))
{
  }

SourceView::~SourceView()
{
  destroy_();
}

SourceView::CppClassType SourceView::sourceview_class_; // initialize static member

GType SourceView::get_type()
{
  return sourceview_class_.init().get_type();
}

GType SourceView::get_base_type()
{
  return gtk_source_view_get_type();
}


Glib::RefPtr<SourceView> SourceView::create()
{
  return Glib::RefPtr<SourceView>( new SourceView() );
}
Glib::RefPtr<SourceView> SourceView::create(const Glib::RefPtr<SourceBuffer> & buffer)
{
  return Glib::RefPtr<SourceView>( new SourceView(buffer) );
}
void SourceView::set_show_line_numbers(bool show)
{
gtk_source_view_set_show_line_numbers(gobj(), static_cast<int>(show)); 
}

bool SourceView::get_show_line_numbers() const
{
  return gtk_source_view_get_show_line_numbers(const_cast<GtkSourceView*>(gobj()));
}

void SourceView::set_tab_width(guint width)
{
gtk_source_view_set_tab_width(gobj(), width); 
}

guint SourceView::get_tab_width() const
{
  return gtk_source_view_get_tab_width(const_cast<GtkSourceView*>(gobj()));
}

void SourceView::set_auto_indent(bool enable)
{
gtk_source_view_set_auto_indent(gobj(), static_cast<int>(enable)); 
}

bool SourceView::get_auto_indent() const
{
  return gtk_source_view_get_auto_indent(const_cast<GtkSourceView*>(gobj()));
}

void SourceView::set_insert_spaces_instead_of_tabs(bool enable)
{
gtk_source_view_set_insert_spaces_instead_of_tabs(gobj(), static_cast<int>(enable)); 
}

bool SourceView::get_insert_spaces_instead_of_tabs() const
{
  return gtk_source_view_get_insert_spaces_instead_of_tabs(const_cast<GtkSourceView*>(gobj()));
}

void SourceView::set_show_right_margin(bool show)
{
gtk_source_view_set_show_right_margin(gobj(), static_cast<int>(show)); 
}

bool SourceView::get_show_right_margin() const
{
  return gtk_source_view_get_show_right_margin(const_cast<GtkSourceView*>(gobj()));
}

void SourceView::set_highlight_current_line(bool highlight)
{
gtk_source_view_set_highlight_current_line(gobj(), static_cast<int>(highlight)); 
}

bool SourceView::get_highlight_current_line() const
{
  return gtk_source_view_get_highlight_current_line(const_cast<GtkSourceView*>(gobj()));
}

void SourceView::set_right_margin_position(guint margin)
{
gtk_source_view_set_right_margin_position(gobj(), margin); 
}

guint SourceView::get_right_margin_position() const
{
  return gtk_source_view_get_right_margin_position(const_cast<GtkSourceView*>(gobj()));
}

void SourceView::set_smart_home_end(SourceSmartHomeEndType smart_he)
{
gtk_source_view_set_smart_home_end(gobj(), ((GtkSourceSmartHomeEndType)(smart_he))); 
}

SourceSmartHomeEndType SourceView::get_smart_home_end() const
{
  return ((SourceSmartHomeEndType)(gtk_source_view_get_smart_home_end(const_cast<GtkSourceView*>(gobj()))));
}

void SourceView::set_show_line_marks(bool show)
{
gtk_source_view_set_show_line_marks(gobj(), static_cast<int>(show)); 
}

bool SourceView::get_show_line_marks() const
{
  return gtk_source_view_get_show_line_marks(const_cast<GtkSourceView*>(gobj()));
}

void SourceView::set_indent_on_tab(bool show)
{
gtk_source_view_set_indent_on_tab(gobj(), static_cast<int>(show)); 
}

bool SourceView::get_indent_on_tab() const
{
  return gtk_source_view_get_indent_on_tab(const_cast<GtkSourceView*>(gobj()));
}

void SourceView::set_indent_width(gint width)
{
gtk_source_view_set_indent_width(gobj(), width); 
}

gint SourceView::get_indent_width() const
{
  return gtk_source_view_get_indent_width(const_cast<GtkSourceView*>(gobj()));
}

void SourceView::set_mark_category_priority(const Glib::ustring& category, gint priority)
{
gtk_source_view_set_mark_category_priority(gobj(), category.c_str(), priority); 
}

gint SourceView::get_mark_category_priority(const Glib::ustring& category) const
{
  return gtk_source_view_get_mark_category_priority(const_cast<GtkSourceView*>(gobj()), category.c_str());
}

void SourceView::set_mark_category_pixbuf(const Glib::ustring& category, const Glib::RefPtr<Gdk::Pixbuf>& pixbuf)
{
gtk_source_view_set_mark_category_pixbuf(gobj(), category.c_str(), Glib::unwrap(pixbuf)); 
}

Glib::RefPtr<Gdk::Pixbuf> SourceView::get_mark_category_pixbuf(const Glib::ustring& category)
{

  Glib::RefPtr<Gdk::Pixbuf> retvalue = Glib::wrap(gtk_source_view_get_mark_category_pixbuf(gobj(), category.c_str()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;

}

Glib::RefPtr<const Gdk::Pixbuf> SourceView::get_mark_category_pixbuf(const Glib::ustring& category) const
{
  return const_cast<SourceView*>(this)->get_mark_category_pixbuf(category);
}


Glib::SignalProxy0< void > SourceView::signal_redo()
{
  return Glib::SignalProxy0< void >(this, &SourceView_signal_redo_info);
}


Glib::SignalProxy0< void > SourceView::signal_undo()
{
  return Glib::SignalProxy0< void >(this, &SourceView_signal_undo_info);
}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> SourceView::property_show_line_numbers() 
{
  return Glib::PropertyProxy<bool>(this, "show-line-numbers");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> SourceView::property_show_line_numbers() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "show-line-numbers");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> SourceView::property_show_line_marks() 
{
  return Glib::PropertyProxy<bool>(this, "show-line-marks");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> SourceView::property_show_line_marks() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "show-line-marks");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<guint> SourceView::property_tab_width() 
{
  return Glib::PropertyProxy<guint>(this, "tab-width");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<guint> SourceView::property_tab_width() const
{
  return Glib::PropertyProxy_ReadOnly<guint>(this, "tab-width");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<int> SourceView::property_indent_width() 
{
  return Glib::PropertyProxy<int>(this, "indent-width");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<int> SourceView::property_indent_width() const
{
  return Glib::PropertyProxy_ReadOnly<int>(this, "indent-width");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> SourceView::property_auto_indent() 
{
  return Glib::PropertyProxy<bool>(this, "auto-indent");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> SourceView::property_auto_indent() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "auto-indent");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> SourceView::property_insert_spaces_instead_of_tabs() 
{
  return Glib::PropertyProxy<bool>(this, "insert-spaces-instead-of-tabs");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> SourceView::property_insert_spaces_instead_of_tabs() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "insert-spaces-instead-of-tabs");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> SourceView::property_show_right_margin() 
{
  return Glib::PropertyProxy<bool>(this, "show-right-margin");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> SourceView::property_show_right_margin() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "show-right-margin");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<guint> SourceView::property_right_margin_position() 
{
  return Glib::PropertyProxy<guint>(this, "right-margin-position");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<guint> SourceView::property_right_margin_position() const
{
  return Glib::PropertyProxy_ReadOnly<guint>(this, "right-margin-position");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<SourceSmartHomeEndType> SourceView::property_smart_home_end() 
{
  return Glib::PropertyProxy<SourceSmartHomeEndType>(this, "smart-home-end");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<SourceSmartHomeEndType> SourceView::property_smart_home_end() const
{
  return Glib::PropertyProxy_ReadOnly<SourceSmartHomeEndType>(this, "smart-home-end");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> SourceView::property_highlight_current_line() 
{
  return Glib::PropertyProxy<bool>(this, "highlight-current-line");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> SourceView::property_highlight_current_line() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "highlight-current-line");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy<bool> SourceView::property_indent_on_tab() 
{
  return Glib::PropertyProxy<bool>(this, "indent-on-tab");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly<bool> SourceView::property_indent_on_tab() const
{
  return Glib::PropertyProxy_ReadOnly<bool>(this, "indent-on-tab");
}
#endif //GLIBMM_PROPERTIES_ENABLED


#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
void gtksourceview::SourceView::on_redo()
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->redo)
    (*base->redo)(gobj());
}
void gtksourceview::SourceView::on_undo()
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->undo)
    (*base->undo)(gobj());
}
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED


} // namespace gtksourceview

