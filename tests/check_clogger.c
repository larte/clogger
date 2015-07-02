#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <check.h>

#include "clogger.h"

#define TEST_FILE  __FILE__

int tests_run = 0;
int failed = 0;

START_TEST(test_clogger_log_macro)
{
    //ck_assert_int_eq(money_amount(m), 5);
    //    ck_assert_str_eq(money_currency(m), "USD");

}
END_TEST

int main(void)
{
    return 0;
}
