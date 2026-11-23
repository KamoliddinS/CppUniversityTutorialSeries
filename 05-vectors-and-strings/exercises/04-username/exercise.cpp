// Exercise 4: Username
// Read a full name (one line) and print a username for it:
// the first letter of the first name, then the last name, all in small letters.
//     Malika Karimova  ->  mkarimova
// A line without a space is a single name. Print it in small letters:
//     Aziz  ->  aziz
#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>

int main() {
    std::string fullName;
    std::getline(std::cin, fullName);

    std::string username;
    // TODO: build the username from fullName.

    std::cout << username << '\n';
}
