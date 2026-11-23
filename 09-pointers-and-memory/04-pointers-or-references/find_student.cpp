#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int grade = 0;
};

// There is always a group: a reference. There may be no such student: a pointer.
Student* findStudent(std::vector<Student>& group, const std::string& name) {
    for (Student& student : group) {
        if (student.name == name) {
            return &student;
        }
    }
    return nullptr;
}

int main() {
    std::vector<Student> group = {{"Aziz", 78}, {"Malika", 91}};

    Student* found = findStudent(group, "Malika");
    if (found != nullptr) {
        found->grade += 5;              // the same as (*found).grade += 5
        std::cout << found->name << ": " << found->grade << '\n';
    }
    if (findStudent(group, "Jasur") == nullptr) {
        std::cout << "Jasur: not found\n";
    }
}
