
; Title          gtkmm for win32 installer
; Author         Cedric Gustin <cedric.gustin@swing.be>

;    Copyright (C) 2004-2006  Cedric Gustin
;                  2008       Armin Burgmeier
;
;    This program is free software; you can redistribute it and/or modify
;    it under the terms of the GNU General Public License as published by
;    the Free Software Foundation; either version 2 of the License, or
;    (at your option) any later version.
;
;    This program is distributed in the hope that it will be useful,
;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;    GNU General Public License for more details.
;
;    You should have received a copy of the GNU General Public License
;    along with this program; if not, write to the Free Software
;    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

;--------------------------------
; Settings

; !define RUNTIME_ONLY 1

!ifndef PRODUCT_VERSION_MAJOR
!define PRODUCT_VERSION_MAJOR "2"
!endif
!ifndef PRODUCT_VERSION_MINOR
!define PRODUCT_VERSION_MINOR "14"
!endif
!ifndef PRODUCT_VERSION_MICRO
!define PRODUCT_VERSION_MICRO "5"
!endif
!ifndef PRODUCT_VERSION_INSTALLER
!define PRODUCT_VERSION_INSTALLER "1"
!endif

!ifdef PRODUCT_API_VERSION
!undef PRODUCT_API_VERSION
!endif

; TODO: Autodetect this
!define PRODUCT_API_VERSION "2.4"

;--------------------------------
; Defines

!define PRODUCT_NAME "gtkmm"
!define PRODUCT_SMNAME "Gtkmm"
!ifdef RUNTIME_ONLY
  !define PRODUCT_FULLNAME "gtkmm Runtime Environment"
!else
  !define PRODUCT_FULLNAME "gtkmm Development Environment"
!endif
!define PRODUCT_PUBLISHER "The gtkmm developers"
!define PRODUCT_WEB_SITE "http://www.gtkmm.org/"

!ifdef PRODUCT_VERSION
!undef PRODUCT_VERSION
!endif
!define PRODUCT_VERSION "${PRODUCT_VERSION_MAJOR}.${PRODUCT_VERSION_MINOR}.${PRODUCT_VERSION_MICRO}"

!ifdef RUNTIME_ONLY
  !define INSTALLER_NAME "${PRODUCT_NAME}-win32-runtime-${PRODUCT_VERSION}-${PRODUCT_VERSION_INSTALLER}.exe"
  !define BINDIR "bin_stripped"
!else
  !define INSTALLER_NAME "${PRODUCT_NAME}-win32-devel-${PRODUCT_VERSION}-${PRODUCT_VERSION_INSTALLER}.exe"
  !define BINDIR "bin"
!endif

!define GTKMM_COMMONDIR          "$COMMONFILES\${PRODUCT_NAME}\${PRODUCT_API_VERSION}"
!define GTKMM_REG_KEY	         "Software\gtkmm\${PRODUCT_API_VERSION}"
!define GTKMM_UNINSTALL_KEY	 "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
!define GTKMM_UNINSTALL_EXE	 "gtkmm-uninst.exe"

;--------------------------------
; Installer Details

SetCompressor /SOLID lzma
ShowInstDetails hide
ShowUninstDetails hide
SetDateSave on
CRCCheck on
XPStyle on

;--------------------------------
; Standard Libraries

!include "MUI.nsh"
!include "Sections.nsh"
!include "StrFunc.nsh"
${StrTok} # Supportable for Install Sections and Functions

;--------------------------------
; Local Libraries

!addincludedir "NSISLibrary"
!include "PathManipulation.nsh"
;!include "DetectGTK.nsh"
!include "VersionCheck.nsh"
!include "CmdParameters.nsh"
!include "StringUtilities.nsh"

;--------------------------------
; Variables

Var CB_PATH_VALUE
Var ISADMIN
Var CONTEXT
Var ICONS_GROUP
Var FORCE_UNINSTALL
Var USE_GTKDIR

;--------------------------------
; MUI Settings

!define MUI_ABORTWARNING
!define MUI_ICON .\gtkmm.ico
!define MUI_UNICON .\gtkmm.ico

; Reserve space for InstallOptions
; Don't do it here as we want full extraction during the installer initialization
; ReserveFile "NSISLibrary\PathQuestion.ini"
; Reservefile "NSISLibrary\SetContext.ini"
; !insertmacro MUI_RESERVEFILE_INSTALLOPTIONS
; !insertmacro MUI_RESERVEFILE_LANGDLL

; Remember the installer language
!define MUI_LANGDLL_REGISTRY_ROOT "HKCU"
!define MUI_LANGDLL_REGISTRY_KEY "Software\${PRODUCT_NAME}\${PRODUCT_API_VERSION}"
!define MUI_LANGDLL_REGISTRY_VALUENAME "Installer Language"

!define MUI_CUSTOMFUNCTION_GUIINIT CustomPreviousVersion
!define MUI_PAGE_CUSTOMFUNCTION_PRE EnableGTKInstaller
!define MUI_PAGE_CUSTOMFUNCTION_LEAVE DisableGTKInstaller
!insertmacro MUI_PAGE_INSTFILES
!define MUI_WELCOMEPAGE_TITLE_3LINES
!insertmacro MUI_PAGE_WELCOME
; !define MUI_LICENSEPAGE_RADIOBUTTONS
!insertmacro MUI_PAGE_LICENSE "lgpl.txt"
Page custom CustomPageSetContext
!define MUI_PAGE_CUSTOMFUNCTION_PRE CustomSetTargetDirectory
!insertmacro MUI_PAGE_DIRECTORY
Page custom CustomPagePathQuestion
!ifndef RUNTIME_ONLY
  !insertmacro MUI_PAGE_COMPONENTS
!endif
!define MUI_STARTMENUPAGE_NODISABLE
!define MUI_STARTMENUPAGE_DEFAULTFOLDER "Gtkmm"
!define MUI_STARTMENUPAGE_REGISTRY_ROOT "HKLM"
!define MUI_STARTMENUPAGE_REGISTRY_KEY "${GTKMM_UNINSTALL_KEY}"
!define MUI_STARTMENUPAGE_REGISTRY_VALUENAME "NSIS:StartMenuDir"
!insertmacro MUI_PAGE_STARTMENU Application $ICONS_GROUP
!insertmacro MUI_PAGE_INSTFILES
!define MUI_FINISHPAGE_TITLE_3LINES
!insertmacro MUI_PAGE_FINISH

!define MUI_WELCOMEPAGE_TITLE_3LINES
!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_INSTFILES
!define MUI_FINISHPAGE_TITLE_3LINES
!insertmacro MUI_UNPAGE_FINISH

;--------------------------------
; Languages

!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "French"

!include "translations\english.nsh"
!include "translations\french.nsh"

;--------------------------------
; General Installer Options

Name "${PRODUCT_FULLNAME} ${PRODUCT_VERSION}"
OutFile "${INSTALLER_NAME}"
InstallDir "$PROGRAMFILES\${PRODUCT_NAME}"
; Get installation folder from registry if available
InstallDirRegKey HKLM Software\${PRODUCT_NAME}\${PRODUCT_API_VERSION} "Path"

;--------------------------------
; Installer Sections

!ifndef RUNTIME_ONLY
  InstType "Full"
  InstType "Runtime only"
!endif

;Section -installgtk SecGTKInstaller
; 
;  Push ${GTK_VERSION}
;  Call CheckGTKRuntime
; 
;SectionEnd

SubSection "GTK+"

Section "Runtime" SecGTKRuntime
!ifndef RUNTIME_ONLY
  SectionIn 1 2 RO
!else
  SectionIn RO
!endif
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\bin

  ; These break when stripped, therefore we always load them from bin/
  File bin\zlib1.dll
  File bin\intl.dll
  File bin\charset.dll
  File bin\iconv.dll
  File bin\libxml2.dll

  File ${BINDIR}\jpeg62.dll
  File ${BINDIR}\libpng12-0.dll
  File ${BINDIR}\libtiff3.dll
  File ${BINDIR}\libglib-2.0-0.dll
  File ${BINDIR}\libgobject-2.0-0.dll
  File ${BINDIR}\libgmodule-2.0-0.dll
  File ${BINDIR}\libgthread-2.0-0.dll
  File ${BINDIR}\libgio-2.0-0.dll
  File ${BINDIR}\libcairo-2.dll
  File ${BINDIR}\libatk-1.0-0.dll
  File ${BINDIR}\libpango-1.0-0.dll
  File ${BINDIR}\libpangocairo-1.0-0.dll
  File ${BINDIR}\libpangoft2-1.0-0.dll
  File ${BINDIR}\libpangowin32-1.0-0.dll
  File ${BINDIR}\libgailutil-18.dll
  File ${BINDIR}\libgdk-win32-2.0-0.dll
  File ${BINDIR}\libgdk_pixbuf-2.0-0.dll
  File ${BINDIR}\libgtk-win32-2.0-0.dll
  File ${BINDIR}\libglade-2.0-0.dll
  File ${BINDIR}\gspawn-win32-helper.exe
  File ${BINDIR}\gspawn-win32-helper-console.exe
  File ${BINDIR}\gtk-update-icon-cache.exe
  File ${BINDIR}\gtk-demo.exe

  SetOutPath $INSTDIR\lib\gtk-2.0\2.10.0
  File /r lib\gtk-2.0\2.10.0\engines

  SetOutPath $INSTDIR\lib\gtk-2.0
  File /r lib\gtk-2.0\modules

  SetOutPath $INSTDIR\etc
  File /r etc\gtk-2.0
  File /r etc\pango

  SetOutPath $INSTDIR\share\doc
  File /r share\doc\glib-2.18.1
  File /r share\doc\cairo_1.7.6-1_win32
  File /r share\doc\pango-1.22.0
  File /r share\doc\gtk+-2.14.3

  SetOutPath $INSTDIR\share
  File /r share\locale
  File /r share\themes
; Only required for gtk-demo:
  File /r share\gtk-2.0

  SetOutPath $INSTDIR\contrib
  File /r contrib\tiff

SectionEnd

