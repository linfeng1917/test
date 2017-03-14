DIR = (shell pwd)
CFLAG += -g 
CC = gcc 
OBJS = %.o
TARGET = $(patsubst %.c,%,$(OBJS)

all:$(OBJS)
	CC -c $(OBJS) $(TARGET)
%.o: %.c
	CC $@ $^

clean :
	rm bin
