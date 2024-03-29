%define name mona
%define version 1.4
%define release 13

Summary: a decision procedure for the logics WS1S and WS2S
Name: %{name}
Version: %{version}
Release: %{release}
License: GPL
Group: Development/Tools
URL: http://www.brics.dk/mona
Vendor: BRICS
Source: http:/www.brics.dk/mona/download/%{name}-%{version}-%{release}.tar.gz
BuildRoot: /tmp/%{name}-%{version}
Packager: Anders Moeller <amoeller@brics.dk>

%description 
MONA is a tool that translates formulas in the logics WS1S or WS2S
into finite-state automata represented by BDDs.  The formulas may
express search patterns, temporal properties of reactive systems,
parse tree constraints, etc.  MONA also analyses the automaton
resulting from the compilation, and determines whether the formula is
valid and, if the formula is not valid, generates a counter-example.

%prep
%setup -q

%build
%configure 
make

%install
`rpm --eval '%makeinstall'`-strip

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%doc README COPYING INSTALL
%{_bindir}/mona
%{_bindir}/dfa2dot
%{_bindir}/gta2dot
%{_mandir}/man1/*
%{_datadir}/mona-mode.el
%{_includedir}/mona/*
%{_libdir}/*.so*
%{_libdir}/*.a*
%{_libdir}/*.la*

