#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <CUnit/CUnit.h>
#include <CUnit/Automated.h>

extern int dosum(int x, int y);
void AddTests(void);

void testIQJ()
{
        CU_ASSERT_EQUAL(dosum(1,-1),0);
        CU_ASSERT_EQUAL(dosum(0,-0),0);
}

void testborders()
{
        CU_ASSERT_EQUAL(dosum(65535,1),65536);
        CU_ASSERT_EQUAL(dosum(-60000,-100000),-70000);
        CU_ASSERT_EQUAL(dosum(1,-2),0);
}

CU_TestInfo testcases[] = {
        {"Testing x + y:", testIQJ},
        {"Testing x + y on borders:", testborders},
CU_TEST_INFO_NULL
};

int suite_success_init(void) { return 0; }
int suite_success_clean(void) { return 0; }


CU_SuiteInfo suites[] = {
        {"Testing the function dosum:", suite_success_init, suite_success_clean, NULL, NULL, testcases},
        {"Testing the function dosum again:",suite_success_init, suite_success_clean, NULL, NULL, testcases},
CU_SUITE_INFO_NULL
};
/**//*---- setting enviroment -----------*/
void AddTests(void)
{
        assert(NULL != CU_get_registry());
        assert(!CU_is_test_running());
        /**//* shortcut regitry */

        if(CUE_SUCCESS != CU_register_suites(suites)){
                fprintf(stderr, "Register suites failed - %s ", CU_get_error_msg());
                exit(1);
        }
}