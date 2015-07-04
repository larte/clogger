#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <check.h>

#include "clogger.h"

#define TEST_FILE  "/tmp/check_clogger.log"

int tests_run = 0;
int failed = 0;
FILE *output_fd = 0;

void new_output()
{
    output_fd = fopen(TEST_FILE, "w");
    clogger_set_output(output_fd);
}

void teardown()
{

}

unsigned long output_size()
{
    FILE * f = fopen(TEST_FILE, "r");
    fseek(f, 0, SEEK_END);
    unsigned long len = (unsigned long)ftell(f);
    fclose(f);
    return len;
}

START_TEST(test_clogger_log_macro)
{
    new_output();
    ck_assert_int_eq(output_size(), 0);
    LOG(Info, "This is a log line");
    fflush(output_fd);
    ck_assert_int_gt(output_size(), 0);
}
END_TEST

START_TEST(test_clogger_expanded_macro)
{
    new_output();
    ck_assert_int_eq(output_size(), 0);
    LOG_INFO("This is a log line");
    fflush(output_fd);
    ck_assert_int_gt(output_size(), 0);
}
END_TEST

START_TEST(test_clogger_log_levels)
{
    new_output();
    clogger_set_level(Warn);
    ck_assert_int_eq(output_size(), 0);
    LOG_INFO("This is a log line");
    fflush(output_fd);
    ck_assert_int_eq(output_size(), 0);
    LOG_WARN("This is a log line");
    fflush(output_fd);
    ck_assert_int_gt(output_size(), 0);
}
END_TEST


Suite * clogger_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("clogger");

    tc_core = tcase_create("Logging");

    tcase_add_test(tc_core, test_clogger_log_macro);
    tcase_add_test(tc_core, test_clogger_expanded_macro);
    tcase_add_test(tc_core, test_clogger_log_levels);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = clogger_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
