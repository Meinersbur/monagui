dnl Process this file with autoconf to produce a configure script.
dnl
dnl This file is free software; as a special exception the author gives
dnl unlimited permission to copy and/or distribute it, with or without
dnl modifications, as long as this notice is preserved.
dnl
dnl This program is distributed in the hope that it will be useful, but
dnl WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
dnl implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

AC_INIT([monagui], [1.0.1], [monagui@meinersbur.de])

AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([subdir-objects foreign -Wall -Werror])

AC_PREREQ([2.64])

AC_CONFIG_HEADERS([src/guiconfig.h])
AC_CONFIG_SRCDIR([src/main.cpp])

AM_MAINTAINER_MODE([disable])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_LEX
AC_PROG_YACC

AM_PROG_CC_C_O

# Checks for libraries.
ROOT=`pwd`
sigc_ver='sigc++-2.0 >= 2.2.2'
glibmm_ver='glibmm-2.4 >= 2.18.1'
cairomm_ver='cairomm-1.0 >= 1.6.4'
pangomm_ver='pangomm-1.4 >= 2.14.0'
gtkmm_ver='gtkmm-2.4 >= 2.14.1 gthread-2.0 >= 2.18.1'
gtksourceview_ver='gtksourceview-2.0 >= 2.10.5'
libraries_ver="$sigc_ver $glibmm_ver $cairomm_ver $pangomm_ver $gtkmm_ver $gtksourceview_ver"

PKG_CHECK_EXISTS([$libraries_ver],[
		DUMMY=
	],[
		echo ""
		echo "ERROR: Some libraries are missing"
		echo "To install them, cd to the folders below in this order"
		echo ""
	])

PKG_CHECK_EXISTS([$sigc_ver],[
		DUMMY=
	], [
		echo "contrib/libsigc++"
	])

PKG_CHECK_EXISTS([$glibmm_ver],[
		DUMMY=
	], [
		echo "contrib/glibmm"
	])

PKG_CHECK_EXISTS([$cairomm_ver],[
		DUMMY=
	], [
		echo "contrib/cairomm"
	])

PKG_CHECK_EXISTS([$pangomm_ver],[
		DUMMY=
	], [
		echo "contrib/pangomm"
	])

PKG_CHECK_EXISTS([$gtkmm_ver],[
		DUMMY=
	], [
		echo "contrib/gtkmm"
	])

PKG_CHECK_EXISTS([$gtksourceview_ver],[
		DUMMY=
	], [
		echo "contrib/gtksourcemm"
	])

PKG_CHECK_EXISTS([$libraries_ver],[
		DUMMY=
	],[
		echo ""
		echo "and execute "
		echo ""
		echo "./configure"
		echo "make"
		echo "sudo make install" 
		echo ""
		echo "in each of them."
		echo "However, if possible please use your package manager to install them."
		echo ""
		AC_MSG_FAILURE([Required libraries not found.]);
	])

PKG_CHECK_MODULES([GTK], [$libraries_ver]) 
CPPFLAGS="$CPPFLAGS $GTK_CPPFLAGS"
LDFLAGS="$LDFLAGS $GTK_LDFLAGS"

AH_TEMPLATE([HAVE_GTK_STYLE_GET], [Does gtk have the function gtk_style_get?])

PKG_CHECK_EXISTS([gtk+-2.0 >= 2.16],[
		AC_DEFINE([HAVE_GTK_STYLE_GET], [1])
	], [
		AC_DEFINE([HAVE_GTK_STYLE_GET], [0])
	])


AC_CONFIG_FILES([Makefile])
AC_OUTPUT

