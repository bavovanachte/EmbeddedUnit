/** @file
 *
 * COPYRIGHT AND PERMISSION NOTICE
 *
 * Copyright (c) 2003 Embedded Unit Project
 *
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, and/or sell copies of the Software, and to permit persons
 * to whom the Software is furnished to do so, provided that the above
 * copyright notice(s) and this permission notice appear in all copies
 * of the Software and that both the above copyright notice(s) and this
 * permission notice appear in supporting documentation.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT
 * OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY
 * SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER
 * RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF
 * CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Except as contained in this notice, the name of a copyright holder
 * shall not be used in advertising or otherwise to promote the sale,
 * use or other dealings in this Software without prior written
 * authorization of the copyright holder.
 */
#ifndef	__HELPERMACRO_H__
#define	__HELPERMACRO_H__

/** Set up a single testcase
 *
 * Create a single testcase
 * @param ca Name of the testcase (should be a C-identifier)
 * @param name String indentifier of the testcase
 * @param sup Setup function to be called before executing the test case
 * @param tdw Tear down function to be called after executing the test case
 * @param run Run function to execute
 */
#define EMB_UNIT_TESTCASE(ca,name,sup,tdw,run) \
	static const TestCase	ca = new_TestCase(name,sup,tdw,run)

#define EMB_UNIT_TESTSUITE(su,name,array) \
	static const TestSuite	su = new_TestSuite(name,(Test**)array,sizeof(array)/sizeof(array[0]))

#define EMB_UNIT_TESTREFS(tests) \
	static Test* const tests[] =

#define EMB_UNIT_ADD_TESTREF(testref) \
				(Test*)	testref

/** Set up a testfixture
 *
 * Create a testfixture that executes a list of testcases. Before every testcase,
 * the given setup() function is called. After every testcase, the given teardown()
 * function is called.
 * @param fixture Name of the testfixture object (should be a C-identifier)
 * @param name String identifier of the testfixture
 * @param sup Setup function to be called before every testcase
 * @param tdw Tear down function to be called after every testcase
 * @param functions List of TestFunction instances
 */
#define EMB_UNIT_TESTFIXTURE(fixture,name,sup,tdw,functions) \
	static const TestFixture fixture = new_TestFixture(#name,sup,tdw,sizeof(functions)/sizeof(functions[0]),functions)

#define EMB_UNIT_TESTFUNCTIONS(functions) \
	static const TestFunction	functions[] =

/** Set up a repeated test
 *
 * Create a repeated test that is repeated tmrp times.
 *
 * @param repeater Name of the repeated test (should be a C-identifier)
 * @param test Test* object to execute on every iteration
 * @param tmrp Number of times the test cycle should be executed
 */
#define EMB_UNIT_REPEATEDTEST(repeater,test,tmrp) \
	static const RepeatedTest	repeater = new_RepeatedTest(test,tmrp)

/** Run a previously defined (set of) test case(s)
 *
 * Run a test case, or set of test cases which were previously defined using
 * EMB_UNIT_TESTCASE(), EMB_UNIT_TESTSUITE(), EMB_UNIT_TESTFIXTURE(), or EMB_UNIT_REPEATEDTEST()
 * @param test Name of the test to execute
 */
#define EMB_UNIT_RUN(test) TestRunner_runTest((Test*)&test);


#endif/*__HELPERMACRO_H__*/
