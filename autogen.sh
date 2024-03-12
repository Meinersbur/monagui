#! /bin/sh -e
test -n "$srcdir" || srcdir=`dirname "$0"`
test -n "$srcdir" || srcdir=.

#mm-common-prepare --force --copy "$srcdir"
./makefilelist.sh
#intltoolize --force --automake --copy
autoreconf --verbose --force --install --warnings=all "$srcdir"
test -n "$NOCONFIGURE" || "$srcdir/configure" --enable-maintainer-mode "$@"
make -j2

