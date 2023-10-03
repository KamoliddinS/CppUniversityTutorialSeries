# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = gradebook_manager
SOURCES = main.cpp Student.cpp

# Default rule
all: $(TARGET)

# Rule to build the target
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

# Rule to clean the build artifacts
clean:
	rm -f $(TARGET)
