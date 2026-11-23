#include <cstddef>
#include <iostream>

int sum(int values[], std::size_t size) {       // values is really an int*
    int total = 0;
    for (std::size_t i = 0; i < size; ++i) {
        total += values[i];
    }
    return total;
}

int main() {
    const std::size_t size = 4;
    int prices[size] = {500, 700, 900, 1200};
    std::cout << "Sum: " << sum(prices, size) << '\n';

    int* end = prices + size;                   // one past the last element
    for (int* p = prices; p != end; ++p) {
        std::cout << *p << ' ';
    }
    std::cout << '\n';
    std::cout << "Elements: " << end - prices << '\n';
}
