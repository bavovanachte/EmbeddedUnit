/*
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
 *
 * $Id$
 */
#include "TestCase.h"
#include "TestResult.h"

static TestResultRef result_;
static TestCaseRef self_;

char* TestCase_name(TestCaseRef self)
{
	return self->name;
}

void TestCase_run(TestCaseRef self,TestResultRef result)
{
	if (result) {
		result->isa->startTest(result, self);
	}
	if (self->setUp) {
		self->setUp();
	}
	if (self->runTest) {
		TestResultRef wr =result_;	/*push*/
		TestCaseRef ws = self_;	/*push*/
		result_ = result;
		self_ = self;
		self->runTest();
		result_ = wr;	/*pop*/
		self_ = ws;	/*pop*/
	}
	if (self->tearDown) {
		self->tearDown();
	}
	if (result) {
		result->isa->endTest(result, self);
	}
}

int TestCase_countTestCases(TestCaseRef self)
{
	return 1;
}

const TestImplement TestCaseImplement = {
	(TestTypeID)				TestCaseTypeID,
	(TestNameFunction)			TestCase_name,
	(TestRunFunction)			TestCase_run,
	(TestCountTestCasesFunction)TestCase_countTestCases,
};

void addFailure(const char* msg, long line, const char* file)
{
	if (result_) {
		result_->isa->addFailure(result_, self_, (char*)msg, line, (char*)file);
	}
}