!ifndef RUNTIME_ONLY
Section "Development" SecGTKDevelopment
  SectionIn 1
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\bin

  ; Again, we always use the non-stripped version here since stripping breaks it
  File bin\iconv.exe

  ; These are only useful to developers
  File ${BINDIR}\pkg-config.exe
  File ${BINDIR}\glib-genmarshal.exe
  File ${BINDIR}\glib-gettextize
  File ${BINDIR}\glib-mkenums
  File ${BINDIR}\gobject-query.exe
  File ${BINDIR}\pango-querymodules.exe
  File ${BINDIR}\gdk-pixbuf-csource.exe
  File ${BINDIR}\gdk-pixbuf-query-loaders.exe
  File ${BINDIR}\gtk-builder-convert
  File ${BINDIR}\gtk-query-immodules-2.0.exe

  SetOutPath $INSTDIR\include
  File /r include\libxml
  File /r include\glib-2.0
  File /r include\cairo
  File /r include\atk-1.0
  File /r include\pango-1.0
  File /r include\gtk-2.0
  File /r include\libglade-2.0

  File include\iconv.h
  File include\libcharset.h
  File include\localcharset.h
  File include\libintl.h
  File include\png.h
  File include\pngconf.h
  File include\tiff.h
  File include\tiffconf.h
  File include\tiffio.h
  file include\tiffvers.h
  file include\zconf.h
  file include\zlib.h

  SetOutPath $INSTDIR\lib\gtk-2.0
  File /r lib\gtk-2.0\include

  SetOutPath $INSTDIR\lib\glib-2.0
  File /r lib\glib-2.0\include

  SetOutPath $INSTDIR\lib\gtk-2.0
  File /r lib\gtk-2.0\include

  SetOutPath $INSTDIR\lib
  File lib\libxml2.lib
  File lib\libxml2.dll.a
  File lib\charset.lib
  File lib\iconv.lib
  File lib\libiconv.a
  File lib\intl.def
  File lib\intl.lib
  File lib\libintl.dll.a
  File lib\libtiff.def
  File lib\libtiff.lib
  File lib\libtiff.dll.a
  File lib\libpng.def
  File lib\libpng.lib
  File lib\libpng12.dll.a
  File lib\zlib.def
  File lib\zdll.lib
  File lib\libz.a
  File lib\glib-2.0.def
  File lib\glib-2.0.lib
  File lib\libglib-2.0.dll.a
  File lib\gobject-2.0.def
  File lib\gobject-2.0.lib
  File lib\libgobject-2.0.dll.a
  File lib\gmodule-2.0.def
  File lib\gmodule-2.0.lib
  File lib\libgmodule-2.0.dll.a
  File lib\gthread-2.0.def
  File lib\gthread-2.0.lib
  File lib\libgthread-2.0.dll.a
  File lib\gio-2.0.def
  File lib\gio-2.0.lib
  File lib\libgio-2.0.dll.a
  File lib\cairo.def
  File lib\cairo.lib
  File lib\libcairo.dll.a
  File lib\atk-1.0.def
  File lib\atk-1.0.lib
  File lib\libatk-1.0.dll.a
  File lib\pango-1.0.def
  File lib\pango-1.0.lib
  File lib\libpango-1.0.dll.a
  File lib\pangocairo-1.0.def
  File lib\pangocairo-1.0.lib
  File lib\libpangocairo-1.0.dll.a
  File lib\pangoft2-1.0.def
  File lib\pangoft2-1.0.lib
  File lib\libpangoft2-1.0.dll.a
  File lib\pangowin32-1.0.def
  File lib\pangowin32-1.0.lib
  File lib\libpangowin32-1.0.dll.a
  File lib\gailutil.lib
  File lib\libgailutil.dll.a
; TODO: What about .defs here?
  File lib\gdk-win32-2.0.lib
  File lib\libgdk-win32-2.0.dll.a
  File lib\gdk_pixbuf-2.0.lib
  File lib\libgdk_pixbuf-2.0.dll.a
  File lib\gtk-win32-2.0.lib
  File lib\libgtk-win32-2.0.dll.a
  File lib\glade-2.0.lib
  File lib\libglade-2.0.dll.a

  SetOutPath $INSTDIR\lib\pkgconfig
  File lib\pkgconfig\libxml-2.0.pc
  File lib\pkgconfig\libpng.pc
  File lib\pkgconfig\libpng12.pc
  File lib\pkgconfig\glib-2.0.pc
  File lib\pkgconfig\gmodule-2.0.pc
  File lib\pkgconfig\gmodule-no-export-2.0.pc
  File lib\pkgconfig\gobject-2.0.pc
  File lib\pkgconfig\gthread-2.0.pc
  File lib\pkgconfig\gio-2.0.pc
  File lib\pkgconfig\cairo.pc
  File lib\pkgconfig\cairo-png.pc
  File lib\pkgconfig\cairo-pdf.pc
  File lib\pkgconfig\cairo-ps.pc
  File lib\pkgconfig\cairo-svg.pc
  File lib\pkgconfig\cairo-win32.pc
  File lib\pkgconfig\cairo-win32-font.pc
  File lib\pkgconfig\atk.pc
  File lib\pkgconfig\pango.pc
  File lib\pkgconfig\pangocairo.pc
  File lib\pkgconfig\pangoft2.pc
  File lib\pkgconfig\pangowin32.pc
  File lib\pkgconfig\gdk-2.0.pc
  File lib\pkgconfig\gdk-pixbuf-2.0.pc
  File lib\pkgconfig\gdk-win32-2.0.pc
  File lib\pkgconfig\gtk+-2.0.pc
  File lib\pkgconfig\gtk+-win32-2.0.pc
  File lib\pkgconfig\libglade-2.0.pc

  SetOutPath $INSTDIR\share\doc
  File /r share\doc\glib-dev-2.18.1
  File /r share\doc\pango-dev-1.22.0
  File /r share\doc\gtk+-dev-2.14.3

  SetOutPath $INSTDIR\share\xml
  File /r share\xml\libglade

  SetOutPath $INSTDIR\share\aclocal
  File share\aclocal\glib-2.0.m4
  File share\aclocal\glib-gettext.m4
  File share\aclocal\gtk-2.0.m4
  File share\aclocal\pkg.m4
SectionEnd

Section "Documentation" SecGTKDocumentation
  SectionIn 1
  SetOverwrite ifnewer
  
  SetOutPath $INSTDIR\share\doc
  File /r share\doc\libiconv

  SetOutPath $INSTDIR\share\gtk-doc\html
  File /r share\gtk-doc\html\glib
  File /r share\gtk-doc\html\gobject
  File /r share\gtk-doc\html\cairo
  File /r share\gtk-doc\html\pango
  File /r share\gtk-doc\html\gdk
  File /r share\gtk-doc\html\gdk-pixbuf
  File /r share\gtk-doc\html\gtk
  File /r share\gtk-doc\html\libglade

SectionEnd
!endif

SubSectionEnd 

SubSection "libsigc++"

Section "Runtime" SecSigcRuntime
!ifndef RUNTIME_ONLY
  SectionIn 1 2 RO
!else
  SectionIn RO
!endif
  SetOverwrite ifnewer
  
  SetOutPath $INSTDIR\bin
  File ${BINDIR}\libsigc-2.0-0.dll
  File MSVC\sigc-vc80-2_0.dll
  File MSVC\sigc-vc90-2_0.dll
  !ifndef RUNTIME_ONLY
    File MSVC\sigc-vc80-d-2_0.dll
    File MSVC\sigc-vc90-d-2_0.dll
    File MSVC\sigc-vc80-d-2_0.pdb
    File MSVC\sigc-vc90-d-2_0.pdb
  !endif
  
SectionEnd

!ifndef RUNTIME_ONLY
Section "Development" SecSigcDevelopment
  SectionIn 1
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\include
  File /r include\sigc++-2.0

  SetOutPath $INSTDIR\lib
  File lib\libsigc-2.0.dll.a
  File /r lib\sigc++-2.0
  File MSVC\sigc-vc80-2_0.lib
  File MSVC\sigc-vc90-2_0.lib
  File MSVC\sigc-vc80-d-2_0.lib
  File MSVC\sigc-vc90-d-2_0.lib
  
  SetOutPath $INSTDIR\lib\pkgconfig
  File lib\pkgconfig\sigc++-2.0.pc

SectionEnd

Section "Documentation" SecSigcDocumentation
  SectionIn 1
  SetOverwrite ifnewer
  
  SetOutPath $INSTDIR\share\doc
  
  File /r share\doc\libsigc-2.0
  
SectionEnd
!endif

SubSectionEnd

SubSection "cairomm"

Section "Runtime" SecCairommRuntime
!ifndef RUNTIME_ONLY
  SectionIn 1 2 RO
!else
  SectionIn RO
!endif
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\bin
  File ${BINDIR}\libcairomm-1.0-1.dll
  File MSVC\cairomm-vc80-1_0.dll
  File MSVC\cairomm-vc90-1_0.dll
  !ifndef RUNTIME_ONLY
    File MSVC\cairomm-vc80-d-1_0.dll
    File MSVC\cairomm-vc90-d-1_0.dll
    File MSVC\cairomm-vc80-d-1_0.pdb
    File MSVC\cairomm-vc90-d-1_0.pdb
  !endif
  
SectionEnd

!ifndef RUNTIME_ONLY
Section "Development" SecCairommDevelopment
  SectionIn 1
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\include
  File /r include\cairomm-1.0

  SetOutPath $INSTDIR\lib
  File lib\libcairomm-1.0.dll.a
  File MSVC\cairomm-vc80-1_0.lib
  File MSVC\cairomm-vc90-1_0.lib
  File MSVC\cairomm-vc80-d-1_0.lib
  File MSVC\cairomm-vc90-d-1_0.lib

  SetOutPath $INSTDIR\lib\pkgconfig
  File lib\pkgconfig\cairomm-1.0.pc
  
SectionEnd

Section "Documentation" SecCairommDocumentation
  SectionIn 1
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\share\doc
  File /r share\doc\libcairomm-1.0

SectionEnd
!endif

SubSectionEnd

SubSection "glibmm"

Section "Runtime" SecGlibmmRuntime
!ifndef RUNTIME_ONLY
  SectionIn 1 2 RO
!else
  SectionIn RO
!endif
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\bin
  File ${BINDIR}\libglibmm-2.4-1.dll
  File ${BINDIR}\libgiomm-2.4-1.dll
  File ${BINDIR}\libglibmm_generate_extra_defs-2.4-1.dll
  File MSVC\glibmm-vc80-2_4.dll
  File MSVC\glibmm-vc90-2_4.dll
  File MSVC\giomm-vc80-2_4.dll
  File MSVC\giomm-vc90-2_4.dll
  !ifndef RUNTIME_ONLY
    File MSVC\glibmm-vc80-d-2_4.dll
    File MSVC\glibmm-vc90-d-2_4.dll
    File MSVC\glibmm-vc80-d-2_4.pdb
    File MSVC\glibmm-vc90-d-2_4.pdb
    File MSVC\giomm-vc80-d-2_4.dll
    File MSVC\giomm-vc90-d-2_4.dll
    File MSVC\giomm-vc80-d-2_4.pdb
    File MSVC\giomm-vc90-d-2_4.pdb
  !endif
  
