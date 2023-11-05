#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Constructor
    Person(std::string name = "", int age = 0) : name(name), age(age) {}

    // Friend functions for overloading the operators
    friend std::ostream& operator<<(std::ostream& out, const Person& person);
    friend std::istream& operator>>(std::istream& in, Person& person);
};

// Overloading the stream insertion operator
std::ostream& operator<<(std::ostream& out, const Person& person) {
    // Output the data members of 'Person' to the stream
    out << "Person(Name: " << person.name << ", Age: " << person.age << ")";
    return out; // Return the stream to allow chaining
}

// Overloading the stream extraction operator
std::istream& operator>>(std::istream& in, Person& person) {
    // Input the data into the 'Person' object from the stream
    std::cout << "Enter name: ";
    in >> person.name;
    std::cout << "Enter age: ";
    in >> person.age;
    // It is a good idea to handle errors and set failbits if input is incorrect, though this is a simple example
    return in; // Return the stream to allow chaining
}

int main() {
    Person person;
    std::cout << "Please enter person details:" << std::endl;
    
    // Use the overloaded '>>' operator to input person details
    std::cin >> person;
    
    // Use the overloaded '<<' operator to output person details
    std::cout << "You entered: " << person << std::endl;

    return 0;
}
