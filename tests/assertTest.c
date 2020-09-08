#include <embUnit/embUnit.h>

// TEST_ASSERT_EQUAL_MEMORY(expected,actual,size)
// TEST_ASSERT_EQUAL_UINT(expected,actual)
// TEST_ASSERT_EQUAL_HEX(expected,actual)
// TEST_ASSERT_EQUAL_PTR(expected,actual)
// TEST_ASSERT_EQUAL_INT_WITH_MARGIN(expected,actual,margin)
// TEST_ASSERT_EQUAL_WITH_MARGIN(expected,actual,margin)
// TEST_ASSERT_EQUAL_UINT_WITH_MARGIN(expected,actual,margin)
// TEST_ASSERT_NOT_LOWER_THAN_INT(min, actual)
// TEST_ASSERT_NOT_HIGHER_THAN_INT(max, actual)
// TEST_ASSERT_RANGE_INT(min, max, actual)
// TEST_ASSERT_NOT_LOWER_THAN_UINT(min, actual)
// TEST_ASSERT_NOT_HIGHER_THAN_UINT(max, actual)
// TEST_ASSERT_RANGE_UINT(min, max, actual)

static void setUp(void)
{
}

static void tearDown(void)
{
}

static void verify_failure(TestCaseRef test)
{
	TestResult result = new_TestResult(NULL);

	test->isa->run(test,&result);

	if (result.failureCount == 0) {
		TEST_FAIL("fail");
	}
}

static void verify_success(TestCaseRef test)
{
	TestResult result = new_TestResult(NULL);

	test->isa->run(test,&result);

	if (result.failureCount > 0) {
		TEST_FAIL("fail");
	}
}

static void assert_equal_string_runTest_fail(void)
{
	TEST_ASSERT_EQUAL_STRING("123","456");
}

static void assert_equal_string_runTest_success(void)
{
	volatile char* string1 = "123";
	volatile char* string2 = "123";
	TEST_ASSERT_EQUAL_STRING(string1, string1);
}

static void testASSERT_EQUAL_STRING(void)
{
	TestCase tcase_fail = new_TestCase("assert_equal_string",NULL,NULL,assert_equal_string_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert_equal_string",NULL,NULL,assert_equal_string_runTest_success);
	verify_success(&tcase_success);
}

static void assert_equal_int_runTest_fail(void)
{
	TEST_ASSERT_EQUAL_INT(123,456);
}

static void assert_equal_int_runTest_success(void)
{
	volatile int int1 = 123;
	volatile int int2 = 123;
	TEST_ASSERT_EQUAL_INT(int1, int2);
}

static void testASSERT_EQUAL_INT(void)
{
	TestCase tcase_fail = new_TestCase("assert_equal_int",NULL,NULL,assert_equal_int_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert_equal_int",NULL,NULL,assert_equal_int_runTest_success);
	verify_success(&tcase_success);
}

static void assert_null_runTest_fail(void)
{
	char *p="";
	TEST_ASSERT_NULL(p);
}

static void assert_null_runTest_success(void)
{
	char *p=NULL;
	TEST_ASSERT_NULL(p);
}

static void testASSERT_NULL(void)
{
	TestCase tcase_fail = new_TestCase("assert_null",NULL,NULL,assert_null_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert_null",NULL,NULL,assert_null_runTest_success);
	verify_success(&tcase_success);
}

static void assert_not_null_runTest_fail(void)
{
	char *p=NULL;
	TEST_ASSERT_NOT_NULL(p);
}

static void assert_not_null_runTest_success(void)
{
	char *p="";
	TEST_ASSERT_NOT_NULL(p);
}

static void testASSERT_NOT_NULL(void)
{
	TestCase tcase_fail = new_TestCase("assert_not_null",NULL,NULL,assert_not_null_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert_not_null",NULL,NULL,assert_not_null_runTest_success);
	verify_success(&tcase_success);
}

static void assert_message_runTest_fail(void)
{
	TEST_ASSERT_MESSAGE(0,"0");
}

static void assert_message_runTest_success(void)
{
	TEST_ASSERT_MESSAGE(1,"1");
}

static void testASSERT_MESSAGE(void)
{
	TestCase tcase_fail = new_TestCase("assert_message",NULL,NULL,assert_message_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert_message",NULL,NULL,assert_message_runTest_success);
	verify_success(&tcase_success);
}

static void assert_runTest_fail(void)
{
	TEST_ASSERT(0);
}

static void assert_runTest_success(void)
{
	TEST_ASSERT(1);
}

static void testASSERT(void)
{
	TestCase tcase_fail = new_TestCase("assert",NULL,NULL,assert_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert",NULL,NULL,assert_runTest_success);
	verify_success(&tcase_success);
}

TestRef assertTest_tests( TestCaller *test )
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("testASSERT_EQUAL_STRING",testASSERT_EQUAL_STRING),
		new_TestFixture("testASSERT_EQUAL_INT",testASSERT_EQUAL_INT),
		new_TestFixture("testASSERT_NULL",testASSERT_NULL),
		new_TestFixture("testASSERT_NOT_NULL",testASSERT_NOT_NULL),
		new_TestFixture("testASSERT_MESSAGE",testASSERT_MESSAGE),
		new_TestFixture("testASSERT",testASSERT),
	};
	EMB_UNIT_TESTCALLER(test,"AssertTest",setUp,tearDown,fixtures);

	return (TestRef)test;
}
