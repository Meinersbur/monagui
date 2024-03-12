// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKSOURCEVIEWMM_SOURCECOMPLETION_P_H
#define _GTKSOURCEVIEWMM_SOURCECOMPLETION_P_H


#include <glibmm/private/object_p.h>

#include <glibmm/class.h>

namespace Gsv
{

class SourceCompletion_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef SourceCompletion CppObjectType;
  typedef GtkSourceCompletion BaseObjectType;
  typedef GtkSourceCompletionClass BaseClassType;
  typedef Glib::Object_Class CppClassParent;
  typedef GObjectClass BaseClassParent;

  friend class SourceCompletion;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void hide_callback(GtkSourceCompletion* self);
  static void populate_context_callback(GtkSourceCompletion* self, GtkSourceCompletionContext* p0);
  static void show_callback(GtkSourceCompletion* self);

  //Callbacks (virtual functions):
};


} // namespace Gsv


#endif /* _GTKSOURCEVIEWMM_SOURCECOMPLETION_P_H */

