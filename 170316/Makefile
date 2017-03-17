CC := gcc 
CFLAG := -g 
SOURCE := $(wildcard *.c)
TARGET := $(patsubst %.c,%,$(SOURCE))

all:$(TARGET)
#####.c:
$(TARGET):$(SOURCE)
	$(CC) $(CFLAG) -o $@ $<

.PHONY:clean
clean:
	@rm $(TARGET) core -f
