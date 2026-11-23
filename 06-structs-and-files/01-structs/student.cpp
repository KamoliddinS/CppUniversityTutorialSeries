#include <iostream>
#include <string>

struct Student {
    std::string name;       // a string is empty by itself
    int age = 0;            // default values: used when you give none
    double grade = 0.0;
};

int main() {
    Student aziz{"Aziz", 19, 4.5};      // values in the order of the members
    std::cout << aziz.name << " is " << aziz.age << '\n';

    aziz.age = 20;                      // change one member
    std::cout << aziz.name << " is " << aziz.age << '\n';

    Student nobody;                     // every member has its default value
    std::cout << '[' << nobody.name << "] " << nobody.age << ' ' << nobody.grade << '\n';
}
