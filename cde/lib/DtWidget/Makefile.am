unixdir = $(CDE_INSTALLATION_TOP)/app-defaults/C

MAINTAINERCLEANFILES = Makefile.in

lib_LTLIBRARIES = libDtWidget.la

AM_CPPFLAGS += -DCDE_INSTALLATION_TOP=$(CDE_INSTALLATION_TOP) $(DT_INCDIR)

libDtWidget_la_CFLAGS = $(AM_CFLAGS) -DI18N_MSG -DMULTIBYTE

libDtWidget_la_LIBADD = ../DtSvc/libDtSvc.la $(XTOOLLIB)

libDtWidget_la_LDFLAGS = $(AM_LDFLAGS) -version-number 2:1:0

if SOLARIS
libDtWidget_la_CFLAGS += -DNO_REGCOMP
libDtWidget_la_LIBADD += -lw -lintl
endif


libDtWidget_la_SOURCES = ComboBox.c      Control.c       DialogBox.c \
			 DtMsgs.c        DtStrDefs.c     EditAreaData.c \
			 EditCalls.c     Editor.c        Icon.c \
			 MenuButton.c    NewCvt.c        SearchCalls.c \
			 SearchDlg.c     SpinBox.c       TitleBox.c \
			 View.c

# cpp this...
BUILT_SOURCES = UNIXbindings
CLEANFILES = UNIXbindings

UNIXbindings: UNIXbindings.cpp
	$(RM) $@
	$(GENCPP) -P -DXCOMM=# $(AM_CPPFLAGS) $< > $@
