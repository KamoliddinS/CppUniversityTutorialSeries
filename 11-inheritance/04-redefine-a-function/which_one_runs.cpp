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
    void describe() const {
        Person::describe();
        std::cout << "Student id: " << id_ << '\n';
    }

private:
    int id_ = 0;
};

int main() {
    Student malika("Malika", 1042);
    malika.describe();

    Person& ref = malika;       // the same object, seen as a Person
    ref.describe();

    Person* ptr = &malika;
    ptr->describe();

    Person copy = malika;       // a new Person
    copy.describe();
}
