clogger
=======

A simple C logger lib. I wrote this to try to learn autotools and libtool.


Defined logging macros for levels Debug, Info, Warn, Error and Fatal. The macros are LOG(LEVEL,format, ...) and LOG_LEVEL(format, ...). The default level is INFO, and FATAL level lines are always printed. Debug level messages will include filename and line.


## Installation

Default installation dir is /usr/local/lib with prefix /usr/local, which is often not in LD_LIBRARY_PATH. Another prefix can be defined:

    $ configure --prefix=usr
    $ make
    $ make install


## Usage


test.c

     #include "clogger.h"


     int main() {

       clogger_set_colorize(); // or clogger_unset_colorize()
       clogger_set_leve(Debug);

       LOG_WARN("This is log line #%d", 1);

       LOG(Info, "This is line #%s", "2");

       LOG(Fatal, "This will be printed regardless of level");

       LOG_DEBUG("This will also contain filename and line");
       return 0;
     }


and compile:

    $ gcc -o test test.c -lclogger
