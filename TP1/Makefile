CC = g++
CFLAGS = -g -Wall

all: exe.out

exe.out: main.o liste.o element.o
	$(CC) $(CFLAGS) main.o liste.o element.o -o exe.out

main.o: main.c liste.h element.h
	$(CC) $(CFLAGS) -c main.c

liste.o: liste.c liste.h element.h
	$(CC) $(CFLAGS) -c liste.c

element.o: element.c element.h
	$(CC) $(CFLAGS) -c element.c

clean:
	rm -f *.o

veryclean: clean
	rm -f exe.out

.PHONY: clean veryclean
