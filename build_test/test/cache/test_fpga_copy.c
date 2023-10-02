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



void tearDown(void){}







void test_vaccel_arraycopy_null(void)

{

    int input_array[] = {1, 2, 3, 4, 5};

    int output_array[] = {1, 2, 6, 4, 5};

    size_t len_input_array = sizeof(input_array) / sizeof(input_array[0]);



    UnityAssertEqualNumber((UNITY_INT)((vaccel_fpga_arraycopy(

   ((void *)0)

   , input_array, output_array, len_input_array))), (UNITY_INT)((

   22

   )), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);

}



void test_vaccel_arraycopy_valid(void)

{

    int ret;

    struct vaccel_session sess;

    int input_array[] = {1, 2, 3, 4, 5};

    int output_array[] = {1, 2, 6, 4, 5};

    size_t len_input_array = sizeof(input_array) / sizeof(input_array[0]);



    ret = vaccel_sess_init(&sess, 0);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_INT);



    ret = vaccel_fpga_arraycopy(&sess, input_array, output_array, len_input_array);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vaccel_sess_free(&sess))), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);

    do {if (((

   95

   ) != (ret))) {} else {UnityFail( ((" Expected Not-Equal")), (UNITY_UINT)((UNITY_UINT)(49)));}} while(0);



    UnityAssertEqualIntArray(( const void*)((input_array)), ( const void*)((output_array)), (UNITY_UINT32)((len_input_array)), (

   ((void *)0)

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_INT, UNITY_ARRAY_TO_ARRAY);



}
