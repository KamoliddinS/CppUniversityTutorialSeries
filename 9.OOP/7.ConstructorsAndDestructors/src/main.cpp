#include <iostream>

// Define a simple class named 'Example'
class Example {
private:
    int data;

public:
    // Default constructor
    Example() : data(0) {
        std::cout << "Default constructor called, data initialized to 0." << std::endl;
    }

    // Parameterized constructor
    Example(int value) : data(value) {
        std::cout << "Parameterized constructor called, data initialized to " << data << "." << std::endl;
    }

    // Copy constructor
    Example(const Example &obj) : data(obj.data) {
        std::cout << "Copy constructor called, data initialized to " << data << " from object." << std::endl;
    }

    // Destructor
    ~Example() {
        std::cout << "Destructor called, data was " << data << "." << std::endl;
    }

    // A simple member function to display the data
    void display() const {
        std::cout << "The value of data is " << data << std::endl;
    }
};

int main() {
    // Using the default constructor
    Example obj1;
    obj1.display();

    // Using the parameterized constructor
    Example obj2(10);
    obj2.display();

    // Using the copy constructor
    Example obj3 = obj2;
    obj3.display();

    // As the function ends, destructors for obj1, obj2, and obj3 will be called automatically

    return 0;
}

