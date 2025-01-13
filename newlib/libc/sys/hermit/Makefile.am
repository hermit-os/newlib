AUTOMAKE_OPTIONS = cygnus
INCLUDES = $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS)
AM_CCASFLAGS = $(INCLUDES)

noinst_LIBRARIES = lib.a

lib_a_SOURCES:= \
	_exit.c \
	alloc.c \
	context.S \
	environ.c \
	errno.c \
	execve.c \
	fork.c \
	forward.c \
	fstat.c \
	getaddrinfo.c \
	getpagesize.c \
	getpid.c \
	gettod.c \
	inet_ntoa.c \
	isatty.c \
	kill.c \
	link.c \
	makecontext.c \
	nanosleep.c \
	open.c \
	readlink.c \
	sched.c \
	setitimer.c \
	signal.c \
	stat.c \
	stub.c \
	symlink.c \
	sysconf.c \
	time.c \
	times.c \
	unlink.c \
	wait.c

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
