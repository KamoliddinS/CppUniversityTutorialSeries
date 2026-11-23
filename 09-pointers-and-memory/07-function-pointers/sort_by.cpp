#include <cstddef>
#include <iostream>
#include <vector>

using Compare = bool (*)(int, int);     // a pointer to a function that compares two ints

bool smallerFirst(int a, int b) {
    return a < b;
}

bool largerFirst(int a, int b) {
    return a > b;
}

// Sorts values. comesFirst(a, b) says whether a must stand before b.
void sortBy(std::vector<int>& values, Compare comesFirst) {
    for (std::size_t i = 0; i < values.size(); ++i) {
        for (std::size_t j = i + 1; j < values.size(); ++j) {
            if (comesFirst(values[j], values[i])) {
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
}

void print(const std::vector<int>& values) {
    for (int value : values) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> numbers = {35, 12, 48, 21};
    sortBy(numbers, smallerFirst);
    print(numbers);
    sortBy(numbers, largerFirst);
    print(numbers);
}
