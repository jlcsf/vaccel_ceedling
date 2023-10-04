#include "unity.h"
#include "id_pool.h"
#include "error.h"
#include <stdlib.h>



void setUp(void){}
void tearDown(void){}



void test_id_pool_new_no_ids(void)
{
    id_pool_t test_pool;
    int ret;

    
    ret = id_pool_new(&test_pool, 0);
    TEST_ASSERT_EQUAL(VACCEL_EINVAL, ret);

}

void test_id_pool_new_ok(void)
{
    id_pool_t test_pool;
    int ret;
    
    ret = id_pool_new(&test_pool, 5);
    TEST_ASSERT_EQUAL(VACCEL_OK, ret);

}

void test_id_pool_destroy_no_pool(void)
{
    int ret;

    ret = id_pool_destroy(NULL);
    TEST_ASSERT_EQUAL(VACCEL_EINVAL, ret);
}

void test_id_pool_destroy_ok(void)
{
    int ret;
    id_pool_t test_pool;
    id_pool_new(&test_pool, 1);

    ret = id_pool_destroy(&test_pool);

    TEST_ASSERT_EQUAL(VACCEL_OK, ret);

}

void test_id_pool_get(void)
{
    int ret;
    id_pool_t test_pool;
    id_pool_new(&test_pool, 2);
    ret = id_pool_get(&test_pool);
    TEST_ASSERT_EQUAL(1, ret);
    ret = id_pool_get(&test_pool);
    TEST_ASSERT_EQUAL(2, ret);

    /// loop it perhaps... ptr outside of id case now.
    ret = id_pool_get(&test_pool);
    TEST_ASSERT_EQUAL(0, ret);
}

void test_id_pool_release(void)
{
    int ret;
    int id = 3;
    id_pool_t test_pool;
    id_pool_new(&test_pool, 10);

    id_pool_release(&test_pool, id);

    TEST_ASSERT_EQUAL(3, id);
    /// I assume pointer hasn't moved?
    TEST_ASSERT_EQUAL(id, id_pool_get(&test_pool));
}