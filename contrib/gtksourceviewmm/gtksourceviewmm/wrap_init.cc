
#define Gsv gtksourceview
#include <glib.h>

// Disable the 'const' function attribute of the get_type() functions.
// GCC would optimize them out because we don't use the return value.
#undef  G_GNUC_CONST
#define G_GNUC_CONST /* empty */

#include <gtksourceviewmm/wrap_init.h>
#include <glibmm/error.h>
#include <glibmm/object.h>

// #include the widget headers so that we can call the get_type() static methods:

#include "sourcestyle.h"
#include "sourcestylescheme.h"
#include "sourcelanguage.h"
#include "sourcelanguagemanager.h"
#include "sourceview.h"
#include "sourcebuffer.h"
#include "sourceiter.h"
#include "sourcemark.h"
#include "sourcestyleschememanager.h"
#include "sourcecompletion.h"
#include "sourcecompletioncontext.h"
#include "sourcecompletioninfo.h"
#include "sourcecompletionproposal.h"
#include "sourcecompletionprovider.h"
#include "sourcecompletionitem.h"
#include "sourcecompletionwords.h"

extern "C"
{

//Declarations of the *_get_type() functions:

GType gtk_source_buffer_get_type(void);
GType gtk_source_language_get_type(void);
GType gtk_source_language_manager_get_type(void);
GType gtk_source_mark_get_type(void);
GType gtk_source_style_get_type(void);
GType gtk_source_style_scheme_manager_get_type(void);
GType gtk_source_view_get_type(void);
GType gtk_source_completion_get_type(void);
GType gtk_source_completion_context_get_type(void);
GType gtk_source_completion_info_get_type(void);
GType gtk_source_completion_proposal_get_type(void);
GType gtk_source_completion_provider_get_type(void);
GType gtk_source_completion_item_get_type(void);
GType gtk_source_completion_words_get_type(void);

//Declarations of the *_error_quark() functions:

} // extern "C"


//Declarations of the *_Class::wrap_new() methods, instead of including all the private headers:

namespace Gsv {  class SourceBuffer_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gsv {  class SourceLanguage_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gsv {  class SourceLanguageManager_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gsv {  class SourceMark_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gsv {  class SourceStyle_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gsv {  class SourceStyleSchemeManager_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gsv {  class SourceView_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gsv {  class SourceCompletion_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gsv {  class SourceCompletionContext_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gsv {  class SourceCompletionInfo_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gsv {  class SourceCompletionProposal_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gsv {  class SourceCompletionProvider_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gsv {  class SourceCompletionItem_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }
namespace Gsv {  class SourceCompletionWords_Class { public: static Glib::ObjectBase* wrap_new(GObject*); };  }

namespace Gsv { 

void wrap_init()
{
  // Register Error domains:

// Map gtypes to gtkmm wrapper-creation functions:
  Glib::wrap_register(gtk_source_buffer_get_type(), &Gsv::SourceBuffer_Class::wrap_new);
  Glib::wrap_register(gtk_source_language_get_type(), &Gsv::SourceLanguage_Class::wrap_new);
  Glib::wrap_register(gtk_source_language_manager_get_type(), &Gsv::SourceLanguageManager_Class::wrap_new);
  Glib::wrap_register(gtk_source_mark_get_type(), &Gsv::SourceMark_Class::wrap_new);
  Glib::wrap_register(gtk_source_style_get_type(), &Gsv::SourceStyle_Class::wrap_new);
  Glib::wrap_register(gtk_source_style_scheme_manager_get_type(), &Gsv::SourceStyleSchemeManager_Class::wrap_new);
  Glib::wrap_register(gtk_source_view_get_type(), &Gsv::SourceView_Class::wrap_new);
  Glib::wrap_register(gtk_source_completion_get_type(), &Gsv::SourceCompletion_Class::wrap_new);
  Glib::wrap_register(gtk_source_completion_context_get_type(), &Gsv::SourceCompletionContext_Class::wrap_new);
  Glib::wrap_register(gtk_source_completion_info_get_type(), &Gsv::SourceCompletionInfo_Class::wrap_new);
  Glib::wrap_register(gtk_source_completion_proposal_get_type(), &Gsv::SourceCompletionProposal_Class::wrap_new);
  Glib::wrap_register(gtk_source_completion_provider_get_type(), &Gsv::SourceCompletionProvider_Class::wrap_new);
  Glib::wrap_register(gtk_source_completion_item_get_type(), &Gsv::SourceCompletionItem_Class::wrap_new);
  Glib::wrap_register(gtk_source_completion_words_get_type(), &Gsv::SourceCompletionWords_Class::wrap_new);
  
  // Register the gtkmm gtypes:
  Gsv::SourceBuffer::get_type();
  Gsv::SourceLanguage::get_type();
  Gsv::SourceLanguageManager::get_type();
  Gsv::SourceMark::get_type();
  Gsv::SourceStyle::get_type();
  Gsv::SourceStyleSchemeManager::get_type();
  Gsv::SourceView::get_type();
  Gsv::SourceCompletion::get_type();
  Gsv::SourceCompletionContext::get_type();
  Gsv::SourceCompletionInfo::get_type();
  Gsv::SourceCompletionProposal::get_type();
  Gsv::SourceCompletionProvider::get_type();
  Gsv::SourceCompletionItem::get_type();
  Gsv::SourceCompletionWords::get_type();
} // wrap_init()

} //gtksourceview


