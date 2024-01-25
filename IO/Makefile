
CC = clang
CFLAGS = -Wall -O2 -m64 -g -O0

OBJS = main.o lshIO.o 

main: $(OBJS)
	$(CC) $(CFLAGS) -o main $(OBJS)

main.o: main.c lshIO.h

lshIO.o: lshIO.h

clean:
	rm -rf *.o main