#include <iostream>

int main() {
    constexpr int secret = 1234;
    int pin = 0;
    int tries = 0;

    do {
        std::cout << "PIN: ";
        std::cin >> pin;
        tries = tries + 1;
    } while (pin != secret && tries < 3);       // tested after every round

    if (pin == secret) {
        std::cout << "Welcome!\n";
    } else {
        std::cout << "Card blocked.\n";
    }
}
