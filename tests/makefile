CC = gcc
CFLAGS = -O
LDFLAGS =
INCLUDES = -I..
LIBS = -L../embUnit/
RM = rm
TARGET = embUnitTest
OBJS = AllTests.o RepeatedTestTest.o assertTest.o stdImplTest.o TestCallerTest.o TestCaseTest.o TestResultTest.o MockTestCase.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lembUnit

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

clean:
	-$(RM) $(TARGET) $(OBJS)

.PHONY: clean all
