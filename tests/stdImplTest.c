#include <embUnit/embUnit.h>

static void setUp(void)
{
}

static void tearDown(void)
{
}

static void testStrcpy(void)
{
	char buf[8];
	char *ret;

	ret = stdimpl_strcpy(buf, "test");
	TEST_ASSERT( buf[0]=='t' );
	TEST_ASSERT( buf[1]=='e' );
	TEST_ASSERT( buf[2]=='s' );
	TEST_ASSERT( buf[3]=='t' );
	TEST_ASSERT( buf[4]=='\0' );
	TEST_ASSERT( ret==buf+4 );

	ret = stdimpl_strcpy(buf, "");
	TEST_ASSERT( buf[0]=='\0' );
	TEST_ASSERT( ret==buf );
}

static void testStrncpy(void)
{
	char buf[8];
	char *ret;

	ret = stdimpl_strncpy(buf, "test", 8);
	TEST_ASSERT( buf[0]=='t' );
	TEST_ASSERT( buf[1]=='e' );
	TEST_ASSERT( buf[2]=='s' );
	TEST_ASSERT( buf[3]=='t' );
	TEST_ASSERT( buf[4]=='\0' );
	TEST_ASSERT( buf[5]=='\0' );
	TEST_ASSERT( buf[6]=='\0' );
	TEST_ASSERT( buf[7]=='\0' );
	TEST_ASSERT( ret==buf+4 );
	
	ret = stdimpl_strncpy(buf, "", 4);
	TEST_ASSERT( buf[0]=='\0' );
	TEST_ASSERT( buf[1]=='\0' );
	TEST_ASSERT( buf[2]=='\0' );
	TEST_ASSERT( buf[3]=='\0' );
	TEST_ASSERT( ret==buf );

	stdimpl_strcpy(buf, "_xxxx_");
	ret = stdimpl_strncpy(buf+1, "test", 4);
	TEST_ASSERT( buf[0]=='_' );
	TEST_ASSERT( buf[1]=='t' );
	TEST_ASSERT( buf[2]=='e' );
	TEST_ASSERT( buf[3]=='s' );
	TEST_ASSERT( buf[4]=='t' );
	TEST_ASSERT( buf[5]=='_' );
	TEST_ASSERT( buf[6]=='\0' );
	TEST_ASSERT( ret==buf+5 );
}

static void testStrlen(void)
{
	TEST_ASSERT( stdimpl_strlen("test")==4 );
	TEST_ASSERT( stdimpl_strlen("")==0 );
}

static void testStrcmp(void)
{
	TEST_ASSERT( stdimpl_strcmp("aaa","aaa")==0 );
	TEST_ASSERT( stdimpl_strcmp("aaa","bbb")!=0 );
	TEST_ASSERT( stdimpl_strcmp("aaa","AAA")!=0 );
	TEST_ASSERT( stdimpl_strcmp("Test","TestCase")!=0 );
	TEST_ASSERT( stdimpl_strcmp("","")==0 );
}

static void testItoa(void)
{
	char buf[33];

	stdimpl_itoa(10, buf, 2);
	TEST_ASSERT_EQUAL_STRING("1010", buf);

	stdimpl_itoa(10, buf, 8);
	TEST_ASSERT_EQUAL_STRING("12", buf);

	stdimpl_itoa(10, buf, 10);
	TEST_ASSERT_EQUAL_STRING("10", buf);

	stdimpl_itoa(10, buf, 16);
	TEST_ASSERT_EQUAL_STRING("a", buf);

	stdimpl_itoa(-10, buf, 2);
	TEST_ASSERT_EQUAL_STRING("11111111111111111111111111110110", buf);

	stdimpl_itoa(-10, buf, 8);
	TEST_ASSERT_EQUAL_STRING("37777777766", buf);

	stdimpl_itoa(-10, buf, 10);
	TEST_ASSERT_EQUAL_STRING("-10", buf);

	stdimpl_itoa(-10, buf, 16);
	TEST_ASSERT_EQUAL_STRING("fffffff6", buf);
}

static void testMemcmp(void)
{
	TEST_ASSERT(stdimpl_memcmp("sample","sample",6) == 0);
	TEST_ASSERT(stdimpl_memcmp("sample","SAMPLE",6) != 0);
	TEST_ASSERT(stdimpl_memcmp("sample","sample",0) == 0);
	TEST_ASSERT(stdimpl_memcmp("sample","samPLE",3) == 0);
}

TestRef stdImplTest_tests(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("testStrcpy",testStrcpy),
		new_TestFixture("testStrncpy",testStrncpy),
		new_TestFixture("testStrlen",testStrlen),
		new_TestFixture("testStrcmp",testStrcmp),
		new_TestFixture("testItoa",testItoa),
		new_TestFixture("testMemcmp",testMemcmp),
	};
	EMB_UNIT_TESTCALLER(StdImplTest,"stdImplTest",setUp,tearDown,fixtures);

	return (TestRef)&StdImplTest;
}
