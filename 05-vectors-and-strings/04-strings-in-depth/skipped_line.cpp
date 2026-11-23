#include <iostream>
#include <string>

int main() {
    std::cout << "Age: ";
    int age = 0;
    std::cin >> age;

    std::cout << "Full name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Name: [" << name << "], age: " << age << '\n';
}
