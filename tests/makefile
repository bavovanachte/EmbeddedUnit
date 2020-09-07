CC = gcc
CFLAGS = -O
LDFLAGS =
LIBS = ../lib
RM = rm
TARGET = embUnitTest
OBJS = AllTests.o RepeatedTestTest.o assertTest.o stdImplTest.o TestCallerTest.o TestCaseTest.o TestResultTest.o MockTestCase.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) -L$(LIBS) -lembUnit

.c.o:
	$(CC) $(CFLAGS) -I.. -I../embUnit -c $<

clean:
	-$(RM) $(TARGET) $(OBJS)

.PHONY: clean all
