MAINTAINERCLEANFILES = Makefile.in

SUBDIRS = api db mp util tttk

lib_LTLIBRARIES = libtt.la

libtt_la_SOURCES =

# fake things so libtool creates this as a C++ library
nodist_EXTRA_libtt_la_SOURCES = dummy.cxx
libtt_la_LIBADD = api/c/libapi.la api/dnd/libdnd.la db/libdb.la mp/libmp.la \
		  util/libutil.la tttk/libtttk.la $(XTOOLLIB)

if SOLARIS
# This stuff should be figured out by configure
libtt_la_LIBADD += -lnsl -lsocket -lintl -lw
endif

if LINUX
libtt_la_LIBADD += $(TIRPCLIB)
endif

libtt_la_LDFLAGS = $(AM_LDFLAGS) -version-number 2:1:0

