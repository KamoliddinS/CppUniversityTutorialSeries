#include <iostream>
#include <string>

class Person {
public:
    explicit Person(const std::string& name) : name_(name) {}
    const std::string& name() const { return name_; }

private:
    std::string name_;
};

class Student : public Person {
public:
    explicit Student(int id) : id_(id) {}       // no base constructor is named

private:
    int id_ = 0;
};

int main() {
    Student malika(1042);
    std::cout << malika.name() << '\n';
}
