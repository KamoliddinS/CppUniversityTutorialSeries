#include <iostream>

class Student {
public:
    int id() const { return 1042; }     // student id
};

class Employee {
public:
    int id() const { return 77; }       // staff id
};

class TeachingAssistant : public Student, public Employee {};

int main() {
    TeachingAssistant aziz;
    std::cout << aziz.id() << '\n';
}
