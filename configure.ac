#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([src/clogger.c])
AC_CONFIG_HEADERS([config.h])
LT_INIT
AM_INIT_AUTOMAKE
# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL

AM_PROG_CC_C_O

AC_ARG_ENABLE([tests], AS_HELP_STRING([--enable-tests],[enable building of tests @<:@default=no@:>@]))
AM_CONDITIONAL([RUNTESTS], [test "x$enable_tests" != "xno"])

AC_CONFIG_MACRO_DIRS([m4])


# Checks for libraries.


AM_PATH_CHECK(0.9.6,[],[])
# Checks for header files.
AC_CHECK_HEADERS([string.h stdarg.h])

AC_CHECK_HEADER(check.h,
            [],
            [AC_MSG_WARN([*** Couldn't find or include check.h. Unit tests won't work!])]
            )

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_PID_T

# Checks for library functions.
AC_FUNC_ALLOCA
AC_FUNC_MALLOC
AC_CHECK_FUNCS([stpcpy strdup strstr])

AC_CONFIG_FILES([Makefile
                 src/Makefile include/Makefile tests/Makefile])
AC_OUTPUT
