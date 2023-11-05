#include <iostream>

// Define a simple class named 'Example'
class Example {
private:
    int data;

public:
    // Default constructor - it is declared and defined by the user.
    // This will initialize 'data' to 0 whenever an object of 'Example' is created without any arguments.
    Example() : data(0) {
        std::cout << "Default constructor called, data initialized to " << data << std::endl;
    }

    // Member function to display the value of 'data'
    void display() const {
        std::cout << "The value of data is " << data << std::endl;
    }
};

int main() {
    // Creating an object 'obj1' of class 'Example' with the default constructor
    Example obj1;
    // The default constructor is called automatically, initializing 'data' to 0.

    // Display the value of 'data' in 'obj1'
    obj1.display();

    // When main() ends, 'obj1' goes out of scope and its destructor is called automatically.
    return 0;
}
