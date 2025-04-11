# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Target executable
TARGET = matrix

# Source files
SRCS = main.cpp

# Header file
HEADERS = matrix.hpp

# Default target
all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean build files
clean:
	rm -f $(TARGET)
