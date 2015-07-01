#ifndef _MINUNIT_H_
#define _MINUNIT_H_

#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++;     \
        if (message) {failed++; return message;} } while (0)
extern int tests_run;
extern int failed;

#endif
