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
#include "stdImpl.h"
#include "AssertImpl.h"

void assertImplementationInt(int expected,int actual, long line, const char* file)
{
	char buffer[36],*bp;

	bp = stdimpl_strcpy(buffer, "exp ");
	bp = stdimpl_itoa(expected, bp, 10);
	bp = stdimpl_strcpy(bp, " was ");
	bp = stdimpl_itoa(actual, bp, 10);

	addFailure(buffer, line, file);
}

void assertImplementationCStr(const char* expected,const char* actual, long line, const char* file)
{
	char buffer[64],*bp;
	int el,al;

	if (expected) {
		el = stdimpl_strlen(expected);
	} else {
		el = 4;
		expected = "null";
	}

	if (actual) {
		al = stdimpl_strlen(actual);
	} else {
		al = 4;
		actual = "null";
	}

	if (el > 26) {
		if (al > 26) {
			al = 26;
			el = 26;
		} else {
			int w = 26 + (26 - al);
			if (el > w) {
				el = w;
			}
		}
	} else {
		int w = 26 + (26 - el);
		if (al > w) {
			al = w;
		}
	}

	bp = stdimpl_strcpy(buffer, "exp'");
	bp = stdimpl_strncpy(bp, expected, el);
	bp = stdimpl_strcpy(bp, "' was'");
	bp = stdimpl_strncpy(bp, actual, al);
	stdimpl_strcpy(bp, "'");

	addFailure(buffer, line, file);
}
