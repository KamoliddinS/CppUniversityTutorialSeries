// Exercise 5: One person, two names
// It builds and runs, but the staff card shows the old name. Repair the classes, not main.
#include <iostream>
#include <string>

class Person {
public:
    explicit Person(const std::string& name) : name_(name) {}
    const std::string& name() const { return name_; }
    void rename(const std::string& name) { name_ = name; }

private:
    std::string name_;
};

class Student : public Person {
public:
    Student(const std::string& name, int id) : Person(name), id_(id) {}
    void studentCard() const { std::cout << "Student " << id_ << ": " << name() << '\n'; }

private:
    int id_ = 0;
};

class Employee : public Person {
public:
    Employee(const std::string& name, int id) : Person(name), id_(id) {}
    void staffCard() const { std::cout << "Staff " << id_ << ": " << name() << '\n'; }

private:
    int id_ = 0;
};

class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(const std::string& name, int studentId, int staffId)
        : Student(name, studentId), Employee(name, staffId) {}
};

int main() {
    TeachingAssistant aziz("Aziz Karimo", 1042, 77);
    aziz.Student::rename("Aziz Karimov");       // the student office corrects the name
    aziz.studentCard();
    aziz.staffCard();
}
