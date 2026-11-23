#include <cstddef>
#include <iostream>

// Returns an array of count squares. The caller owns it and must delete[] it.
int* makeSquares(std::size_t count) {
    int* squares = new int[count]{};        // count ints on the heap, all 0
    int number = 0;
    for (std::size_t i = 0; i < count; ++i) {
        squares[i] = number * number;
        ++number;
    }
    return squares;                         // the array lives on after this function
}

int main() {
    std::cout << "How many squares? ";
    std::size_t count = 0;
    std::cin >> count;
    if (count > 20) {
        count = 20;                         // keeps the example small
    }

    int* squares = makeSquares(count);
    for (std::size_t i = 0; i < count; ++i) {
        std::cout << squares[i] << ' ';
    }
    std::cout << '\n';

    delete[] squares;                       // new[] pairs with delete[]
}
