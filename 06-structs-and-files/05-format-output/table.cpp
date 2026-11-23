#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    double mark = 0.0;
};

int main() {
    std::vector<Student> group = {{"Aziz", 85.5}, {"Dilnoza", 92.375}, {"Jasur", 100.0}};

    std::cout << std::fixed << std::setprecision(1);    // for every number from here on

    std::cout << std::left << std::setw(10) << "Name"
              << std::right << std::setw(6) << "Mark" << '\n';
    std::cout << std::setfill('-') << std::setw(16) << "" << std::setfill(' ') << '\n';
    for (const Student& s : group) {
        std::cout << std::left << std::setw(10) << s.name
                  << std::right << std::setw(6) << s.mark << '\n';
    }
}