SectionEnd

!ifndef RUNTIME_ONLY
Section "Development" SecGlibmmDevelopment
  SectionIn 1
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\include
  File /r include\glibmm-2.4
  File /r include\giomm-2.4

  SetOutPath $INSTDIR\lib
  File lib\libglibmm-2.4.dll.a
  File lib\libgiomm-2.4.dll.a
  File lib\libglibmm_generate_extra_defs-2.4.dll.a
  File /r lib\glibmm-2.4
  File /r lib\giomm-2.4
  File MSVC\glibmm-vc80-2_4.lib
  File MSVC\glibmm-vc90-2_4.lib
  File MSVC\glibmm-vc80-d-2_4.lib
  File MSVC\glibmm-vc90-d-2_4.lib
  File MSVC\giomm-vc80-2_4.lib
  File MSVC\giomm-vc90-2_4.lib
  File MSVC\giomm-vc80-d-2_4.lib
  File MSVC\giomm-vc90-d-2_4.lib

  SetOutPath $INSTDIR\lib\pkgconfig
  File lib\pkgconfig\glibmm-2.4.pc
  File lib\pkgconfig\giomm-2.4.pc
  
  SetOutPath $INSTDIR\share\aclocal
  File share\aclocal\glibmm_check_perl.m4
  
SectionEnd

Section "Documentation" SecGlibmmDocumentation
  SectionIn 1
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\share\doc
  File /r share\doc\glibmm-2.4

;  SetOutPath $INSTDIR\share\devhelp\books
;  File /r share\devhelp\books\glibmm-2.4
SectionEnd
!endif

SubSectionEnd

SubSection "pangomm"

Section "Runtime" SecPangommRuntime
!ifndef RUNTIME_ONLY
  SectionIn 1 2 RO
!else
  SectionIn RO
!endif
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\bin
  File ${BINDIR}\libpangomm-1.4-1.dll
  File MSVC\pangomm-vc80-1_4.dll
  File MSVC\pangomm-vc90-1_4.dll

  !ifndef RUNTIME_ONLY
    File MSVC\pangomm-vc80-d-1_4.dll
    File MSVC\pangomm-vc90-d-1_4.dll
    File MSVC\pangomm-vc80-d-1_4.pdb
    File MSVC\pangomm-vc90-d-1_4.pdb
  !endif

SectionEnd

!ifndef RUNTIME_ONLY
Section "Development" SecPangommDevelopment
  SectionIn 1
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\include
  File /r include\pangomm-1.4

  SetOutPath $INSTDIR\lib
  File lib\libpangomm-1.4.dll.a
  
  File MSVC\pangomm-vc80-1_4.lib
  File MSVC\pangomm-vc90-1_4.lib
  File MSVC\pangomm-vc80-d-1_4.lib
  File MSVC\pangomm-vc90-d-1_4.lib

  SetOutPath $INSTDIR\lib\pkgconfig
  File lib\pkgconfig\pangomm-1.4.pc
  
SectionEnd

Section "Documentation" SecPangommDocumentation
  SectionIn 1
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\share\doc
  File /r share\doc\pangomm-1.4

  SetOutPath $INSTDIR\share\devhelp\books
  File /r share\devhelp\books\pangomm-1.4

SectionEnd
!endif

SubSectionEnd

SubSection "gtkmm"

Section "Runtime" SecGtkmmRuntime
!ifndef RUNTIME_ONLY
  SectionIn 1 2 RO
!else
  SectionIn RO
!endif
  SetOverwrite ifnewer
  
  SetOutPath $INSTDIR\bin
  File ${BINDIR}\libatkmm-1.6-1.dll
  File ${BINDIR}\libgdkmm-2.4-1.dll
  File ${BINDIR}\libgtkmm-2.4-1.dll

  File MSVC\atkmm-vc80-1_6.dll
  File MSVC\atkmm-vc90-1_6.dll
  File MSVC\gdkmm-vc80-2_4.dll
  File MSVC\gdkmm-vc90-2_4.dll
  File MSVC\gtkmm-vc80-2_4.dll
  File MSVC\gtkmm-vc90-2_4.dll

  !ifndef RUNTIME_ONLY
    File MSVC\atkmm-vc80-d-1_6.dll
    File MSVC\atkmm-vc90-d-1_6.dll
    File MSVC\atkmm-vc80-d-1_6.pdb
    File MSVC\atkmm-vc90-d-1_6.pdb
    File MSVC\gdkmm-vc80-d-2_4.dll
    File MSVC\gdkmm-vc90-d-2_4.dll
    File MSVC\gdkmm-vc80-d-2_4.pdb
    File MSVC\gdkmm-vc90-d-2_4.pdb
    File MSVC\gtkmm-vc80-d-2_4.dll
    File MSVC\gtkmm-vc90-d-2_4.dll
    File MSVC\gtkmm-vc80-d-2_4.pdb
    File MSVC\gtkmm-vc90-d-2_4.pdb
  !endif
  
SectionEnd

!ifndef RUNTIME_ONLY
Section "Development" SecGtkmmDevelopment
  SectionIn 1
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\include
  File /r include\atkmm-1.6
  File /r include\gtkmm-2.4
  File /r include\gdkmm-2.4

  SetOutPath $INSTDIR\lib
  File lib\libatkmm-1.6.dll.a
  File lib\libgdkmm-2.4.dll.a
  File lib\libgtkmm-2.4.dll.a
  File /r lib\gtkmm-2.4
  File /r lib\gdkmm-2.4
  
  File MSVC\atkmm-vc80-1_6.lib
  File MSVC\atkmm-vc90-1_6.lib
  File MSVC\atkmm-vc80-d-1_6.lib
  File MSVC\atkmm-vc90-d-1_6.lib
  File MSVC\gdkmm-vc80-2_4.lib
  File MSVC\gdkmm-vc90-2_4.lib
  File MSVC\gdkmm-vc80-d-2_4.lib
  File MSVC\gdkmm-vc90-d-2_4.lib
  File MSVC\gtkmm-vc80-2_4.lib
  File MSVC\gtkmm-vc90-2_4.lib
  File MSVC\gtkmm-vc80-d-2_4.lib
  File MSVC\gtkmm-vc90-d-2_4.lib

  SetOutPath $INSTDIR\lib\pkgconfig
  File lib\pkgconfig\atkmm-1.6.pc
  File lib\pkgconfig\gtkmm-2.4.pc
  File lib\pkgconfig\gdkmm-2.4.pc
  
  SetOutPath $INSTDIR\MSVC
  File MSVC\gtkmm-vc80-2_4.vsprops
  File MSVC\gtkmm-vc90-2_4.vsprops
  File MSVC\gtkmm-vc80-d-2_4.vsprops
  File MSVC\gtkmm-vc90-d-2_4.vsprops
  File MSVC\gtkmm-2.4.vsprops
  File MSVC\gtkmm-2.4d.vsprops

SectionEnd

Section "Demo" SecGtkmmDemo
  SectionIn 1
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\gtkmm-demo
  File /oname=gtkmm-demo.exe demo\demo.exe
  File demo\*.cc
  File demo\*.png
  File demo\*.jpg
  File demo\*.gif

SectionEnd

Section "Documentation" SecGtkmmDocumentation
  SectionIn 1
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\share\doc
  File /r share\doc\gtkmm-2.4

  SetOutPath $INSTDIR\share\devhelp\books
  File /r share\devhelp\books\gtkmm-2.4

SectionEnd
!endif

SubSectionEnd

SubSection "libglademm"

Section "Runtime" SecLibglademmRuntime
!ifndef RUNTIME_ONLY
  SectionIn 1 2
!endif
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\bin
  File ${BINDIR}\libglademm-2.4-1.dll
  File MSVC\glademm-vc80-2_4.dll
  File MSVC\glademm-vc90-2_4.dll
;  CreateShortCut "libglademm-2.4.dll.lnk" "glademm-2.4.dll"
  !ifndef RUNTIME_ONLY
    File MSVC\glademm-vc80-d-2_4.dll
    File MSVC\glademm-vc90-d-2_4.dll
;    CreateShortCut "libglademm-2.4d.dll.lnk" "glademm-2.4d.dll"
    File MSVC\glademm-vc80-d-2_4.pdb
    File MSVC\glademm-vc90-d-2_4.pdb
;    CreateShortCut "libglademm-2.4d.pdb.lnk" "glademm-2.4d.pdb"
  !endif
  
SectionEnd

!ifndef RUNTIME_ONLY
Section "Development" SecLibglademmDevelopment
  SectionIn 1
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\include
  File /r include\libglademm-2.4

  SetOutPath $INSTDIR\lib
  File lib\libglademm-2.4.dll.a
  File /r lib\libglademm-2.4
  File MSVC\glademm-vc80-2_4.lib
  File MSVC\glademm-vc90-2_4.lib
  File MSVC\glademm-vc80-d-2_4.lib
  File MSVC\glademm-vc90-d-2_4.lib

;  CreateShortCut "libglademm-2.4.lib.lnk" "$INSTDIR\lib\glademm-2.4.lib"
;  CreateShortCut "libglademm-2.4d.lib.lnk" "$INSTDIR\lib\glademm-2.4d.lib"

  SetOutPath $INSTDIR\lib\pkgconfig
  File lib\pkgconfig\libglademm-2.4.pc

SectionEnd

Section "Documentation" SecLibglademmDocumentation
  SectionIn 1
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\share\doc\gnomemm-2.6
  File /r share\doc\gnomemm-2.6\libglademm-2.4
  
  SetOutPath $INSTDIR\share\devhelp\books
  File /r share\devhelp\books\libglademm-2.4

SectionEnd
!endif

SubSectionEnd

SubSection "libxml++"

Section "Runtime" SecLibxmlRuntime
!ifndef RUNTIME_ONLY
  SectionIn 1 2
!endif
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\bin
  File ${BINDIR}\libxml++-2.6-2.dll
  File MSVC\xml++-vc80-2_6.dll
  File MSVC\xml++-vc90-2_6.dll
;  CreateShortCut "libxml++-2.6.dll.lnk" "xml++-2.6.dll"
  !ifndef RUNTIME_ONLY
    File MSVC\xml++-vc80-d-2_6.dll
    File MSVC\xml++-vc90-d-2_6.dll
