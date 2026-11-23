#include <iostream>

int* makeNumber() {
    int number = 42;
    return &number;         // number disappears when the function ends
}

int main() {
    int* p = makeNumber();
    std::cout << *p << '\n';
}
