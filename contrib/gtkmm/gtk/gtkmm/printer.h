// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_PRINTER_H
#define _GTKMM_PRINTER_H


#include <glibmm.h>

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

#include <gtkmm/pagesetup.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkPrinter GtkPrinter;
typedef struct _GtkPrinterClass GtkPrinterClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class Printer_Class; } // namespace Gtk
namespace Gtk
{

/** @addtogroup gtkmmEnums Enums and Flags */

/**
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>%PrintCapabilities operator|(PrintCapabilities, PrintCapabilities)</tt><br>
 * <tt>%PrintCapabilities operator&(PrintCapabilities, PrintCapabilities)</tt><br>
 * <tt>%PrintCapabilities operator^(PrintCapabilities, PrintCapabilities)</tt><br>
 * <tt>%PrintCapabilities operator~(PrintCapabilities)</tt><br>
 * <tt>%PrintCapabilities& operator|=(PrintCapabilities&, PrintCapabilities)</tt><br>
 * <tt>%PrintCapabilities& operator&=(PrintCapabilities&, PrintCapabilities)</tt><br>
 * <tt>%PrintCapabilities& operator^=(PrintCapabilities&, PrintCapabilities)</tt><br>
 */
enum PrintCapabilities
{
  PRINT_CAPABILITY_PAGE_SET = 1 << 0,
  PRINT_CAPABILITY_COPIES = 1 << 1,
  PRINT_CAPABILITY_COLLATE = 1 << 2,
  PRINT_CAPABILITY_REVERSE = 1 << 3,
  PRINT_CAPABILITY_SCALE = 1 << 4,
  PRINT_CAPABILITY_GENERATE_PDF = 1 << 5,
  PRINT_CAPABILITY_GENERATE_PS = 1 << 6,
  PRINT_CAPABILITY_PREVIEW = 1 << 7,
  PRINT_CAPABILITY_NUMBER_UP = 1 << 8,
  PRINT_CAPABILITY_NUMBER_UP_LAYOUT = 1 << 9
};

/** @ingroup gtkmmEnums */
inline PrintCapabilities operator|(PrintCapabilities lhs, PrintCapabilities rhs)
  { return static_cast<PrintCapabilities>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline PrintCapabilities operator&(PrintCapabilities lhs, PrintCapabilities rhs)
  { return static_cast<PrintCapabilities>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline PrintCapabilities operator^(PrintCapabilities lhs, PrintCapabilities rhs)
  { return static_cast<PrintCapabilities>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline PrintCapabilities operator~(PrintCapabilities flags)
  { return static_cast<PrintCapabilities>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline PrintCapabilities& operator|=(PrintCapabilities& lhs, PrintCapabilities rhs)
  { return (lhs = static_cast<PrintCapabilities>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline PrintCapabilities& operator&=(PrintCapabilities& lhs, PrintCapabilities rhs)
  { return (lhs = static_cast<PrintCapabilities>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline PrintCapabilities& operator^=(PrintCapabilities& lhs, PrintCapabilities rhs)
  { return (lhs = static_cast<PrintCapabilities>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gtk


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Gtk::PrintCapabilities> : public Glib::Value_Flags<Gtk::PrintCapabilities>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{


/** A Printer object represents a printer. You only need to deal directly with printers if you use the 
 * non-portable PrintUnixDialog API.
 *
 * A Printer object allows to get status information about the printer, such as its description, its location, 
 * the number of queued jobs, etc. Most importantly, a Printer object can be used to create a PrintJob object, 
 * which lets you print to the printer.
 *
 * @newin2p10
 *
 * @ingroup Printing
 */

class Printer : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef Printer CppObjectType;
  typedef Printer_Class CppClassType;
  typedef GtkPrinter BaseObjectType;
  typedef GtkPrinterClass BaseClassType;

private:  friend class Printer_Class;
  static CppClassType printer_class_;

private:
  // noncopyable
  Printer(const Printer&);
  Printer& operator=(const Printer&);

protected:
  explicit Printer(const Glib::ConstructParams& construct_params);
  explicit Printer(GtkPrinter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~Printer();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkPrinter*       gobj()       { return reinterpret_cast<GtkPrinter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkPrinter* gobj() const { return reinterpret_cast<GtkPrinter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkPrinter* gobj_copy();

private:

  //This is not available in on Win32.
//This source file will not be compiled,
//and the class will not be registered in wrap_init.h or wrap_init.cc


public:
  //TODO: _WRAP_CREATE() - probably not, it's only accessible through PrintUnixDialog + GtkPrintBackend should be ignored
  //TODO: I think these are not needed as well, and that Printer should generally be read-only - marko.
  
  
  bool equal(const Glib::RefPtr<Printer>& other) const;

  //GtkPrintBackend is in a "semi-private" header.
  //_WRAP_METHOD(Glib::RefPtr<PrintBackend> get_backend(), gtk_printer_get_backend, refreturn)
  //_WRAP_METHOD(Glib::RefPtr<const PrintBackend> get_backend() const, gtk_printer_get_backend, refreturn, constversion)
  

  /** Return value: the name of @a printer
   * @return The name of @a printer
   * 
   * @newin2p10.
   */
  Glib::ustring get_name() const;
  
  /** Return value: the state message of @a printer
   * @return The state message of @a printer
   * 
   * @newin2p10.
   */
  Glib::ustring get_state_message() const;
  
  /** Gets the description of the printer.
   * @return The description of @a printer
   * 
   * @newin2p10.
   */
  Glib::ustring get_description() const;
  
  /** Return value: the location of @a printer
   * @return The location of @a printer
   * 
   * @newin2p10.
   */
  Glib::ustring get_location() const;
  
  /** Gets the name of the icon to use for the printer.
   * @return The icon name for @a printer
   * 
   * @newin2p10.
   */
  Glib::ustring get_icon_name() const;
  
  /** Gets the number of jobs currently queued on the printer.
   * @return The number of jobs on @a printer
   * 
   * @newin2p10.
   */
  int get_job_count() const;
  
  /** Return value: <tt>true</tt> if @a printer is active
   * @return <tt>true</tt> if @a printer is active
   * 
   * @newin2p10.
   */
  bool is_active() const;
  
  /** Return value: <tt>true</tt> if @a printer is paused
   * @return <tt>true</tt> if @a printer is paused
   * 
   * @newin2p14.
   */
  bool is_paused() const;
  
  /** Return value: <tt>true</tt> if @a printer is accepting jobs
   * @return <tt>true</tt> if @a printer is accepting jobs
   * 
   * @newin2p14.
   */
  bool is_accepting_jobs() const;
  
  /** Return value: <tt>true</tt> if @a printer is virtual
   * @return <tt>true</tt> if @a printer is virtual
   * 
   * @newin2p10.
   */
  bool is_virtual() const;
  
  /** Return value: <tt>true</tt> if @a printer is the default
   * @return <tt>true</tt> if @a printer is the default
   * 
   * @newin2p10.
   */
  bool is_default() const;
  
  /** Return value: <tt>true</tt> if @a printer accepts PDF
   * @return <tt>true</tt> if @a printer accepts PDF
   * 
   * @newin2p10.
   */
  bool accepts_pdf() const;
  
  /** Return value: <tt>true</tt> if @a printer accepts PostScript
   * @return <tt>true</tt> if @a printer accepts PostScript
   * 
   * @newin2p10.
   */
  bool accepts_ps() const;

 
  /** Lists all the paper sizes @a printer supports.
   * This will return and empty list unless the printer's details are 
   * available, see has_details() and request_details().
   * @return A newly allocated list of newly allocated Gtk::PageSetup s.
   * 
   * @newin2p12.
   */
  Glib::ListHandle< Glib::RefPtr<PageSetup> > list_papers();

  
  /** Return value: a newly allocated Gtk::PageSetup with default page size of the printer.
   * @return A newly allocated Gtk::PageSetup with default page size of the printer.
   * 
   * Since: 2.13.
   */
  Glib::RefPtr<PageSetup> get_default_page_size() const;

 
  /** Lists all the paper sizes @a printer supports.
   * This will return and empty list unless the printer's details are 
   * available, see has_details() and request_details().
   * @return A newly allocated list of newly allocated Gtk::PageSetup s.
   * 
   * @newin2p12.
   */
  Glib::ListHandle< Glib::RefPtr<const PageSetup> > list_papers() const;

  
  /** Return value: <tt>true</tt> if @a printer details are available
   * @return <tt>true</tt> if @a printer details are available
   * 
   * @newin2p12.
   */
  bool has_details() const;
  
  /** Requests the printer details. When the details are available,
   * the details_acquired signal will be emitted.
   * 
   * @newin2p12
   */
  void request_details();
  
  /** Return value: the printer's capabilities
   * @return The printer's capabilities
   * 
   * @newin2p12.
   */
  PrintCapabilities get_capabilities() const;


  /**
   * @par Prototype:
   * <tt>void on_my_%details_acquired(bool success)</tt>
   */

  Glib::SignalProxy1< void,bool > signal_details_acquired();

  
  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Name of the printer.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::ustring> property_name() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  //GtkPrintBackend is in a "semi-private" header:
  //_WRAP_PROPERTY("backend", Glib::RefPtr<PrintBackend>)

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** FALSE if this represents a real hardware printer.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_is_virtual() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** String giving the current state of the printer.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::ustring> property_state_message() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The location of the printer.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::ustring> property_location() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** The icon name to use for the printer.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::ustring> property_icon_name() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** Number of jobs queued in the printer.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<int> property_job_count() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** TRUE if this printer can accept PDF.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_accepts_pdf() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** TRUE if this printer can accept PostScript.
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_accepts_ps() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


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
  virtual void on_details_acquired(bool success);
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


};

/** @relates Gtk::Printer */
inline bool operator==(const Glib::RefPtr<Printer>& lhs, const Glib::RefPtr<Printer>& rhs)
  { return lhs->equal(rhs); }

/** @relates Gtk::Printer */
inline bool operator!=(const Glib::RefPtr<Printer>& lhs, const Glib::RefPtr<Printer>& rhs)
  { return !lhs->equal(rhs); }

/** For example, 
 * bool on_enumerate_printers(const Glib::RefPtr<Printer>& printer);
 * @param printer A printer.
 * @param result true to stop the enumeration, false to continue. 
 *
 * @relates Gtk::Printer
 */
typedef sigc::slot< bool, const Glib::RefPtr<Printer>& > SlotPrinterEnumerator;

/** Calls a function for all Printers. If the callback returns true, the enumeration is stopped.
 * @slot A function to call for each printer
 * @parm wait If true, wait in a recursive mainloop until all printers are enumerated; otherwise return early.
 *
 * @relates Gtk::Printer
 */
void enumerate_printers(const SlotPrinterEnumerator& slot, bool wait = true);

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::Printer
   */
  Glib::RefPtr<Gtk::Printer> wrap(GtkPrinter* object, bool take_copy = false);
}


#endif /* _GTKMM_PRINTER_H */

