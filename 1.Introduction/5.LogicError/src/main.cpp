#include <iostream>

int main() {
    int x, y;
    std::cout << "Enter two numbers to find the average: ";
    std::cin >> x >> y;

    // Intended to calculate the average of x and y
    int average = x + y / 2;  // Logic error here

    std::cout << "The average of " << x << " and " << y << " is: " << average << std::endl;
    return 0;
}

// The line int average = x + y / 2; is intended to calculate the average of x and y.
// However, due to the order of operations, it first divides y by 2 and then adds x to the result. 
// The correct calculation for the average should be (x + y) / 2.
