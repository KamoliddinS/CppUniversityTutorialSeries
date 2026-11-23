#include <format>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    double mark = 0.0;
};

int main() {
    std::vector<Student> group = {{"Aziz", 85.5}, {"Dilnoza", 92.375}, {"Jasur", 100.0}};

    std::cout << std::format("{:<10}{:>6}\n", "Name", "Mark");
    std::cout << std::format("{:-<16}\n", "");    // an empty text, 16 wide, filled with -
    for (const Student& s : group) {
        std::cout << std::format("{:<10}{:>6.1f}\n", s.name, s.mark);
    }
}
