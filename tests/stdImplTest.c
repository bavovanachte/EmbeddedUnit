#include <embUnit/embUnit.h>

static void setUp(void)
{
}

static void tearDown(void)
{
}

static void teststrcpy(void)
{
	char buf[32];
	char *p;

	p = stdimpl_strcpy(buf, "test");
	TEST_ASSERT_EQUAL_STRING("test", buf);
	TEST_ASSERT( p == buf );
}

static void teststrcat(void)
{
	char buf[64];

	stdimpl_strcpy(buf,"sample");
	stdimpl_strcat(buf," extra string");
	TEST_ASSERT_EQUAL_STRING("sample extra string", buf);

	stdimpl_strcpy(buf,"");
	stdimpl_strcat(buf,"sample");
	TEST_ASSERT_EQUAL_STRING("sample", buf);
}

static void teststrncat(void)
{
	char buf[64];

	stdimpl_strcpy(buf,"sample");
	stdimpl_strncat(buf," extra string",13);
	TEST_ASSERT_EQUAL_STRING("sample extra string", buf);

	stdimpl_strcpy(buf,"This is the initial string!");
	stdimpl_strncat(buf," extra text to add to the string", 19);
	TEST_ASSERT_EQUAL_STRING("This is the initial string! extra text to add ", buf);
}

static void teststrlen(void)
{
	TEST_ASSERT( stdimpl_strlen("test")==4 );
	TEST_ASSERT( stdimpl_strlen("")==0 );
}

static void teststrcmp(void)
{
	TEST_ASSERT( stdimpl_strcmp("aaa","aaa") == 0 );
	TEST_ASSERT( stdimpl_strcmp("aaa","bbb") != 0 );
	TEST_ASSERT( stdimpl_strcmp("aaa","AAA") != 0 );
	TEST_ASSERT( stdimpl_strcmp("Test","TestCase") != 0 );
	TEST_ASSERT( stdimpl_strcmp("TestCase","Test") != 0 );
	TEST_ASSERT( stdimpl_strcmp("","") == 0 );
}

static void testitoa(void)
{
	char buf[33];
	char *p;

	p = stdimpl_itoa(10, buf, 2);
	TEST_ASSERT_EQUAL_STRING("1010", buf);
	TEST_ASSERT(p == buf);

	p = stdimpl_itoa(10, buf, 8);
	TEST_ASSERT_EQUAL_STRING("12", buf);
	TEST_ASSERT(p == buf);

	p = stdimpl_itoa(10, buf, 10);
	TEST_ASSERT_EQUAL_STRING("10", buf);
	TEST_ASSERT(p == buf);

	p = stdimpl_itoa(10, buf, 16);
	TEST_ASSERT_EQUAL_STRING("a", buf);
	TEST_ASSERT(p == buf);

	p = stdimpl_itoa(-10, buf, 10);
	TEST_ASSERT_EQUAL_STRING("-10", buf);
	TEST_ASSERT(p == buf);
}

void stdImplTest_tests( void )
{
	EMB_UNIT_TESTFUNCTIONS(fixtures) {
		new_TestFunction("teststrcpy",teststrcpy),
		new_TestFunction("teststrcat",teststrcat),
		new_TestFunction("teststrncat",teststrncat),
		new_TestFunction("teststrlen",teststrlen),
		new_TestFunction("teststrcmp",teststrcmp),
		new_TestFunction("testitoa",testitoa),
	};
	EMB_UNIT_TESTFIXTURE(test,"stdImplTest",setUp,tearDown,fixtures);

	EMB_UNIT_RUN(test);
}