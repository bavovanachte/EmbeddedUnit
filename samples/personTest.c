#include <embUnit/embUnit.h>
#include "person.h"

PersonRef personRef;

static void setUp(void)
{
	personRef = Person_personWithName("test tarou");
}

static void tearDown(void)
{
	Person_dealloc(personRef);
}

static void testfullname(void)
{
	TEST_ASSERT_EQUAL_STRING("test tarou", Person_fullName(personRef));
}

static void testfirstname(void)
{
	TEST_ASSERT_EQUAL_STRING("test", Person_firstName(personRef));
}

static void testlastname(void)
{
	TEST_ASSERT_EQUAL_STRING("tarou", Person_lastName(personRef));
}

static void testsetfullname(void)
{
	Person_setFullName(personRef, "sample hanako");

	TEST_ASSERT_EQUAL_STRING("sample hanako", Person_fullName(personRef));
	TEST_ASSERT_EQUAL_STRING("sample", Person_firstName(personRef));
	TEST_ASSERT_EQUAL_STRING("hanako", Person_lastName(personRef));
}

static void testsetfirstname(void)
{
	Person_setFirstName(personRef, "sample");

	TEST_ASSERT_EQUAL_STRING("sample tarou", Person_fullName(personRef));
	TEST_ASSERT_EQUAL_STRING("sample", Person_firstName(personRef));
	TEST_ASSERT_EQUAL_STRING("tarou", Person_lastName(personRef));
}

static void testsetlastname(void)
{
	Person_setLastName(personRef, "hanako");

	TEST_ASSERT_EQUAL_STRING("test hanako", Person_fullName(personRef));
	TEST_ASSERT_EQUAL_STRING("test", Person_firstName(personRef));
	TEST_ASSERT_EQUAL_STRING("hanako", Person_lastName(personRef));
}

static void testnullcharfullname(void)
{
	Person_setFullName(personRef, "");

	TEST_ASSERT_EQUAL_STRING("", Person_fullName(personRef));
	TEST_ASSERT_EQUAL_STRING("", Person_firstName(personRef));
	TEST_ASSERT_EQUAL_STRING("", Person_lastName(personRef));
}

static void testnullpointerfullname(void)
{
	Person_setFullName(personRef, NULL);

	TEST_ASSERT_NULL(Person_fullName(personRef));
	TEST_ASSERT_NULL(Person_firstName(personRef));
	TEST_ASSERT_NULL(Person_lastName(personRef));
}

static void testnosepfullname(void)
{
	Person_setFullName(personRef, "sample");

	TEST_ASSERT_EQUAL_STRING("sample", Person_fullName(personRef));
	TEST_ASSERT_EQUAL_STRING("sample", Person_firstName(personRef));
	TEST_ASSERT_EQUAL_STRING("", Person_lastName(personRef));

	Person_setLastName(personRef, "tarou");
	TEST_ASSERT_EQUAL_STRING("sample tarou", Person_fullName(personRef));
	TEST_ASSERT_EQUAL_STRING("sample", Person_firstName(personRef));
	TEST_ASSERT_EQUAL_STRING("tarou", Person_lastName(personRef));

	Person_setFirstName(personRef, "test");
	TEST_ASSERT_EQUAL_STRING("test tarou", Person_fullName(personRef));
	TEST_ASSERT_EQUAL_STRING("test", Person_firstName(personRef));
	TEST_ASSERT_EQUAL_STRING("tarou", Person_lastName(personRef));
}

void PersonTest_tests( void )
{
	EMB_UNIT_TESTFUNCTIONS(fixtures) {
		new_TestFunction("testfullname",testfullname),
		new_TestFunction("testfirstname",testfirstname),
		new_TestFunction("testlastname",testlastname),
		new_TestFunction("testsetfullname",testsetfullname),
		new_TestFunction("testsetfirstname",testsetfirstname),
		new_TestFunction("testsetlastname",testsetlastname),
		new_TestFunction("testnullcharfullname",testnullcharfullname),
		new_TestFunction("testnullpointerfullname",testnullpointerfullname),
		new_TestFunction("testnosepfullname",testnosepfullname),
	};
	EMB_UNIT_TESTFIXTURE(test,"PersonTest",setUp,tearDown,fixtures);

	EMB_UNIT_RUN(test);
}
