#include <iostream>
#include <string>

class Person {
public:
    explicit Person(const std::string& name) : name_(name) {
        std::cout << "Person(" << name_ << ")\n";
    }
    ~Person() { std::cout << "~Person(" << name_ << ")\n"; }

private:
    std::string name_;
};

class Laptop {
public:
    Laptop() { std::cout << "Laptop()\n"; }
    ~Laptop() { std::cout << "~Laptop()\n"; }
};

class Student : public Person {
public:
    Student(const std::string& name, int id) : Person(name), id_(id) {
        std::cout << "Student(" << id_ << ")\n";
    }
    ~Student() { std::cout << "~Student(" << id_ << ")\n"; }

private:
    Laptop laptop_;
    int id_ = 0;
};

int main() {
    Student malika("Malika", 1042);
    std::cout << "--- end of main ---\n";
}
