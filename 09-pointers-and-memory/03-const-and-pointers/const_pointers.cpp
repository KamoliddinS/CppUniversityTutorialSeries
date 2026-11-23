#include <iostream>

int main() {
    int price = 500;
    int other = 900;

    const int* look = &price;       // pointer to const: look can only read
    price = 550;                    // fine: price itself is not const
    std::cout << *look << '\n';
    look = &other;                  // fine: look may point elsewhere
    std::cout << *look << '\n';

    int* const fixed = &price;      // const pointer: fixed always points to price
    *fixed = 600;                   // fine: the value may change
    std::cout << price << '\n';
}
