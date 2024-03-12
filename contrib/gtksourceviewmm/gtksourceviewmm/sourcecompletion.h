#ifndef HEADER_7C78B3E7FBDFA1F0
#define HEADER_7C78B3E7FBDFA1F0

// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKSOURCEVIEWMM_SOURCECOMPLETION_H
#define _GTKSOURCEVIEWMM_SOURCECOMPLETION_H

#include <glibmm.h>

/* sourcecompletion.h
 *
 * Copyright (C) 2009, 2010, 2011 Krzesimir Nowak
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

#include <vector>

#include <glibmm/object.h>

#include <gtksourceviewmm/sourcecompletioncontext.h>
#include <gtksourceviewmm/sourcecompletionprovider.h>
#include <gtksourceviewmm/sourceview.h>
#include <gtksourceviewmm/sourcecompletioninfo.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkSourceCompletion GtkSourceCompletion;
typedef struct _GtkSourceCompletionClass GtkSourceCompletionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gsv
{ class SourceCompletion_Class; } // namespace Gsv
namespace Gsv
{

class SourceCompletionContext;
class SourceCompletionProvider;

class SourceCompletionError : public Glib::Error
{
public:
  enum Code
  {
    ALREADY_BOUND,
    NOT_BOUND
  };

  SourceCompletionError(Code error_code, const Glib::ustring& error_message);
  explicit SourceCompletionError(GError* gobject);
  Code code() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  static void throw_func(GError* gobject);

  friend void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};

} // namespace Gsv

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gsv::SourceCompletionError::Code> : public Glib::Value_Enum<Gsv::SourceCompletionError::Code>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gsv
{


/** Main Completion Object
 *
 * @newin{2,10}
 */

class SourceCompletion : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef SourceCompletion CppObjectType;
  typedef SourceCompletion_Class CppClassType;
  typedef GtkSourceCompletion BaseObjectType;
  typedef GtkSourceCompletionClass BaseClassType;

private:  friend class SourceCompletion_Class;
  static CppClassType sourcecompletion_class_;

private:
  // noncopyable
  SourceCompletion(const SourceCompletion&);
  SourceCompletion& operator=(const SourceCompletion&);

