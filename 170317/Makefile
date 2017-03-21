CC := gcc 
CFLAG := -g -Wall 
SOURCR := $(wildcard *.c)
TARGET := $(patsubst %.c,%,$(SOURCR))

all:$(TARGET)
.c:
	$(CC) $(CFLAG) -o $@ $^

.PHONY:clean
clean:
	@rm $(TARGET)  -f
