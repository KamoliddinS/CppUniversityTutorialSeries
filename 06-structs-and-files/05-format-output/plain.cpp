#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    double mark = 0.0;
};

int main() {
    std::vector<Student> group = {{"Aziz", 85.5}, {"Dilnoza", 92.375}, {"Jasur", 100.0}};

    for (const Student& s : group) {
        std::cout << s.name << ' ' << s.mark << '\n';
    }
}
