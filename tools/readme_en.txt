1.Overview

    tbcuppa & tbuma is developed by cuppa project.
    It is the tool which generates the test code for CUnit.
    ���Τ��Ӳ�Ƹ�������Ϥ��Ǥ��Ф������ɤ�Embedded Unit�Ѥ˽񤭴����ޤ�����

    Original tbcuppa & tbuma can be downloaded from the following URL.

    cuppa project
    http://sourceforge.jp/projects/cuppa/

    cuppa (CppUnit PreProcess Aid)
    http://www.unittest.org/


2.Release Contents
    [tools]
    +- readme.txt       : japanese
    +- readme_en.txt    : this file
    +- makefile         :
    +- COPYING          : copyright notice
    +- [tbcuppa]        : tcuppa & bcuppa source code
    +- [tbuma]          : tuma & buma source code


3.Compile
    tools�ǥ��쥯�Ȥ˰�ư����'make'���ޥ�ɤ�¹Ԥ��Ƥ���������
    tools�ǥ��쥯�ȥ�˰ʲ��Σ��ĤΥ��ץꥱ������󤬺�������ޤ���

    tcuppa  ���ƥ��ȥ��롼�פο������������ޤ���
    bcuppa  ��tcuppa���������줿�ƥ��ȥ��롼�פ�¹Ԥ���main��������ޤ���
    tuma    ��tcuppa���������줿�ƥ��ȥ��롼�פ˥ƥ��Ȥ��ɲä��ޤ���
    buma    ��bcuppa���������줿main�˥ƥ��ȼ¹ԥ����ɤ��ɲä��ޤ���


4.Usage

4.1.tcuppa
    My.h���������Ƥ���ؿ���ƥ��Ȥ���ƥ��ȥ��롼�� MyTest ���������������

    $ tcuppa My.h MyTest testXxx testYyy

    �����Ϥ��롥���������My.h�򥤥󥯥롼�ɤ����Υƥ��ȴؿ�

        static void testXxx(void)
        static void testYyy(void)

    ���������MyTest.c ����������롥�إå��Ͼ�ά��ǽ,�ޤ�ʣ�������ǽ.

4.2.bcuppa
    bcuppa��tcuppa�ˤ�ä��������줿�ƥ��ȥ��롼�פ�缡�¹Ԥ���
    �ᥤ��롼������������ޤ���
    ��ۤɺ������� MyTest ��¹Ԥ��륳���� AllTests ����������ˤ�

    $ bcuppa AllTests MyTest

    �����Ϥ��롥�ޤ������ȥǥ��쥯�ȥ�� ATest.c BTest.c�Ⱥߤä����

    $ bcuppa AllTests *Test.c

    �Τ褦�ʥ��ޥ�ɤλ��꤬��ǽ�Ǥ���

4.3.tuma
    tcuppa���������줿�ƥ��ȥ��롼�פ˥ƥ��Ȥ��ɲä��ޤ���
    ��Ϥ���ۤɺ������� MyTest �˥ƥ��� testZzz ���ɲä�������硢

    $ tuma MyTest testZzz

    �����Ϥ��ޤ���

4.4.buma
    bcuppa���������줿 AllTests �˼¹ԥ����ɤ��ɲä��ޤ���
    ������ YourTest �ȸ����ƥ��ȥ��롼�פ��������ޤ�.

    $ tcuppa YourTest testXxx testYyy

    ������ YourTest �� AllTests ���ɲä��ޤ���

    $ buma AllTests YourTest

------------------------------------------------------------------------------
$Id$
