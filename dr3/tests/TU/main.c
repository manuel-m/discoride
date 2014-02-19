/* 
 * File:   test_lib.c
 * Author: jam
 *
 * Created on 23 mars 2013, 14:22
 */

#include <stdio.h>
#include <stdlib.h>

#include "CUnit/Basic.h" 

#include "tests.h"



int main(int argc, char** argv) {
    (void) argc;
    (void) argv;

    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* add a suite to the registry */
    pSuite = CU_add_suite("drUi", NULL, NULL);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add the tests to the suite */
    if (NULL == CU_add_test(pSuite, "TEST_drUi_load", TEST_drUi_load)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();


    return (EXIT_SUCCESS);
}

