# Process this file with automake to produce Makefile.in (in this,
# and all subdirectories).

EXTRA_DIST =
MAINTAINERCLEANFILES = 
CLEANFILES = 

nobase_dist_pkgdata_DATA =

#gladedir = $(pkgdatadir)/glade
#langspecdir = $(pkgdatadir)/language-specs
#templatedir = $(pkgdatadir)/templates

# The EXTRA_DIST argument holds a list of all the files that are part of the package, but are not installed by default and were not specified in any other way.
EXTRA_DIST += AUTHORS autogen.sh ChangeLog filelist.am lib_finder.script makefilelist.sh monagui.anjuta monagui.cbp NEWS README
#MAINTAINERCLEANFILES += aclocal.m4 config.guess src/guiconfig.h.in Makefile.in

include filelist.am


bin_PROGRAMS = monagui
EXTRA_PROGRAMS = src/front2/completiongen

DEFS += -DPKGDATADIR=\"${pkgdatadir}\" -DUSE_MALLOC -DNDEBUG
AM_LFLAGS = -v -Cfa -L
AM_YFLAGS = -d

# Maybe we can make some convenience libraries instead
# This gives an incredibly loooooooooooooooooooooooooooong command line for linking
monagui_SOURCES = src/front2/parser.ypp src/front2/scanner.lpp src/front2/activetable.cpp src/front2/activetable.h src/front2/completiontable.cpp src/front2/completiontable.h \
	$(src_cpp) $(src_c) $(src_h) $(src_front2_cpp) $(src_front2_c) $(src_front2_h)  \
	$(contrib_mona_bdd_c) $(contrib_mona_bdd_h) $(contrib_mona_dfa_c) $(contrib_mona_dfa_h) $(contrib_mona_gta_c) $(contrib_mona_gta_h) $(contrib_mona_mem_c) $(contrib_mona_mem_h) \
	$(contrib_boost_cpp) $(contrib_boost_hpp) \
	$(contrib_gtksourceviewmm_cc) $(contrib_gtksourceviewmm_h)
#monagui_DATA = doc/codecompletion.png doc/editwin.png doc/index.html doc/newdialog.png doc/resultwin.png
nobase_dist_pkgdata_DATA += glade/about.glade glade/editor.glade glade/newfile.glade glade/progress.glade glade/result.glade
nobase_dist_pkgdata_DATA += language-specs/mona.lang
nobase_dist_pkgdata_DATA += templates/ws1s_tutorial.mona



monagui_CPPFLAGS = $(GTK_CFLAGS) -Icontrib -Icontrib/mona -Icontrib/mona/BDD -Icontrib/mona/DFA -Icontrib/mona/GTA -Icontrib/mona/Mem -Icontrib/boost -Icontrib/gtksourceviewmm
monagui_LDFLAGS = $(GTK_LIBS) 

#BUILT_SOURCES = src/front2/parser.cpp src/front2/parser.h src/front2/scanner.cpp


src_front2_completiongen_SOURCES = src/front2/parser.ypp src/front2/scanner.lpp src/front2/completiongen.cpp $(src_front2_cpp) $(src_front2_c) $(src_front2_h) \
	$(contrib_mona_bdd_c) $(contrib_mona_bdd_h) $(contrib_mona_dfa_c) $(contrib_mona_dfa_h) $(contrib_mona_gta_c) $(contrib_mona_gta_h) $(contrib_mona_mem_c) \
	$(contrib_boost_cpp) $(contrib_boost_hpp)

src_front2_completiongen_CPPFLAGS = -Icontrib -Icontrib/mona -Icontrib/mona/BDD -Icontrib/mona/DFA -Icontrib/mona/GTA -Icontrib/mona/Mem -Icontrib/boost
src_front2_completiongen_LDFLAGS = -lrt

src/front2/activetable.cpp src/front2/activetable.h: src/front2/completiongen
	cd src/front2 && ./completiongen

# Additional dependencies that GNU autotools "forgets"
src/front2/parser.cpp src/front2/parser.h: src/front2/parser.ypp

src/front2/scanner.cpp: src/front2/scanner.lpp

# monagui$(EXEEXT) is just there to stop autotools from complaining
src/front2/monagui-completiontable.$(OBJEXT) monagui$(EXEEXT): src/front2/activetable.h

src/front2/src_front2_completiongen-completiontable.$(OBJEXT) monagui$(EXEEXT): src/front2/activetable.h

src/front2/monagui-completiongen.$(OBJEXT) monagui$(EXEEXT): src/front2/parser.cpp

src/front2/src_front2_completiongen-completiongen.$(OBJEXT) monagui$(EXEEXT): src/front2/parser.cpp



