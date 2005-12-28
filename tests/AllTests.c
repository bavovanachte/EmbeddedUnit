#include <embUnit/embUnit.h>

extern TestRef assertTest_tests( TestCaller *test );
extern TestRef stdImplTest_tests( TestCaller *test );
extern TestRef TestCaseTest_tests( TestCaller *test );
extern TestRef TestCallerTest_tests( TestCaller *test );
extern TestRef TestResultTest_tests( TestCaller *test );
extern TestRef RepeatedTestTest_tests( TestCaller *test );

int main (int argc, const char* argv[])
{
	static TestCaller test;
	
	TestRunner_start();
		TestRunner_runTest(assertTest_tests(&test));
		TestRunner_runTest(stdImplTest_tests(&test));
		TestRunner_runTest(TestCaseTest_tests(&test));
		TestRunner_runTest(TestCallerTest_tests(&test));
		TestRunner_runTest(TestResultTest_tests(&test));
		TestRunner_runTest(RepeatedTestTest_tests(&test));
	TestRunner_end();
	return 0;
}
