#include <iostream>
#include <string>

class Person {
public:
    explicit Person(const std::string& name) : name_(name) {
        std::cout << "Person(" << name_ << ")\n";
    }
    const std::string& name() const { return name_; }

private:
    std::string name_;
};

class Student : virtual public Person {
public:
    explicit Student(const std::string& name) : Person(name) {}
};

class Employee : virtual public Person {
public:
    explicit Employee(const std::string& name) : Person(name) {}
};

class TeachingAssistant : public Student, public Employee {
public:
    explicit TeachingAssistant(const std::string& name)
        : Person(name), Student(name), Employee(name) {}    // builds the shared Person part
};

int main() {
    TeachingAssistant aziz("Aziz");
    std::cout << aziz.name() << '\n';
}
