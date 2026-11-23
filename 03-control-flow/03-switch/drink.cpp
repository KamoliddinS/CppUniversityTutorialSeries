#include <iostream>

int main() {
    std::cout << "Tea or coffee (t/c)? ";
    char drink = ' ';
    std::cin >> drink;

    switch (drink) {
    case 't':
    case 'T':                           // two labels share one block
        std::cout << "Tea costs 5000 so'm.\n";
        break;
    case 'c':
    case 'C':
        std::cout << "Coffee costs 15000 so'm.\n";
        break;
    default:
        std::cout << "We do not sell that.\n";
        break;
    }
}
