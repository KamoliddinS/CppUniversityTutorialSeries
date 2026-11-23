#include <iostream>
#include <stdexcept>

int half(int number) noexcept {     // promise: no exception leaves this function
    if (number % 2 != 0) {
        throw std::runtime_error("odd number");     // breaks the promise
    }
    return number / 2;
}

int main() {
    try {
        std::cout << half(7) << '\n';
    } catch (const std::runtime_error& e) {
        std::cout << "caught: " << e.what() << '\n';    // never reached
    }
}
