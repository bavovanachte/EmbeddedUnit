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

EMB_UNIT_TESTFUNCTIONS(fixtures) {
	new_TestFunction("testInit",testInit),
	new_TestFunction("testSetValue",testSetValue),
	new_TestFunction("testInc",testInc),
	new_TestFunction("testDec",testDec),
	new_TestFunction("testClr",testClr),
};

EMB_UNIT_TESTFIXTURE(fixture_test,"CounterTest",setUp,tearDown,fixtures);

void testFixtureSample_test( void )
{
	EMB_UNIT_RUN(fixture_test);
}

