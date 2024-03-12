// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _ATKMM_HYPERLINK_P_H
#define _ATKMM_HYPERLINK_P_H


#include <glibmm/private/object_p.h>
#include <atk/atkobject.h>

#include <glibmm/class.h>

namespace Atk
{

class Hyperlink_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Hyperlink CppObjectType;
  typedef AtkHyperlink BaseObjectType;
  typedef AtkHyperlinkClass BaseClassType;
  typedef Glib::Object_Class CppClassParent;
  typedef GObjectClass BaseClassParent;

  friend class Hyperlink;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();

  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void link_activated_callback(AtkHyperlink* self);
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

  //Callbacks (virtual functions):
#ifdef GLIBMM_VFUNCS_ENABLED
  static gchar* get_uri_vfunc_callback(AtkHyperlink* self, gint i);
  static AtkObject* get_object_vfunc_callback(AtkHyperlink* self, gint i);
  static gint get_end_index_vfunc_callback(AtkHyperlink* self);
  static gint get_start_index_vfunc_callback(AtkHyperlink* self);
  static gboolean is_valid_vfunc_callback(AtkHyperlink* self);
  static gint get_n_anchors_vfunc_callback(AtkHyperlink* self);
  static guint link_state_vfunc_callback(AtkHyperlink* self);
  static gboolean is_selected_link_vfunc_callback(AtkHyperlink* self);
#endif //GLIBMM_VFUNCS_ENABLED
};


} // namespace Atk


#endif /* _ATKMM_HYPERLINK_P_H */
