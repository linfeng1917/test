CC := gcc 
CFLAG := -g -Wall 
TARGET := log
OBJS := log.o

all:$(TARGET)
$(TARGET):$(OBJS)
	$(CC) $(CFLAG) -o $@ $^

.PHONY:clean
clean:
	rm $(TARGET) *.o core -f
