PATH_SOURCE = ../../src
PATH_TEST = ../../test/cstack
PATH_HEADER = ../../inc

TARGET = stack.out
CC = g++
CFLAGS = -ansi -pedantic -g
OBJS = cstack.o cstackTest.o 

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) 

cstack.o:$(PATH_SOURCE)/cstack.c $(PATH_HEADER)/cstack.h 
	$(CC) $(CFLAGS) -c -I$(PATH_HEADER) $(PATH_SOURCE)/cstack.c 

cstackTest.o:$(PATH_TEST)/cstackTest.c $(PATH_HEADER)/cstack.h $(PATH_HEADER)/mu_test.h
	$(CC) $(CFLAGS) -c -I$(PATH_HEADER) -I$(PATH_HEADER) $(PATH_TEST)/cstackTest.c

check: $(TARGET)
	./$(TARGET) -v
	
clean:
	@$(RM) $(TARGET) $(OBJS)
	
.PHONY: chack clean
