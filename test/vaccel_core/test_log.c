#include "unity.h"
#include "log.h"
#include "error.h"

void test_vaccel_log_init(void) 
{
    int ret = vaccel_log_init();
    TEST_ASSERT_EQUAL(VACCEL_OK, ret);
}

void test_vaccel_log_shutdown(void)
{   
    vaccel_log_init();
    int ret = vaccel_log_shutdown();
    TEST_ASSERT_EQUAL(VACCEL_OK, ret );
}

/// set_log_file 
/// set_debug_level