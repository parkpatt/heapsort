CFLAGS = -Wall

all: heapSort printArray.o

heapSort: heapsort.c printArray.o
	gcc $(CFLAGS) -o $(@) $(^)

printArray.o: printArray.c printArray.h
	gcc $(CFLAGS) -c printArray.c

.PHONY: clean

clean:
	rm *.o *~ heapSort

