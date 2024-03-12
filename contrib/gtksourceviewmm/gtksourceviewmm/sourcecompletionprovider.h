// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKSOURCEVIEWMM_SOURCECOMPLETIONPROVIDER_H
#define _GTKSOURCEVIEWMM_SOURCECOMPLETIONPROVIDER_H


#include <glibmm.h>

/* sourcecompletionprovider.h
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

#include <glibmm/interface.h>
#include <gtksourceview/gtksourcecompletionprovider.h>

#include <gtksourceviewmm/sourcecompletionactivation.h>
#include <gtksourceviewmm/sourcecompletioncontext.h>
#include <gtksourceviewmm/sourcecompletioninfo.h>
#include <gtksourceviewmm/sourcecompletionproposal.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkSourceCompletionProvider GtkSourceCompletionProvider;
typedef struct _GtkSourceCompletionProviderClass GtkSourceCompletionProviderClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gsv
{ class SourceCompletionProvider_Class; } // namespace Gsv
namespace Gsv
{

class SourceCompletionContext;

/** Completion provider interface.
 *
 * You must implement this interface to provide proposals to SourceCompletion.
 *
 * @newin{2,10}
 */

class SourceCompletionProvider : public Glib::Interface
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef SourceCompletionProvider CppObjectType;
  typedef SourceCompletionProvider_Class CppClassType;
  typedef GtkSourceCompletionProvider BaseObjectType;
  typedef GtkSourceCompletionProviderIface BaseClassType;

private:
  friend class SourceCompletionProvider_Class;
  static CppClassType sourcecompletionprovider_class_;

  // noncopyable
  SourceCompletionProvider(const SourceCompletionProvider&);
  SourceCompletionProvider& operator=(const SourceCompletionProvider&);

