MAINTAINERCLEANFILES = Makefile.in

SUBDIRS = raima

lib_LTLIBRARIES = libDtSearch.la

BUILT_SOURCES = boolyac.h boolyac.c
CLEANFILES = boolyac.h boolyac.c
AM_YFLAGS = -d

libDtSearch_la_CFLAGS = $(AM_CFLAGS) -DI18N_MSG -DMULTIBYTE -I./raima \
			$(DT_INCDIR)


libDtSearch_la_LDFLAGS = $(AM_LDFLAGS) -version-number 2:1:0

libDtSearch_la_LIBADD = ../DtSvc/libDtSvc.la raima/libraima.la $(XTOOLLIB)

libDtSearch_la_SOURCES = apndext.c	ausdopen.c	ausexit.c \
			 bmstrstr.c	boolpars.c	boolsrch.c \
			 boolyac.y	cuslang.c	dbchange.c \
			 dberr.c	delspace.c	dtoe.c \
			 dtoeinit.c	dtsrapi.c	dtsrdbrec.c \
			 dtsrjoint.c	dtsrswab.c	dtsrutil.c  \
			 dtsrve.c	endslash.c	fileman.c \
			 globals.c	hdecode.c	hencode.c \
			 hilite.c	iscompat.c	isduprec.c \
			 jpn.c		lang.c		langmap.c \
			 msgs.c		msgutil.c	objdate.c \
			 ocf.c		opendblk.c	ophuf.c \
			 readchar.c	strupr.c	userint.c \
			 vedelete.c	vestatis.c	vstfunct.c
