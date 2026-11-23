#include <iostream>
#include <memory>
#include <string>

struct Person {
    std::string name;
    std::shared_ptr<Person> student;    // owns the student
    std::weak_ptr<Person> teacher;      // only observes the teacher
    explicit Person(const std::string& personName) : name(personName) {}
    ~Person() { std::cout << name << " is destroyed\n"; }
};

void printTeacher(const Person& person) {
    std::shared_ptr<Person> teacher = person.teacher.lock();
    if (teacher != nullptr) {
        std::cout << person.name << "'s teacher is " << teacher->name << '\n';
    } else {
        std::cout << person.name << "'s teacher is gone\n";
    }
}

int main() {
    auto laziz = std::make_shared<Person>("Laziz");
    {
        auto nodira = std::make_shared<Person>("Nodira");
        nodira->student = laziz;
        laziz->teacher = nodira;        // no new owner: Nodira's count stays 1
        printTeacher(*laziz);
    }                                   // nodira is destroyed, and Nodira with it
    printTeacher(*laziz);
}
