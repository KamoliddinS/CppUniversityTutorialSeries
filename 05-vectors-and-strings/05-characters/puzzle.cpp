#include <cctype>
#include <iostream>
#include <string>

int main() {
    std::string code = "ab12";
    std::string letters;
    int sum = 0;
    for (unsigned char c : code) {
        if (std::isdigit(c)) {
            sum += c - '0';
        } else {
            letters += static_cast<char>(std::toupper(c));
        }
    }
    std::cout << letters << ' ' << sum << '\n';
}
