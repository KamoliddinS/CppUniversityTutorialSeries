#include <iostream>

int main() {
    int age = 19;

    bool adult = age >= 18;                     // a comparison gives true or false
    bool teenager = age >= 13 && age <= 19;     // both sides must be true
    bool freeEntry = age < 7 || age >= 65;      // one true side is enough
    bool mustPay = !freeEntry;                  // the opposite

    std::cout << std::boolalpha;                // print true/false instead of 1/0
    std::cout << "adult:      " << adult << '\n';
    std::cout << "teenager:   " << teenager << '\n';
    std::cout << "free entry: " << freeEntry << '\n';
    std::cout << "must pay:   " << mustPay << '\n';
}
