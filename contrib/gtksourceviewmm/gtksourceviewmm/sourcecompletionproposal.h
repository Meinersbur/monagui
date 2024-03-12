#ifndef HEADER_14CF8D50E7E45B93
#define HEADER_14CF8D50E7E45B93

// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKSOURCEVIEWMM_SOURCECOMPLETIONPROPOSAL_H
#define _GTKSOURCEVIEWMM_SOURCECOMPLETIONPROPOSAL_H


#include <glibmm.h>

/* sourcecompletionproposal.h
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
#include <glibmm/ustring.h>
#include <gdkmm/pixbuf.h>
#include <gtksourceview/gtksourcecompletionproposal.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkSourceCompletionProposal GtkSourceCompletionProposal;
typedef struct _GtkSourceCompletionProposalClass GtkSourceCompletionProposalClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gsv
{ class SourceCompletionProposal_Class; } // namespace Gsv
namespace Gsv
{

/** Completion proposal object.
 *
 * The proposal interface represents a completion item in the completion window.
 * It provides information on how to display the completion item and what action
 * should be taken when the completion item is activated.
 *
 * @newin{2,10}
 */

class SourceCompletionProposal : public Glib::Interface
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef SourceCompletionProposal CppObjectType;
  typedef SourceCompletionProposal_Class CppClassType;
  typedef GtkSourceCompletionProposal BaseObjectType;
  typedef GtkSourceCompletionProposalIface BaseClassType;

private:
  friend class SourceCompletionProposal_Class;
  static CppClassType sourcecompletionproposal_class_;

  // noncopyable
  SourceCompletionProposal(const SourceCompletionProposal&);
  SourceCompletionProposal& operator=(const SourceCompletionProposal&);

protected:
  SourceCompletionProposal(); // you must derive from this class

  /** Called by constructors of derived classes. Provide the result of 
   * the Class init() function to ensure that it is properly 
   * initialized.
   * 
   * @param interface_class The Class object for the derived type.
   */
  explicit SourceCompletionProposal(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface. 
  explicit SourceCompletionProposal(GtkSourceCompletionProposal* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~SourceCompletionProposal();

  static void add_interface(GType gtype_implementer);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkSourceCompletionProposal*       gobj()       { return reinterpret_cast<GtkSourceCompletionProposal*>(gobject_); }

  ///Provides access to the underlying C GObject.  
  const GtkSourceCompletionProposal* gobj() const { return reinterpret_cast<GtkSourceCompletionProposal*>(gobject_); }

private:


public:
  
  /** Gets the label of a proposal.
   *
   * The label is shown in the list of proposals as plain text. If you need any
   * markup (such as bold or italic text), you have to implement get_markup().
   *
   * @return The label of a proposal.
   *
   * @newin{2,10}
   */
  Glib::ustring get_label() const;

  
  /** Gets the label of a proposal with markup. The label is shown in the list
   * of proposals and may contain markup. This will be used instead of
   * get_label() if implemented.
   *
   * @return The label of a proposal with markup.
   *
   * @newin{2,10}
   */
  Glib::ustring get_markup() const;

  
  /** Gets the text of a proposal.
   *
   * The text that is inserted into the text buffer when the proposal is
   * activated by the default activation. You are free to implement a custom
   * activation handler in the provider and not implement this function.
   *
   * @return The text of a proposal.
   *
   * @newin{2,10}
   */
  Glib::ustring get_text() const;

  
  /** Gets the icon of a proposal.
   *
   * @return The icon of a proposal.
   *
   * @newin{2,10}
   */
  Glib::RefPtr<Gdk::Pixbuf> get_icon();

  
  /** Gets the icon of a proposal.
   *
   * @return The icon of a proposal.
   *
   * @newin{2,10}
   */
  Glib::RefPtr<const Gdk::Pixbuf> get_icon() const;

  
  /** Gets extra information associated to the proposal.
   *
   * This information will be used to present the user with extra, detailed
   * information about the selected proposal.
   *
   * @return The extra information of a proposal or empty string if no extra
   * information is associated to a proposal.
   *
   * @newin{2,10}
   */
  Glib::ustring get_info() const;

  
  /** Emits the "changed" signal on a proposal.
   *
   * This should be called by implementations whenever the name, icon or info of
   * the proposal has changed.
   *
   * @newin{2,10}
   */
  void changed();

  
  /** Get the hash value of a proposal.
   *
   * This is used to (together with equal()) to match proposals in the
   * completion model. By default, it uses a direct hash.
   *
   * @return The hash value of a proposal.
   *
   * @newin{2,10}
   */
  guint hash() const;

  
  /** Get whether two proposal objects are the same.
   *
   * This is used to (together with hash()) to match proposals in the
   * completion model. By default, it uses direct equality.
   *
   * @param other A SourceCompletionProposal.
   * @return @c true if a proposal and @a other are the same proposal.
   *
   * @newin{2,10}
   */
  bool equal(const Glib::RefPtr<const SourceCompletionProposal>& other) const;

  /** Emitted when the proposal has changed.
   *
   * The completion popup will react to this by updating the shown information.
   *
   * @newin{2,10}
   *
   * @par Prototype:
   * <tt>void on_my_%changed()</tt>
   */

  Glib::SignalProxy0< void > signal_changed();


private:

    virtual Glib::ustring get_label_vfunc() const;


    virtual Glib::ustring get_markup_vfunc() const;


    virtual Glib::ustring get_text_vfunc() const;


    virtual Glib::RefPtr<Gdk::Pixbuf> get_icon_vfunc() const;


    virtual Glib::ustring get_info_vfunc() const;


    virtual guint hash_vfunc() const;


    virtual bool equal_vfunc(const Glib::RefPtr<const SourceCompletionProposal>& other) const;

 
public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  virtual void on_changed();


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
   * @relates Gsv::SourceCompletionProposal
   */
  Glib::RefPtr<Gsv::SourceCompletionProposal> wrap(GtkSourceCompletionProposal* object, bool take_copy = false);

} // namespace Glib


#endif /* _GTKSOURCEVIEWMM_SOURCECOMPLETIONPROPOSAL_H */


#endif // header guard 