protected:
  explicit SourceCompletion(const Glib::ConstructParams& construct_params);
  explicit SourceCompletion(GtkSourceCompletion* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~SourceCompletion();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkSourceCompletion*       gobj()       { return reinterpret_cast<GtkSourceCompletion*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkSourceCompletion* gobj() const { return reinterpret_cast<GtkSourceCompletion*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkSourceCompletion* gobj_copy();

private:

public:

  
  /** Add a new SourceCompletionProvider to the completion object.
   *
   * This will add a reference provider.
   *
   * @param provider A SourceCompletionProvider.
   *
   * @return @c true if provider was successfully added, otherwise error is
   * thrown.
   *
   * @newin{2,10}
   */
  bool add_provider(const Glib::RefPtr<SourceCompletionProvider>& provider);

  
  /** Remove provider from the completion.
   *
   * @param provider A SourceCompletionProvider.
   *
   * @return @c true if provider was successfully removed, otherwise error is
   * thrown.
   *
   * @newin{2,10}
   */
  bool remove_provider(const Glib::RefPtr<SourceCompletionProvider>& provider);

 
  /** Get list of providers registered on completion.
   *
   * @return List of SourceCompletionProvider.
   *
   * @newin{2,10}
   */
  std::vector<Glib::RefPtr<SourceCompletionProvider> > get_providers() const;

 
  /** Starts a new completion with the specified SourceCompletionContext and
   *  a list of potential candidate providers for completion.
   *
   * @param providers A list of SourceCompletionProvider.
   * @param context The SourceCompletionContext with which to start the
   * completion.
   *
   * @return @c true if it was possible to the show completion window.
   *
   * @newin{2,10}
   */
  bool show(const std::vector<Glib::RefPtr<SourceCompletionProvider> >& providers, const Glib::RefPtr<SourceCompletionContext>& context);

  
  /** Hides the completion if it is active (visible).
   *
   * @newin{2,10}
   */
  void hide();

  
  /** Gets the SourceCompletionInfo window.
   *
   * The info widget is the window where the completion displays optional extra information of the proposal.
   *
   * @return The SourceCompletionInfo window.
   *
   * @newin{2,10}
   */
  SourceCompletionInfo* get_info_window();

  
  /** Gets the SourceCompletionInfo window.
   *
   * The info widget is the window where the completion displays optional extra information of the proposal.
   *
   * @return The SourceCompletionInfo window.
   *
   * @newin{2,10}
   */
  const SourceCompletionInfo* get_info_window() const;

  
  /** Gets the SourceView associated with completion.
   *
   * @return The SourceView associated with completion.
   *
   * @newin{2,10}
   */
  SourceView* get_view();

  
  /** Gets the SourceView associated with completion.
   *
   * @return The SourceView associated with completion.
   *
   * @newin{2,10}
   */
  const SourceView* get_view() const;

  // TODO: Does "The reference being returned is a 'floating' reference, so if you invoke gtk_source_completion_show with this context you don't need to unref it." something mean for us? krnowak
 

  /** Create a new SourceCompletionContext for completion.
   *
   * The position at which the completion using the new context will consider
   * completion can be provided by @a position.
   *
   * @param position A Gtk::TextIter.
   *
   * @return A new SourceCompletionContext.
   *
   * @newin{2,10}
   */
  Glib::RefPtr<SourceCompletionContext> create_context(const Gtk::TextIter& position);

  // TODO: better wording could be used here - it is too convoluted. krnowak
  /** Create a new SourceCompletionContext for completion.
   *
   * The position at which the completion using the new context will consider
   * completion is current cursor position.
   *
   * @return A new SourceCompletionContext.
   *
   * @newin{2,10}
   */
  Glib::RefPtr<SourceCompletionContext> create_context();

  
  /** Move the completion window to a specific iter.
   *
   * @param iter A Gtk::TextIter.
   *
   * @newin{2,10}
   */
  void move_window(const Gtk::TextIter& iter);

  
  /** Block interactive completion.
   *
   * This can be used to disable interactive completion when inserting or
   * deleting text from the buffer associated with the completion. Use
   * unblock_interactive() to enable interactive completion again.
   *
   * @newin{2,10}
   */
  void block_interactive();

  
  /** Unblock interactive completion.
   *
   * This can be used after using block_interactive() to enable interactive
   * completion again.
   *
   * @newin{2,10}
   */
  void unblock_interactive();

  /** Emitted when the completion window is hidden.
   *
   * The default handler will actually hide the window.
   *
   * @newin{2,10}
   *
   * @par Prototype:
   * <tt>void on_my_%hide()</tt>
   */

  Glib::SignalProxy0< void > signal_hide();


  /** Emitted just before starting to populate the completion with providers.
   *
   * You can use this signal to add additional attributes in the context.
   *
   * @par Handler parameters:
   * context The context for current completion.
   *
   * @newin{2,10}
   *
   * @par Prototype:
   * <tt>void on_my_%populate_context(const Glib::RefPtr<SourceCompletionContext>& context)</tt>
   */

  Glib::SignalProxy1< void,const Glib::RefPtr<SourceCompletionContext>& > signal_populate_context();

 
  /** Emitted when the completion window is shown.
   *
   * The default handler will actually show the window.
   *
   * @newin{2,10}
   *
   * @par Prototype:
   * <tt>void on_my_%show()</tt>
   */

  Glib::SignalProxy0< void > signal_show();

// those are keybinding signals, so ignore them
  
  
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Number of proposal accelerators to show.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<guint> property_accelerators() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Number of proposal accelerators to show.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<guint> property_accelerators() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Completion popup delay for interactive completion.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<guint> property_auto_complete_delay() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Completion popup delay for interactive completion.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<guint> property_auto_complete_delay() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Proposal scrolling page size.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<guint> property_proposal_page_size() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Proposal scrolling page size.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<guint> property_proposal_page_size() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Provider scrolling page size.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<guint> property_provider_page_size() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Provider scrolling page size.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<guint> property_provider_page_size() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Remember the last info window visibility state.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_remember_info_visibility() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Remember the last info window visibility state.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_remember_info_visibility() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Select first proposal when completion is shown.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_select_on_show() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Select first proposal when completion is shown.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_select_on_show() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Show provider headers when proposals from multiple providers are available.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_show_headers() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Show provider headers when proposals from multiple providers are available.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_show_headers() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Show provider and proposal icons in the completion popup.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_show_icons() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** Show provider and proposal icons in the completion popup.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_show_icons() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The GtkSourceView bound to the completion.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<SourceView*> property_view() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  virtual void on_hide();
  virtual void on_populate_context(const Glib::RefPtr<SourceCompletionContext>& context);
  virtual void on_show();


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
   * @relates Gsv::SourceCompletion
   */
  Glib::RefPtr<Gsv::SourceCompletion> wrap(GtkSourceCompletion* object, bool take_copy = false);
}


#endif /* _GTKSOURCEVIEWMM_SOURCECOMPLETION_H */

#endif // header guard 
