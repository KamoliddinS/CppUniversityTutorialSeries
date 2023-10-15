// main.cpp

#include <iostream> // For input-output stream operations

// Function Prototypes with Default Argument Values
void greet(std::string name = "Guest");
void displayBox(int width = 10, int height = 5);
double calculateVolume(double length, double breadth = 5.0, double height = 10.0);

int main() {
    // Introduction
    std::cout << "Exploring Default Argument Values in C++\n" << std::endl;

    // Demonstration: Basic Default Argument
    greet();          // Uses default name "Guest"
    greet("Alice");   // Uses provided name "Alice"

    // Demonstration: Multiple Default Arguments
    displayBox();           // Uses default width 10 and height 5
    displayBox(15);         // Uses provided width 15 and default height 5
    displayBox(15, 10);     // Uses provided width 15 and height 10

    // Demonstration: Default Arguments in Middle of Parameter List
    double volume = calculateVolume(5.0);
    std::cout << "Volume of the box: " << volume << " units^3" << std::endl;

    return 0;
}

// Function Definitions
void greet(std::string name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

void displayBox(int width, int height) {
    std::cout << "Displaying a box of width " << width << " and height " << height << std::endl;
}

double calculateVolume(double length, double breadth, double height) {
    return length * breadth * height;
}

