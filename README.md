In directory just run: 'ceedling test:all'

Ruby 3.0.5 with ceedling gem installed.


Throws up many more warnings this time.



```

Test 'test_a.c'
---------------
Generating runner for test_a.c...
Compiling test_a_runner.c...
Compiling test_a.c...
Compiling unity.c...
Compiling cmock.c...
Linking test_a.out...
Running test_a.out...


Test 'test_noop.c'
------------------
Generating runner for test_noop.c...
Compiling test_noop_runner.c...
Compiling test_noop.c...
test/test_noop.c: In function ‘test_vaccel_noop_valid’:
test/test_noop.c:47:41: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
   47 |     printf("Memory address of x: %p\n", (void *)ret);
      |                                         ^
Linking test_noop.out...
Running test_noop.out...


Test 'test_plugin.c'
--------------------
Generating runner for test_plugin.c...
Compiling test_plugin_runner.c...
Compiling test_plugin.c...
test/test_plugin.c: In function ‘setUp’:
test/test_plugin.c:169:5: warning: implicit declaration of function ‘plugins_bootstrap’ [-Wimplicit-function-declaration]
  169 |     plugins_bootstrap();
      |     ^~~~~~~~~~~~~~~~~
test/test_plugin.c: In function ‘tearDown’:
test/test_plugin.c:176:5: warning: implicit declaration of function ‘plugins_shutdown’ [-Wimplicit-function-declaration]
  176 |     plugins_shutdown();
      |     ^~~~~~~~~~~~~~~~
Linking test_plugin.out...
Running test_plugin.out...


Test 'test_session.c'
---------------------
Generating runner for test_session.c...
Compiling test_session_runner.c...
Compiling test_session.c...
test/test_session.c: In function ‘test_sessions_boostrap’:
test/test_session.c:56:15: warning: implicit declaration of function ‘sessions_bootstrap’; did you mean ‘test_sessions_boostrap’? [-Wimplicit-function-declaration]
   56 |     int ret = sessions_bootstrap();
      |               ^~~~~~~~~~~~~~~~~~
      |               test_sessions_boostrap
Linking test_session.out...
Running test_session.out...

-----------
TEST OUTPUT
-----------
[test_a.c]
  - "Running a()"

[test_noop.c]
  - "Memory address of x: 0x5f"

--------------------
OVERALL TEST SUMMARY
--------------------
TESTED:  14
PASSED:  14
FAILED:   0
IGNORED:  0
```
