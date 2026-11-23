// Exercise 5: Wrong average
// This program should print the average of three whole numbers.
// It builds and runs, but the answer is wrong. Find the logic error and fix it.
#include <iostream>

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    std::cin >> a >> b >> c;

    int average = a + b + c / 3;
    std::cout << "Average: " << average << '\n';
}
