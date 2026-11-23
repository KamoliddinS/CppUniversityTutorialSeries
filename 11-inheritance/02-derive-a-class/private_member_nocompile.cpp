#include <iostream>
#include <string>

class Person {
public:
    const std::string& name() const { return name_; }

private:
    std::string name_ = "Malika";
};

class Student : public Person {
public:
    void printCard() const { std::cout << name_ << '\n'; }      // name_ is private in Person
};

int main() {
    Student malika;
    malika.printCard();
}
