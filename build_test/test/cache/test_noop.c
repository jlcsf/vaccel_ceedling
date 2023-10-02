#include "src/session.h"
#include "src/include/ops/noop.h"
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



void test_plugin_true(void)

{

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((0)), (

   ((void *)0)

   ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);

}





void test_vaccel_noop_null(void)

{

    UnityAssertEqualNumber((UNITY_INT)((vaccel_noop(

   ((void *)0)

   ))), (UNITY_INT)((

   22

   )), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

}



void test_vaccel_noop_valid(void)

{

    int ret;

    struct vaccel_session sess;



    ret = vaccel_sess_init(&sess, 0);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_INT);



    ret = vaccel_noop(&sess);



    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vaccel_sess_free(&sess))), (

   ((void *)0)

   ), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_INT);

    do {if (((

   95

   ) != (ret))) {} else {UnityFail( ((" Expected Not-Equal")), (UNITY_UINT)((UNITY_UINT)(45)));}} while(0);







}
