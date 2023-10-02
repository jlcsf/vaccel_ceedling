#include "src/id_pool.h"
#include "src/utils.h"
#include "src/log.h"
#include "src/plugin.h"
#include "src/session.h"
#include "/home/jl/.rvm/gems/ruby-3.0.5/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




struct vaccel_session test_sess = {0};



extern struct {



 

_Bool 

     initialized;





 id_pool_t ids;





 struct vaccel_session *running_sessions[1024];

} sessions;





static void mock_sessions_bootstrap(void)

{

    sessions.initialized = 

                          1

                              ;

}



static void mock_sessions_cleanup(void)

{

    sessions.initialized = 

                          0

                               ;

}

void test_vaccel_sess_register_null(void)

{

    int ret = vaccel_sess_register(

                                  ((void *)0)

                                      , 

                                        ((void *)0)

                                            );

    UnityAssertEqualNumber((UNITY_INT)((

   22

   )), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_INT);

}



void test_vaccel_sess_init(void)

{

    int ret = vaccel_sess_init(&test_sess, 0);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);

}



void test_vaccel_sess_init_null(void)

{

    int ret = vaccel_sess_init(

                              ((void *)0)

                                  , 0);

    UnityAssertEqualNumber((UNITY_INT)((

   22

   )), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_INT);

}



void test_vaccel_sess_init_not_init(void)

{

    mock_sessions_cleanup();

    int ret = vaccel_sess_init(&test_sess, 0);

    UnityAssertEqualNumber((UNITY_INT)((

   104

   )), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_INT);

    mock_sessions_bootstrap();

}



void test_vaccel_sess_update(void)

{

    int ret = vaccel_sess_update(&test_sess, 0);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT);

}



void test_vaccel_sess_update_null(void)

{

    int ret = vaccel_sess_update(

                                ((void *)0)

                                    , 0);

    UnityAssertEqualNumber((UNITY_INT)((

   22

   )), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);

}



void test_vaccel_sess_update_not_init(void)

{

    mock_sessions_cleanup();

    int ret = vaccel_sess_update(&test_sess, 0);

    UnityAssertEqualNumber((UNITY_INT)((

   104

   )), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_INT);

    mock_sessions_bootstrap();

}



void test_vaccel_free_null(void)

{

    int ret = vaccel_sess_free(

                              ((void *)0)

                                  );

    UnityAssertEqualNumber((UNITY_INT)((

   22

   )), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_INT);

}



void test_vaccel_free_not_init(void)

{

    mock_sessions_cleanup();

    int ret = vaccel_sess_free(&test_sess);

    UnityAssertEqualNumber((UNITY_INT)((

   104

   )), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(110), UNITY_DISPLAY_STYLE_INT);

    mock_sessions_bootstrap();

}





void test_vaccel_free(void)

{

    int ret = vaccel_sess_free(&test_sess);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ret)), (

   ((void *)0)

   ), (UNITY_UINT)(118), UNITY_DISPLAY_STYLE_INT);

}
