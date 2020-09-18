#include <embUnit/embUnit.h>
#include <stdint.h>

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
};

static void assert_equal_int_with_margin_runTest_fail(void)
{
	TEST_ASSERT_EQUAL_INT_WITH_MARGIN(8, 16, 7);
	TEST_ASSERT_EQUAL_WITH_MARGIN(8, 16, 7);
	TEST_ASSERT_EQUAL_INT_WITH_MARGIN(-8, -16, 7);
	TEST_ASSERT_EQUAL_WITH_MARGIN(-8, -16, 7);
	TEST_ASSERT_EQUAL_INT_WITH_MARGIN(-8, 8, 15);
	TEST_ASSERT_EQUAL_WITH_MARGIN(-8, 8, 15);
}

static void assert_equal_int_with_margin_runTest_success(void)
{
	TEST_ASSERT_EQUAL_INT_WITH_MARGIN(8, 16, 8);
	TEST_ASSERT_EQUAL_WITH_MARGIN(8, 16, 8);
	TEST_ASSERT_EQUAL_INT_WITH_MARGIN(8, 16, 9);
	TEST_ASSERT_EQUAL_WITH_MARGIN(8, 16, 9);
	TEST_ASSERT_EQUAL_INT_WITH_MARGIN(-8, -16, 8);
	TEST_ASSERT_EQUAL_WITH_MARGIN(-8, -16, 8);
	TEST_ASSERT_EQUAL_INT_WITH_MARGIN(-8, -16, 9);
	TEST_ASSERT_EQUAL_WITH_MARGIN(-8, -16, 9);
	TEST_ASSERT_EQUAL_INT_WITH_MARGIN(-8, 8, 16);
	TEST_ASSERT_EQUAL_WITH_MARGIN(-8, 8, 16);
	TEST_ASSERT_EQUAL_INT_WITH_MARGIN(-8, 8, 17);
	TEST_ASSERT_EQUAL_WITH_MARGIN(-8, 8, 17);
}

