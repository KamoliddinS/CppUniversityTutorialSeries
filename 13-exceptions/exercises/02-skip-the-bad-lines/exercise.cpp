// Exercise 2: Skip the bad lines
// Every input line should be a whole number. The program adds up the good lines,
// reports each bad line, and prints the total at the end.
// It builds, but it has two bugs. Find and fix them.
#include <iostream>
#include <stdexcept>
#include <string>

int main() {
    int total = 0;
    std::string line;
    try {
        while (std::getline(std::cin, line)) {
            total += std::stoi(line);
        }
    } catch (const std::exception&) {
        std::cout << "not a number: " << line << '\n';
    } catch (const std::out_of_range&) {
        std::cout << "too large: " << line << '\n';
    }
    std::cout << "Total: " << total << '\n';
}
