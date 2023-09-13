
# Variables
CXX = g++
CXXFLAGS = -o2
TARGET = fibonacci
SOURCES = main.cpp

# Default rule
all: $(TARGET)

# Rule to build the target
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

# Rule to clean the build artifacts
clean:
	rm -f $(TARGET)

libfibonacci.so: 
	$(CXX) $(CXXFLAGS) -shared -fPIC -o libfibonacci.so fibonacci_lib.cpp

