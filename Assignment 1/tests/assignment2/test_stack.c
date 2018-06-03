#include <check.h>
#include "assignment2/stack.h"

START_TEST(test_stack){
    /**Check empty stack*/
    ck_assert(pop() == -INFINITY);
    ck_assert(peek() == -INFINITY);
    push(23);
    push(34);
    push(11);
    push(0.5);
    /**test of pop() and peek()*/
    ck_assert(pop() == 0.5);
    ck_assert(pop() == 11);
    ck_assert(peek() == 34);
    ck_assert(peek() == 34);
    /**check exit code*/
    ck_assert(push(0.5) == 0);
    pop();
    pop();
    pop();
    ck_assert(pop() == -INFINITY);
    int n = 0;
    while (n < 50){
        push(69);
        n++;
    }
    /**check full stack actions*/
    ck_assert(push(69) == 1);
}
END_TEST

Suite* str_suite (void) {
    Suite *suite = suite_create("Home assignment 1");
    TCase *tcase = tcase_create("case");
    tcase_add_test(tcase, test_stack);
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