;    CreateShortCut "libxml++-2.6d.dll.lnk" "xml++-2.6d.dll"
    File MSVC\xml++-vc80-d-2_6.pdb
    File MSVC\xml++-vc90-d-2_6.pdb
;    CreateShortCut "libxml++-2.6d.pdb.lnk" "xml++-2.6d.pdb"
  !endif

SectionEnd

!ifndef RUNTIME_ONLY
Section "Development" SecLibxmlDevelopment
  SectionIn 1
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\include
  File /r include\libxml++-2.6

  SetOutPath $INSTDIR\lib
  File lib\libxml++-2.6.dll.a
  File /r lib\libxml++-2.6
  File MSVC\xml++-vc80-2_6.lib
  File MSVC\xml++-vc90-2_6.lib
  File MSVC\xml++-vc80-d-2_6.lib
  File MSVC\xml++-vc90-d-2_6.lib

;  CreateShortCut "libxml++-2.6.lib.lnk" "$INSTDIR\lib\xml++-2.6.lib"
;  CreateShortCut "libxml++-2.6d.lib.lnk" "$INSTDIR\lib\xml++-2.6.d.lib"

  SetOutPath $INSTDIR\lib\pkgconfig
  File lib\pkgconfig\libxml++-2.6.pc

SectionEnd

Section "Documentation" SecLibxmlDocumentation
  SectionIn 1
  SetOverwrite ifnewer

  SetOutPath $INSTDIR\share\doc
  File /r share\doc\libxml++-2.6

SectionEnd
!endif

SubSectionEnd

!ifndef RUNTIME_ONLY
;Section "glade--" SecGlademm
;  SectionIn 1
;  SetOverwrite ifnewer
;
;  SetOutPath $INSTDIR\bin
;  File bin_stripped\glade--.exe
;  File bin_stripped\glademm-embed.exe
;
;SectionEnd

;Section "gideon" SecGideon
;  SectionIn 1
;  SetOverwrite ifnewer
;
;  SetOutPath $INSTDIR\bin
;  File bin\gideon.exe
;  File bin\libgideon.dll
;  File bin\libguiloader.dll
;  File bin\libguiloader-c++.dll
;  SetOutPath $INSTDIR\include
;  File /r include\gideon
;  File /r include\guiloader
;  File /r include\guiloader-c++
;  SetOutPath $INSTDIR\lib
;  File lib\libgideon.dll.a
;  File lib\libguiloader.dll.a
;  File lib\libguiloader-c++.dll.a
;
;SectionEnd
!endif

Section -Post SecPost

  Strcmp $ISADMIN "1" 0 +3
    IfSilent +2
      !insertmacro MUI_INSTALLOPTIONS_READ $CONTEXT "SetContext.ini" "Field 2" "State"

  ; TODO: Check that, if CONTEXT is set on silent install (meaning /ALLUSERS
  ; was given on the command line), $ISADMIN is set as well, otherwise we
  ; can't install for all users.

  ; Get rid of leftover start menus
  StrCmp $CONTEXT "1" 0 +3
  RMDir /r "$SMPROGRAMS\gtkmm for Mingw"
  SetShellVarContext all

  ; Start Menu
  CreateDirectory "$SMPROGRAMS\$ICONS_GROUP"

  SetOutPath $INSTDIR
  File "gtkmm.ico"
  File "lgpl.txt"
  File "gtkmm_win32.txt"
  CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\License.lnk" "$INSTDIR\lgpl.txt"
  CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Read Me.lnk" "$INSTDIR\gtkmm_win32.txt"
  
  WriteIniStr "$INSTDIR\${PRODUCT_NAME}.url" "InternetShortcut" "URL" "${PRODUCT_WEB_SITE}"
  CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Website.lnk" "$INSTDIR\${PRODUCT_NAME}.url"

  ; Registry + Add/Remove Entry
  StrCmp $CONTEXT "1" 0 +11
  WriteRegStr HKLM "Software\${PRODUCT_NAME}\${PRODUCT_API_VERSION}" "Path" "$INSTDIR"
  WriteRegStr HKLM "Software\${PRODUCT_NAME}\${PRODUCT_API_VERSION}" "Version" "${PRODUCT_VERSION}"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "DisplayName" "${PRODUCT_FULLNAME} ${PRODUCT_VERSION_MAJOR}.${PRODUCT_VERSION_MINOR}"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "DisplayIcon" "$INSTDIR\gtkmm.ico"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "Publisher" "${PRODUCT_PUBLISHER}"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "UninstallString" "$INSTDIR\${GTKMM_UNINSTALL_EXE}"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "DisplayVersion" "${PRODUCT_VERSION}-${PRODUCT_VERSION_INSTALLER}"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "URLInfoAbout" "${PRODUCT_WEB_SITE}"
  WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "NSIS:StartMenuDir" "$ICONS_GROUP"
  Goto +10
  WriteRegStr HKCU "Software\${PRODUCT_NAME}\${PRODUCT_API_VERSION}" "Path" "$INSTDIR"
  WriteRegStr HKCU "Software\${PRODUCT_NAME}\${PRODUCT_API_VERSION}" "Version" "${PRODUCT_VERSION}"
  WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "DisplayName" "${PRODUCT_FULLNAME} ${PRODUCT_VERSION_MAJOR}.${PRODUCT_VERSION_MINOR}"
  WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "DisplayIcon" "$INSTDIR\gtkmm.ico"
  WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "Publisher" "${PRODUCT_PUBLISHER}"
  WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "UninstallString" "$INSTDIR\${GTKMM_UNINSTALL_EXE}"
  WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "DisplayVersion" "${PRODUCT_VERSION}-${PRODUCT_VERSION_INSTALLER}"
  WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "URLInfoAbout" "${PRODUCT_WEB_SITE}"
  WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "NSIS:StartMenuDir" "$ICONS_GROUP"

!ifndef RUNTIME_ONLY
  IfFileExists "$INSTDIR\share\doc\*.*" "" +2
    CreateDirectory "$SMPROGRAMS\$ICONS_GROUP\Documentation"
  IfFileExists "$INSTDIR\share\gtk-doc\html\*.*" "" +2
    CreateDirectory "$SMPROGRAMS\$ICONS_GROUP\Documentation"

  IfFileExists "$INSTDIR\share\gtk-doc\html\glib\index.html" "" +2
       CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Documentation\glib Reference Manual.lnk" "$INSTDIR\share\gtk-doc\html\glib\index.html"

  IfFileExists "$INSTDIR\share\gtk-doc\html\gobject\index.html" "" +2
       CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Documentation\gobject Reference Manual.lnk" "$INSTDIR\share\gtk-doc\html\gobject\index.html"

  IfFileExists "$INSTDIR\share\gtk-doc\html\cairo\index.html" "" +2
       CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Documentation\cairo Reference Manual.lnk" "$INSTDIR\share\gtk-doc\html\cairo\index.html"

  IfFileExists "$INSTDIR\share\gtk-doc\html\pango\index.html" "" +2
       CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Documentation\pango Reference Manual.lnk" "$INSTDIR\share\gtk-doc\html\pango\index.html"

  IfFileExists "$INSTDIR\share\gtk-doc\html\gdk\index.html" "" +2
       CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Documentation\GDK Reference Manual.lnk" "$INSTDIR\share\gtk-doc\html\gdk\index.html"

  IfFileExists "$INSTDIR\share\gtk-doc\html\gdk-pixbuf\index.html" "" +2
       CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Documentation\gdk-pixbuf Reference Manual.lnk" "$INSTDIR\share\gtk-doc\html\gdk-pixbuf\index.html"

  IfFileExists "$INSTDIR\share\gtk-doc\html\gtk\index.html" "" +2
       CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Documentation\GTK+ Reference Manual.lnk" "$INSTDIR\share\gtk-doc\html\gtk\index.html"

  IfFileExists "$INSTDIR\share\gtk-doc\html\libglade\index.html" "" +2
       CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Documentation\libglade Reference Manual.lnk" "$INSTDIR\share\gtk-doc\html\libglade\index.html"

  IfFileExists "$INSTDIR\share\doc\libsigc-2.0\docs\reference\html\index.html" "" +2
       CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Documentation\libsigc++ Reference Manual.lnk" "$INSTDIR\share\doc\libsigc-2.0\docs\reference\html\index.html"

  IfFileExists "$INSTDIR\share\doc\libcairomm-1.0\reference\html\index.html" "" +2
       CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Documentation\cairomm Reference Manual.lnk" "$INSTDIR\share\doc\libcairomm-1.0\reference\html\index.html"

  IfFileExists "$INSTDIR\share\doc\glibmm-2.4\docs\reference\html\index.html" "" +2
       CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Documentation\glibmm Reference Manual.lnk" "$INSTDIR\share\doc\glibmm-2.4\docs\reference\html\index.html"

  IfFileExists "$INSTDIR\share\doc\pangomm-1.4\docs\reference\html\index.html" "" +2
       CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Documentation\pangomm Reference Manual.lnk" "$INSTDIR\share\doc\pangomm-1.4\docs\reference\html\index.html"

  IfFileExists "$INSTDIR\share\doc\gtkmm-2.4\docs\reference\html\index.html" "" +2
       CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Documentation\gtkmm Reference Manual.lnk" "$INSTDIR\share\doc\gtkmm-2.4\docs\reference\html\index.html"

  IfFileExists "$INSTDIR\share\doc\gnomemm-2.6\libglademm-2.4\docs\reference\html\index.html" "" +2
       CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Documentation\libglademm Reference Manual.lnk" "$INSTDIR\share\doc\gnomemm-2.6\libglademm-2.4\docs\reference\html\index.html"     

  IfFileExists "$INSTDIR\share\doc\libxml++-2.6\docs\reference\2.22\html\index.html" "" +2
       CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Documentation\libxml++ Reference Manual.lnk" "$INSTDIR\share\doc\libxml++-2.6\docs\reference\2.22\html\index.html"

  IfFileExists "$INSTDIR\gtkmm-demo\gtkmm-demo.exe" "" +11
       Push $OUTDIR
       SetOutPath "$INSTDIR\gtkmm-demo"
       CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Demo.lnk" "$INSTDIR\gtkmm-demo\gtkmm-demo.exe" "" "$INSTDIR\gtkmm.ico"
       StrCmp $CONTEXT "1" 0 +4
       WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\App Paths\gtkmm-demo.exe" "" "$INSTDIR\gtkmm-demo\gtkmm-demo.exe"
       WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\App Paths\gtkmm-demo.exe" "Path" "$INSTDIR\bin"
       Goto +3
       WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\App Paths\gtkmm-demo.exe" "" "$INSTDIR\gtkmm-demo\gtkmm-demo.exe"
       WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\App Paths\gtkmm-demo.exe" "Path" "$INSTDIR\bin"
       Pop $OUTDIR
       
