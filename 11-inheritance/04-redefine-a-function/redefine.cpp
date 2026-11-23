#include <iostream>
#include <string>

class Person {
public:
    explicit Person(const std::string& name) : name_(name) {}
    void describe() const { std::cout << "Name: " << name_ << '\n'; }

private:
    std::string name_;
};

class Student : public Person {
public:
    Student(const std::string& name, int id) : Person(name), id_(id) {}
    void describe() const {             // the same name as in Person
        Person::describe();             // call the original
        std::cout << "Student id: " << id_ << '\n';
    }

private:
    int id_ = 0;
};

int main() {
    Student malika("Malika", 1042);
    malika.describe();
}
