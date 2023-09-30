# Makefile for a C project

# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11

SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

all: $(BINDIR) $(OBJDIR) $(BINDIR)/cranky clean

$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR)/cranky: $(OBJDIR)/main.o $(OBJDIR)/HashNode.o $(OBJDIR)/HashMap.o
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/HashNode.h $(INCDIR)/HashMap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/HashNode.o: $(SRCDIR)/HashNode.c $(INCDIR)/HashNode.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/HashMap.o: $(SRCDIR)/HashMap.c $(INCDIR)/HashMap.h $(INCDIR)/HashNode.h
	$(CC) $(CFLAGS) -c $< -o $@

#$(BINDIR)/cranky: $(OBJDIR)/main.o $(OBJDIR)/OptNode.o $(OBJDIR)/NameNode.o $(OBJDIR)/NameSpace.o
#	$(CC) $(CFLAGS) $^ -o $@

#$(OBJDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/OptNode.h $(INCDIR)/HashNode.h $(INCDIR)/HashMap.h $(INCDIR)/NameSpace.h
#	$(CC) $(CFLAGS) -c $< -o $@

#$(OBJDIR)/OptNode.o: $(SRCDIR)/OptNode.c $(INCDIR)/OptNode.h
#	$(CC) $(CFLAGS) -c $< -o $@

#$(OBJDIR)/NameNode.o: $(SRCDIR)/NameNode.c $(INCDIR)/NameNode.h
#	$(CC) $(CFLAGS) -c $< -o $@

#$(OBJDIR)/NameSpace.o: $(SRCDIR)/NameSpace.c $(INCDIR)/NameSpace.h $(INCDIR)/NameNode.h
#	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*.o