static void testASSERT_EQUAL_INT_WITH_MARGIN(void)
{
	TestCase tcase_fail = new_TestCase("assert_equal_int_with_margin",NULL,NULL,assert_equal_int_with_margin_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert_equal_int_with_margin",NULL,NULL,assert_equal_int_with_margin_runTest_success);
	verify_success(&tcase_success);
}

static void assert_not_lower_than_int_runTest_fail(void)
{
	TEST_ASSERT_NOT_LOWER_THAN_INT(0, -1);
	TEST_ASSERT_NOT_LOWER_THAN_INT(-8, -9);
	TEST_ASSERT_NOT_LOWER_THAN_INT(8, 7);
}

static void assert_not_lower_than_int_runTest_success(void)
{
	TEST_ASSERT_NOT_LOWER_THAN_INT(0, 0);
	TEST_ASSERT_NOT_LOWER_THAN_INT(0, 1);
	TEST_ASSERT_NOT_LOWER_THAN_INT(-8, -8);
	TEST_ASSERT_NOT_LOWER_THAN_INT(-8, -7);
	TEST_ASSERT_NOT_LOWER_THAN_INT(8, 8);
	TEST_ASSERT_NOT_LOWER_THAN_INT(8, 9);
}

static void testASSERT_NOT_LOWER_THAN_INT(void)
{
	TestCase tcase_fail = new_TestCase("assert_not_lower_than_int",NULL,NULL,assert_not_lower_than_int_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert_not_lower_than_int",NULL,NULL,assert_not_lower_than_int_runTest_success);
	verify_success(&tcase_success);
}

static void assert_not_higher_than_int_runTest_fail(void)
{
	TEST_ASSERT_NOT_HIGHER_THAN_INT(0, 1);
	TEST_ASSERT_NOT_HIGHER_THAN_INT(-8, -7);
	TEST_ASSERT_NOT_HIGHER_THAN_INT(-8, 8);
	TEST_ASSERT_NOT_HIGHER_THAN_INT(8, 9);
}

static void assert_not_higher_than_int_runTest_success(void)
{
	TEST_ASSERT_NOT_HIGHER_THAN_INT(0, 0);
	TEST_ASSERT_NOT_HIGHER_THAN_INT(0, -1);
	TEST_ASSERT_NOT_HIGHER_THAN_INT(-8, -8);
	TEST_ASSERT_NOT_HIGHER_THAN_INT(-8, -9);
	TEST_ASSERT_NOT_HIGHER_THAN_INT(8, -8);
	TEST_ASSERT_NOT_HIGHER_THAN_INT(8, 8);
	TEST_ASSERT_NOT_HIGHER_THAN_INT(8, 7);
}

static void testASSERT_NOT_HIGHER_THAN_INT(void)
{
	TestCase tcase_fail = new_TestCase("assert_not_higher_than_int",NULL,NULL,assert_not_higher_than_int_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert_not_higher_than_int",NULL,NULL,assert_not_higher_than_int_runTest_success);
	verify_success(&tcase_success);
}

static void assert_range_int_runTest_fail(void)
{
	TEST_ASSERT_RANGE_INT(-8, 8, 9);
	TEST_ASSERT_RANGE_INT(8, 8, 9);
	TEST_ASSERT_RANGE_INT(-8, -1, 0);
	TEST_ASSERT_RANGE_INT(1, 8, 0);
	TEST_ASSERT_RANGE_INT(8, 1, 5);
	TEST_ASSERT_RANGE_INT(8, 1, 8);
	TEST_ASSERT_RANGE_INT(8, 1, 1);
}

static void assert_range_int_runTest_success(void)
{
	TEST_ASSERT_RANGE_INT(-8, 8, -8);
	TEST_ASSERT_RANGE_INT(-8, 8, -7);
	TEST_ASSERT_RANGE_INT(-8, 8, 8);
	TEST_ASSERT_RANGE_INT(-8, 8, 7);
	TEST_ASSERT_RANGE_INT(8, 8, 8);
	TEST_ASSERT_RANGE_INT(-8, -1, -5);
	TEST_ASSERT_RANGE_INT(1, 8, 5);
}

static void testASSERT_RANGE_INT(void)
{
	TestCase tcase_fail = new_TestCase("assert_range_int",NULL,NULL,assert_range_int_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert_range_int",NULL,NULL,assert_range_int_runTest_success);
	verify_success(&tcase_success);
}

static void assert_equal_hex_runTest_fail(void)
{
	TEST_ASSERT_EQUAL_HEX(0x123, 0x456u);
}

static void assert_equal_hex_runTest_success(void)
{
	volatile unsigned int uint1 = 0x123;
	volatile unsigned int uint2 = 0x123;
	TEST_ASSERT_EQUAL_UINT(uint1, uint2);
}

static void testASSERT_EQUAL_HEX(void)
{
	TestCase tcase_fail = new_TestCase("assert_equal_hex",NULL,NULL,assert_equal_hex_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert_equal_hex",NULL,NULL,assert_equal_hex_runTest_success);
	verify_success(&tcase_success);
}

static void assert_equal_uint_runTest_fail(void)
{
	TEST_ASSERT_EQUAL_UINT(123u,456u);
}

static void assert_equal_uint_runTest_success(void)
{
	volatile unsigned int uint1 = 123u;
	volatile unsigned int uint2 = 123u;
	TEST_ASSERT_EQUAL_UINT(uint1, uint2);
}

static void testASSERT_EQUAL_UINT(void)
{
	TestCase tcase_fail = new_TestCase("assert_equal_uint",NULL,NULL,assert_equal_uint_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert_equal_uint",NULL,NULL,assert_equal_uint_runTest_success);
	verify_success(&tcase_success);
}

static void assert_equal_uint_with_margin_runTest_fail(void)
{
	TEST_ASSERT_EQUAL_UINT_WITH_MARGIN(8, 16, 7);
	TEST_ASSERT_EQUAL_UINT_WITH_MARGIN(0, 8, 7);
	TEST_ASSERT_EQUAL_UINT_WITH_MARGIN(-9, -1, 7);
}

static void assert_equal_uint_with_margin_runTest_success(void)
{
	TEST_ASSERT_EQUAL_UINT_WITH_MARGIN(8, 16, 8);
	TEST_ASSERT_EQUAL_UINT_WITH_MARGIN(8, 16, 9);
	TEST_ASSERT_EQUAL_UINT_WITH_MARGIN(0, 8, 8);
	TEST_ASSERT_EQUAL_UINT_WITH_MARGIN(0, 8, 9);
	TEST_ASSERT_EQUAL_UINT_WITH_MARGIN(-9, -1, 8);
	TEST_ASSERT_EQUAL_UINT_WITH_MARGIN(-9, -1, 20); /* Checking for overflow behaviour */
}

static void testASSERT_EQUAL_UINT_WITH_MARGIN(void)
{
	TestCase tcase_fail = new_TestCase("assert_equal_uint_with_margin",NULL,NULL,assert_equal_uint_with_margin_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert_equal_uint_with_margin",NULL,NULL,assert_equal_uint_with_margin_runTest_success);
	verify_success(&tcase_success);
}

static void assert_not_lower_than_uint_runTest_fail(void)
{
	TEST_ASSERT_NOT_LOWER_THAN_UINT(8u, 7u);
}

static void assert_not_lower_than_uint_runTest_success(void)
{
	TEST_ASSERT_NOT_LOWER_THAN_UINT(0u, 0u);
	TEST_ASSERT_NOT_LOWER_THAN_UINT(0u, 1u);
	TEST_ASSERT_NOT_LOWER_THAN_UINT(8u, 8u);
	TEST_ASSERT_NOT_LOWER_THAN_UINT(8u, 9u);
}

static void testASSERT_NOT_LOWER_THAN_UINT(void)
{
	TestCase tcase_fail = new_TestCase("assert_not_lower_than_uint",NULL,NULL,assert_not_lower_than_uint_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert_not_lower_than_uint",NULL,NULL,assert_not_lower_than_uint_runTest_success);
	verify_success(&tcase_success);
}

static void assert_not_higher_than_uint_runTest_fail(void)
{
	TEST_ASSERT_NOT_HIGHER_THAN_UINT(0u, 1u);
	TEST_ASSERT_NOT_HIGHER_THAN_UINT(8u, 9u);
}

static void assert_not_higher_than_uint_runTest_success(void)
{
	TEST_ASSERT_NOT_HIGHER_THAN_UINT(0u, 0u);
	TEST_ASSERT_NOT_HIGHER_THAN_UINT(8u, 8u);
	TEST_ASSERT_NOT_HIGHER_THAN_UINT(8u, 7u);
}

static void testASSERT_NOT_HIGHER_THAN_UINT(void)
{
	TestCase tcase_fail = new_TestCase("assert_not_higher_than_uint",NULL,NULL,assert_not_higher_than_uint_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert_not_higher_than_uint",NULL,NULL,assert_not_higher_than_uint_runTest_success);
	verify_success(&tcase_success);
}

static void assert_range_uint_runTest_fail(void)
{
	TEST_ASSERT_RANGE_UINT(8u, 8u, 9u);
	TEST_ASSERT_RANGE_UINT(1u, 8u, 0u);
	TEST_ASSERT_RANGE_UINT(8u, 1u, 5u);
	TEST_ASSERT_RANGE_UINT(8u, 1u, 8u);
	TEST_ASSERT_RANGE_UINT(8u, 1u, 1u);
}

static void assert_range_uint_runTest_success(void)
{
	TEST_ASSERT_RANGE_UINT(8u, 8u, 8u);
	TEST_ASSERT_RANGE_UINT(1u, 8u, 5u);
	TEST_ASSERT_RANGE_UINT(1u, 8u, 1u);
	TEST_ASSERT_RANGE_UINT(1u, 8u, 8u);
	TEST_ASSERT_RANGE_UINT(0u, -1u, 2000u);
}

static void testASSERT_RANGE_UINT(void)
{
	TestCase tcase_fail = new_TestCase("assert_range_uint",NULL,NULL,assert_range_uint_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert_range_uint",NULL,NULL,assert_range_uint_runTest_success);
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

static void assert_equal_ptr_runTest_fail(void)
{
	char value = 'a';
	char value2 = 'b';
	char *volatile p1 = &value;
	char *volatile p2 = &value2;
	TEST_ASSERT_EQUAL_PTR(p1, p2);
}

static void assert_equal_ptr_runTest_success(void)
{
	char value = 'a';
	char *volatile p1 = &value;
	char *volatile p2 = &value;
	TEST_ASSERT_EQUAL_PTR(p1, p2);
}

static void testASSERT_EQUAL_PTR(void)
{
	TestCase tcase_fail = new_TestCase("assert_equal_ptr",NULL,NULL,assert_equal_ptr_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert_equal_ptr",NULL,NULL,assert_equal_ptr_runTest_success);
	verify_success(&tcase_success);
}

static void assert_equal_memory_runTest_fail(void)
{
	int volatile p1[] = {1, 2, 3, 4};
	int volatile p2[] = {2, 3, 4, 1};
	TEST_ASSERT_EQUAL_MEMORY(p1, p2, sizeof(char) * 4);
}

static void assert_equal_memory_runTest_success(void)
{
	int volatile p1[] = {1, 2, 3, 4};
	int volatile p2[] = {1, 2, 3, 4};
	TEST_ASSERT_EQUAL_MEMORY(p1, p2, sizeof(int) * 4);
}

static void testASSERT_EQUAL_MEMORY(void)
{
	TestCase tcase_fail = new_TestCase("assert_equal_memory",NULL,NULL,assert_equal_memory_runTest_fail);
	verify_failure(&tcase_fail);
	TestCase tcase_success = new_TestCase("assert_equal_memory",NULL,NULL,assert_equal_memory_runTest_success);
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

void assertTest_tests(void)
{
	EMB_UNIT_TESTFUNCTIONS(fixtures) {
		new_TestFunction("testASSERT_EQUAL_STRING",testASSERT_EQUAL_STRING),
		new_TestFunction("testASSERT_EQUAL_INT",testASSERT_EQUAL_INT),
		new_TestFunction("testASSERT_EQUAL_INT_WITH_MARGIN",testASSERT_EQUAL_INT_WITH_MARGIN),
		new_TestFunction("testASSERT_NOT_LOWER_THAN_INT",testASSERT_NOT_LOWER_THAN_INT),
		new_TestFunction("testASSERT_NOT_HIGHER_THAN_INT",testASSERT_NOT_HIGHER_THAN_INT),
		new_TestFunction("testASSERT_RANGE_INT",testASSERT_RANGE_INT),
		new_TestFunction("testASSERT_EQUAL_HEX",testASSERT_EQUAL_HEX),
		new_TestFunction("testASSERT_EQUAL_UINT",testASSERT_EQUAL_UINT),
		new_TestFunction("testASSERT_EQUAL_UINT_WITH_MARGIN",testASSERT_EQUAL_UINT_WITH_MARGIN),
		new_TestFunction("testASSERT_NOT_LOWER_THAN_UINT",testASSERT_NOT_LOWER_THAN_INT),
		new_TestFunction("testASSERT_NOT_HIGHER_THAN_UINT",testASSERT_NOT_HIGHER_THAN_INT),
		new_TestFunction("testASSERT_RANGE_UINT",testASSERT_RANGE_INT),
		new_TestFunction("testASSERT_NULL",testASSERT_NULL),
		new_TestFunction("testASSERT_EQUAL_PTR",testASSERT_EQUAL_PTR),
		new_TestFunction("testASSERT_EQUAL_MEMORY",testASSERT_EQUAL_MEMORY),
		new_TestFunction("testASSERT_NOT_NULL",testASSERT_NOT_NULL),
		new_TestFunction("testASSERT_MESSAGE",testASSERT_MESSAGE),
		new_TestFunction("testASSERT",testASSERT),
	};

	EMB_UNIT_TESTFIXTURE(test,"AssertTest",setUp,tearDown,fixtures);
	EMB_UNIT_RUN(test);
}
