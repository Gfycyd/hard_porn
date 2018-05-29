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
        /** change '\t' to '    ' */

        const char input1[] = "\t";
        const char pattern1[] = "    ";
        char* output = detab(input1);
        int k = 1;
        COMPARATOR(k, output, pattern1);
        /** check statement is true */
        ck_assert(1 == k);

        const char input2[] = "\tc\t";
        const char pattern2[] = "    c    ";
        char* output2 = detab(input2);
        k = 1;
        COMPARATOR(k, output2, pattern2);
        /** check statement is true */
        ck_assert(1 == k);

        const char input3[] = "\tddddfffd\t\tc\t";
        const char pattern3[] = "    ddddfffd        c    ";
        char* output3 = detab(input3);
        k = 1;
        COMPARATOR(k, output3, pattern3);
        /** check statement is true */
        ck_assert(1 == k);
    }
END_TEST

START_TEST (test_entab)
    {   /** change '    ' to '\t' */
        const char input[] = "    abc      b\ta   t         ";
        const char pattern[] = "\tabc\t  b\ta   t\t\t ";
        char* output = entab(input);
        int k = 1;
        COMPARATOR(k, output, pattern);
        ck_assert(1 == k);
    }
END_TEST

START_TEST (test_enter)
    {
        int n = 5;
        const char input1[] = "adgfghdhdggfhdh";
        const char pattern1[] = "adgfg\nhdhdg\ngfhdh";
        char* output1 = enter(n, input1);
        int k = 1;
        COMPARATOR(k, output1, pattern1);
        ck_assert(1 == k);

        n = 7;
        const char input2[] = "adgfghdhdggfhdh";
        const char pattern2[] = "adgfghd\nhdggfhd\nh";
        char* output2 = enter(n, input2);
        k = 1;
        COMPARATOR(k, output2, pattern2);
        ck_assert(1 == k);

    }
END_TEST

START_TEST (test_flush)
{
	  int v;
    v = 1;
    int s = 1;
    char s1 [] = "\"f\\df//dfsdf\"";
    char t1 [] =  "\"f\\df//dfsdf\"";
    COMPARATOR(v,flush(s1),t1);
    //printf("%d", v);
    ck_assert( 1 == v );
    char s2 [] = "fdfd//fdfd\nffdf";
    char t2 [] = "fdfd\nffdf";
    COMPARATOR(v,flush(s2),t2);
    v = 1;
    //printf("%d",v);
    ck_assert( 1 == v );
    char s3 [] = "Katya//121212";
    char t3 [] = "Katya";
    v = 1;
    COMPARATOR(v,flush(s3),t3);
    ck_assert( 1 == v );
    //printf("%d",v);
}
END_TEST


START_TEST (test_htoi)
    {
        /** insert \n to fit limit of n */
        const char input1[] = "0xAb1";
        int  pattern = 2737;
        int output = htoi(input1);
        ck_assert(output == pattern);

        const char input2[] = "0xAb1r";
        pattern = -1;
        output = htoi(input2);
        ck_assert(output == pattern);

    }
END_TEST


START_TEST (test_squeeze)
    {
        /** тест с большими строчками, строчка-удалитель больше исходной */
        const char s1[] = "v otvetax ya ograni4en";
        const char s2[] = "a vot eto pravilnii vopros";
        char* pattern = "xyg4";
        int k = 1;
        char* output = squeeze(s1,s2);
        COMPARATOR(k,output,pattern);
        ck_assert(k==1);
/** Большие и маленькие буквы с цифрами*/
        const char name1[] = "NiKita3";
        const char remover1[] = "Rinat3";
        pattern = "NK";
        output = squeeze(name1, remover1);
        COMPARATOR(k,output,pattern);
        ck_assert(k==1);
/** Попробуем удалить пустой символ */
        const char name2[] = "Kate";
        const char remover2[] = "";
        pattern = "Kate";
        output = squeeze(name2, remover2);
        COMPARATOR(k, output, pattern);
        ck_assert(k==1);
/** Исходная строка пустая */
        char name3[] = "";
        char remover3[] = "Evgeniia";
        pattern = "";
        output = squeeze(name3, remover3);
        COMPARATOR(k, output, pattern);
        ck_assert(k==1);
    }
END_TEST

START_TEST (test_any)
    {
        const char s1[] = "asd";
        const char s2[] = "";

        int output = any(s1,s2);
        int pattern = -1;

        ck_assert(output==pattern);



        const char s3[] = "asd";
        const char s4[] = "dsa";

        output = any(s3,s4);
        pattern = 0;

        ck_assert(output==pattern);



        const char s5[] = "asd";
        const char s6[] = "d";

        output = any(s5,s6);
        pattern = 2;

        ck_assert(output==pattern);
    }
END_TEST

START_TEST (test_setbits)
    {
        unsigned x = 31;
        int p = 3;
        int n = 2;
        unsigned y = 1;

        const unsigned pattern = 27;
        const unsigned output = setbits(x,p,n,y);

        ck_assert(pattern==output);



        x = 63;
        p = 3;
        n = 2;
        y = 1;

        const unsigned pattern1 = 59;
        const unsigned output1 = setbits(x,p,n,y);

        ck_assert(pattern1==output1);


        x = 256;
        p = 4;
        n = 3;
        y = 7;

        const unsigned pattern2 = 270;
        const unsigned output2 = setbits(x,p,n,y);

        ck_assert(pattern2==output2);

    }
END_TEST

