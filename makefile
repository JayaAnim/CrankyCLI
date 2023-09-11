# Makefile for a C++ project

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -Wextra -g

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

#generates list of files ending with cpp
SRC = $(wildcard $(SRCDIR)/*.cpp)
#finds every file in src directory ending in cpp, and replaces directory path with OBJDIR and extension with .o
OBJ = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))

# Executable name
TARGET = $(BINDIR)/cranky

# Phony targets (targets that are not real files)
.PHONY: all clean

# Default target
all: $(TARGET)

#Links all object files from OBJ list to to target
$(TARGET): $(OBJ) | $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Explicit rules for object files with dependencies
#$(OBJDIR)/example1.o: $(SRCDIR)/example1.cpp $(INCDIR)/example1.hpp $(INCDIR)/example2.hpp $(INCDIR)/example3.hpp | $(OBJDIR)
	#$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

#$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(INCDIR)/example1.hpp | $(OBJDIR)
	#$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/example1.o: $(SRCDIR)/example1.cpp $(INCDIR)/example1.hpp $(INCDIR)/example2.hpp $(INCDIR)/example3.hpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(INCDIR)/example1.hpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Create the output directories if they don't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# Clean rule to remove object files and the executable
clean:
	rm -rf $(OBJDIR) $(BINDIR)






# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Create the output directories if they don't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# Generates list of files ending with cpp
SRC = $(wildcard $(SRCDIR)/*.cpp)
# Finds every file in src directory ending in cpp, and replaces directory path with OBJDIR and extension with .o
OBJ = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))

# Executable name
TARGET = $(BINDIR)/cranky

# Default target
all: $(TARGET)

# Links all object files from OBJ list to to target
$(TARGET): $(OBJ)
	echo "making $(TARGET)"
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule for compiling main.cpp
$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(INCDIR)/globals.hpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/cli.o: $(SRCDIR)/cli.o $(INCDIR)/cli.hpp $(INCDIR)/globals.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


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

$(BINDIR)/cranky: $(OBJDIR)/main.o $(OBJDIR)/cranky.o
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(INCDIR)/cranky.hpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/cranky.o: $(SRCDIR)/cranky.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJDIR)/*o
