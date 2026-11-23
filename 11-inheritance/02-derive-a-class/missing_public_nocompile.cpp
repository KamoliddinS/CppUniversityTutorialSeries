#include <iostream>
#include <string>

class Person {
public:
    const std::string& name() const { return name_; }

private:
    std::string name_ = "Malika";
};

class Student : Person {};      // the word "public" is missing

int main() {
    Student malika;
    std::cout << malika.name() << '\n';
}
