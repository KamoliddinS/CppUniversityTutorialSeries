#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int age = 0;
    double grade = 0.0;
};

int main() {
    std::ifstream in("students.csv");
    if (!in) {
        std::cout << "Cannot open students.csv\n";
        return 1;
    }

    std::vector<Student> students;
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream fields(line);
        Student student;
        std::string ageText;
        std::string gradeText;
        std::getline(fields, student.name, ',');
        std::getline(fields, ageText, ',');
        std::getline(fields, gradeText);
        if (fields) {                           // all three reads worked
            student.age = std::stoi(ageText);
            student.grade = std::stod(gradeText);
            students.push_back(student);
        } else {
            std::cout << "Skipped: " << line << '\n';
        }
    }

    for (const Student& s : students) {
        std::cout << s.name << ", " << s.age << ", grade " << s.grade << '\n';
    }
}
