#include <cctype>
#include <iostream>
#include <string>

int main() {
    std::cout << "Type a line: ";
    std::string line;
    std::getline(std::cin, line);

    int letters = 0;
    int spaces = 0;
    int digitSum = 0;
    for (unsigned char c : line) {      // unsigned char: see Watch out
        if (std::isalpha(c)) {
            ++letters;
        } else if (std::isspace(c)) {
            ++spaces;
        } else if (std::isdigit(c)) {
            digitSum += c - '0';        // '7' - '0' is the number 7
        }
    }
    std::cout << letters << " letters, " << spaces << " spaces, digit sum " << digitSum << '\n';
}
