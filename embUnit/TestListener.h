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
#ifndef	__TESTLISTENER_H__
#define	__TESTLISTENER_H__

#include "Test.h"

typedef struct __TestListnerImplement	TestListnerImplement;
typedef struct __TestListnerImplement*	TestListnerImplementRef;

typedef void(*TestListnerStartTestCallBack)(void*,void*);
typedef void(*TestListnerEndTestCallBack)(void*,void*);
typedef void(*TestListnerAddFailureCallBack)(void*,void*,char*,int,char*);

struct __TestListnerImplement {
	TestListnerStartTestCallBack startTest;
	TestListnerEndTestCallBack endTest;
	TestListnerAddFailureCallBack addFailure;
};

typedef struct __TestListner	TestListner;
typedef struct __TestListner*	TestListnerRef;

struct __TestListner {
	TestListnerImplementRef isa;
};

#define TestListner_startTest(s,t)			(s)->isa->startTest(s,t)
#define TestListner_endTest(s,t)			(s)->isa->endTest(s,t)
#define TestListner_addFailure(s,t,m,l,f)	(s)->isa->addFailure(s,t,m,l,f)

#endif/*__TESTLISTENER_H__*/
