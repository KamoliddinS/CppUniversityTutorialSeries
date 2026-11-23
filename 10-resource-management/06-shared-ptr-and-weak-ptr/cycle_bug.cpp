#include <iostream>
#include <memory>
#include <string>

struct Person {
    std::string name;
    std::shared_ptr<Person> student;
    std::shared_ptr<Person> teacher;
    explicit Person(const std::string& personName) : name(personName) {}
    ~Person() { std::cout << name << " is destroyed\n"; }
};

int main() {
    auto nodira = std::make_shared<Person>("Nodira");
    auto laziz = std::make_shared<Person>("Laziz");
    nodira->student = laziz;        // Nodira owns Laziz
    laziz->teacher = nodira;        // Laziz owns Nodira: a cycle
    std::cout << "owners of Nodira: " << nodira.use_count() << '\n';
    std::cout << "end of main\n";
}
