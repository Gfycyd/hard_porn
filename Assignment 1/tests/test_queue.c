#include "priority_queue.h"
#include <check.h>

START_TEST(test_priority_queue){
    /** empty queue */
    ck_assert(extract_min() == -INFINITY);
    insert(5, 3);
    /** extract_min testing*/
    ck_assert(extract_min() == 5);
    insert(4, 1);
    insert(12, 5);
    ck_assert(extract_min() == 4);
    insert(44, -1);
    insert(10, 10);
    /** check exit code*/
    ck_assert(insert(45, 0) == 0);
    ck_assert(extract_min() == 44);
    extract_min();
    extract_min();
    extract_min();
    /** empty queue again*/
    ck_assert(extract_min() == -INFINITY);
    int n = 0;
    while (n < 100){
        insert(69, n);
        n++;
    }
    /** check exit code for full queue*/
    ck_assert(insert(69,69) == 1);
}
END_TEST

Suite* str_suite (void) {
    Suite *suite = suite_create("Home assignment 1");
    TCase *tcase = tcase_create("case");
    tcase_add_test(tcase, test_priority_queue);
    suite_add_tcase(suite, tcase);
    return suite;
}

int main(int argc, char *argv[]) {
    int number_failed;
    Suite *suite = str_suite();
    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return number_failed;
}
