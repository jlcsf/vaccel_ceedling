#include "unity.h"
#include "misc.h"

struct vaccel_session test_sess;
enum vaccel_op_type test_op;


void test_vaccel_get_plugins(void) {
    // get_available_plugins_IgnoreAndReturn(VACCEL_OK);
    int result;
    result = vaccel_get_plugins(&test_sess, test_op);
    TEST_ASSERT_EQUAL(VACCEL_OK, result);
}

void test_vaccel_get_plugins_null(void) {
    enum vaccel_op_type test_op;
    // get_available_plugins_IgnoreAndReturn(VACCEL_OK);
    int result = vaccel_get_plugins(NULL, test_op);
    TEST_ASSERT_EQUAL(VACCEL_EINVAL, result);
}