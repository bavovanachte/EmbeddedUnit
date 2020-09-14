<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="file">
    <name>AssertImpl.c</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>AssertImpl_8c</filename>
    <includes id="config_8h" name="config.h" local="yes" imported="no">config.h</includes>
    <includes id="stdImpl_8h" name="stdImpl.h" local="yes" imported="no">stdImpl.h</includes>
    <includes id="AssertImpl_8h" name="AssertImpl.h" local="yes" imported="no">AssertImpl.h</includes>
    <member kind="function">
      <type>void</type>
      <name>assertImplementationInt</name>
      <anchorfile>AssertImpl_8c.html</anchorfile>
      <anchor>a7d12cd10de3e7ba341f11f88acfdd9d9</anchor>
      <arglist>(long expected, long actual, unsigned char base, unsigned long line, const char *file)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>assertImplementationUInt</name>
      <anchorfile>AssertImpl_8c.html</anchorfile>
      <anchor>a3b8c61e27377171a4ced696c984da829</anchor>
      <arglist>(unsigned long expected, unsigned long actual, unsigned char base, unsigned long line, const char *file)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>assertImplementationCStr</name>
      <anchorfile>AssertImpl_8c.html</anchorfile>
      <anchor>acad26cbc9c64b37bd0a56639b89ac00e</anchor>
      <arglist>(const char *expected, const char *actual, unsigned long line, const char *file)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>assertImplementationMem</name>
      <anchorfile>AssertImpl_8c.html</anchorfile>
      <anchor>ada334aa191a5ef4cc38ca205d6652b9e</anchor>
      <arglist>(const void *exp, const void *act, int size, unsigned long line, const char *file)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>AssertImpl.h</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>AssertImpl_8h</filename>
    <includes id="stdImpl_8h" name="stdImpl.h" local="no" imported="no">stdImpl.h</includes>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_EQUAL_STRING</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>a1432f008fb6fb923371d4d0402571bf6</anchor>
      <arglist>(expected, actual)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_EQUAL_MEMORY</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>a91e7af396bbb7112e7122224d9f453c2</anchor>
      <arglist>(expected, actual, size)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_EQUAL_INT</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>af52a321a93c580a6213fef3e0f85c237</anchor>
      <arglist>(expected, actual)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_EQUAL_UINT</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>aff20a2bc399f4d31f69aa468542f11d1</anchor>
      <arglist>(expected, actual)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_EQUAL_HEX</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>ab1497984306b3fe78e851341d82c7147</anchor>
      <arglist>(expected, actual)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_EQUAL_PTR</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>a765240c346d79b58ef22d81982aced18</anchor>
      <arglist>(expected, actual)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_EQUAL_INT_WITH_MARGIN</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>a0dabc9ae6eaa3b46536521b5a99854c7</anchor>
      <arglist>(expected, actual, margin)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_EQUAL_WITH_MARGIN</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>a154b724ab91c33b7d977b17e964b16a4</anchor>
      <arglist>(expected, actual, margin)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_EQUAL_UINT_WITH_MARGIN</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>a7cc9b8a44d2711eb07fb2a0ed92ffb8d</anchor>
      <arglist>(expected, actual, margin)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_NOT_LOWER_THAN_INT</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>ae4e883189e1d231587845a4761aa6783</anchor>
      <arglist>(min, actual)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_NOT_HIGHER_THAN_INT</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>a735d523a0ba4034f6e15feed21a65a05</anchor>
      <arglist>(max, actual)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_RANGE_INT</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>a7e50e547df9295fb216debc703b84496</anchor>
      <arglist>(min, max, actual)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_NOT_LOWER_THAN_UINT</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>aafd9c8bc24dbf7000aeb891f7ecdfd7a</anchor>
      <arglist>(min, actual)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_NOT_HIGHER_THAN_UINT</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>a10c24d423941a1a21b284114fd4126c9</anchor>
      <arglist>(max, actual)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_RANGE_UINT</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>ae170691e04d93ad13a0ebd08bc8ba47a</anchor>
      <arglist>(min, max, actual)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_NULL</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>a4d807ccb46fae06886f16ea8a86590ca</anchor>
      <arglist>(pointer)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_NOT_NULL</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>afae78efdc83dcc60f08347b8390525b9</anchor>
      <arglist>(pointer)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT_MESSAGE</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>ae525f7ac1168f789c109324166cd6e13</anchor>
      <arglist>(condition, message)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_ASSERT</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>ae0a72bc174ac97e90c4a711e5e52d540</anchor>
      <arglist>(condition)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TEST_FAIL</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>a3650e4aa89d05fbc5f0152f014576093</anchor>
      <arglist>(message)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>assertImplementationInt</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>a7d12cd10de3e7ba341f11f88acfdd9d9</anchor>
      <arglist>(long expected, long actual, unsigned char base, unsigned long line, const char *file)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>assertImplementationUInt</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>a3b8c61e27377171a4ced696c984da829</anchor>
      <arglist>(unsigned long expected, unsigned long actual, unsigned char base, unsigned long line, const char *file)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>assertImplementationCStr</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>acad26cbc9c64b37bd0a56639b89ac00e</anchor>
      <arglist>(const char *expected, const char *actual, unsigned long line, const char *file)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>assertImplementationMem</name>
      <anchorfile>AssertImpl_8h.html</anchorfile>
      <anchor>a04b5c15cb155134f8077199951363700</anchor>
      <arglist>(const void *expected, const void *actual, int size, unsigned long line, const char *file)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>config.h</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>config_8h</filename>
  </compound>
  <compound kind="file">
    <name>embUnit.h</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>embUnit_8h</filename>
    <includes id="Test_8h" name="Test.h" local="no" imported="no">embUnit/Test.h</includes>
    <includes id="TestCase_8h" name="TestCase.h" local="no" imported="no">embUnit/TestCase.h</includes>
    <includes id="TestListener_8h" name="TestListener.h" local="no" imported="no">embUnit/TestListener.h</includes>
    <includes id="TestResult_8h" name="TestResult.h" local="no" imported="no">embUnit/TestResult.h</includes>
    <includes id="TestSuite_8h" name="TestSuite.h" local="no" imported="no">embUnit/TestSuite.h</includes>
    <includes id="TestRunner_8h" name="TestRunner.h" local="no" imported="no">embUnit/TestRunner.h</includes>
    <includes id="TestCaller_8h" name="TestCaller.h" local="no" imported="no">embUnit/TestCaller.h</includes>
    <includes id="RepeatedTest_8h" name="RepeatedTest.h" local="no" imported="no">embUnit/RepeatedTest.h</includes>
    <includes id="stdImpl_8h" name="stdImpl.h" local="no" imported="no">embUnit/stdImpl.h</includes>
    <includes id="AssertImpl_8h" name="AssertImpl.h" local="no" imported="no">embUnit/AssertImpl.h</includes>
    <includes id="HelperMacro_8h" name="HelperMacro.h" local="no" imported="no">embUnit/HelperMacro.h</includes>
  </compound>
  <compound kind="file">
    <name>HelperMacro.h</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>HelperMacro_8h</filename>
    <member kind="define">
      <type>#define</type>
      <name>EMB_UNIT_TESTCASE</name>
      <anchorfile>HelperMacro_8h.html</anchorfile>
      <anchor>abf7226e11ddec99f1b695cee8668daf8</anchor>
      <arglist>(ca, name, sup, tdw, run)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>EMB_UNIT_TESTCALLER</name>
      <anchorfile>HelperMacro_8h.html</anchorfile>
      <anchor>ad406aea8e6dd13c9d14b713658f1122e</anchor>
      <arglist>(caller, name, sup, tdw, fixtures)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>EMB_UNIT_REPEATEDTEST</name>
      <anchorfile>HelperMacro_8h.html</anchorfile>
      <anchor>adf691ecd77b7835c79450f5843b27a9f</anchor>
      <arglist>(repeater, test, tmrp)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>EMB_UNIT_RUN</name>
      <anchorfile>HelperMacro_8h.html</anchorfile>
      <anchor>ae0e1faec895b32a0c60654f1049db91c</anchor>
      <arglist>(test)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>RepeatedTest.c</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>RepeatedTest_8c</filename>
    <includes id="Test_8h" name="Test.h" local="yes" imported="no">Test.h</includes>
    <includes id="RepeatedTest_8h" name="RepeatedTest.h" local="yes" imported="no">RepeatedTest.h</includes>
  </compound>
  <compound kind="file">
    <name>RepeatedTest.h</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>RepeatedTest_8h</filename>
    <class kind="struct">__RepeatedTest</class>
  </compound>
  <compound kind="file">
    <name>stdImpl.c</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>stdImpl_8c</filename>
    <includes id="stdImpl_8h" name="stdImpl.h" local="yes" imported="no">stdImpl.h</includes>
  </compound>
  <compound kind="file">
    <name>stdImpl.h</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>stdImpl_8h</filename>
  </compound>
  <compound kind="file">
    <name>Test.h</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>Test_8h</filename>
    <class kind="struct">__TestImplement</class>
    <class kind="struct">__Test</class>
  </compound>
  <compound kind="file">
    <name>TestCaller.c</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>TestCaller_8c</filename>
    <includes id="Test_8h" name="Test.h" local="yes" imported="no">Test.h</includes>
    <includes id="TestCase_8h" name="TestCase.h" local="yes" imported="no">TestCase.h</includes>
    <includes id="TestCaller_8h" name="TestCaller.h" local="yes" imported="no">TestCaller.h</includes>
  </compound>
  <compound kind="file">
    <name>TestCaller.h</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>TestCaller_8h</filename>
    <class kind="struct">__TestFixture</class>
    <class kind="struct">__TestCaller</class>
  </compound>
  <compound kind="file">
    <name>TestCase.c</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>TestCase_8c</filename>
    <includes id="Test_8h" name="Test.h" local="yes" imported="no">Test.h</includes>
    <includes id="TestCase_8h" name="TestCase.h" local="yes" imported="no">TestCase.h</includes>
    <includes id="TestResult_8h" name="TestResult.h" local="yes" imported="no">TestResult.h</includes>
  </compound>
  <compound kind="file">
    <name>TestCase.h</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>TestCase_8h</filename>
    <class kind="struct">__TestCase</class>
  </compound>
  <compound kind="file">
    <name>TestListener.h</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>TestListener_8h</filename>
    <class kind="struct">__TestListnerImplement</class>
    <class kind="struct">__TestListner</class>
  </compound>
  <compound kind="file">
    <name>TestResult.c</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>TestResult_8c</filename>
    <includes id="Test_8h" name="Test.h" local="yes" imported="no">Test.h</includes>
    <includes id="TestListener_8h" name="TestListener.h" local="yes" imported="no">TestListener.h</includes>
    <includes id="TestResult_8h" name="TestResult.h" local="yes" imported="no">TestResult.h</includes>
  </compound>
  <compound kind="file">
    <name>TestResult.h</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>TestResult_8h</filename>
    <class kind="struct">__TestResult</class>
  </compound>
  <compound kind="file">
    <name>TestRunner.c</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>TestRunner_8c</filename>
    <includes id="config_8h" name="config.h" local="yes" imported="no">config.h</includes>
    <includes id="stdImpl_8h" name="stdImpl.h" local="yes" imported="no">stdImpl.h</includes>
    <includes id="Test_8h" name="Test.h" local="yes" imported="no">Test.h</includes>
    <includes id="TestListener_8h" name="TestListener.h" local="yes" imported="no">TestListener.h</includes>
    <includes id="TestResult_8h" name="TestResult.h" local="yes" imported="no">TestResult.h</includes>
    <includes id="TestRunner_8h" name="TestRunner.h" local="yes" imported="no">TestRunner.h</includes>
  </compound>
  <compound kind="file">
    <name>TestRunner.h</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>TestRunner_8h</filename>
  </compound>
  <compound kind="file">
    <name>TestSuite.c</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>TestSuite_8c</filename>
    <includes id="Test_8h" name="Test.h" local="yes" imported="no">Test.h</includes>
    <includes id="TestSuite_8h" name="TestSuite.h" local="yes" imported="no">TestSuite.h</includes>
  </compound>
  <compound kind="file">
    <name>TestSuite.h</name>
    <path>/home/runner/work/EmbeddedUnit/EmbeddedUnit/embUnit/</path>
    <filename>TestSuite_8h</filename>
    <class kind="struct">__TestSuite</class>
  </compound>
  <compound kind="struct">
    <name>__RepeatedTest</name>
    <filename>struct____RepeatedTest.html</filename>
  </compound>
  <compound kind="struct">
    <name>__Test</name>
    <filename>struct____Test.html</filename>
  </compound>
  <compound kind="struct">
    <name>__TestCaller</name>
    <filename>struct____TestCaller.html</filename>
  </compound>
  <compound kind="struct">
    <name>__TestCase</name>
    <filename>struct____TestCase.html</filename>
  </compound>
  <compound kind="struct">
    <name>__TestFixture</name>
    <filename>struct____TestFixture.html</filename>
  </compound>
  <compound kind="struct">
    <name>__TestImplement</name>
    <filename>struct____TestImplement.html</filename>
  </compound>
  <compound kind="struct">
    <name>__TestListner</name>
    <filename>struct____TestListner.html</filename>
  </compound>
  <compound kind="struct">
    <name>__TestListnerImplement</name>
    <filename>struct____TestListnerImplement.html</filename>
  </compound>
  <compound kind="struct">
    <name>__TestResult</name>
    <filename>struct____TestResult.html</filename>
  </compound>
  <compound kind="struct">
    <name>__TestSuite</name>
    <filename>struct____TestSuite.html</filename>
  </compound>
</tagfile>
