MAINTAINERCLEANFILES = Makefile.in

lib_LTLIBRARIES = libDtPamSvc.la

# the PamSvc.h header file is located in include/Dt/
libDtPamSvc_la_SOURCES = PamSvc.c ${top_srcdir}/include/Dt/PamSvc.h

libDtPamSvc_la_LIBADD = -lpam

libDtPamSvc_la_LDFLAGS = $(AM_LDFLAGS) -version-number 2:1:0


