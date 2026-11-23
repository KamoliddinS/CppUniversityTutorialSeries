#include <iostream>
#include <string>

class Person {
public:
    void describe() const { std::cout << "a person\n"; }
    void describe(const std::string& title) const { std::cout << title << ": a person\n"; }
};

class Student : public Person {
public:
    void describe() const { std::cout << "a student\n"; }    // hides both functions above
};

int main() {
    Student malika;
    malika.describe();
    malika.describe("Guest");
}
