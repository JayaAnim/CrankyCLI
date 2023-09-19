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

$(BINDIR)/cranky: $(OBJDIR)/main.o $(OBJDIR)/ArgNode.o $(OBJDIR)/OptNode.o $(OBJDIR)/FlagNode.o
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(OBJDIR)/ArgNode.o $(OBJDIR)/OptNode.o $(OBJDIR)/FlagNode.o 
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/ArgNode.o: $(SRCDIR)/ArgNode.cpp $(INCDIR)/ArgNode.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/OptNode.o: $(SRCDIR)/OptNode.cpp $(INCDIR)/OptNode.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/FlagNode.o: $(SRCDIR)/FlagNode.cpp $(INCDIR)/FlagNode.h
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJDIR)/*o
