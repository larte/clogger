/*

logger.h

Author: Lauri Arte <lauri.arte@gmail.com>

Created: Sat Sep 19 19:38:07 2009 larte

*/

/*
 *
 * a Logger
 */

#ifndef __CLOGGER_H__
#define __CLOGGER_H__

#include <stdio.h>

typedef enum{
    Debug = 1,
    Info  = 2,
    Warn  = 3,
    Error = 4,
    Fatal = 5
}LogLevel;

const char* clogger_headers[] = {
            "",
            "[DEBUG]",
            "[INFO ]",
            "[WARN ]",
            "[ERROR]",
            "[FATAL]" };

const char* clogger_colors[] = {
        "",
        "\033[1;32;48m",
        "\033[1;34;48m",
        "\033[1;33;48m",
        "\033[1;35;48m",
        "\033[1;31;48m" };

#define CLOGGER_RESET "\033[0m "


void clogger_set_colorize();
void clogger_unset_colorize();

void clogger_set_level(LogLevel level);

void clogger_log(int level, char *file, int line, const char *format, ...);

#define LOG(level, format, ...) \
    clogger_log(level,__FILE__,__LINE__,(const char*)format, ## __VA_ARGS__);

#define LOG_DEBUG(format, ...)                                          \
    clogger_log(Debug, __FILE__, __LINE__, (const char*)format, ## __VA_ARGS__);

#define LOG_INFO(format, ...)                                           \
    clogger_log(Info, __FILE__, __LINE__, (const char*)format, ## __VA_ARGS__);

#define LOG_WARN(format, ...)                                           \
    clogger_log(Warn, __FILE__, __LINE__, (const char*)format, ## __VA_ARGS__);

#define LOG_ERROR(format, ...)                                          \
    clogger_log(Error, __FILE__, __LINE__, (const char*)format, ## __VA_ARGS__);

#define LOG_FATAL(format, ...)                                          \
    clogger_log(Fatal, __FILE__, __LINE__, (const char*)format, ## __VA_ARGS__);


#endif
