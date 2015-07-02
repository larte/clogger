#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "minunit.h"
#include "clogger.h"

#define TEST_FILE  __FILE__

int tests_run = 0;
int failed = 0;


static char * test_clogger_levels() {
    LOG(Debug, "This is Debug");
    LOG(Info, "This is Info");
    LOG(Warn, "This is Warn");
    LOG(Error, "This is Error");
    LOG(Fatal, "This is Fatal");
    return NULL;
}

static char * test_clogger_macros() {
    LOG_DEBUG("This is %d", Debug);
    LOG_INFO("This is %d", Info);
    LOG_WARN("This is %d", Warn);
    LOG_ERROR("This is %d", Error);
    LOG_FATAL("This is %d", Fatal);
    return NULL;
}

static char * all_tests() {
    mu_run_test(test_clogger_levels);
    mu_run_test(test_clogger_macros);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = NULL;
    freopen("/tmp/clogger_test_stderr", "w", stderr);
    freopen("/tmp/clogger_test_stdout", "w", stdout);
    all_tests();
    freopen("/dev/stdout", "w", stdout);
    freopen("/dev/stderr", "w", stderr);
    if (result) {
        printf("\n%s\n", result);
    }
    else {
        printf("\t\t\t\t...ALL TESTS PASSED\n");
    }
    printf("Tests run: %d, failed tests %d\n",
           tests_run, failed);

    return result != 0;
}
