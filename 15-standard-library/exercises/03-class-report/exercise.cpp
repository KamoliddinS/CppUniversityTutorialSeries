// Exercise 3: Class report
// Complete the three TODO parts. Each one needs an algorithm and a lambda.
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
        {"Jasur", 58}, {"Nodira", 95}, {"Dilnoza", 72},
        {"Malika", 95}, {"Laziz", 41}, {"Aziz", 72},
    };
    int passMark = 0;
    std::cin >> passMark;

    // TODO 1: sort the group with std::sort: the highest score first;
    //         students with the same score in alphabetical order.

    for (const Student& student : group) {
        std::cout << student.name << ' ' << student.score << '\n';
    }

    // TODO 2: count the students whose score is at least passMark (std::count_if).
    int passed = 0;
    std::cout << "passed: " << passed << '\n';

    // TODO 3: find the first student in the sorted group whose score is below passMark
    //         (std::find_if). Print "first below: " and the name,
    //         or "nobody below" when there is no such student.
    std::cout << "first below: TODO\n";
}
