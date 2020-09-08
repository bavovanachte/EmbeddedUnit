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
#include "config.h"
#include "stdImpl.h"
#include "AssertImpl.h"

/** Implementation for failing assert for integers
 *
 * The given set of parameters is used to add a failure
 * @param expected The expected value for the assert
 * @param actual The actual value for the assert
 * @param base The base in which to print a failure (10 for decimal, 16 for hex)
 * @param line Line number on which the assertion is done
 * @param file File name in which the assertion is done
 */
void assertImplementationInt(long expected,long actual,unsigned char base, unsigned long line, const char *file)
{
	char buffer[42];	/*"expected: -2147483647 actual: -2147483647" when base=10*/
				/*"expected: 0x12345678 actual: 0x12345678" when base=16*/
	char numbuf[12];	/*32bit int decimal maximum column is 11 (-2147483647~2147483647)*/

	stdimpl_strcpy(buffer, "expected: ");
	stdimpl_strncat(buffer, (base==16)?"0x":"", 2);

	{	stdimpl_itoa(expected, numbuf, base);
		stdimpl_strncat(buffer, numbuf, 11);	}

	stdimpl_strcat(buffer, " actual: ");
	stdimpl_strncat(buffer, (base==16)?"0x":"", 2);

	{	stdimpl_itoa(actual, numbuf, base);
		stdimpl_strncat(buffer, numbuf, 11);	}

	addFailure(buffer, line, file);
}

/** Implementation for failing assert for unsigned integers
 *
 * The given set of parameters is used to add a failure
 * @param expected The expected value for the assert
 * @param actual The actual value for the assert
 * @param base The base in which to print a failure (10 for decimal, 16 for hex)
 * @param line Line number on which the assertion is done
 * @param file File name in which the assertion is done
 */
void assertImplementationUInt(unsigned long expected,unsigned long actual,unsigned char base, unsigned long line, const char *file)
{
	char buffer[42];	/*"expected: -4294967295 actual: -4294967295" when base=10*/
				/*"expected: 0x12345678 actual: 0x12345678" when base=16*/
	char numbuf[12];	/*32bit unsigned int decimal maximum column is 11 (-4294967295~4294967296)*/

	stdimpl_strcpy(buffer, "expected: ");
	stdimpl_strncat(buffer, (base==16)?"0x":"", 2);

	{	stdimpl_utoa(expected, numbuf, base);
		stdimpl_strncat(buffer, numbuf, 11);	}

	stdimpl_strcat(buffer, " actual: ");
	stdimpl_strncat(buffer, (base==16)?"0x":"", 2);

	{	stdimpl_utoa(actual, numbuf, base);
		stdimpl_strncat(buffer, numbuf, 11);	}

	addFailure(buffer, line, file);
}

/** Implementation for failing assert for string
 *
 * The given set of parameters is used to add a failure
 * @param expected The expected string for the assert
 * @param actual The actual string for the assert
 * @param line Line number on which the assertion is done
 * @param file File name in which the assertion is done
 */
void assertImplementationCStr(const char *expected,const char *actual, unsigned long line, const char *file)
{
	char buffer[ASSERT_STRING_BUFFER_MAX];
	#define exp_act_limit_cstr ((ASSERT_STRING_BUFFER_MAX-11-1)/2)/*	"exp'' was''" = 11 byte	*/
	int el;
	int al;

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
	if (el > exp_act_limit_cstr) {
		if (al > exp_act_limit_cstr) {
			al = exp_act_limit_cstr;
			el = exp_act_limit_cstr;
		} else {
			int w = exp_act_limit_cstr + (exp_act_limit_cstr - al);
			if (el > w) {
				el = w;
			}
		}
	} else {
		int w = exp_act_limit_cstr + (exp_act_limit_cstr - el);
		if (al > w) {
			al = w;
		}
	}
	stdimpl_strcpy(buffer, "exp \"");
	stdimpl_strncat(buffer, expected, el);
	stdimpl_strcat(buffer, "\" was \"");
	stdimpl_strncat(buffer, actual, al);
	stdimpl_strcat(buffer, "\"");

	addFailure(buffer, line, file);
}

/** Implementation for failing assert for memory
 *
 * The given set of parameters is used to add a failure
 * @param exp The expected memory for the assert
 * @param act The actual memory for the assert
 * @param size The size of the memory for the assert
 * @param line Line number on which the assertion is done
 * @param file File name in which the assertion is done
 */
void assertImplementationMem(const void *exp,const void *act, int size, unsigned long line, const char *file)
{
	const char* expected = (char*)exp;
	const char* actual = (char*)act;
	char buffer[ASSERT_MEMORY_BUFFER_MAX];
	char numbuf[4];
	#define exp_act_limit_mem ((ASSERT_MEMORY_BUFFER_MAX-11-1)/2)/*	"exp'' was''" = 11 byte	*/
	int el;
	int al;
	int it;

	if (expected) {
		el = 3 * size; /* " xx" = 3 byte */
	} else {
		el = 4;
		expected = "null";
	}

	if (actual) {
		al =  3 * size; /* " xx" = 3 byte */
	} else {
		al = 4;
		actual = "null";
	}
	if (el > exp_act_limit_mem) {
		if (al > exp_act_limit_mem) {
			al = exp_act_limit_mem;
			el = exp_act_limit_mem;
		} else {
			int w = exp_act_limit_mem + (exp_act_limit_mem - al);
			if (el > w) {
				el = w;
			}
		}
	} else {
		int w = exp_act_limit_mem + (exp_act_limit_mem - el);
		if (al > w) {
			al = w;
		}
	}
	stdimpl_strcpy(buffer, "exp \"");
	it = 0;
	while (el >= 3) {
		stdimpl_itoa(expected[it], numbuf, 16);
		stdimpl_strncat(buffer, numbuf, 2);
		stdimpl_strncat(buffer, " ", 1);
		it++;
		el -= 3;
	}
	stdimpl_strcat(buffer, "\" was \"");
	it = 0;
	while (al >= 3) {
		stdimpl_itoa(actual[it], numbuf, 16);
		stdimpl_strncat(buffer, numbuf, 2);
		stdimpl_strncat(buffer, " ", 1);
		it++;
		al -= 3;
	}
	stdimpl_strcat(buffer, "\"");

	addFailure(buffer, line, file);
}

