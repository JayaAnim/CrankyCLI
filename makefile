# Makefile for a C++ project

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -Wextra -g -std=c++11

SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

all: $(BINDIR) $(OBJDIR) $(BINDIR)/cranky clean

$(BINDIR):
	mkdir -p $(BINDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR)/cranky: $(OBJDIR)/main.o $(OBJDIR)/OptNode.o
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(INCDIR)/OptNode.h $(INCDIR)/HashNode.h $(INCDIR)/HashMap.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/OptNode.o: $(SRCDIR)/OptNode.cpp $(INCDIR)/OptNode.h
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJDIR)/*o
