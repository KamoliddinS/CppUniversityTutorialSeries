#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Constructor that uses the 'this' pointer to differentiate between
    // parameter names and member variable names
    Person(std::string name, int age) {
        this->name = name;
        this->age = age;
    }

    // A method that returns a reference to the instance itself to allow chaining
    Person& setName(const std::string& name) {
        this->name = name; // Assigns the member variable 'name' the value of the parameter 'name'
        return *this; // Returns the calling object itself
    }

    // Another method that does the same for 'age'
    Person& setAge(int age) {
        this->age = age; // Assigns the member variable 'age' the value of the parameter 'age'
        return *this;
    }

    // A const member function that uses 'this' to access the calling object's members
    void introduceSelf() const {
        std::cout << "Hello, I am " << this->name << " and I am " << this->age << " years old." << std::endl;
    }

    // print this pointer
    void printThisPointer(){
        std::cout << "this pointer: " << this << std::endl;
    }
};

int main() {
    // Creating an object of Person using the constructor
    Person person("John", 25);

    // Chaining method calls using 'this' to return the object itself
    person.setName("Alice").setAge(30);

    // Calling introduceSelf to display the person's name and age
    person.introduceSelf();


    //print this pointer
    std::cout << "this pointer: " << &person << std::endl;

    //print this pointer
    person.printThisPointer();


    return 0;
}