START_TEST (test_binsearch)
{int x = 7;
    int n = 5;
    int v [] = {1,4,5,6,7};
    int  k = binsearch(x,v,n);
    ck_assert( k == 4);

    x = 7;
    n = 4;
    int v3 [] = {0,40,60,70};
    k = binsearch(x,v3,n);
    ck_assert(-1 == k) ;

    x = 6;
    n = 10;
    int v4 [] = {0,1,2,3,4,5,6,6,6,6,9};
    k = binsearch(x,v4,n);

    ck_assert(7 == k) ;
}
END_TEST

START_TEST (test_escape)
{int i = 0;
    int v = 0;
    int s = 1;
    char t [100000];
    char s1 [] = "hey guys, y menya         vse";
    char t1 [] = "hey guys, y menya         vse";
    escape(s1,t);
    v = 1;
    COMPARATOR(v,t,t1);
    //printf("%d",v);
    ck_assert( 1 == v );
    char s2 [] = " ";
    char t2 [] = " ";
    escape(s2,t);
    v = 1;
    COMPARATOR(v,t,t2);
    //printf("%d",v);
    ck_assert( 1 == v );
    char s3 [] = "\ndetka\nti lubish\nrvanie jeans";
    escape(s3,t);
    char t3 [] = "\\ndetka\\nti lubish\\nrvanie jeans";
    v = 1;
    COMPARATOR(v,t,t3);
    //printf("%d",v);
    ck_assert( 1 == v );


    char s4 [] = "\tkek\tlol\nlekarstvo";
    char t4 [] = "\\tkek\\tlol\\nlekarstvo";
    escape(s4,t);
    v = 1;
    COMPARATOR(v,t,t4);
    //printf("%d",v);
    ck_assert( 1 == v );

    char s5 [] = "\\n";
    char t5 [] = "\\n";
    escape(s5,t);
    v = 1;
    COMPARATOR(v,t,t5);
    //printf("%d",v);
    ck_assert( 1 == v );
}
END_TEST

START_TEST (test_expand)
{
	  char a1 [] = "f-w";
    char s1 [] = "fghijklmnopqrstuvw";
    int v = 1;
    COMPARATOR(v,expand(a1),s1);
    printf("%d",v);
    //ck_assert( 1 == v );
    char a2 [] = "1-17";
    char s2 [] = "17";
    expand(a2);
    v = 1;
    COMPARATOR(v,expand(a2),s2);
    printf("%d",v);
    //ck_assert( 1 == v );
    char a3 [] = "a-b-c";
    char s3 [] = "abc";
    expand(a3);
    v = 1;
    COMPARATOR(v,expand(s3),s3);
    printf("%d",v);
    //ck_assert( 1 == v );

    char a4 [] = "-a-b-c9-0-3b-s-";
    char s4 [] = "abc90123bcdefghijklmnopqrs";
    expand(a4);
    v = 1;
    COMPARATOR(v,expand(s4),s4);
    printf("%d",v);
    //ck_assert( 1 == v );

    char a5 [] = "a-A-C8-9";
    char s5 [] = "aABC89";
    expand(a5);
    v = 1;
    COMPARATOR(v,expand(s5),s5);
    printf("%d",v);
    //ck_assert( 1 == v );
    return 0;
}
END_TEST

START_TEST (test_itoa)
{
    int n = -400;
    int w = 10;
    char s [10000];
    itoa(n,s,w);
    char t [] = "      -400";
    int v = 1;
    COMPARATOR(v,s,t);
    ck_assert( 1 == v );
     n = -4;
     w = 3;
     char s2 [10000];
    itoa(n,s2,w);
    char t2 [] = " -4";
	v = 1;
    COMPARATOR(v,s2,t2);
    ck_assert( 1 == v );
    n = 100;
    w = 2;
    char s3 [10000];
    itoa(n,s3,w);
    char t3 [] = "100";
	v = 1;
    COMPARATOR(v,s3,t3);
    ck_assert( 1 == v );
	ck_assert(v == 1);
}
END_TEST

START_TEST (test_itob)
{
	int n;
    char v[10000];
    int b;
    n = -10;
    b = 16;
    itob(n,v,b);
    int i = 0;
    char t [] = "-a";
    int s = 1;
    while (v[i] != '\0') {
        if (t[i] != v[i]) {
            s = 0;
        }
        ++i;
    }
    n = 100;
    b = 16;
    itob(n,v,b);
    char t2 [] = "64";
     i = 0;
    while (v[i] != '\0') {
        if (t2[i] != v[i]) {
            s = 0;
        }
        ++i;
    }
    n = 170;
    b = 9;
    itob(n,v,b);
    char t3 [] = "208";
    i = 0;
    while (v[i] != '\0') {
        if (t3[i] != v[i]) {
            s = 0;
        }
        ++i;
    }
    n = 0;
    b = 16;
    itob(n,v,b);
    char t4 [] = "0";
    i = 0;
    while (v[i] != '\0') {
        if (t4[i] != v[i]) {
            s = 0;
        }
        ++i;
    }
    n = 14;
    b = 2;
    itob(n,v,b);
    char t5 [] = "1110";
    i = 0;
    while (v[i] != '\0') {
        if (t5[i] != v[i]) {
            s = 0;
        }
        ++i;
    }
	ck_assert(1 == s);
	
}
END_TEST

START_TEST (test_strrindex)
{
	const char s[] = "aaabbabba";
	const char t[] = "abba";
	int  pattern = 5;
	int output = strrindex(s,t);
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
