// Exercise 1: Which type
// Do not run this program yet. Write what it prints into prediction.txt.
#include <iostream>
#include <string>

template <typename T>
T half(const T& value) {
    return value / 2;
}

template <typename T>
T twice(const T& value) {
    return value + value;
}

int main() {
    int apples = 9;
    double metres = 9.8;
    std::string word = "ha";

    std::cout << half(apples) << '\n';
    std::cout << half(metres) << '\n';
    std::cout << half<double>(apples) << '\n';
    std::cout << half<int>(metres) << '\n';
    std::cout << twice(word) << '\n';
    std::cout << twice(half(apples)) << '\n';
    std::cout << twice(half(metres)) << '\n';
}
