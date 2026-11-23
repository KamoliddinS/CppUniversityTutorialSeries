#include <iostream>

int nextNumber() {
    static int number = 0;
    number += 10;
    return number;
}

int main() {
    int number = 1;
    for (int i = 0; i < 2; ++i) {
        int number = nextNumber();
        std::cout << number << ' ';
    }
    std::cout << number << '\n';
}
