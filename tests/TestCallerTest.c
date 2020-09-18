#include <embUnit/embUnit.h>

static void setUp(void)
{
}

static void tearDown(void)
{
}

static void testOneFixture(void)
{
	TestFixture	testFixtures[] = {
		new_TestFunction(NULL,NULL),
	};

	TestFixture fixture = new_TestFixture(NULL,NULL,NULL,1,testFixtures);
	TestResult result = new_TestResult(NULL);

	fixture.isa->run(&fixture,&result);

	TEST_ASSERT_EQUAL_INT(1, result.runCount);
	TEST_ASSERT_EQUAL_INT(1, fixture.isa->countTestCases(&fixture));
}

static void testMoreThanOne(void)
{
	TestFixture	fixtures[] = {
		new_TestFunction(NULL,NULL),
		new_TestFunction(NULL,NULL),
		new_TestFunction(NULL,NULL),
		new_TestFunction(NULL,NULL),
		new_TestFunction(NULL,NULL),
	};

	TestFixture fixture =  new_TestFixture(NULL,NULL,NULL,5,fixtures);
	TestResult result = new_TestResult(NULL);

	fixture.isa->run(&fixture,&result);

	TEST_ASSERT_EQUAL_INT(5, result.runCount);
	TEST_ASSERT_EQUAL_INT(5, fixture.isa->countTestCases(&fixture));
}

static void testZeroFixture(void)
{
	TestFixture fixture = new_TestFixture(NULL,NULL,NULL,0,NULL);
	TestResult result = new_TestResult(NULL);

	fixture.isa->run(&fixture,&result);

	TEST_ASSERT_EQUAL_INT(0, result.runCount);
	TEST_ASSERT_EQUAL_INT(0, fixture.isa->countTestCases(&fixture));
}

void TestFixtureTest_tests( void )
{
	EMB_UNIT_TESTFUNCTIONS(fixtures) {
		new_TestFunction("testOneFixture",testOneFixture),
		new_TestFunction("testMoreThanOne",testMoreThanOne),
		new_TestFunction("testZeroFixture",testZeroFixture),
	};
	EMB_UNIT_TESTFIXTURE(test,"TestFixtureTest",setUp,tearDown,fixtures);
	EMB_UNIT_RUN(test);
}
