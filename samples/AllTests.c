#include <embUnit/embUnit.h>

void testSuiteSample_test(void);
void repeatTestSample_test(void);
void testFixtureSample_test(void);
void PersonTest_tests(void);

int main (int argc, const char* argv[])
{
	TestRunner_start();
	testSuiteSample_test();
	testFixtureSample_test();
	repeatTestSample_test();
	PersonTest_tests();
	TestRunner_end();
	return 0;
}
