#include <iostream>

class Person {
public:
    void greet() const { std::cout << "Salom!\n"; }
};

class Student : public Person {     // a Student IS a Person
public:
    void study() const { std::cout << "Student studies\n"; }
};

int main() {
    Student malika;
    malika.greet();     // comes from Person
    malika.study();     // added by Student
}
