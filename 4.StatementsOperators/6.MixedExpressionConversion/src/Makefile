# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = mixed_expression
SOURCES = main.cpp 

# Default rule
all: $(TARGET)

# Rule to build the target
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

# Rule to clean the build artifacts
clean:
	rm -f $(TARGET)
