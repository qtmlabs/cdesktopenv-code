MAINTAINERCLEANFILES = Makefile.in

SUBDIRS = util TermPrim Term TermView

lib_LTLIBRARIES = libDtTerm.la

libDtTerm_la_SOURCES =

libDtTerm_la_LIBADD = Term/libTerm.la TermPrim/libTermPrim.la \
		       TermView/libTermView.la ../DtSvc/libDtSvc.la $(XTOOLLIB)

if OPENBSD
libDtTerm_la_LIBADD += -lutil
endif

if FREEBSD
libDtTerm_la_LIBADD += -lutil
endif

if SOLARIS
libDtTerm_la_LIBADD += -lgen
endif

if HAS_UTEMPTER_LIBRARY
libDtTerm_la_LIBADD += -lutempter
endif

libDtTerm_la_LDFLAGS = $(AM_LDFLAGS) -version-number 2:1:0

