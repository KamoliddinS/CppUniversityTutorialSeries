#include <iostream>
#include <stdexcept>
#include <string>

int total(const std::string& a, const std::string& b) {
    return std::stoi(a) + std::stoi(b);     // std::stoi throws when the text is not a number
}

int main() {
    try {
        std::cout << "40 + 2 = " << total("40", "2") << '\n';
        std::cout << "40 + two = " << total("40", "two") << '\n';
    } catch (const std::invalid_argument&) {
        std::cout << "not a number\n";
    }
}
