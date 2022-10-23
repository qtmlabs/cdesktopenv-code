MAINTAINERCLEANFILES = Makefile.in

lib_LTLIBRARIES = libDtMrm.la

libDtMrm_la_CFLAGS = $(AM_CFLAGS) -I../DtTerm/Term -I../DtTerm/TermPrim -I../DtHelp \
		     @DT_INCDIR@ @DTI_INCDIR@

libDtMrm_la_SOURCES = DtMrm.c

libDtMrm_la_LIBADD = ../DtSvc/libDtSvc.la ../DtHelp/libDtHelp.la \
		     ../DtTerm/libDtTerm.la ../DtPrint/libDtPrint.la \
		     ../DtWidget/libDtWidget.la $(XTOOLLIB)

libDtMrm_la_LDFLAGS = $(AM_LDFLAGS) -version-number 2:1:0

