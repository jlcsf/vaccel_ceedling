#include "src/session.h"
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





void setUp(void) {}





void tearDown(void) {}





void test_true_values(void)

{

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((1)), (

   ((void *)0)

   ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_INT);

}





void test_session_init_no_sess(void)

{

    UnityAssertEqualNumber((UNITY_INT)((vaccel_sess_init(

   ((void *)0)

   ,0))), (UNITY_INT)((

   22

   )), (

   ((void *)0)

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);

}





void test_session_init(void)

{

    static struct vaccel_session session;

    UnityAssertEqualNumber((UNITY_INT)((vaccel_sess_init(&session,0))), (UNITY_INT)((0)), (

   ((void *)0)

   ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);

}





void test_sess_update(void)

{

    static struct vaccel_session session;

    vaccel_sess_update(&session, 1);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((session.hint)), (

   ((void *)0)

   ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);

}





void test_sessions_boostrap(void)

{

    static struct vaccel_session session;

    int ret = sessions_bootstrap();

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_INT);

}
