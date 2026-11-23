#include <iostream>
#include <string>

template <typename T>
T larger(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::string first = "Samarkand";
    std::string second = "Tashkent";

    std::cout << larger(3, 7) << '\n';            // T is int
    std::cout << larger(2.5, 1.5) << '\n';        // T is double
    std::cout << larger(first, second) << '\n';   // T is std::string
}
