/*

  clogger.c

  Author: Lauri Arte <lauri.arte@wayfinder.com>

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

/* Header defines */
#define INFO_COLOR  "\033[1;32;48m[INFO ]\033[0m "
#define DEBUG_COLOR "\033[1;34;48m[DEBUG]\033[0m "
#define WARN_COLOR  "\033[1;33;48m[WARN ]\033[0m "
#define ERROR_COLOR "\033[1;35;48m[ERROR]\033[0m "
#define FATAL_COLOR "\033[1;31;48m[FATAL]\033[0m "

#define INFO_NO_COLOR  "[INFO ] "
#define DEBUG_NO_COLOR "[DEBUG] "
#define WARN_NO_COLOR  "[WARN ] "
#define ERROR_NO_COLOR "[ERROR] "
#define FATAL_NO_COLOR "[FATAL] "


static int clogger_colors  = 0;
static int clogger_level = Info;

void clogger_set_colorize(int colors)
{
    clogger_colors = (colors == 1) ? 1 : 0;
}

// TODO: check level sanity;
void clogger_set_level(LogLevel level)
{
    clogger_level = level;
}

void clogger_log(int level, char *file, int line, const char *format, ...)
{

    FILE *outputs = ((level < Error) ? stdout : stderr);
    size_t size;
    char *buffer;

    if (level >= clogger_level || level == Fatal) {
        switch (level) {
        case Info:

            fprintf(outputs, clogger_colors == 1 ? INFO_COLOR : INFO_NO_COLOR);
            break;
        case Debug:
            fprintf(outputs,
                    clogger_colors == 1 ? DEBUG_COLOR : DEBUG_NO_COLOR);
            fprintf(outputs, "%s:%d ", file, line);
            break;
        case Warn:
            fprintf(outputs,
                    clogger_colors == 1 ? WARN_COLOR : WARN_NO_COLOR);
            break;
        case Error:
            fprintf(outputs,
                    clogger_colors == 1 ? ERROR_COLOR : ERROR_NO_COLOR);
            break;
        default:
            fprintf(outputs,
                    clogger_colors == 1 ? FATAL_COLOR : FATAL_NO_COLOR);
            break;
        }

        va_list args;
        va_start(args, format);

        size = vsnprintf(NULL, 0, format, args);
        buffer = (char *) malloc(sizeof(char) * size + 1);
        vsnprintf(buffer, sizeof(buffer), format, args);

        va_end(args);

        fprintf(outputs, "%s\n", buffer);

        free(buffer);
    }
}
