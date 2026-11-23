// Exercise 4: Which one runs?
// Do not run this program yet. Write what it prints into prediction.txt.
#include <iostream>

class Person {
public:
    void role() const { std::cout << "person\n"; }
    void greet() const { std::cout << "Salom!\n"; }
};

class Teacher : public Person {
public:
    void role() const { std::cout << "teacher\n"; }
};

void byReference(const Person& person) { person.role(); }
void byValue(Person person) { person.role(); }

int main() {
    Teacher nodira;
    nodira.role();
    nodira.greet();
    nodira.Person::role();

    Person& ref = nodira;
    ref.role();

    Teacher* ptr = &nodira;
    ptr->role();

    byReference(nodira);
    byValue(nodira);
}
