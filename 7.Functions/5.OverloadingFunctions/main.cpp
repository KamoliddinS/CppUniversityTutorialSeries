#include <iostream>

// Function prototype for adding integers
int add(int a, int b);

// Function prototype for adding doubles
double add(double a, double b);

int main() {
    // Call the overloaded add functions
    int sum_int = add(5, 3);
    double sum_double = add(2.5, 3.7);

    // Display the results
    std::cout << "Sum of integers: " << sum_int << std::endl;
    std::cout << "Sum of doubles: " << sum_double << std::endl;

    return 0;
}

// Function definition for adding integers
int add(int a, int b) {
    return a + b;
}

// Function definition for adding doubles
double add(double a, double b) {
    return a + b;
}
