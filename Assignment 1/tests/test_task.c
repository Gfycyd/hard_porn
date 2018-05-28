//
// Created by cubazis on 25.05.18.
//

#include <check.h>
#include <math.h>
#include "task.h"


START_TEST (test_stub)
{
	ck_assert(42 == stub());
}
END_TEST

START_TEST (test_array_changer)
{
	const char input[] = "abcba";
	const char pattern[] = "abbba";

	/** change 'c' to 'b' */

	char* output = array_changer(input);

	/** initialise k because ck_assert need's it to be sure
	 *  that he compare something initialised with 1
	 *  because if COMPARATOR will not change it value, k will not have any value
	 *  */
	int k = 1;

	/** get k, k, output, pattern
	 *  compare output array with pattern array by elements
	 *  return 0 if they are not equal
	 * */
	COMPARATOR(k, output, pattern);

	/** check statement is true */
	ck_assert(1 == k);

}
END_TEST

/** YOUT TEST CASES HERE
 *
 *  please use 'test_fname' format for naming tcases
 *  fname is function name
 *
 *  if function name is 'detab' then test case is 'test_detab'
 * */

START_TEST (test_detab)
{
	const char input[] = "abc\tb\ta";
	const char pattern[] = "abc    b    a";

	/** change '\t' to '    ' */

	char* output = detab(input);

	/** initialise k because ck_assert need's it to be sure
	 *  that he compare something initialised with 1
	 *  because if COMPARATOR will not change it value, k will not have any value
	 *  */
	int k = 1;

	/** get k, k, output, pattern
	 *  compare output array with pattern array by elements
	 *  return 0 if they are not equal
	 * */
	COMPARATOR(k, output, pattern);

	/** check statement is true */
	ck_assert(1 == k);
}
END_TEST

START_TEST (test_entab)
		{
			const char input[] = "abc      b\ta   t         ";
			const char pattern[] = "abc\t  b\ta   t\t\t ";

			/** change '    ' to '\t' */

			char* output = entab(input);

			/** initialise k because ck_assert need's it to be sure
             *  that he compare something initialised with 1
             *  because if COMPARATOR will not change it value, k will not have any value
             *  */
			int k = 1;

			/** get k, k, output, pattern
             *  compare output array with pattern array by elements
             *  return 0 if they are not equal
             * */
			COMPARATOR(k, output, pattern);

			/** check statement is true */
			ck_assert(1 == k);
}
END_TEST

START_TEST (test_enter)
	{
		int n = 5;
		const char input[] = "adgfghdhdggfhdh";
		const char pattern[] = "adgfg\nhdhdg\ngfhdh";

		/** insert \n to fit limit of n */

		char* output = enter(n, input);

		/** initialise k because ck_assert need's it to be sure
         *  that he compare something initialised with 1
         *  because if COMPARATOR will not change it value, k will not have any value
         *  */
		int k = 1;

		/** get k, k, output, pattern
         *  compare output array with pattern array by elements
         *  return 0 if they are not equal
         * */
		COMPARATOR(k, output, pattern);

		/** check statement is true */

		ck_assert(1 == k);
}
END_TEST

START_TEST (test_flush)
{

}
END_TEST

START_TEST (test_htoi)
{
	const char input[] = "0xAb1";
	int  pattern = 2737;

	/** insert \n to fit limit of n */

	int output = htoi(input);

	/** check statement is true */

	ck_assert(output == pattern);
}
END_TEST

START_TEST (test_squeeze)
{

}
END_TEST

START_TEST (test_any)
{

}
END_TEST

START_TEST (test_setbits)
{

}
END_TEST

START_TEST (test_binsearch)
{

}
END_TEST

START_TEST (test_escape)
{

}
END_TEST

START_TEST (test_expand)
{

}
END_TEST

START_TEST (test_itoa)
{
 int i;
    //test_one_three();
    int n = -400;
    int w = 10;
    char s [10000];
    itoa(n,s,w);
    char t [] = "      -400";
    i = 0;
    int v = 1;
   while (s[i] != '\0') {
       if (t[i] != s[i]) {
           v = 0;
       }
       ++i;
   }
     n = -4;
     w = 3;
     char s2 [10000];
    itoa(n,s2,w);
    char t2 [] = " -4";
    i = 0;
    while (s2[i] != '\0') {
        if (t2[i] != s2[i]) {
            v = 0;
        }
        ++i;
    }
    n = 100;
    w = 2;
    char s3 [10000];
    itoa(n,s3,w);
    char t3 [] = "100";
    i = 0;
    while (s3[i] != '\0') {
        if (t3[i] != s3[i]) {
            v = 0;
        }
        ++i;
    }
	ck_assert(v == 1);
}
END_TEST

START_TEST (test_itob)
{

}
END_TEST

START_TEST (test_strrindex)
{
	const char s[] = "aaabbabba";
	const char t[] = "abba";
	int  pattern = 5;

	/** insert \n to fit limit of n */

	int output = strrindex(s,t);

	/** check statement is true */

	ck_assert(output == pattern);
}
END_TEST

START_TEST (test_atofe)
{
	const char input1[] = "12.11";
	double  pattern = 12.11;
	/** insert \n to fit limit of n */
	double output = atofe(input1);
	/** check statement is true */

	ck_assert(fabs(output - pattern)<0.00001);

	const char input2[] = "12.11e-2";
	pattern = 0.1211;
	/** insert \n to fit limit of n */
	output = atofe(input2);
	/** check statement is true */
	ck_assert(fabs(output - pattern)<0.00001);
}
END_TEST



Suite* str_suite (void) {
	Suite *suite = suite_create("Home assignment 1");
	TCase *tcase = tcase_create("case");

	tcase_add_test(tcase, test_stub);
	tcase_add_test(tcase, test_array_changer);

	tcase_add_test(tcase, test_detab);
	tcase_add_test(tcase, test_entab);
	tcase_add_test(tcase, test_enter);
	tcase_add_test(tcase, test_flush);
	tcase_add_test(tcase, test_htoi);
	tcase_add_test(tcase, test_squeeze);
	tcase_add_test(tcase, test_any);
	tcase_add_test(tcase, test_setbits);
	tcase_add_test(tcase, test_binsearch);
	tcase_add_test(tcase, test_escape);
	tcase_add_test(tcase, test_expand);
	tcase_add_test(tcase, test_itoa);
	tcase_add_test(tcase, test_itob);
	tcase_add_test(tcase, test_strrindex);
	tcase_add_test(tcase, test_atofe);
	/** YOUT TEST CASES HERE */

	suite_add_tcase(suite, tcase);
	return suite;
}

int main (int argc, char *argv[]) {
	int number_failed;
	Suite *suite = str_suite();
	SRunner *runner = srunner_create(suite);
	srunner_run_all(runner, CK_NORMAL);
	number_failed = srunner_ntests_failed(runner);
	srunner_free(runner);
	return number_failed;
}
