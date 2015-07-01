check_PROGRAMS = clogger_tests

clogger_tests_SOURCES = clogger_tests.c $(top_builddir)/include/clogger.h
clogger_tests_CFLAGS = -I./../src -I./../include -ggdb3 -O0
clogger_tests_LDADD = $(top_builddir)/src/clogger.o

TESTS = clogger_tests
