// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKSOURCEVIEWMM_SOURCELANGUAGE_H
#define _GTKSOURCEVIEWMM_SOURCELANGUAGE_H


#include <glibmm.h>

/* sourcebuffer.hg
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

/// \file
/// \brief the SourceLanguage class

#include <glibmm/object.h>
#include <gtksourceviewmm/sourcestylescheme.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkSourceLanguage GtkSourceLanguage;
typedef struct _GtkSourceLanguageClass GtkSourceLanguageClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace gtksourceview
{ class SourceLanguage_Class; } // namespace gtksourceview
namespace gtksourceview
{

class SourceLanguageManager ;


/// \brief The abstraction of a language.
///
/// Languages are used in the syntax highlighting
/// workflow.

class SourceLanguage : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef SourceLanguage CppObjectType;
  typedef SourceLanguage_Class CppClassType;
  typedef GtkSourceLanguage BaseObjectType;
  typedef GtkSourceLanguageClass BaseClassType;

private:  friend class SourceLanguage_Class;
  static CppClassType sourcelanguage_class_;

private:
  // noncopyable
  SourceLanguage(const SourceLanguage&);
  SourceLanguage& operator=(const SourceLanguage&);

protected:
  explicit SourceLanguage(const Glib::ConstructParams& construct_params);
  explicit SourceLanguage(GtkSourceLanguage* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~SourceLanguage();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkSourceLanguage*       gobj()       { return reinterpret_cast<GtkSourceLanguage*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkSourceLanguage* gobj() const { return reinterpret_cast<GtkSourceLanguage*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkSourceLanguage* gobj_copy();

private:


protected:
  SourceLanguage();

public:

  /// \brief create a language.
  ///
  /// \return the newly created language
  
  static Glib::RefPtr<SourceLanguage> create();


  /// \brief get language ID
  ///
  /// a language ID is unique among language IDs.
  /// \return the langugae ID.
  
  /** Returns: the ID of @a language.
   * @return The ID of @a language.
   * The returned string is owned by @a language and should not be freed
   * or modified.
   */
  Glib::ustring get_id() const;

  /// \brief gets the localized name of the language.
  ///
  /// \return the localized name of the language
  
  /** Returns: the name of @a language.
   * @return The name of @a language.
   * The returned string is owned by @a language and should not be freed
   * or modified.
   */
  Glib::ustring get_name() const;

  /// \brief the localized section of the language.
  ///
  /// Each language belong to a section (ex. HTML belogs to the Markup section).
  /// \return the localized section of the language.
  
  /** Returns: the section of @a language.
   * @return The section of @a language.
   * The returned string is owned by @a language and should not be freed
   * or modified.
   */
  Glib::ustring get_section() const;

  /// \brief Whether the language should be hidden from the user.
  ///
  /// \return true if the language should be hidden, false otherwise.
  
  /** Returns: <tt>true</tt> if the language should be hidden, <tt>false</tt> otherwise.
   * @return <tt>true</tt> if the language should be hidden, <tt>false</tt> otherwise.
   */
  gboolean get_hidden() const;

 
  /// \brief gets the list of mime types for the given language.
  ///
  /// After usage you should free each element of the list as well as the list itself.
  /// \return the list of  mime types for the given language.
  
  /** Returns: a newly-allocated <tt>0</tt> terminated array containing
   * @return A newly-allocated <tt>0</tt> terminated array containing
   * the mime types or <tt>0</tt> if no mime types are found.
   * The returned array must be freed with Glib::strfreev().
   */
  Glib::StringArrayHandle get_mime_types() const;
  
  /** Returns: a newly-allocated <tt>0</tt> terminated array containing
   * @return A newly-allocated <tt>0</tt> terminated array containing
   * the globs or <tt>0</tt> if no globs are found.
   * The returned array must be freed with Glib::strfreev().
   */
  Glib::StringArrayHandle get_globs() const;
  
  /** Returns: a  <tt>0</tt> terminated array containing
   * @return A  <tt>0</tt> terminated array containing
   * ids of the styles defined by this @a language or <tt>0</tt> if no style is
   * defined.  The returned array must be freed with Glib::strfreev().
   */
  Glib::StringArrayHandle get_style_ids() const;

  
  /** Returns: the name of the style with ID @a style_id defined by this @a language or
   * @param style_id A style ID.
   * @return The name of the style with ID @a style_id defined by this @a language or
   * <tt>0</tt> if the style has no name or there is no style with ID @a style_id defined
   * by this @a language. The returned string is owned by the @a language and must
   * not be modified.
   */
  Glib::ustring get_style_name(const Glib::ustring& style_id) const;
  
  /** 
   * @param name Metadata property name.
   * @return Value of property @a name stored in the metadata of @a language
   * or <tt>0</tt> if language doesn't contain that metadata property.
   * The returned string is owned by @a language and should not be freed
   * or modified.
   */
  Glib::ustring get_metadata(const Glib::ustring& name) const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

protected:
  //GTK+ Virtual Functions (override these to change behaviour):
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

  //Default Signal Handlers::
#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


};

} /* namespace gtksourceview */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates gtksourceview::SourceLanguage
   */
  Glib::RefPtr<gtksourceview::SourceLanguage> wrap(GtkSourceLanguage* object, bool take_copy = false);
}


#endif /* _GTKSOURCEVIEWMM_SOURCELANGUAGE_H */
