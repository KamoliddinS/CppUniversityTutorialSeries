#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int score = 0;
};

int main() {
    std::vector<Student> group = {
        {"Aziz", 72}, {"Malika", 95}, {"Jasur", 58}, {"Nodira", 90},
    };

    // The lambda answers one question: does a come before b?
    std::sort(group.begin(), group.end(),
              [](const Student& a, const Student& b) { return a.score > b.score; });
    for (const Student& student : group) {
        std::cout << student.name << ' ' << student.score << '\n';
    }

    // The ranges form takes the container itself and the same kind of lambda.
    std::ranges::sort(group,
                      [](const Student& a, const Student& b) { return a.name < b.name; });
    std::cout << "first by name: " << group[0].name << '\n';
}
