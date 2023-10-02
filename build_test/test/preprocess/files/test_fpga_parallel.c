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

    float add_out[len_a];

    float mult_out[len_a];



    UnityAssertEqualNumber((UNITY_INT)((vaccel_fpga_parallel(

   ((void *)0)

   , a, b, add_out, mult_out, len_a))), (UNITY_INT)((

   22

   )), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);

}



void test_vaccel_mmult_valid(void)

{

    int ret;

    struct vaccel_session sess;



    float a[] = {1.2, 3.2, 3.0, 4.1, 5.7};

    float b[] = {1.1, 0.2, 6.1, 4.6, 5.2};

    size_t len_a = sizeof(a) / sizeof(a);

    float add_out[len_a];

    float mult_out[len_a];



    ret = vaccel_sess_init(&sess, 0);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);



    ret = vaccel_fpga_parallel(&sess, a, b, add_out, mult_out, len_a);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vaccel_sess_free(&sess))), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);

    do {if (((

   95

   ) != (ret))) {} else {UnityFail( ((" Expected Not-Equal")), (UNITY_UINT)((UNITY_UINT)(53)));}} while(0);



    float expected_add_out[] = {9,1, 9.1, 9.1, 9.1, 9.1};

    float expected_mult_out[] = {18.2, 18.2, 18.2, 18.2, 18.2};



    UnityAssertEqualFloatArray((UNITY_FLOAT*)((expected_add_out)), (UNITY_FLOAT*)((expected_add_out)), (UNITY_UINT32)((len_a)), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_ARRAY_TO_ARRAY);

    UnityAssertEqualFloatArray((UNITY_FLOAT*)((expected_mult_out)), (UNITY_FLOAT*)((expected_mult_out)), (UNITY_UINT32)((len_a)), (

   ((void *)0)

   ), (UNITY_UINT)(59), UNITY_ARRAY_TO_ARRAY);



}
