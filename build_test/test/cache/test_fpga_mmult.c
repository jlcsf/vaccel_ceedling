#include "src/session.h"
#include "src/include/ops/noop.h"
#include "src/include/ops/fpga.h"
#include "src/error.h"
#include "/opt/hostedtoolcache/Ruby/3.0.5/x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




static int fini(void)

{

    return 0;

}



static int init(void)

{

    return 0;

}



void setUp(void){}



void tearDown(void){}







void test_vaccel_mmult_null(void)

{

    float a[] = {1.2, 3.2, 3.0, 4.1, 5.7};

    float b[] = {1.1, 0.2, 6.1, 4.6, 5.2};

    size_t len_a = sizeof(a) / sizeof(a);

    float c[] = {0.1,0.1,0.1,0.1,0.1};



    UnityAssertEqualNumber((UNITY_INT)((vaccel_fpga_mmult(

   ((void *)0)

   , a, b, c, len_a))), (UNITY_INT)((

   22

   )), (

   ((void *)0)

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);

}



void test_vaccel_mmult_valid(void)

{

    int ret;

    struct vaccel_session sess;



    float a[] = {1.2, 3.2, 3.0, 4.1, 5.7};

    float b[] = {1.1, 0.2, 6.1, 4.6, 5.2};

    size_t len_a = sizeof(a) / sizeof(a);

    float c[] = {0.1,0.1,0.1,0.1,0.1};



    ret = vaccel_sess_init(&sess, 0);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);



    ret = vaccel_fpga_mmult(&sess, a, b, c, len_a);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vaccel_sess_free(&sess))), (

   ((void *)0)

   ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);

    do {if (((

   95

   ) != (ret))) {} else {UnityFail( ((" Expected Not-Equal")), (UNITY_UINT)((UNITY_UINT)(51)));}} while(0);



    float expected_c[] = {9.1, 9.1, 9.1, 9.1, 9.1};



    UnityAssertEqualFloatArray((UNITY_FLOAT*)((expected_c)), (UNITY_FLOAT*)((c)), (UNITY_UINT32)((len_a)), (

   ((void *)0)

   ), (UNITY_UINT)(55), UNITY_ARRAY_TO_ARRAY);



}
