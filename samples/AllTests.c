#include <embUnit/embUnit.h>

void CounterTest_tests(void);
void PersonTest_tests(void);

int main (int argc, const char* argv[])
{
	static TestCaller test;

	TestRunner_start();
	CounterTest_tests();
	PersonTest_tests();
	TestRunner_end();
	return 0;
}
