CC = gcc
CFLAGS = -O
INCLUDES = -I..
LIBS = -L../embUnit/
RM = rm
TARGET = samples
OBJS = AllTests.o counter.o counterTest.o person.o personTest.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lembUnit

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

clean:
	-$(RM) $(TARGET) $(OBJS)

.PHONY: clean all
