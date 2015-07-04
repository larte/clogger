check_PROGRAMS = check_clogger

check_clogger_SOURCES = check_clogger.c
check_clogger_CFLAGS = -I./../src -I./../include -ggdb3 -O0 @CHECK_CFLAGS@
check_clogger_LDADD = $(top_builddir)/src/clogger.o @CHECK_LIBS@

TESTS = check_clogger
