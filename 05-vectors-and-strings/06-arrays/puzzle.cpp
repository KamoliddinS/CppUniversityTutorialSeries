#include <array>
#include <iostream>

int main() {
    std::array<int, 4> numbers = {5, 6};
    std::cout << numbers.size() << ' ' << numbers[1] << ' ' << numbers[3] << '\n';
}
