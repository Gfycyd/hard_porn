#include <check.h>
#include "assignment3/bitMap.h"
#include "stdio.h"

START_TEST (test_setBitByNumber)
    {
        int array[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        ck_assert(array[4] == 0);
        setBitByNumber(array, 1, 4);
        ck_assert(array[4] == 1);
    }
END_TEST

START_TEST (test_getBitByNumber)
    {
        int array[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        setBitByNumber(array, 1, 4);
        ck_assert((array[2] == 0)&&(getBitByNumber(array, 2) == 0));
        ck_assert((array[4] == 1)&&(getBitByNumber(array, 4) == 1));
        ck_assert(getBitByNumber(array, 4) != getBitByNumber(array, 2));
    }
END_TEST

START_TEST (test_setBitByAddress)
    {
        int array[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        int* secondBit = &array[1];
        ck_assert((*secondBit == 0) && (array[1] == 0));
        setBitByAddress(secondBit, 1);
        ck_assert(array[1] == 1);
    }
END_TEST

START_TEST (test_getBitByAddress)
    {
        int array[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        ck_assert(getBitByAddress(&array[2]) == 0);
        setBitByAddress(&array[2], 1);
        ck_assert(getBitByAddress(&array[2]) == 1);

    }
END_TEST

Suite *str_suite(void) {
    Suite *suite = suite_create("priority queue");
    TCase *tcase = tcase_create("case");
    tcase_add_test(tcase, test_setBitByNumber);
    tcase_add_test(tcase, test_getBitByNumber);
    tcase_add_test(tcase, test_setBitByAddress);
    tcase_add_test(tcase, test_getBitByAddress);
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