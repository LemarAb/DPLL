# Compiler and flags
# g++ src/*.cpp  -o main -std=c++11 -Wall -Wno-sign-compare -Wno-format -g -O3 //--Manual run
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wno-sign-compare -Wno-format -g -O3 

# Directories
SRCDIR = src
INCDIR = include
BINDIR = .

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
SELECTED_SOURCES =  $(wildcard $(SRCDIR)/main.cpp) $(wildcard $(SRCDIR)/parseDIMACS.cpp)
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = main

# Build target
all: $(EXECUTABLE)

# Rule to create executable
$(EXECUTABLE): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $^
	
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	del main.exe

run: $(EXECUTABLE) 
	$(EXECUTABLE) $(arg) $(heur=0)

