Writing embUnit Tests
=====================

The following class diagram shows the architecture of EmbeddedUnit.

.. uml::

   @startuml

   abstract Test {
      # <b>TestImplement* isa</b>
   }
   class TestSuite {
      + <b>TestImplement* isa</b>
	   + char *name
	   + int numberOfTests
	   + Test* [] tests
   }
   class RepeatedTest {
      + <b>TestImplement* isa</b>
	   + Test* test;
	   + int timesRepeat;
   }
   class TestCaller {
      + <b>TestImplement* isa</b>
	   + char *name
	   + void(*setUp)(void)
	   + void(*tearDown)(void)
	   + int numberOfFixtures
	   + TestFixture [] fixtures
   }
   class TestCase {
      + <b>TestImplement* isa</b>
	   + char *name
	   + void(*setUp)(void)
	   + void(*tearDown)(void)
	   + void(*runTest)(void)
   }

   TestListener <|-- TestRunner
   TestRunner -- Test: +Runs
   Test - TestResult: Collects results
   Test <|-- TestSuite
   Test <|-- RepeatedTest
   Test <|-- TestCaller
   Test <|-- TestCase
   @enduml

----------------------------
Tests, Test Cases and Suites
----------------------------

Below is a program listing for unit tests of module counter.c. The full example can be found in /examples folder.

==========  =========
 Line no.    Comment
==========  =========
1           Include references for embUnit framework and unit under test.
6           setUp() and tearDown() functions for test case.
16          Unit test for checking the counter is initialized on construction.
32          Collect all the unit tests under fixtures with a string as name of test.
36          Create a new test case from setUp(), tearDown(), and fixtures.
38          Return with pointer to test suite just created.
==========  =========

.. code-block:: c
   :emphasize-lines: 1,6,16,32,36,38
   :linenos:

    #include <embUnit/embUnit.h>
    #include "counter.h"

    CounterRef counterRef;

    static void setUp(void)
    {
    	counterRef = Counter_counter();
    }

    static void tearDown(void)
    {
    	Counter_dealloc(counterRef);
    }

    static void testInit(void)
    {
    	TEST_ASSERT_EQUAL_INT(0, Counter_value(counterRef));
    }

    static void testSetValue(void)
    {
    	Counter_setValue(counterRef,1);
    	TEST_ASSERT_EQUAL_INT(1, Counter_value(counterRef));

    	Counter_setValue(counterRef,-1);
    	TEST_ASSERT_EQUAL_INT(-1, Counter_value(counterRef));
    }

    TestRef CounterTest_tests(void)
    {
      EMB_UNIT_TESTFUNCTIONS(fixtures) {
        new_TestFunction("testInit",testInit),
        new_TestFunction("testSetValue",testSetValue),
    	};

      EMB_UNIT_TESTFIXTURE(CounterTest,"CounterTest",setUp,tearDown,fixtures);
      return (TestRef)&CounterTest;
    }

-----------------
Running the Tests
-----------------

Below is a program listing for running the testcase via standard test runner. The full example can be found in /examples folder.


.. code-block:: c
   :linenos:

    #include <embUnit/embUnit.h>
    TestRef CounterTest_tests( TestCaller *test );

    int main (int argc, const char* argv[])
    {
        static TestCaller test;

        TestRunner_start();
        TestRunner_runTest(CounterTest_tests(&test));
        TestRunner_end();
        return 0;
    }

----------------------
Building and Executing
----------------------

Below is a makefile for automated build of counter.c tests. The full example can be found in /examples folder.

.. code-block:: make
    :linenos:

    CC = gcc
    CFLAGS = -O
    INCLUDES = ..
    LIBS = ../lib
    RM = rm
    TARGET = samples
    OBJS = AllTests.o counter.o counterTest.o

    all: $(TARGET)

    $(TARGET): $(OBJS)
        $(CC) -o $@ $(OBJS) -L$(LIBS) -lembUnit

    .c.o:
        $(CC) $(CFLAGS) -I$(INCLUDES) -c $<

    clean:
        -$(RM) $(TARGET) $(OBJS)

    .PHONY: clean all

Build your tests with make. Execute the created executable to run the tests.
The standard test runner gives you the results in following format (results are not from earlier example):

| ....
| shutterTest.testBuffer (shuttertest.c 168) exp 0 was 1
|
| run 4 failures 1
