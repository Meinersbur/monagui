/* gtksourceview/gtksourceviewmmconfig.h.  Generated from gtksourceviewmmconfig.h.in by configure.  */
#ifndef _GTKSOURCEVIEWMM_CONFIG_H
#define _GTKSOURCEVIEWMM_CONFIG_H 1

/* version numbers */
#define GTKSOURCEVIEWMM_MAJOR_VERSION 2
#define GTKSOURCEVIEWMM_MINOR_VERSION 3
#define GTKSOURCEVIEWMM_MICRO_VERSION 1

// detect common platforms
#if defined(_WIN32)
// Win32 compilers have a lot of varation
#if defined(_MSC_VER)
#define GTKSOURCEVIEWMM_MSC
#define GTKSOURCEVIEWMM_WIN32
#define GTKSOURCEVIEWMM_DLL
#elif defined(__CYGWIN__)
#define GTKSOURCEVIEWMM_CONFIGURE
#elif defined(__MINGW32__)
#define GTKSOURCEVIEWMM_WIN32
#define GTKSOURCEVIEWMM_CONFIGURE
#else
//AIX clR compiler complains about this even though it doesn't get this far:
//#warning "Unknown architecture (send me gcc --dumpspecs or equiv)"
#endif
#else
#define GTKSOURCEVIEWMM_CONFIGURE
#endif /* _WIN32 */

#ifdef GTKSOURCEVIEWMM_CONFIGURE
/* compiler feature tests that are used during compile time and run-time
   by gtk-- only. tests used by gdk-- and gtk-- should go into
   gdk--config.h.in */
/* #undef GTKSOURCEVIEWMM_CXX_HAVE_MUTABLE */
/* #undef GTKSOURCEVIEWMM_CXX_HAVE_NAMESPACES */
//#undef GTKSOURCEVIEWMM_CXX_GAUB
//#undef GTKSOURCEVIEWMM_CXX_AMBIGUOUS_TEMPLATES
/* #undef GTKSOURCEVIEWMM_HAVE_NAMESPACE_STD */
/* #undef GTKSOURCEVIEWMM_HAVE_STD_ITERATOR_TRAITS */
/* #undef GTKSOURCEVIEWMM_HAVE_SUN_REVERSE_ITERATOR */
/* #undef GTKSOURCEVIEWMM_HAVE_TEMPLATE_SEQUENCE_CTORS */
/* #undef GTKSOURCEVIEWMM_HAVE_DISAMBIGUOUS_CONST_TEMPLATE_SPECIALIZATIONS */
/* #undef GTKSOURCEVIEWMM_COMPILER_SUN_FORTE */
/* #undef GTKSOURCEVIEWMM_DEBUG_REFCOUNTING */
/* #undef GTKSOURCEVIEWMM_CAN_USE_DYNAMIC_CAST_IN_UNUSED_TEMPLATE_WITHOUT_DEFINITION */
/* #undef GTKSOURCEVIEWMM_CAN_ASSIGN_NON_EXTERN_C_FUNCTIONS_TO_EXTERN_C_CALLBACKS */
/* #undef GTKSOURCEVIEWMM_CAN_USE_NAMESPACES_INSIDE_EXTERNC */
/* #undef GTKSOURCEVIEWMM_HAVE_ALLOWS_STATIC_INLINE_NPOS */
#endif

#ifdef GTKSOURCEVIEWMM_MSC
  #define GTKSOURCEVIEWMM_CXX_HAVE_MUTABLE 1
  #define GTKSOURCEVIEWMM_CXX_HAVE_NAMESPACES 1
  #define GTKSOURCEVIEWMM_HAVE_NAMESPACE_STD 1
  #define GTKSOURCEVIEWMM_HAVE_STD_ITERATOR_TRAITS 1
  #define GTKSOURCEVIEWMM_HAVE_TEMPLATE_SEQUENCE_CTORS 2
  #define GTKSOURCEVIEWMM_HAVE_DISAMBIGUOUS_CONST_TEMPLATE_SPECIALIZATIONS 1
  #define GTKSOURCEVIEWMM_CAN_USE_DYNAMIC_CAST_IN_UNUSED_TEMPLATE_WITHOUT_DEFINITION 1
  #define GTKSOURCEVIEWMM_CAN_ASSIGN_NON_EXTERN_C_FUNCTIONS_TO_EXTERN_C_CALLBACKS 1
  #define GTKSOURCEVIEWMM_CAN_USE_NAMESPACES_INSIDE_EXTERNC 1
  #pragma warning (disable: 4786 4355 4800 4181)
#endif

#ifndef GTKSOURCEVIEWMM_HAVE_NAMESPACE_STD
#  define GTKSOURCEVIEWMM_USING_STD(Symbol) namespace std { using ::Symbol; }
#else
#  define GTKSOURCEVIEWMM_USING_STD(Symbol) /* empty */
#endif

#ifdef GTKSOURCEVIEWMM_DLL
  #if defined(GTKSOURCEVIEWMM_BUILD) && defined(_WINDLL)
    /* Do not dllexport as it is handled by gendef on MSVC */
    #define GTKSOURCEVIEWMM_API 
  #elif !defined(GTKSOURCEVIEWMM_BUILD)
    #define GTKSOURCEVIEWMM_API __declspec(dllimport)
  #else
    /* Build a static library */
    #define GTKSOURCEVIEWMM_API
  #endif /* GTKSOURCEVIEWMM_BUILD - _WINDLL */
#else
  #define GTKSOURCEVIEWMM_API
#endif /* GTKSOURCEVIEWMM_DLL */

#endif /* _GTKSOURCEVIEWMM_CONFIG_H */

