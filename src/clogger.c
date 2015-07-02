/*

  clogger.c

  Author: Lauri Arte <lauri.arte@gmail.com>

  All rights reserved

  Created: Sat Sep 19 19:42:06 2009 larte

*/

/*
 *
 */

#include "clogger.h"
#include <string.h>
#include <stdlib.h>
#include "stdarg.h"

static int clogger_colorize  = 0;
static int clogger_level = Info;

void clogger_set_colorize()
{
    clogger_colorize = 1;
}

void clogger_unset_colorize()
{
    clogger_colorize = 0;
}

void clogger_set_level(LogLevel level)
{
    clogger_level = level;
}


static void write_log_header(FILE *outputs, LogLevel level, char *file, int line)
{
    fprintf(outputs, "%s%s%s",
            clogger_colors[clogger_colorize * (int) level],
            clogger_headers[level],
            (clogger_colorize == 0) ? " " : CLOGGER_RESET);
    if (level == Debug)
            fprintf(outputs, "%s:%d ", file, line);
}

void clogger_log(int level, char *file, int line, const char *format, ...)
{

    FILE *outputs = ((level < Error) ? stdout : stderr);
    size_t size = 1024;
    int n;
    char *buffer, *tmp;
    va_list args;

    if (level >= clogger_level) {

        write_log_header(outputs, level, file, line);


        if ((buffer = malloc(size)) == NULL)
            return;

        while(1) {

            va_start(args, format);
            n = vsnprintf(buffer, size, format, args);
            va_end(args);

            /* couldn't allocate */
            if (n < 0) {
                free(buffer);
                return;
            }

            /* managed to allocate needed space */
            if ( n < (int) size) {
                fprintf(outputs, "%s\n", buffer);
                free(buffer);
                return;
            }

            size = n + 1;

            if  ((tmp = realloc(buffer,size)) == NULL) {
                free(buffer);
                return;
            }
            else {
                buffer = tmp;
            }
        }

    }
}
