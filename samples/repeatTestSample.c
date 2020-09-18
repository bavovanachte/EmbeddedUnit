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

static int repeattest_inputs[][2] = {
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
	i++;
}

EMB_UNIT_TESTCASE(repeat_tc, "Repeated testcase", setUp, tearDown, repeat_testcase);
EMB_UNIT_REPEATEDTEST(repeat_test, &repeat_tc, 4);

void repeatTestSample_test( void )
{
	EMB_UNIT_RUN(repeat_test);
}

