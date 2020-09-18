CC = gcc
CFLAGS = -O
LIBS = ../lib
RM = rm
TARGET = samples
OBJS = AllTests.o counter.o testSuiteSample.o testFixtureSample.o repeatTestSample.o person.o personTest.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) -L$(LIBS) -lembUnit

.c.o:
	$(CC) $(CFLAGS) -I.. -I../embUnit -c $<

clean:
	-$(RM) $(TARGET) $(OBJS)

.PHONY: clean all
