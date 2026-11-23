#include <iostream>
#include <string>

class Person {
public:
    explicit Person(const std::string& name) : name_(name) {}
    const std::string& name() const { return name_; }

private:
    std::string name_;
};

class Guest : public Person {
public:
    using Person::Person;       // take over the constructors of Person
    void visit() const { std::cout << name() << " visits the campus\n"; }
};

int main() {
    Guest laziz("Laziz");       // uses the constructor of Person
    Guest copy = laziz;         // the generated copy constructor copies the Person part too
    copy.visit();
}
