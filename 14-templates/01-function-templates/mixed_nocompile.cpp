#include <iostream>

template <typename T>
T larger(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << larger(1, 2.5) << '\n';   // is T int or double?
}