protected:
  SourceCompletionProvider(); // you must derive from this class

  /** Called by constructors of derived classes. Provide the result of 
   * the Class init() function to ensure that it is properly 
   * initialized.
   * 
   * @param interface_class The Class object for the derived type.
   */
  explicit SourceCompletionProvider(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface. 
  explicit SourceCompletionProvider(GtkSourceCompletionProvider* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~SourceCompletionProvider();

  static void add_interface(GType gtype_implementer);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkSourceCompletionProvider*       gobj()       { return reinterpret_cast<GtkSourceCompletionProvider*>(gobject_); }

  ///Provides access to the underlying C GObject.  
  const GtkSourceCompletionProvider* gobj() const { return reinterpret_cast<GtkSourceCompletionProvider*>(gobject_); }

private:

public:
  
  /** Get the name of the provider. This should be a translatable name for
   * display to the user. For example: _("Document word completion provider"). The
   * returned string must be freed with Glib::free().
   * @return A new string containing the name of the provider.
   */
  Glib::ustring get_name() const;

  
  /** Get the icon of the provider.
   *
   * @return The icon to be used for the provider, or empty Glib::RefPtr if the
   * provider does not have a special icon.
   *
   * @newin{2,10}
   */
  Glib::RefPtr<Gdk::Pixbuf> get_icon();

  
  /** Get the icon of the provider.
   *
   * @return The icon to be used for the provider, or empty Glib::RefPtr if the
   * provider does not have a special icon.
   *
   * @newin{2,10}
   */
  Glib::RefPtr<const Gdk::Pixbuf> get_icon() const;

  
  /** Populate @a context with proposals from a provider.
   *
   * @param context The SourceCompletionContext.
   *
   * @newin{2,10}
   */
  void populate(const Glib::RefPtr<SourceCompletionContext>& context);

  
  /** Get whether the provider match the context of completion detailed in
   *  @a context.
   *
   * @param context The SourceCompletionContext.
   *
   * @return @c true if provider matches the completion context, @c false
   * otherwise.
   *
   * @newin{2,10}
   */
  bool match(const Glib::RefPtr<const SourceCompletionContext>& context) const;

  
  /** Get a customized info widget to show extra information of a proposal.
   *
   * This allows for customized widgets on a proposal basis, although in general
   * providers will have the same custom widget for all their proposals and
   * @a proposal can be ignored. The implementation of this function is
   * optional. If implemented, update_info() @b must also be implemented. If not
   * implemented, the default get_info() will be used to display extra
   * information about a SourceCompletionProposal.
   *
   * @param proposal The currently selected SourceCompletionProposal.
   *
   * @return A custom Gtk::Widget to show extra information about @a proposal.
   *
   * @newin{2,10}
   */
  Gtk::Widget* get_info_widget(const Glib::RefPtr<const SourceCompletionProposal>& proposal);

  
  /** Get a customized info widget to show extra information of a proposal.
   *
   * This allows for customized widgets on a proposal basis, although in general
   * providers will have the same custom widget for all their proposals and
   * @a proposal can be ignored. The implementation of this function is
   * optional. If implemented, update_info() @b must also be implemented. If not
   * implemented, the default get_info() will be used to display extra
   * information about a SourceCompletionProposal.
   *
   * @param proposal The currently selected SourceCompletionProposal.
   *
   * @return A custom Gtk::Widget to show extra information about @a proposal.
   *
   * @newin{2,10}
   */
  const Gtk::Widget* get_info_widget(const Glib::RefPtr<const SourceCompletionProposal>& proposal) const;

  
  /** Update extra information shown in @a info for @a proposal.
   *
   * This should be implemented if your provider sets a custom info widget for
   * @a proposal. This function @b must be implemented when get_info_widget() is
   * implemented.
   *
   * @param proposal A SourceCompletionProposal.
   * @param info A SourceCompletionInfo.
   *
   * @newin{2,10}
   */
  void update_info(const Glib::RefPtr<const SourceCompletionProposal>& proposal, const SourceCompletionInfo& info);

 
  /** Get the Gtk::TextIter at which the completion for @a proposal starts.
   *
   * When implemented, the completion can use this information to position the
   * completion window accordingly when a proposal is selected in the completion
   * window.
   *
   * @param proposal A SourceCompletionProposal.
   * @param context A SourceCompletionContext.
   * @param iter A Gtk::TextIter.
   *
   * @return @c true if @a iter was set for @a proposal, @c false otherwise.
   *
   * @newin{2,10}
   */
  bool get_start_iter(const Glib::RefPtr<const SourceCompletionContext>& context, const Glib::RefPtr<const SourceCompletionProposal>& proposal, Gtk::TextIter& iter);

 
  /** Activate @a proposal at @a iter.
   *
   * When this functions returns <tt>false</tt>, the default activation of
   * @a proposal will take place which replaces the word at @a iter with the
   * label of @a proposal.
   *
   * @param proposal A SourceCompletionProposal.
   * @param iter A Gtk::TextIter.
   *
   * @return @c true to indicate that the proposal activation has been handled,
   * @c false otherwise.
   *
   * @newin{2,10}
   */
  bool activate_proposal(const Glib::RefPtr<SourceCompletionProposal>& proposal, const Gtk::TextIter& iter);

  
  /** Get with what kind of activation the provider should be activated.
   *
   * @return A combination of SourceCompletionActivation.
   *
   * @newin{2,10}
   */
  SourceCompletionActivation get_activation() const;

  
  /** Get the delay in milliseconds before starting interactive completion for
   *  this provider.
   *
   * A value of -1 indicates to use the default value as set
   * by SourceCompletion::property_auto_complete_delay().
   *
   * @return The interactive delay in milliseconds.
   *
   * @newin{2,10}
   */
  int get_interactive_delay() const;

  
  /** Get the provider priority.
   *
   * The priority determines the order in which proposals appear in the
   * completion popup. Higher priorities are sorted before lower priorities. The
   * default priority is 0.
   *
   * @return The provider priority.
   *
   * @newin{2,10}
   */
  int get_priority() const;

private:

    virtual Glib::ustring get_name_vfunc() const;


    virtual Glib::RefPtr<Gdk::Pixbuf> get_icon_vfunc();


    virtual void populate_vfunc(const Glib::RefPtr<SourceCompletionContext>& context);

 
    virtual bool match_vfunc(const Glib::RefPtr<const SourceCompletionContext>& context) const;

 
    virtual SourceCompletionActivation get_activation_vfunc() const;


    virtual Gtk::Widget* get_info_widget_vfunc(const Glib::RefPtr<const SourceCompletionProposal>& proposal) const;

 
    virtual void update_info_vfunc(const Glib::RefPtr<const SourceCompletionProposal>& proposal, const SourceCompletionInfo& info);

 
    virtual bool get_start_iter_vfunc(const Glib::RefPtr<const SourceCompletionContext>& context, const Glib::RefPtr<const SourceCompletionProposal>& proposal, Gtk::TextIter& iter);

 
    virtual bool activate_proposal_vfunc(const Glib::RefPtr<SourceCompletionProposal>& proposal, const Gtk::TextIter& iter);

 
    virtual int get_interactive_delay_vfunc() const;


    virtual int get_priority_vfunc() const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gsv


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gsv::SourceCompletionProvider
   */
  Glib::RefPtr<Gsv::SourceCompletionProvider> wrap(GtkSourceCompletionProvider* object, bool take_copy = false);

} // namespace Glib


#endif /* _GTKSOURCEVIEWMM_SOURCECOMPLETIONPROVIDER_H */

