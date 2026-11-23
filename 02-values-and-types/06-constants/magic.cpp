#include <iostream>

int main() {
    int bill = 250000;
    std::cout << "Service: " << bill * 15 / 100 << " so'm\n";
    std::cout << "To pay:  " << bill + bill * 15 / 100 << " so'm\n";
}
