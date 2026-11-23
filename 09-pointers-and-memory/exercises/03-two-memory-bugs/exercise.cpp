// Exercise 3: Two memory bugs
// This program should read a count, then that many whole numbers, and print
// the numbers in reverse order. It builds, but it has two memory bugs.
// Build it with the sanitizer, run it, and read the report (see the exercise text).
#include <cstddef>
#include <iostream>

void printReversed(const int* values, std::size_t count) {
    for (std::size_t i = count; i > 0; --i) {
        std::cout << values[i] << ' ';
    }
    std::cout << '\n';
    delete[] values;
}

int main() {
    std::size_t count = 0;
    std::cin >> count;

    int* values = new int[count]{};
    for (std::size_t i = 0; i < count; ++i) {
        std::cin >> values[i];
    }

    printReversed(values, count);
    delete[] values;
}
