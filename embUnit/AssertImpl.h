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
#ifndef	__ASSERTIMPL_H__
#define	__ASSERTIMPL_H__

#include <stdImpl.h>

#ifdef	__cplusplus
extern "C" {
#endif

void addFailure(const char *msg, unsigned long line, const char *file);	/*TestCase.c*/

void assertImplementationInt(long expected,long actual, unsigned char base, unsigned long line, const char *file);
void assertImplementationUInt(unsigned long expected,unsigned long actual, unsigned char base, unsigned long line, const char *file);
void assertImplementationCStr(const char *expected,const char *actual, unsigned long line, const char *file);
void assertImplementationMem(const void *expected,const void *actual, int size, unsigned long line, const char *file);

/** Assert string equality
 *
 * @param expected Expected value
 * @param actual Actual value
 */
#define TEST_ASSERT_EQUAL_STRING(expected,actual)\
	if (expected && actual && (stdimpl_strcmp(expected,actual)==0)) {} else {assertImplementationCStr(expected,actual,__LINE__,__FILE__);}

/** Assert memory equality
 *
 * @param expected Expected value
 * @param actual Actual value
 * @param size Size of the memory to compare
 */
#define TEST_ASSERT_EQUAL_MEMORY(expected,actual,size)\
	if ((expected!=NULL) && (actual!=NULL) && (stdimpl_memcmp(expected,actual,size)==0)) {} else {assertImplementationMem(expected,actual,size,__LINE__,__FILE__);}

/** Assert signed integer equality
 *
 * @param expected Expected value
 * @param actual Actual value
 */
#define TEST_ASSERT_EQUAL_INT(expected,actual)\
	if (expected == actual) {} else {assertImplementationInt(expected,actual, 10,__LINE__,__FILE__);}

/** Assert unsigned integer equality
 *
 * @param expected Expected value
 * @param actual Actual value
 */
#define TEST_ASSERT_EQUAL_UINT(expected,actual)\
	if (expected == actual) {} else {assertImplementationUInt(expected,actual, 10,__LINE__,__FILE__);}

/** Assert hexadecimal integer equality
 *
 * @param expected Expected value
 * @param actual Actual value
 */
#define TEST_ASSERT_EQUAL_HEX(expected,actual)\
	if (expected == actual) {} else {assertImplementationUInt(expected,actual, 16,__LINE__,__FILE__);}

/** Assert pointer equality
 *
 * @param expected Expected poiunter
 * @param actual Actual pointer
 */
#define TEST_ASSERT_EQUAL_PTR(expected,actual)\
	if ((void*)expected == (void*)actual) {} else {assertImplementationUInt((int)expected,(int)actual, 16,__LINE__,__FILE__);}

/** Assert signed integer equality with margin
 *
 * @param expected Expected value
 * @param actual Actual value
 * @param margin Allowed margin to be applied during assertion
 */
#define TEST_ASSERT_EQUAL_INT_WITH_MARGIN(expected,actual,margin)\
	TEST_ASSERT_EQUAL_WITH_MARGIN(expected,actual,margin)

/** Assert signed integer equality with margin
 *
 * @param expected Expected value
 * @param actual Actual value
 * @param margin Allowed margin to be applied during assertion
 */
#define TEST_ASSERT_EQUAL_WITH_MARGIN(expected,actual,margin)\
	do { \
		long __margin = margin; \
		if (margin < 0) __margin = -margin; \
		if( expected > actual ) { \
			if( (expected - actual) <= __margin ) {} \
			else {assertImplementationInt(expected,actual,10,__LINE__,__FILE__);} \
		} \
		else { \
			if( (actual - expected) <= __margin ) {} \
			else {assertImplementationInt(expected,actual,10,__LINE__,__FILE__);} \
		} \
	} while(0)

/** Assert unsigned integer equality with margin
 *
 * @param expected Expected value
 * @param actual Actual value
 * @param margin Allowed margin to be applied during assertion
 */
#define TEST_ASSERT_EQUAL_UINT_WITH_MARGIN(expected,actual,margin)\
	do { \
		unsigned long __margin = margin; \
		if( expected > actual ) { \
			if( (expected - actual) <= __margin ) {} \
			else {assertImplementationUInt(expected,actual,10,__LINE__,__FILE__);} \
		} \
		else { \
			if( (actual - expected) <= __margin ) {} \
			else {assertImplementationUInt(expected,actual,10,__LINE__,__FILE__);} \
		} \
	} while(0)

/** Assert signed integer to be higher than or equal to a minimum value
 *
 * @param min Minimum allowed value
 * @param actual Actual value
 */
#define TEST_ASSERT_NOT_LOWER_THAN_INT(min, actual)\
	if (actual < min) { \
		assertImplementationInt(min, actual, 10, __LINE__, __FILE__); \
	}

/** Assert signed integer to be lower than or equal to a maximum value
 *
 * @param max Maximum allowed value
 * @param actual Actual value
 */
#define TEST_ASSERT_NOT_HIGHER_THAN_INT(max, actual)\
	if (actual > max) { \
		assertImplementationInt(max, actual, 10, __LINE__, __FILE__); \
	}

/** Assert signed integer to be within the range (boundaries are allowed) of given minimum and maximum
 *
 * @param min Minimum allowed value
 * @param max Maximum allowed value
 * @param actual Actual value
 */
#define TEST_ASSERT_RANGE_INT(min, max, actual)\
	do { \
		TEST_ASSERT_NOT_LOWER_THAN_INT(min, actual)\
		TEST_ASSERT_NOT_HIGHER_THAN_INT(max, actual)\
	} while(0)

/** Assert unsigned integer to be higher than or equal to a minimum value
 *
 * @param min Minimum allowed value
 * @param actual Actual value
 */
#define TEST_ASSERT_NOT_LOWER_THAN_UINT(min, actual)\
	if (actual < min) { \
		assertImplementationUInt(min, actual, 10, __LINE__, __FILE__); \
	}

/** Assert unsigned integer to be lower than or equal to a maximum value
 *
 * @param max Maximum allowed value
 * @param actual Actual value
 */
#define TEST_ASSERT_NOT_HIGHER_THAN_UINT(max, actual)\
	if (actual > max) { \
		assertImplementationUInt(max, actual, 10, __LINE__, __FILE__); \
	}

/** Assert unsigned integer to be within the range (boundaries are allowed) of given minimum and maximum
 *
 * @param min Minimum allowed value
 * @param max Maximum allowed value
 * @param actual Actual value
 */
#define TEST_ASSERT_RANGE_UINT(min, max, actual)\
	do { \
		TEST_ASSERT_NOT_LOWER_THAN_UINT(min, actual)\
		TEST_ASSERT_NOT_HIGHER_THAN_UINT(max, actual)\
	} while(0)

/** Assert a pointer to be NULL
 *
 * @param pointer Pointer under test
 */
#define TEST_ASSERT_NULL(pointer)\
	TEST_ASSERT_MESSAGE(pointer == NULL,#pointer " was not null.")

/** Assert a pointer to be non-NULL
 *
 * @param pointer Pointer under test
 */
#define TEST_ASSERT_NOT_NULL(pointer)\
	TEST_ASSERT_MESSAGE(pointer != NULL,#pointer " was null.")

/** Assert a condition to pass
 *
 * @param condition Condition under test
 * @param message Message to print when assertion fails
 */
#define TEST_ASSERT_MESSAGE(condition, message)\
	if (condition) {} else {TEST_FAIL(message);}

/** Assert a condition to pass
 *
 * @param condition Condition under test
 */
#define TEST_ASSERT(condition)\
	if (condition) {} else {TEST_FAIL(#condition);}

/** Mark a test as failed
 *
 * @param message Message to print
 */
#define TEST_FAIL(message)\
	if (0) {} else {addFailure(message,__LINE__,__FILE__);}

#ifdef	__cplusplus
}
#endif

#endif/*__ASSERTIMPL_H__*/
