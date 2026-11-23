#include <iostream>

int main() {
    const int servicePercent = 15;
    servicePercent = 20;            // a constant cannot get a new value
    std::cout << servicePercent << '\n';
}
