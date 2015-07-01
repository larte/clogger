###############################################################################
# THE LIBRARIES TO BUILD
###############################################################################
ACLOCAL_AMFLAGS = -I m4
# the library names to build (note we are building static libs only)
lib_LTLIBRARIES = libclogger.la

# where to install the headers on the system
libclogger_ladir = $(includedir)/clogger

# the list of header files that belong to the library (to be installed later)
libclogger_la_HEADERS =    \
                        $(top_srcdir)/include/clogger.h

AM_CPPFLAGS = -I$(top_srcdir)/include

# the sources to add to the library and to add to the source distribution
libclogger_la_SOURCES =    \
                        $(libmylib_la_HEADERS) \
                        clogger.c

libclogger_la_LDFLAGS   = -version 0:0:1

###############################################################################
