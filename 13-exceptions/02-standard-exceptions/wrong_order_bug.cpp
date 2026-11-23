#include <iostream>
#include <stdexcept>
#include <string>

int main() {
    try {
        int age = std::stoi("abc");
        std::cout << "age " << age << '\n';
    } catch (const std::exception& e) {         // fits every standard exception
        std::cout << "error: " << e.what() << '\n';
    } catch (const std::invalid_argument&) {    // too late: never reached
        std::cout << "not a number\n";
    }
}
