#include <cctype>
#include <iostream>
#include <string>

int main() {
    unsigned char letter = 'm';
    std::cout << std::toupper(letter) << '\n';                        // an int: prints a number
    std::cout << static_cast<char>(std::toupper(letter)) << '\n';     // a char again

    std::string name = "mALIKA";
    std::string fixed;                                                // starts empty
    for (unsigned char c : name) {
        if (fixed.empty()) {
            fixed += static_cast<char>(std::toupper(c));              // the first letter
        } else {
            fixed += static_cast<char>(std::tolower(c));              // all the others
        }
    }
    std::cout << fixed << '\n';
}
