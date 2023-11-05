#include <iostream>
#include <string>

// Define a class named 'Person'
class Person {
private:
    std::string name;
    int age;
    std::string address;

public:
    // Primary constructor that initializes all the member variables
    Person(const std::string& n, int a, const std::string& addr) 
        : name(n), age(a), address(addr) {
        std::cout << "Primary constructor called: " << name << ", " << age << ", " << address << std::endl;
    }

    // Delegating constructor that uses only name and age - delegates to the primary constructor
    Person(const std::string& n, int a) : Person(n, a, "Not specified") {
        std::cout << "Delegating constructor (name, age) called" << std::endl;
    }

    // Delegating constructor that uses only name - delegates to the above delegating constructor
    Person(const std::string& n) : Person(n, 0) {
        std::cout << "Delegating constructor (name) called" << std::endl;
    }

    // Default constructor that delegates to the primary constructor with default values
    Person() : Person("No name", 0, "Not specified") {
        std::cout << "Delegating default constructor called" << std::endl;
    }
    
    // A member function to print person's information
    void printInfo() const {
        std::cout << "Person Info: " << name << ", " << age << ", " << address << std::endl;
    }

    // Destructor
    ~Person() {
        std::cout << "Destructor called for " << name << std::endl;
    }
};

int main() {
    std::cout << "Creating Person with default constructor" << std::endl;
    Person person1;
    person1.printInfo();
    
    std::cout << "\nCreating Person with name only" << std::endl;
    Person person2("Alice");
    person2.printInfo();
    
    std::cout << "\nCreating Person with name and age" << std::endl;
    Person person3("Bob", 25);
    person3.printInfo();
    
    std::cout << "\nCreating Person with full information" << std::endl;
    Person person4("Charlie", 30, "123 Main St");
    person4.printInfo();
    
    return 0;
}
