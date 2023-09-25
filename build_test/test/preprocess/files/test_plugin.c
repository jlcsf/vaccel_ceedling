#include "third-party/slog/src/slog.h"
#include "src/include/list.h"
#include "src/include/error.h"
#include "src/plugin.h"
#include "/opt/hostedtoolcache/Ruby/3.0.5/x64/lib/ruby/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"








static const char *pname = "mock_plugin";

static struct vaccel_plugin plugin = {0};

static struct vaccel_plugin_info pinfo = {0};



static int fini(void)

{

    return 0;

}



static int init(void)

{

    return 0;

}





void setUp(void)

{

    plugin.info = &pinfo;

    pinfo.name = pname;

    list_init_entry(&plugin.entry);

    list_init_entry(&plugin.ops);

    pinfo.init = init;

    pinfo.fini = fini;



    plugins_bootstrap();

}







void tearDown(void)

{

    plugins_shutdown();

}



void test_plugin_null(void)

{

    UnityAssertEqualNumber((UNITY_INT)((register_plugin(

   ((void *)0)

   ))), (UNITY_INT)((

   22

   )), (

   ((void *)0)

   ), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);

}



void test_plugin_null_name(void)

{

    struct vaccel_plugin_info info = { 0 };

 struct vaccel_plugin plugin;

 plugin.info = &pinfo;



    plugin.entry.next = &(plugin.entry);

    plugin.entry.prev = &(plugin.entry);



    UnityAssertEqualNumber((UNITY_INT)((register_plugin(&plugin))), (UNITY_INT)((

   22

   )), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

}



void test_plugin_not_boostrapped(void)

{

    struct vaccel_plugin plugin = {};



    do {if (((register_plugin(&plugin)) != (

   71

   ))) {} else {UnityFail( ((" Expected Not-Equal")), (UNITY_UINT)((UNITY_UINT)(65)));}} while(0);

}



void test_plugin_init_values_all(void)

{

    UnityAssertEqualNumber((UNITY_INT)((register_plugin(&plugin))), (UNITY_INT)((0)), (

   ((void *)0)

   ), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((strcmp(plugin.info->name, "mock_plugin"))), (UNITY_INT)((0)), (

   ((void *)0)

   ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT);

    do {if ((list_empty(&plugin.ops))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(72)));}} while(0);



}



void test_plugin_exists(void)

{

    UnityAssertEqualNumber((UNITY_INT)((register_plugin(&plugin))), (UNITY_INT)((0)), (

   ((void *)0)

   ), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((register_plugin(&plugin))), (UNITY_INT)((

   17

   )), (

   ((void *)0)

   ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_INT);

}
