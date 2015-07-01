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
    Debug = 0,
    Info  = 1,
    Warn  = 2,
    Error = 3,
    Fatal = 4
}LogLevel;


void clogger_set_colorize(int colorize);

void clogger_set_level(LogLevel level);

void clogger_log(int level, char *file, int line, const char *format, ...);

#define LOG(level, format, ...) clogger_log(level,__FILE__,__LINE__,(const char*)format, ## __VA_ARGS__);
#define LOG_DEBUG(format, ...) \
    clogger_log(Debug, __FILE__, __LINE__, (const char*)format, ## __VA_ARGS__);
#define LOG_INFO(format, ...) \
    clogger_log(Info, __FILE__, __LINE__, (const char*)format, ## __VA_ARGS__);
#define LOG_WARN(format, ...) \
    clogger_log(Warn, __FILE__, __LINE__, (const char*)format, ## __VA_ARGS__);
#define LOG_ERROR(format, ...) \
    clogger_log(Error, __FILE__, __LINE__, (const char*)format, ## __VA_ARGS__);
#define LOG_FATAL(format, ...) \
    clogger_log(Fatal, __FILE__, __LINE__, (const char*)format, ## __VA_ARGS__);


#endif
