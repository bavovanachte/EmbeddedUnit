CC = gcc
CFLAGS = -O
AR = ar
ARFLAGS = ru
RANLIB = ranlib
RM = rm
OUTPUT = .
TARGET = libembUnit.a
OBJS = AssertImpl.o RepeatedTest.o stdImpl.o TestCaller.o TestCase.o TestResult.o TestRunner.o TestSuite.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $(OUTPUT)$@ $(OBJS)
	$(RANLIB) $(OUTPUT)$@

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

AssertImpl.o: AssertImpl.h stdImpl.h
RepeatedTest.o: RepeatedTest.h Test.h
stdImpl.o: stdImpl.h
TestCaller.o: TestCaller.h TestResult.h TestCase.h Test.h
TestCase.o: TestCase.h TestResult.h Test.h
TestResult.o: TestResult.h Test.h TestListener.h
TestRunner.o: TestRunner.h TestResult.h Test.h TestListener.h
TestSuite.o: TestSuite.h TestResult.h Test.h

clean:
	-$(RM) $(OBJS) $(TARGET)

.PHONY: clean all