;  IfFileExists "$INSTDIR\bin\gideon.exe" "" +11
;       Push $OUTDIR
;       SetOutPath "$INSTDIR\bin"
;       CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Gideon.lnk" "$INSTDIR\bin\gideon.exe" "" "$INSTDIR\gtkmm.ico"
;       StrCmp $CONTEXT "1" 0 +4
;       WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\App Paths\gideon.exe" "" "$INSTDIR\bin\gideon.exe"
;       WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\App Paths\gideon.exe" "Path" "$INSTDIR\bin"
;       Goto +3
;       WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\App Paths\gideon.exe" "" "$INSTDIR\bin\gideon.exe"
;       WriteRegStr HKCU "Software\Microsoft\Windows\CurrentVersion\App Paths\gideon.exe" "Path" "$INSTDIR\bin"
;       Pop $OUTDIR
   
!endif  ; RUNTIME_ONLY

  ; GTKMM_BASEPATH environment variable
  Push "GTKMM_BASEPATH"
  Push "$INSTDIR"
  Push $CONTEXT
  Call WriteEnvStr

  ; Uninstaller
  WriteUninstaller "$INSTDIR\${GTKMM_UNINSTALL_EXE}"
  CreateShortCut "$SMPROGRAMS\$ICONS_GROUP\Uninstall.lnk" "$INSTDIR\${GTKMM_UNINSTALL_EXE}"

  ; Set the PATH with gtkmm target directory (if relevant)
  IfSilent +2
  ; Read a value from an InstallOptions INI file
  !insertmacro MUI_INSTALLOPTIONS_READ $CB_PATH_VALUE "PathQuestion.ini" "Field 1" "State"
  StrCmp $CB_PATH_VALUE "1" "" done
     Push $CONTEXT
     Push "$INSTDIR\bin"
     Call AddToPath
done:

SectionEnd

Section Uninstall SecUninstall

  ClearErrors
  UserInfo::GetName
  IfErrors done
  Pop $0
  UserInfo::GetAccountType
  Pop $0
  StrCmp $0 "Admin" 0 done
  StrCpy $ISADMIN "1"
done:
 
  ClearErrors
  ReadRegStr $R0 HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "DisplayName"
  IfErrors continue
  StrCpy $CONTEXT "1"
  SetShellVarContext all
  StrCmp $ISADMIN "1" continue
  MessageBox MB_OK|MB_ICONEXCLAMATION "$(MISC_ADMIN_REQUIRED)"
  Quit
  
continue:
  StrCmp $CONTEXT "1" 0 +4
  ReadRegStr $INSTDIR HKLM "Software\${PRODUCT_NAME}\${PRODUCT_API_VERSION}" "Path"
  ReadRegStr $ICONS_GROUP HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "NSIS:StartMenuDir"
  Goto +3
  ReadRegStr $INSTDIR HKCU "Software\${PRODUCT_NAME}\${PRODUCT_API_VERSION}" "Path"
  ReadRegStr $ICONS_GROUP HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" "NSIS:StartMenuDir"
  
  ;Remove shortcut
  Delete "$SMPROGRAMS\$ICONS_GROUP\Uninstall.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Website.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\License.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Read Me.lnk"

!ifndef RUNTIME_ONLY
  Delete "$SMPROGRAMS\$ICONS_GROUP\Documentation\glib Reference Manual.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Documentation\gobject Reference Manual.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Documentation\cairo Reference Manual.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Documentation\pango Reference Manual.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Documentation\GDK Reference Manual.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Documentation\gdk-pixbuf Reference Manual.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Documentation\GTK+ Reference Manual.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Documentation\libglade Reference Manual.lnk"

  Delete "$SMPROGRAMS\$ICONS_GROUP\Documentation\libsigc++ Reference Manual.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Documentation\glibmm Reference Manual.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Documentation\pangomm Reference Manual.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Documentation\gtkmm Reference Manual.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Documentation\libglademm Reference Manual.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Documentation\cairomm Reference Manual.lnk"
  Delete "$SMPROGRAMS\$ICONS_GROUP\Documentation\libxml++ Reference Manual.lnk"
  RMDir "$SMPROGRAMS\$ICONS_GROUP\Documentation"
  
  Delete "$SMPROGRAMS\$ICONS_GROUP\Demo.lnk"
;  Delete "$SMPROGRAMS\$ICONS_GROUP\Gideon.lnk"
!endif

  RMDir "$SMPROGRAMS\$ICONS_GROUP"

  SetAutoClose true
  
  ; Delete language selection
  DeleteRegValue HKCU "Software\${PRODUCT_NAME}\${PRODUCT_API_VERSION}" "Installer Language"
  DeleteRegKey /ifempty  HKCU "Software\${PRODUCT_NAME}\${PRODUCT_API_VERSION}"
  DeleteRegKey /ifempty  HKCU "Software\${PRODUCT_NAME}"
  
  StrCmp $CONTEXT "1" 0 +8
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\App Paths\gtkmm-demo.exe"
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\App Paths\gideon.exe"
  DeleteRegKey HKLM "Software\${PRODUCT_NAME}\${PRODUCT_API_VERSION}"
  DeleteRegKey /ifempty  HKLM "Software\${PRODUCT_NAME}"
  ReadRegStr $R0 HKLM "Software\GTK\2.0" "PATH"
  Goto +7
  DeleteRegKey HKCU "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}"
  DeleteRegKey HKCU "Software\Microsoft\Windows\CurrentVersion\App Paths\gtkmm-demo.exe"
  DeleteRegKey HKCU "Software\Microsoft\Windows\CurrentVersion\App Paths\gideon.exe"
  DeleteRegKey HKCU "Software\${PRODUCT_NAME}\${PRODUCT_API_VERSION}"
  DeleteRegKey /ifempty  HKCU "Software\${PRODUCT_NAME}"
  ReadRegStr $R0 HKCU "Software\GTK\2.0" "PATH"
  
  ; Remove gtkmm from PATH

  StrCmp $R0 $INSTDIR +4
     Push $CONTEXT
     Push "$INSTDIR\bin"
     Call un.RemoveFromPath

  Delete "$INSTDIR\gtkmm.ico"
  Delete "$INSTDIR\gtkmm_win32.txt"
  Delete "$INSTDIR\lgpl.txt"
  Delete "$INSTDIR\${PRODUCT_NAME}.url"

