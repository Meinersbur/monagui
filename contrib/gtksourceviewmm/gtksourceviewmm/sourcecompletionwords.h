// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKSOURCEVIEWMM_SOURCECOMPLETIONWORDS_H
#define _GTKSOURCEVIEWMM_SOURCECOMPLETIONWORDS_H


#include <glibmm.h>

/* sourcecompletionwords.h
 *
 * Copyright (C) 2010 Krzesimir Nowak
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

#include <glibmm/object.h>
#include <gtksourceviewmm/sourcecompletionprovider.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkSourceCompletionWords GtkSourceCompletionWords;
typedef struct _GtkSourceCompletionWordsClass GtkSourceCompletionWordsClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gsv
{ class SourceCompletionWords_Class; } // namespace Gsv
namespace Gsv
{
// TODO: docs needed. krnowak
/** Words completion provider.
 *
 * @newin{2,10}
 */

class SourceCompletionWords
:
  public Glib::Object,
  public SourceCompletionProvider
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef SourceCompletionWords CppObjectType;
  typedef SourceCompletionWords_Class CppClassType;
  typedef GtkSourceCompletionWords BaseObjectType;
  typedef GtkSourceCompletionWordsClass BaseClassType;

private:  friend class SourceCompletionWords_Class;
  static CppClassType sourcecompletionwords_class_;

private:
  // noncopyable
  SourceCompletionWords(const SourceCompletionWords&);
  SourceCompletionWords& operator=(const SourceCompletionWords&);

protected:
  explicit SourceCompletionWords(const Glib::ConstructParams& construct_params);
  explicit SourceCompletionWords(GtkSourceCompletionWords* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~SourceCompletionWords();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkSourceCompletionWords*       gobj()       { return reinterpret_cast<GtkSourceCompletionWords*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkSourceCompletionWords* gobj() const { return reinterpret_cast<GtkSourceCompletionWords*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkSourceCompletionWords* gobj_copy();

private:

  
protected:
  explicit SourceCompletionWords(const Glib::ustring& name, const Glib::RefPtr<Gdk::Pixbuf>& icon);
public:
  /** Creates words provider with given name and icon.
   *
   * @param name Provider's name
   * @param icon Provider's icon
   *
   * @return A new SourceCompletionWords.
   *
   * @newin{2,10}
   */
  
  static Glib::RefPtr<SourceCompletionWords> create(const Glib::ustring& name, const Glib::RefPtr<Gdk::Pixbuf>& icon);


// TODO: think about a good method name - register is a C/C++ keyword. krnowak
 

  /** Registers this provider in given buffer.
   *
   * @param buffer A buffer which will use this provider.
   *
   * @newin{2,10}
   */
  void register_provider(const Glib::RefPtr<Gtk::TextBuffer>& buffer);

  
  /** Unregisters this provider from given buffer.
   *
   * @param buffer A buffer which will not use this provider anymore.
   *
   * @newin{2,10}
   */
  void unregister_provider(const Glib::RefPtr<Gtk::TextBuffer>& buffer);

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The provider name.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Glib::ustring> property_name() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The provider name.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::ustring> property_name() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The provider icon.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy< Glib::RefPtr<Gdk::Pixbuf> > property_icon() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The provider icon.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::Pixbuf> > property_icon() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Number of proposals added in one batch.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<guint> property_proposals_batch_size() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Number of proposals added in one batch.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<guint> property_proposals_batch_size() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Number of lines scanned in one batch.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<guint> property_scan_batch_size() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Number of lines scanned in one batch.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<guint> property_scan_batch_size() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The minimum word size to complete.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<guint> property_minimum_word_size() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The minimum word size to complete.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<guint> property_minimum_word_size() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The delay before initiating interactive completion.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<int> property_interactive_delay() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** The delay before initiating interactive completion.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<int> property_interactive_delay() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Provider priority.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<int> property_priority() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Provider priority.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<int> property_priority() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} /* namespace Gsv */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gsv::SourceCompletionWords
   */
  Glib::RefPtr<Gsv::SourceCompletionWords> wrap(GtkSourceCompletionWords* object, bool take_copy = false);
}


#endif /* _GTKSOURCEVIEWMM_SOURCECOMPLETIONWORDS_H */
