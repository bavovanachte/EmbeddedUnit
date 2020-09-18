#include <embUnit/embUnit.h>
#include "MockTestCase.h"

static void setUp(void)
{
}

static void tearDown(void)
{
}

static void testRepeatedOnce(void)
{
	RepeatedTest test = new_RepeatedTest(MockTestCase_case(),1);
	TestResult result = new_TestResult(NULL);

	test.isa->run(&test,&result);

	TEST_ASSERT_EQUAL_INT(1, result.runCount);
	TEST_ASSERT_EQUAL_INT(1, test.isa->countTestCases(&test));
}

static void testRepeatedMoreThanOnce(void)
{
	RepeatedTest test = new_RepeatedTest(MockTestCase_case(),100);
	TestResult result = new_TestResult(NULL);

	test.isa->run(&test,&result);


	TEST_ASSERT_EQUAL_INT(100, result.runCount);
	TEST_ASSERT_EQUAL_INT(100, test.isa->countTestCases(&test));
}

static void testRepeatedZero(void)
{
	RepeatedTest test = new_RepeatedTest(MockTestCase_case(),0);
	TestResult result = new_TestResult(NULL);

	test.isa->run(&test,&result);


	TEST_ASSERT_EQUAL_INT(0, result.runCount);
	TEST_ASSERT_EQUAL_INT(0, test.isa->countTestCases(&test));
}

void RepeatedTestTest_tests(void)
{
	EMB_UNIT_TESTFUNCTIONS(testfunction) {
		new_TestFunction("testRepeatedOnce",testRepeatedOnce),
		new_TestFunction("testRepeatedMoreThanOnce",testRepeatedMoreThanOnce),
		new_TestFunction("testRepeatedZero",testRepeatedZero),
	};
	EMB_UNIT_TESTFIXTURE(test,"RepeatedTestTest",setUp,tearDown,testfunction);
	EMB_UNIT_RUN(test);
}