!ifndef RUNTIME_ONLY
  ; bin

  Delete $INSTDIR\bin\iconv.exe
  Delete $INSTDIR\bin\pkg-config.exe
  Delete $INSTDIR\bin\glib-genmarshal.exe
  Delete $INSTDIR\bin\glib-gettextize
  Delete $INSTDIR\bin\glib-mkenums
  Delete $INSTDIR\bin\gobject-query.exe
  Delete $INSTDIR\bin\pango-querymodules.exe
  Delete $INSTDIR\bin\gdk-pixbuf-csource.exe
  Delete $INSTDIR\bin\gdk-pixbuf-query-loaders.exe
  Delete $INSTDIR\bin\gtk-builder-convert
  Delete $INSTDIR\bin\gtk-query-immodules-2.0.exe

  ; include
  RMDir /r $INSTDIR\include\libxml
  RMDIR /r $INSTDIR\include\glib-2.0
  RMDIR /r $INSTDIR\include\cairo
  RMDIR /r $INSTDIR\include\atk-1.0
  RMDIR /r $INSTDIR\include\pango-1.0
  RMDIR /r $INSTDIR\include\gtk-2.0
  RMDIR /r $INSTDIR\include\libglade-2.0
  Delete $INSTDIR\include\iconv.h
  Delete $INSTDIR\include\libcharset.h
  Delete $INSTDIR\include\localcharset.h
  Delete $INSTDIR\include\libintl.h
  Delete $INSTDIR\include\png.h
  Delete $INSTDIR\include\pngconf.h
  Delete $INSTDIR\include\tiff.h
  Delete $INSTDIR\include\tiffconf.h
  Delete $INSTDIR\include\tiffio.h
  Delete $INSTDIR\include\tiffvers.h
  Delete $INSTDIR\include\zconf.h
  Delete $INSTDIR\include\zlib.h

  RMDir /r $INSTDIR\include\sigc++-2.0
  RMDir /r $INSTDIR\include\cairomm-1.0
  RMDir /r $INSTDIR\include\glibmm-2.4
  RMDir /r $INSTDIR\include\giomm-2.4
  RMDir /r $INSTDIR\include\atkmm-1.6
  RMDir /r $INSTDIR\include\gdkmm-2.4
  RMDir /r $INSTDIR\include\gtkmm-2.4
  RMDir /r $INSTDIR\include\pangomm-1.4
  RMDir /r $INSTDIR\include\libglademm-2.4
  RMDir /r $INSTDIR\include\libxml++-2.6

  ; lib

  RMDir /r $INSTDIR\lib\glib-2.0\include
  RMDir /r $INSTDIR\lib\gtk-2.0\include
  RMDir $INSTDIR\lib\glib-2.0

  RMDir /r $INSTDIR\lib\sigc++-2.0
  RMDir /r $INSTDIR\lib\glibmm-2.4
  RMDir /r $INSTDIR\lib\giomm-2.4
  RMDir /r $INSTDIR\lib\gdkmm-2.4
  RMDir /r $INSTDIR\lib\gtkmm-2.4
  RMDir /r $INSTDIR\lib\libglademm-2.4
  RMDir /r $INSTDIR\lib\libxml++-2.6

  Delete $INSTDIR\lib\libxml2.lib
  Delete $INSTDIR\lib\libxml2.dll.a
  Delete $INSTDIR\lib\charset.lib
  Delete $INSTDIR\lib\iconv.lib
  Delete $INSTDIR\lib\libiconv.a
  Delete $INSTDIR\lib\libintl.dll.a
  Delete $INSTDIR\lib\libtiff.dll.a
  Delete $INSTDIR\lib\libpng12.dll.a
  Delete $INSTDIR\lib\libz.a
  Delete $INSTDIR\lib\libglib-2.0.dll.a
  Delete $INSTDIR\lib\libgobject-2.0.dll.a
  Delete $INSTDIR\lib\libgmodule-2.0.dll.a
  Delete $INSTDIR\lib\libgthread-2.0.dll.a
  Delete $INSTDIR\lib\libgio-2.0.dll.a
  Delete $INSTDIR\lib\libcairo.dll.a
  Delete $INSTDIR\lib\libatk-1.0.dll.a
  Delete $INSTDIR\lib\libpango-1.0.dll.a
  Delete $INSTDIR\lib\libpangocairo-1.0.dll.a
  Delete $INSTDIR\lib\libpangoft2-1.0.dll.a
  Delete $INSTDIR\lib\libpangowin32-1.0.dll.a
  Delete $INSTDIR\lib\libgailutil.dll.a
  Delete $INSTDIR\lib\libgdk-win32-2.0.dll.a
  Delete $INSTDIR\lib\libgdk_pixbuf-2.0.dll.a
  Delete $INSTDIR\lib\libgtk-win32-2.0.dll.a
  Delete $INSTDIR\lib\libglade-2.0.dll.a

  Delete $INSTDIR\lib\libsigc-*.dll.a
  Delete $INSTDIR\lib\libcairomm-*.dll.a
  Delete $INSTDIR\lib\libglibmm-*.dll.a
  Delete $INSTDIR\lib\libgiomm-*.dll.a
  Delete $INSTDIR\lib\libglibmm_generate_extra_defs-*.dll.a
  Delete $INSTDIR\lib\libatkmm-*.dll.a
  Delete $INSTDIR\lib\libgdkmm-*.dll.a
  Delete $INSTDIR\lib\libgtkmm-*.dll.a
  Delete $INSTDIR\lib\libpangomm-*.dll.a
  Delete $INSTDIR\lib\libglademm-*.dll.a
  Delete $INSTDIR\lib\libxml++-*.dll.a
 
  Delete $INSTDIR\lib\intl.def
  Delete $INSTDIR\lib\intl.lib
  Delete $INSTDIR\lib\libtiff.def
  Delete $INSTDIR\lib\libtiff.lib
  Delete $INSTDIR\lib\libpng.def
  Delete $INSTDIR\lib\libpng.lib
  Delete $INSTDIR\lib\zlib.def
  Delete $INSTDIR\lib\zdll.lib
  Delete $INSTDIR\lib\glib-2.0.def
  Delete $INSTDIR\lib\glib-2.0.lib
  Delete $INSTDIR\lib\gobject-2.0.def
  Delete $INSTDIR\lib\gobject-2.0.lib
  Delete $INSTDIR\lib\gmodule-2.0.def
  Delete $INSTDIR\lib\gmodule-2.0.lib
  Delete $INSTDIR\lib\gthread-2.0.def
  Delete $INSTDIR\lib\gthread-2.0.lib
  Delete $INSTDIR\lib\gio-2.0.def
  Delete $INSTDIR\lib\gio-2.0.lib
  Delete $INSTDIR\lib\cairo.def
  Delete $INSTDIR\lib\cairo.lib
  Delete $INSTDIR\lib\atk-1.0.def
  Delete $INSTDIR\lib\atk-1.0.lib
  Delete $INSTDIR\lib\pango-1.0.def
  Delete $INSTDIR\lib\pango-1.0.lib
  Delete $INSTDIR\lib\pangocairo-1.0.def
  Delete $INSTDIR\lib\pangocairo-1.0.lib
  Delete $INSTDIR\lib\pangoft2-1.0.def
  Delete $INSTDIR\lib\pangoft2-1.0.lib
  Delete $INSTDIR\lib\pangowin32-1.0.def
  Delete $INSTDIR\lib\pangowin32-1.0.lib
  Delete $INSTDIR\lib\gailutil.lib
  Delete $INSTDIR\lib\gdk-win32-2.0.lib
  Delete $INSTDIR\lib\gdk_pixbuf-2.0.lib
  Delete $INSTDIR\lib\gtk-win32-2.0.lib
  Delete $INSTDIR\lib\glade-2.0.lib

  Delete $INSTDIR\lib\sigc-*.lib
  Delete $INSTDIR\lib\cairomm-*.lib
  Delete $INSTDIR\lib\glibmm-*.lib
  Delete $INSTDIR\lib\giomm-*.lib
  Delete $INSTDIR\lib\atkmm-*.lib
  Delete $INSTDIR\lib\gdkmm-*.lib
  Delete $INSTDIR\lib\gtkmm-*.lib
  Delete $INSTDIR\lib\pangomm-*.lib
  Delete $INSTDIR\lib\glademm-*.lib
;  Delete $INSTDIR\lib\libglademm-*.lib.lnk
  Delete $INSTDIR\lib\xml++-*.lib
;  Delete $INSTDIR\lib\libxml++-*.lib.lnk

  Delete $INSTDIR\lib\pkgconfig\libxml-2.0.pc
  Delete $INSTDIR\lib\pkgconfig\libpng.pc
  Delete $INSTDIR\lib\pkgconfig\libpng12.pc
  Delete $INSTDIR\lib\pkgconfig\glib-2.0.pc
  Delete $INSTDIR\lib\pkgconfig\gmodule-2.0.pc
  Delete $INSTDIR\lib\pkgconfig\gmodule-no-export-2.0.pc
  Delete $INSTDIR\lib\pkgconfig\gobject-2.0.pc
  Delete $INSTDIR\lib\pkgconfig\gthread-2.0.pc
  Delete $INSTDIR\lib\pkgconfig\gio-2.0.pc
  Delete $INSTDIR\lib\pkgconfig\cairo.pc
  Delete $INSTDIR\lib\pkgconfig\cairo-png.pc
  Delete $INSTDIR\lib\pkgconfig\cairo-pdf.pc
  Delete $INSTDIR\lib\pkgconfig\cairo-ps.pc
  Delete $INSTDIR\lib\pkgconfig\cairo-svg.pc
  Delete $INSTDIR\lib\pkgconfig\cairo-win32.pc
  Delete $INSTDIR\lib\pkgconfig\cairo-win32-font.pc
  Delete $INSTDIR\lib\pkgconfig\atk.pc
  Delete $INSTDIR\lib\pkgconfig\pango.pc
  Delete $INSTDIR\lib\pkgconfig\pangocairo.pc
  Delete $INSTDIR\lib\pkgconfig\pangoft2.pc
  Delete $INSTDIR\lib\pkgconfig\pangowin32.pc
  Delete $INSTDIR\lib\pkgconfig\gdk-2.0.pc
  Delete $INSTDIR\lib\pkgconfig\gdk-pixbuf-2.0.pc
  Delete $INSTDIR\lib\pkgconfig\gdk-win32-2.0.pc
  Delete $INSTDIR\lib\pkgconfig\gtk+-2.0.pc
  Delete $INSTDIR\lib\pkgconfig\gtk+-win32-2.0.pc  
  Delete $INSTDIR\lib\pkgconfig\libglade-2.0.pc  

  Delete $INSTDIR\lib\pkgconfig\sigc++-*.pc
  Delete $INSTDIR\lib\pkgconfig\cairomm-*.pc
  Delete $INSTDIR\lib\pkgconfig\glibmm-*.pc
  Delete $INSTDIR\lib\pkgconfig\giomm-*.pc
  Delete $INSTDIR\lib\pkgconfig\atkmm-*.pc
  Delete $INSTDIR\lib\pkgconfig\gdkmm-*.pc
  Delete $INSTDIR\lib\pkgconfig\gtkmm-*.pc
  Delete $INSTDIR\lib\pkgconfig\pangomm-*.pc
  Delete $INSTDIR\lib\pkgconfig\libglademm-*.pc
  Delete $INSTDIR\lib\pkgconfig\libxml++-*.pc
  RMDir $INSTDIR\lib\pkgconfig

  ; share

  RMDir /r $INSTDIR\share\doc\libiconv

  RMDir /r $INSTDIR\share\doc\glib-dev-2.18.1
  RMDir /r $INSTDIR\share\doc\pango-dev-1.22.0
  RMDir /r $INSTDIR\share\doc\gtk+-dev-2.14.3

  RMDir /r $INSTDIR\share\xml\libglade
  RMDir $INSTDIR\share\xml

  Delete $INSTDIR\share\aclocal\glib-2.0.m4
  Delete $INSTDIR\share\aclocal\glib-gettext.m4
  Delete $INSTDIR\share\aclocal\gtk-2.0.m4
  Delete $INSTDIR\share\aclocal\pkg.m4

  RMDir /r $INSTDIR\share\gtk-doc\html\glib
  RMDir /r $INSTDIR\share\gtk-doc\html\gobject
  RMDir /r $INSTDIR\share\gtk-doc\html\cairo
  RMDir /r $INSTDIR\share\gtk-doc\html\pango
  RMDir /r $INSTDIR\share\gtk-doc\html\gdk
  RMDir /r $INSTDIR\share\gtk-doc\html\gdk-pixbuf
  RMDir /r $INSTDIR\share\gtk-doc\html\gtk
  RMDir /r $INSTDIR\share\gtk-doc\html\libglade
  RMDir $INSTDIR\share\gtk-doc\html
  RMDir $INSTDIR\share\gtk-doc

  RMDir /r $INSTDIR\share\doc\libsigc-2.0
  RMDir /r $INSTDIR\share\doc\libcairomm-1.0
  RMDir /r $INSTDIR\share\doc\glibmm-2.4
  RMDir /r $INSTDIR\share\doc\pangomm-1.4
  RMDir /r $INSTDIR\share\doc\gtkmm-2.4
  RMDir /r $INSTDIR\share\doc\gnomemm-2.6\libglademm-2.4
  RMDir $INSTDIR\share\doc\gnomemm-2.6
  RMDir /r $INSTDIR\share\doc\libxml++-2.6
  RMDir $INSTDIR\share\doc
  
  RMDir /r $INSTDIR\share\devhelp\books\glibmm-2.4
  RMDir /r $INSTDIR\share\devhelp\books\gtkmm-2.4
  RMDir /r $INSTDIR\share\devhelp\books\pangomm-1.4
  RMDir /r $INSTDIR\share\devhelp\books\libglademm-2.4
  RMDir $INSTDIR\share\devhelp\books
  RMDir $INSTDIR\share\devhelp

  Delete $INSTDIR\share\aclocal\glibmm_check_perl.m4
  RMDir $INSTDIR\share\aclocal
  
  Delete $INSTDIR\MSVC\gtkmm-vc80-2_4.vsprops
  Delete $INSTDIR\MSVC\gtkmm-vc90-2_4.vsprops
  Delete $INSTDIR\MSVC\gtkmm-vc80-d-2_4.vsprops
  Delete $INSTDIR\MSVC\gtkmm-vc90-d-2_4.vsprops
  Delete $INSTDIR\MSVC\gtkmm-2.4.vsprops
  Delete $INSTDIR\MSVC\gtkmm-2.4d.vsprops
  RMDir $INSTDIR\MSVC
  
  ; gtkmm-demo
  Delete $INSTDIR\gtkmm-demo\gtkmm-demo.exe
  Delete $INSTDIR\gtkmm-demo\*.cc
  Delete $INSTDIR\gtkmm-demo\*.png
  Delete $INSTDIR\gtkmm-demo\*.jpg
  Delete $INSTDIR\gtkmm-demo\*.gif

  RMDir $INSTDIR\gtkmm-demo
  
  ; glade--
  Delete $INSTDIR\bin\glade--.exe
  Delete $INSTDIR\bin\glademm-embed.exe
  
  ; gideon
  Delete $INSTDIR\bin\gideon.exe
  Delete $INSTDIR\bin\libgideon.dll
  Delete $INSTDIR\bin\libguiloader.dll
  Delete $INSTDIR\bin\libguiloader-*.dll
  RMDir /r $INSTDIR\include\gideon
  RMDir /r $INSTDIR\include\guiloader
  RMDir /r $INSTDIR\include\guiloader-c++
  Delete $INSTDIR\lib\libgideon.dll.a
  Delete $INSTDIR\lib\libguiloader.dll.a
  Delete $INSTDIR\lib\libguiloader-c++.dll.a
  
  RMDir $INSTDIR\include

