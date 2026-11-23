// Exercise 3: Guest list
// This program should read a number, then that many full names (one per line),
// and print the names as a numbered list. It builds, but it has three bugs.
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

void readGuests(std::vector<std::string> guests, int count) {
    for (int i = 0; i < count; ++i) {
        std::string name;
        std::getline(std::cin, name);
        guests.push_back(name);
    }
}

int main() {
    int count = 0;
    std::cin >> count;

    std::vector<std::string> guests;
    readGuests(guests, count);

    std::cout << "Guests: " << guests.size() << '\n';
    for (std::size_t i = 0; i <= guests.size(); ++i) {
        std::cout << i + 1 << ". " << guests.at(i) << '\n';
    }
}
