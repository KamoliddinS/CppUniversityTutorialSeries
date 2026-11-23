#include <iostream>

int main() {
    int first = 80;
    int second = 91;
    double average = static_cast<double>(first + second) / 2;
    std::cout << "Average: " << average << '\n';
}
