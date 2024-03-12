// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKSOURCEVIEWMM_SOURCEBUFFER_P_H
#define _GTKSOURCEVIEWMM_SOURCEBUFFER_P_H


#include <gtkmm/private/textbuffer_p.h>

#include <glibmm/class.h>

namespace gtksourceview
{

class SourceBuffer_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef SourceBuffer CppObjectType;
  typedef GtkSourceBuffer BaseObjectType;
  typedef GtkSourceBufferClass BaseClassType;
  typedef Gtk::TextBuffer_Class CppClassParent;
  typedef GtkTextBufferClass BaseClassParent;

  friend class SourceBuffer;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();

  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

  //Callbacks (virtual functions):
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED
};


} // namespace gtksourceview


#endif /* _GTKSOURCEVIEWMM_SOURCEBUFFER_P_H */
