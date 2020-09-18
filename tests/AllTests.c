#include <embUnit/embUnit.h>

extern void assertTest_tests( void );
extern void stdImplTest_tests( void );
extern void TestCaseTest_tests( void );
extern void TestFixtureTest_tests( void );
extern void TestResultTest_tests( void );
extern void RepeatedTestTest_tests( void );

int main (int argc, const char* argv[])
{
	static TestFixture test;

	TestRunner_start();
	assertTest_tests();
	stdImplTest_tests();
	TestCaseTest_tests();
	TestFixtureTest_tests();
	TestResultTest_tests();
	RepeatedTestTest_tests();
	TestRunner_end();
	return 0;
}
