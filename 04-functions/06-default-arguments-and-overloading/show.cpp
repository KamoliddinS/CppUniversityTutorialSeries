#include <iostream>

void show(int number, int times = 2) {
    for (int i = 0; i < times; ++i) {
        std::cout << number << ' ';
    }
    std::cout << '\n';
}

void show(double number) {
    std::cout << "decimal " << number << '\n';
}

int main() {
    show(7);
    show(7, 3);
    show(7.5);
    show(1 + 2);
}
