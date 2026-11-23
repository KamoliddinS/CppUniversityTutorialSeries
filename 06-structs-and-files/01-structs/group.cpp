#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int age = 0;
    double grade = 0.0;
};

void print(const Student& student) {
    std::cout << student.name << " (" << student.age << "): " << student.grade << '\n';
}

int main() {
    std::vector<Student> group = {{"Malika", 19, 4.8}, {"Aziz", 20, 4.5}};
    group.push_back({"Jasur", 18, 3.9});

    for (const Student& student : group) {
        print(student);
    }
    std::cout << "First in the list: " << group[0].name << '\n';
}
