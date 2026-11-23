#include <iostream>

int main() {
    for (int i = 1; i <= 3; ++i) {
        int square = i * i;
        std::cout << square << '\n';
    }
    std::cout << "last: " << square << '\n';
}
