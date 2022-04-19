
TARGET = run
CC = gcc
CFLAGS = -ansi -pedantic -g 
OBJS = executor.o  main.o task.o time.o 

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)  -L. -lgenDS
	
executor.o: executor.c executor.h heap.h task.h
	$(CC) $(CFLAGS) -c executor.c
	
task.o: task.c task.h time.h
	$(CC) $(CFLAGS) -c task.c
	
time.o: time.c time.h task.h
	$(CC) $(CFLAGS) -c time.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c
		
clean:
	rm -f $(TARGET) $(OBJS)