!endif

  ; bin

  Delete $INSTDIR\bin\zlib1.dll
  Delete $INSTDIR\bin\intl.dll
  Delete $INSTDIR\bin\iconv.dll
  Delete $INSTDIR\bin\charset.dll
  Delete $INSTDIR\bin\libxml2.dll

  Delete $INSTDIR\bin\jpeg62.dll
  Delete $INSTDIR\bin\libpng12-0.dll
  Delete $INSTDIR\bin\libtiff3.dll
  Delete $INSTDIR\bin\libglib-2.0-0.dll
  Delete $INSTDIR\bin\libgobject-2.0-0.dll
  Delete $INSTDIR\bin\libgmodule-2.0-0.dll
  Delete $INSTDIR\bin\libgthread-2.0-0.dll
  Delete $INSTDIR\bin\libgio-2.0-0.dll
  Delete $INSTDIR\bin\libcairo-2.dll
  Delete $INSTDIR\bin\libatk-1.0-0.dll
  Delete $INSTDIR\bin\libpango-1.0-0.dll
  Delete $INSTDIR\bin\libpangocairo-1.0-0.dll
  Delete $INSTDIR\bin\libpangoft2-1.0-0.dll
  Delete $INSTDIR\bin\libpangowin32-1.0-0.dll
  Delete $INSTDIR\bin\libgailutil-18.dll
  Delete $INSTDIR\bin\libgdk-win32-2.0-0.dll
  Delete $INSTDIR\bin\libgdk_pixbuf-2.0-0.dll
  Delete $INSTDIR\bin\libgtk-win32-2.0-0.dll
  Delete $INSTDIR\bin\libglade-2.0-0.dll
  Delete $INSTDIR\bin\gspawn-win32-helper.exe
  Delete $INSTDIR\bin\gspawn-win32-helper-console.exe
  Delete $INSTDIR\bin\gtk-update-icon-cache.exe
  Delete $INSTDIR\bin\gtk-demo.exe

  RMDir /r $INSTDIR\lib\gtk-2.0\2.10.0
  RMDir /r $INSTDIR\lib\gtk-2.0\modules
  RMDir $INSTDIR\lib\gtk-2.0
  RMDir $INSTDIR\lib
  
  ; etc
  RMDir /r $INSTDIR\etc\gtk-2.0
  RMDir /r $INSTDIR\etc\pango
  RMDir $INSTDIR\etc

  Delete $INSTDIR\bin\libsigc-*.dll
  Delete $INSTDIR\bin\libcairomm-*.dll
  Delete $INSTDIR\bin\libglibmm-*.dll
  Delete $INSTDIR\bin\libgiomm-*.dll
  Delete $INSTDIR\bin\libglibmm_generate_extra_defs-*.dll
  Delete $INSTDIR\bin\libatkmm-*.dll
  Delete $INSTDIR\bin\libgdkmm-*.dll
  Delete $INSTDIR\bin\libgtkmm-*.dll
  Delete $INSTDIR\bin\libpangomm-*.dll
  Delete $INSTDIR\bin\libglademm-*.dll
  Delete $INSTDIR\bin\libxml++-*.dll
 
  Delete $INSTDIR\bin\sigc++-*.dll
  Delete $INSTDIR\bin\sigc-*.dll
  Delete $INSTDIR\bin\cairomm-*.dll
  Delete $INSTDIR\bin\glibmm-*.dll
  Delete $INSTDIR\bin\giomm-*.dll
  Delete $INSTDIR\bin\atkmm-*.dll
  Delete $INSTDIR\bin\gdkmm-*.dll
  Delete $INSTDIR\bin\gtkmm-*.dll
  Delete $INSTDIR\bin\pangomm-*.dll
  Delete $INSTDIR\bin\glademm-*.dll
;  Delete $INSTDIR\bin\libglademm-*.dll.lnk
  Delete $INSTDIR\bin\xml++-*.dll
;  Delete $INSTDIR\bin\libxml++-*.dll.lnk
  
  Delete $INSTDIR\bin\sigc-*.pdb
  Delete $INSTDIR\bin\cairomm-*.pdb
  Delete $INSTDIR\bin\glibmm-*.pdb
  Delete $INSTDIR\bin\giomm-*.pdb
  Delete $INSTDIR\bin\atkmm-*.pdb
  Delete $INSTDIR\bin\gdkmm-*.pdb
  Delete $INSTDIR\bin\gtkmm-*.pdb
  Delete $INSTDIR\bin\pangomm-*.pdb
  Delete $INSTDIR\bin\glademm-*.pdb
;  Delete $INSTDIR\bin\libglademm-*.pdb.lnk
  Delete $INSTDIR\bin\xml++-*.pdb
;  Delete $INSTDIR\bin\libxml++-*.pdb.lnk
  
  RMDir $INSTDIR\bin
  
  ; share (non-development files)
  RMDir /r $INSTDIR\share\doc\glib-2.18.1
  RMDir /r $INSTDIR\share\doc\cairo_1.7.6-1_win32
  RMDir /r $INSTDIR\share\doc\pango-1.22.0
  RMDir /r $INSTDIR\share\doc\gtk+-2.14.3
  RMDir $INSTDIR\share\doc

  RMdir /r $INSTDIR\share\locale
  RMDir /r $INSTDIR\share\themes
  RMDir /r $INSTDIR\share\gtk-2.0

  RMDir $INSTDIR\share

  ; contrib
  RMDir /r $INSTDIR\contrib\tiff
  RMDir $INSTDIR\contrib

#  
  ; GTKMM_BASEPATH environment variable
  Push "GTKMM_BASEPATH"
  Push $CONTEXT
  Call un.DeleteEnvStr
  
  ; uninstaller
  Delete $INSTDIR\${GTKMM_UNINSTALL_EXE}
  
  ; $INSTDIR
  RMDir $INSTDIR

SectionEnd

;--------------------------------
; Section Description Macros

!insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN

  !insertmacro MUI_DESCRIPTION_TEXT ${SecGTKRuntime} "GTK+ Runtime Environment"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecSigcRuntime} "libsigc++ Runtime Libraries"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecCairommRuntime} "cairomm Runtime Libraries"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecGlibmmRuntime} "glibmm Runtime Libraries"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecPangommRuntime} "pangomm Runtime Libraries"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecGtkmmRuntime} "gtkmm Runtime Libraries"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecLibglademmRuntime} "libglademm Runtime Libraries"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecLibxmlRuntime} "libxml++ Runtime Libraries"
 
!ifndef RUNTIME_ONLY
  !insertmacro MUI_DESCRIPTION_TEXT ${SecGTKDevelopment} "GTK+ development headers and import libraries"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecGTKDocumentation} "GTK+ Documentation"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecSigcDevelopment} "libsigc++ development headers and import libraries"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecSigcDocumentation} "libsigc++ Documentation"

  !insertmacro MUI_DESCRIPTION_TEXT ${SecCairommDevelopment} "cairomm development headers and import libraries"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecCairommDocumentation} "cairomm Documentation"

  !insertmacro MUI_DESCRIPTION_TEXT ${SecGlibmmDevelopment} "glibmm development headers and import libraries"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecGlibmmDocumentation} "glibmm Documentation"

  !insertmacro MUI_DESCRIPTION_TEXT ${SecPangommDevelopment} "pangomm development headers and import libraries"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecPangommDocumentation} "pangomm Documentation"

  !insertmacro MUI_DESCRIPTION_TEXT ${SecGtkmmDevelopment} "gtkmm development headers and import libraries"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecGtkmmDocumentation} "gtkmm Documentation"

  !insertmacro MUI_DESCRIPTION_TEXT ${SecLibglademmDevelopment} "libglademm development headers and import libraries"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecLibglademmDocumentation} "libglademm Documentation"

  !insertmacro MUI_DESCRIPTION_TEXT ${SecLibxmlDevelopment} "libxml++ development headers and import libraries"
  !insertmacro MUI_DESCRIPTION_TEXT ${SecLibxmlDocumentation} "libxml++ Documentation"
  
;  !insertmacro MUI_DESCRIPTION_TEXT ${SecGlademm} "glade-- executable"
;  !insertmacro MUI_DESCRIPTION_TEXT ${SecGideon} "gideon executable"
!endif
  
!insertmacro MUI_FUNCTION_DESCRIPTION_END

;--------------------------------
; General Functions

Function EnableGTKInstaller

;  !insertmacro SelectSection ${SecGTKInstaller}

  !insertmacro UnselectSection ${SecGTKRuntime}
  !insertmacro UnselectSection ${SecSigcRuntime}
  !insertmacro UnselectSection ${SecCairommRuntime}
  !insertmacro UnselectSection ${SecGlibmmRuntime}
  !insertmacro UnselectSection ${SecPangommRuntime}
  !insertmacro UnselectSection ${SecGtkmmRuntime}
  !insertmacro UnselectSection ${SecLibglademmRuntime}
  !insertmacro UnselectSection ${SecLibxmlRuntime}
  
