SUBDIRS		= gtk-demo

pixmap_files	= background.jpg apple-red.png gnome-applets.png	\
		  gnome-foot.png gnome-gmush.png gnu-keys.png		\
		  gnome-calendar.png gnome-gimp.png gnome-gsame.png

EXTRA_DIST	= README $(pixmap_files)


noinst_PROGRAMS	= pixbuf-demo

pixbuf_demo_SOURCES = pixbuf-demo.cc

if GTKMM_ATKMM_ENABLED
ATKMMINC = -I$(top_builddir)/atk -I$(top_srcdir)/atk
endif

#Where to find the header files needed by the source files:
INCLUDES = -I$(top_builddir)/gtk   -I$(top_srcdir)/gtk   \
           -I$(top_builddir)/gdk   -I$(top_srcdir)/gdk   \
           $(ATKMMINC) \
           $(GTKMM_CFLAGS)

if GTKMM_ATKMM_ENABLED
ATKMMLIB = $(local_atkmm_lib)
endif

#The libraries that the executable needs to link against:
LIBS = $(ATKMMLIB) \
       $(top_builddir)/gdk/gdkmm/libgdkmm-2.4.la \
       $(top_builddir)/gtk/gtkmm/libgtkmm-2.4.la \
       $(GTKMM_LIBS)

