#include <check.h>
#include <stdbool.h>
#include "assignment3/bitMap.h"
#include "stdio.h"

START_TEST (test_setBitByNumber)
    {
        int a[] = {0,1,1};
        int* array = &a[0];
        int position = 31;
        setBitByNumber(array,1,position,32);
        position = 61;
        setBitByNumber(array,1,position,32);
        position = 95;
        setBitByNumber(array,0,position,32);

    }
END_TEST

START_TEST (test_getBitByNumber)
    {
        printf("GetBitByNumber test!!\n");
        int arr[] = {10, 7};
        printf("10 in binary representation: \n");
        bool* ar1 = decimal_to_binary(10, 32);
        int i = 0;
        for(i = 0; i < 32; i++){
            printf("%i",ar1[i]);
        }
        printf("\n");
        printf("7 in binary representation: \n");
        bool* ar2 = decimal_to_binary(7, 32);
        for(i = 0; i < 32; i++){
            printf("%i",ar2[i]);
        }
        printf("\n");
        ck_assert(getBitByNumber(arr, 30, 32) == 1);
        ck_assert(getBitByNumber(arr, 28, 32) == 1);
        ck_assert(getBitByNumber(arr, 5, 32) == 0);
        ck_assert(getBitByNumber(arr, 63, 32) == 1);
        ck_assert(getBitByNumber(arr, 60, 32) == 0);

    }
END_TEST

START_TEST (test_setBitByAddress)
    {
//YOUR CODE HERE
        // code where change just the lasr symbol
        /* int array[8] = {0, 0, -90909, 0, 0, 0, 0, 0};
         int* secondBit = &array[1];
         setBitByAddress(secondBit, 1);
         ck_assert_int_eq(*(int*)secondBit,1);
         int array[8] = {0, 0, -90908, 0, 0, 0, 0, 0};
         int* thirdBit = &array[2];
         setBitByAddress(thirdBit, 1);
         printf("%d\n", array[2]);
         ck_assert_int_eq(*(int*)thirdBit,-90907);
        */
        int array[8] = {0, 0, -90909, -10, 0, 0, 0, 0};
        int* forthBit = &array[3];
        setBitByAddress(forthBit, 1);
        ck_assert_int_eq(*(int*)forthBit,-10);

    }
END_TEST

START_TEST (test_getBitByAddress)
    {
        int b = UINT32_MAX-1;
        void* position = &b;
        int output =  getBitByAddress(position);
        ck_assert(output == 1);

        b = 10000;
        output =  getBitByAddress(position);
        ck_assert(output == 0);

        b = UINT32_MAX >> 1;
        output =  getBitByAddress(position);
        ck_assert(output == 0);

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