!ifndef RUNTIME_ONLY
  !insertmacro UnselectSection ${SecGTKDevelopment}
  !insertmacro UnselectSection ${SecGTKDocumentation}

  !insertmacro UnselectSection ${SecSigcDevelopment}
  !insertmacro UnselectSection ${SecSigcDocumentation}

  !insertmacro UnselectSection ${SecCairommDevelopment}
  !insertmacro UnselectSection ${SecCairommDocumentation}

  !insertmacro UnselectSection ${SecGlibmmDevelopment}
  !insertmacro UnselectSection ${SecGlibmmDocumentation}

  !insertmacro UnselectSection ${SecPangommDevelopment}
  !insertmacro UnselectSection ${SecPangommDocumentation}

  !insertmacro UnselectSection ${SecGtkmmDevelopment}
  !insertmacro UnselectSection ${SecGtkmmDemo}
  !insertmacro UnselectSection ${SecGtkmmDocumentation}

  !insertmacro UnselectSection ${SecLibglademmDevelopment}
  !insertmacro UnselectSection ${SecLibglademmDocumentation}
  
  !insertmacro UnselectSection ${SecLibxmlDevelopment}
  !insertmacro UnselectSection ${SecLibxmlDocumentation}
  
;  !insertmacro UnselectSection ${SecGlademm}
;  !insertmacro UnselectSection ${SecGideon}
!endif
  
  !insertmacro UnselectSection ${SecPost}

FunctionEnd

Function DisableGTKInstaller

;  !insertmacro UnselectSection ${SecGTKInstaller}

  !insertmacro SelectSection ${SecGTKRuntime}
  !insertmacro SelectSection ${SecSigcRuntime}
  !insertmacro SelectSection ${SecCairommRuntime}
  !insertmacro SelectSection ${SecGlibmmRuntime}
  !insertmacro SelectSection ${SecPangommRuntime}
  !insertmacro SelectSection ${SecGtkmmRuntime}
  !insertmacro SelectSection ${SecLibglademmRuntime}
  !insertmacro SelectSection ${SecLibxmlRuntime}

!ifndef RUNTIME_ONLY
  !insertmacro SelectSection ${SecGTKDevelopment}
  !insertmacro SelectSection ${SecGTKDocumentation}

  !insertmacro SelectSection ${SecSigcDevelopment}
  !insertmacro SelectSection ${SecSigcDocumentation}

  !insertmacro SelectSection ${SecCairommDevelopment}
  !insertmacro SelectSection ${SecCairommDocumentation}

  !insertmacro SelectSection ${SecGlibmmDevelopment}
  !insertmacro SelectSection ${SecGlibmmDocumentation}
  
  !insertmacro SelectSection ${SecPangommDevelopment}
  !insertmacro SelectSection ${SecPangommDocumentation}

  !insertmacro SelectSection ${SecGtkmmDevelopment}
  !insertmacro SelectSection ${SecGtkmmDemo}
  !insertmacro SelectSection ${SecGtkmmDocumentation}

  !insertmacro SelectSection ${SecLibglademmDevelopment}
  !insertmacro SelectSection ${SecLibglademmDocumentation}
  
  !insertmacro SelectSection ${SecLibxmlDevelopment}
  !insertmacro SelectSection ${SecLibxmlDocumentation}
  
;  !insertmacro SelectSection ${SecGlademm}
;  !insertmacro SelectSection ${SecGideon}
!endif
  
  !insertmacro SelectSection ${SecPost}

FunctionEnd

;--------------------------------
; Custom Page Functions

Function CustomPagePathQuestion

  ClearErrors
  ReadRegStr $R0 HKLM "Software\GTK\2.0" "PATH"
  IfErrors 0 +2
  ReadRegStr $R0 HKCU "Software\GTK\2.0" "PATH"
  StrCmp $R0 $INSTDIR path_ok
    !insertmacro MUI_HEADER_TEXT "$(MISC_INSTALL_OPTION)" "$(MISC_ANSWER_SYSTEM)"
    !insertmacro MUI_INSTALLOPTIONS_WRITE "PathQuestion.ini" "Field 1" "Text" "$(GTKMM_ADD_PATH)"
    !insertmacro MUI_INSTALLOPTIONS_DISPLAY "PathQuestion.ini"
    Goto done
  path_ok:
    ; no need to set path. Already done by the GTK+ Installer
    IfSilent "" +2
    StrCpy $CB_PATH_VALUE "0"
  done:

FunctionEnd

Function CustomPageSetContext

  ClearErrors
  UserInfo::GetName
  IfErrors continue
  Pop $0
  UserInfo::GetAccountType
  Pop $1
  StrCmp $1 "Admin" 0 done
continue:
  StrCpy $ISADMIN "1"
  IfSilent "" +2
    Goto done

  !insertmacro MUI_HEADER_TEXT "$(MISC_INSTALL_OPTION)" "$(MISC_UNINSTALL_CONTEXT)"
  !insertmacro MUI_INSTALLOPTIONS_WRITE "SetContext.ini" "Field 1" "Text" "$(GTKMM_RIGHTS_INSTALL)"
  !insertmacro MUI_INSTALLOPTIONS_WRITE "SetContext.ini" "Field 2" "Text" "$(GTKMM_RIGHTS_ANYONE)"
  !insertmacro MUI_INSTALLOPTIONS_WRITE "SetContext.ini" "Field 3" "Text" "$(GTKMM_RIGHTS_CURRENT)"
  !insertmacro MUI_INSTALLOPTIONS_DISPLAY "SetContext.ini"
done:
  
FunctionEnd

Function CustomSetTargetDirectory

  IfSilent 0 +2
    StrCmp $USE_GTKDIR "1" 0 done
  ReadRegStr $R0 HKLM Software\${PRODUCT_NAME}\${PRODUCT_API_VERSION} "Path"
  StrCmp $R0 "" "" done
  ReadRegStr $R0 HKCU Software\${PRODUCT_NAME}\${PRODUCT_API_VERSION} "Path"
  StrCmp $R0 "" "" done
  ReadRegStr $R0 HKLM "Software\GTK\2.0" "Path"
  StrCmp $R0 "" "" +3
  ReadRegStr $R0 HKCU "Software\GTK\2.0" "Path"
  StrCmp $R0 "" done
  Push $R0
  Pop $INSTDIR
done:

FunctionEnd

Function CustomPreviousVersion

  ; Get installer location
  ClearErrors
  ReadRegStr $R0 HKLM \
  "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" \
  "UninstallString"
  IfErrors 0 +2
  ReadRegStr $R0 HKCU \
  "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" \
  "UninstallString"
  StrCmp $R0 "" done

  ; Get current installed version
  ClearErrors
  ReadRegStr $R1 HKLM \
  "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" \
  "DisplayVersion"
  IfErrors 0 +2
  ReadRegStr $R1 HKCU \
  "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" \
  "DisplayVersion"

  ; Extract package and installer versions
  ${StrTok} $R2 $R1 "-" 0 1
  ${StrTok} $R3 $R1 "-" 1 1
  
  ${VersionCheck} $R2 ${PRODUCT_VERSION} "$R4"
  StrCmp $R4 "1" newerInstall

  StrCmp $R4 "2" +2
  IntCmp $R3 ${PRODUCT_VERSION_INSTALLER} "" "" newerInstall

  IfSilent "" +2
    StrCmp $FORCE_UNINSTALL "1" +2 no_remove_uninstaller
  MessageBox MB_YESNOCANCEL|MB_ICONEXCLAMATION "$(GTKMM_PREVIOUS_VERSION)" IDNO done IDCANCEL abortInstall

  ;Run the uninstaller
  ClearErrors
  CopyFiles "$R0" $TEMP
  StrCpy $R1 ""
  IfSilent 0 +2
    StrCpy $R1 "/S"
  ExecWait '"$TEMP\${GTKMM_UNINSTALL_EXE}" $R1 _?=$INSTDIR'

  IfErrors no_remove_uninstaller
    Delete $R0
    RMDir $INSTDIR

  no_remove_uninstaller:
    Delete "$TEMP\$R0"
    ; Check that the user completed the uninstallation by examining the registry
    ReadRegStr $R0 HKLM \
    "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" \
    "UninstallString"
    IfErrors 0 +2
    ReadRegStr $R0 HKCU \
    "Software\Microsoft\Windows\CurrentVersion\Uninstall\${PRODUCT_NAME}" \
    "UninstallString"
    StrCmp $R0 "" done abortInstall
    
newerInstall:
    IfSilent +2
      MessageBox MB_OK|MB_ICONEXCLAMATION "$(GTKMM_NEWER)" IDOK ""
    Abort

abortInstall:
    IfSilent 0
      MessageBox MB_OK|MB_ICONEXCLAMATION "$(GTKMM_PREVIOUS_ERROR)"
    Abort

done:
    BringToFront
    
FunctionEnd


;--------------------------------
; Callbacks

;Function .onSelChange
;
;  !insertmacro UnselectSection ${SecGTKInstaller}
;
;FunctionEnd

Function .onInit

  ; Display the language selection dialog
  !insertmacro MUI_LANGDLL_DISPLAY

  ;Extract InstallOptions INI files
  !insertmacro MUI_INSTALLOPTIONS_EXTRACT_AS "NSISLibrary\PathQuestion.ini" "PathQuestion.ini"
  !insertmacro MUI_INSTALLOPTIONS_EXTRACT_AS "NSISLibrary\SetContext.ini" "SetContext.ini"
  
  ; Get Command line Parameters
  Push "ALLUSERS"
  call Cmd_GetParameter
  Pop $CONTEXT
  Push "SET_ENVVARS"
  call Cmd_GetParameter
  Pop $CB_PATH_VALUE
  Push "FORCE_UNINSTALL"
  call Cmd_GetParameter
  Pop $FORCE_UNINSTALL
  Push "USE_GTKDIR"
  call Cmd_GetParameter
  Pop $USE_GTKDIR
  
  IfSilent "" +5
    StrCpy $ICONS_GROUP "Gtkmm"
    Call CustomPreviousVersion
    Call CustomSetTargetDirectory
    Call CustomPagePathQuestion
    Call CustomPageSetContext

FunctionEnd

Function un.onInit

  !insertmacro MUI_UNGETLANGUAGE

FunctionEnd

