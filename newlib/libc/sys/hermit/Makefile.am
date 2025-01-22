AUTOMAKE_OPTIONS = cygnus
INCLUDES = $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS)
AM_CCASFLAGS = $(INCLUDES)

noinst_LIBRARIES = lib.a

lib_a_SOURCES:= \
	alloc.c \
	context.S \
	environ.c \
	errno.c \
	fcntl.c \
	forward.c \
	getaddrinfo.c \
	inet_ntoa.c \
	ioctl.c \
	makecontext.c \
	resource.c \
	sched.c \
	stub.c \
	time.c \
	unistd.c

lib_a_CCASFLAGS = $(AM_CCASFLAGS)
lib_a_CFLAGS = $(AM_CFLAGS)

all-local: crt0.o

ACLOCAL_AMFLAGS = -I ../../..
CONFIG_STATUS_DEPENDENCIES = $(newlib_basedir)/configure.host

install-data-local:
	$(mkinstalldirs) $(DESTDIR)$(tooldir)/include/arpa; \
		for i in $(srcdir)/include/arpa/*.h; do \
			$(INSTALL_DATA) $$i $(DESTDIR)$(tooldir)/include/arpa/`basename $$i`; \
		done;
	$(mkinstalldirs) $(DESTDIR)$(tooldir)/include/netinet; \
		for i in $(srcdir)/include/netinet/*.h; do \
			$(INSTALL_DATA) $$i $(DESTDIR)$(tooldir)/include/netinet/`basename $$i`; \
		done;
