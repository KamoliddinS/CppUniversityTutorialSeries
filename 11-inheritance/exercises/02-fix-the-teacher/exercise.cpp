// Exercise 2: Fix the teacher
// This file does not compile yet. Fixing it is the exercise.
// Change only the class Teacher. Leave Person and main as they are.
#include <iostream>
#include <string>

class Person {
public:
    explicit Person(const std::string& name) : name_(name) {}
    const std::string& name() const { return name_; }

private:
    std::string name_;
};

class Teacher : Person {
public:
    Teacher(const std::string& name, const std::string& subject) : subject_(subject) {}

    void print() const { std::cout << name_ << " teaches " << subject_ << '\n'; }

private:
    std::string subject_;
};

int main() {
    Teacher aziz("Aziz", "Algorithms");
    aziz.print();
    std::cout << "Name: " << aziz.name() << '\n';
}
