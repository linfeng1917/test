CC := gcc
TARGET := gethardware 
TARGET += mystrstr 
OBJS := GetHardware.o mystrstr.o
CFLAG :=  -Wall -g
RM := rm

all:$(TARGET)
$(TARGET):$(OBJS)
	$(CC) $(CFLAG) $< -o $@ 

.PHONY:clean
clean:
	@$(RM) $(TARGET) *.o core -f
