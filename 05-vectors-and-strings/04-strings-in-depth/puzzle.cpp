#include <iostream>
#include <string>

int main() {
    std::string first = "bukhara";
    std::string second = "Samarkand";

    if (first < second) {
        std::cout << first << " comes first\n";
    } else {
        std::cout << second << " comes first\n";
    }
    if (first == "Bukhara") {
        std::cout << "same\n";
    } else {
        std::cout << "different\n";
    }
}
