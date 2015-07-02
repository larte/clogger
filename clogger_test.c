#include "clogger/clogger.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    clogger_set_level(Debug);
    clogger_set_colorize();

    LOG_WARN("This is log line #%d", 1);

    LOG(Info, "This is line #%s", "2");

    LOG(Fatal, "This will be printed regardless of level");

    LOG_DEBUG("This will also contain filename and line");

    return 1;
}
