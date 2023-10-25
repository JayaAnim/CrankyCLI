# Makefile for a C project

# Compiler and compiler flags
CC = gcc
CFLAGS = -g -Wall 


all: cranky clean

cranky: main.o HashNode.o HashMap.o
	$(CC) $(CFLAGS) $^ -o $@

main.o: main.c HashNode.h HashMap.h
	$(CC) $(CFLAGS) -c $< -o $@

HashNode.o: HashNode.c HashNode.h
	$(CC) $(CFLAGS) -c $< -o $@

HashMap.o: HashMap.c HashMap.h HashNode.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

