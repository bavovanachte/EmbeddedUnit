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

static void testInc(void)
{
	Counter_inc(counterRef);
	TEST_ASSERT_EQUAL_INT(1, Counter_value(counterRef));

	Counter_inc(counterRef);
	TEST_ASSERT_EQUAL_INT(2, Counter_value(counterRef));
}

static void testDec(void)
{
	Counter_dec(counterRef);
	TEST_ASSERT_EQUAL_INT(-1, Counter_value(counterRef));

	Counter_dec(counterRef);
	TEST_ASSERT_EQUAL_INT(-2, Counter_value(counterRef));
}

static void testClr(void)
{
	Counter_inc(counterRef);
	TEST_ASSERT_EQUAL_INT(1, Counter_value(counterRef));

	Counter_clr(counterRef);
	TEST_ASSERT_EQUAL_INT(0, Counter_value(counterRef));
}

EMB_UNIT_TESTFIXTURES(fixtures) {
	new_TestFixture("testInit",testInit),
	new_TestFixture("testSetValue",testSetValue),
	new_TestFixture("testInc",testInc),
	new_TestFixture("testDec",testDec),
	new_TestFixture("testClr",testClr),
};

EMB_UNIT_TESTCALLER(fixture_test,"CounterTest",setUp,tearDown,fixtures);

int repeattest_inputs[][2] = {
	{1, 2},
	{2, 3},
	{6, 7},
	{8, 9}
};
static void repeat_testcase(void)
{
	static unsigned int i = 0u;
	TEST_ASSERT_EQUAL_INT(0, counterRef->value);
	Counter_setValue(counterRef, repeattest_inputs[i][0]);
	TEST_ASSERT_EQUAL_INT(repeattest_inputs[i][0], counterRef->value);
	Counter_inc(counterRef);
	TEST_ASSERT_EQUAL_INT(repeattest_inputs[i][1], counterRef->value);
}

EMB_UNIT_TESTCASE(repeat_tc, "Repeated testcase", setUp, tearDown, repeat_testcase);
EMB_UNIT_REPEATEDTEST(repeat_test, &repeat_tc, 4);

void CounterTest_tests( void )
{
	TestRunner_runTest((Test*)&fixture_test);
	TestRunner_runTest((Test*)&repeat_test);
}

