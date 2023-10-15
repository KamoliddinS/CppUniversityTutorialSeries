// main.cpp

#include <iostream>   // For input-output stream operations
#include <vector>     // For vector operations

// Struct Definition
struct Point {
    int x, y;
    
    // A method to display the point
    void display() {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

// Function Prototypes
void processVector(std::vector<int> vec);
void modifyVector(std::vector<int>& vec);
void displayPoint(Point p);
void modifyPoint(Point& p);

int main() {
    // Introduction
    std::cout << "Demonstrating Passing Vectors and Structs to Functions in C++\n" << std::endl;

    // Working with Vectors
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    std::cout << "Original Vector: ";
    processVector(numbers);  // By value

    modifyVector(numbers);   // By reference
    std::cout << "Modified Vector: ";
    processVector(numbers);  // By value
    
    // Working with Structs
    Point p = {5, 10};
    
    std::cout << "\nOriginal Point: ";
    p.display();

    modifyPoint(p);   // By reference
    std::cout << "Modified Point: ";
    p.display();

    return 0;
}

// Function Definitions
void processVector(std::vector<int> vec) {
    for(int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void modifyVector(std::vector<int>& vec) {
    for(int& num : vec) {
        num *= 2;  // Double each number
    }
}

void displayPoint(Point p) {
    p.display();
}

void modifyPoint(Point& p) {
    p.x *= 2;  // Double the x-coordinate
    p.y *= 3;  // Triple the y-coordinate
}

