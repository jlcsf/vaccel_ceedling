#include "src/session.h"
#include "src/include/ops/noop.h"
#include "src/include/ops/fpga.h"
#include "src/error.h"
#include "/home/jl/.rvm/gems/ruby-3.0.5/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


static int fini(void)

{

    return 0;

}



static int init(void)

{

    return 0;

}





void setUp(void){}



void tearDown(void)

{

}



void test_vaccel_arraycopy_null(void)

{

    float A[] = {1, 2, 3, 4, 5};

    float B[] = {1, 2, 6, 4, 5};

    float C[] = {1, 2, 6, 4, 5};

    size_t len_A = sizeof(A) / sizeof(A[0]);

    size_t len_B = sizeof(B) / sizeof(B[0]);



    UnityAssertEqualNumber((UNITY_INT)((vaccel_fpga_vadd(

   ((void *)0)

   , A, B, C, len_A, len_B))), (UNITY_INT)((

   22

   )), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);

}



void test_vaccel_vadd_valid(void)

{

    int ret;

    struct vaccel_session sess;

    float A[] = {1, 2, 3, 4, 5};

    float B[] = {1, 2, 6, 4, 5};









    size_t len_A = sizeof(A) / sizeof(A[0]);

    size_t len_B = sizeof(B) / sizeof(B[0]);





    float C[len_A];



    ret = vaccel_sess_init(&sess, 0);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);

    ret = vaccel_fpga_vadd(&sess, A, B, C, len_A, len_B);



    float C_expected[] = {2,4,9,8,10};

    size_t len_C = sizeof(C) / sizeof(C[0]);

    size_t len_C_expected = sizeof(C_expected) / sizeof(C_expected[0]);





    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vaccel_sess_free(&sess))), (

   ((void *)0)

   ), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_INT);

    do {if (((

   95

   ) != (ret))) {} else {UnityFail( ((" Expected Not-Equal")), (UNITY_UINT)((UNITY_UINT)(61)));}} while(0);





    UnityAssertEqualNumber((UNITY_INT)((len_C_expected)), (UNITY_INT)((len_C)), (

   ((void *)0)

   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualFloatArray((UNITY_FLOAT*)((C_expected)), (UNITY_FLOAT*)((C)), (UNITY_UINT32)((len_C_expected)), (

   ((void *)0)

   ), (UNITY_UINT)(65), UNITY_ARRAY_TO_ARRAY);

}







void test_vaccel_vadd_invalid_arguments(void) {



}
