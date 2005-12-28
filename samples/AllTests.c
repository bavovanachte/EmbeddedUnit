#include <embUnit/embUnit.h>

TestRef CounterTest_tests( TestCaller *test );
TestRef PersonTest_tests( TestCaller *test );

int main (int argc, const char* argv[])
{
	static TestCaller test;
	
	TestRunner_start();
		TestRunner_runTest(CounterTest_tests(&test));
		TestRunner_runTest(PersonTest_tests(&test));
	TestRunner_end();
	return 0;
}
