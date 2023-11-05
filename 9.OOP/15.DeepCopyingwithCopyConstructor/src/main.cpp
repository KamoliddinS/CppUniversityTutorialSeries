#include <iostream>
#include <cstring>

// Class to demonstrate deep copying
class DeepCopy {
private:
    char* data; // Pointer to a dynamically allocated array of characters

public:
    // Constructor to initialize the data with a given string
    DeepCopy(const char* str) {
        if (str != nullptr) {
            data = new char[strlen(str) + 1]; // Allocate memory for the string
            strcpy(data, str); // Copy the string into the allocated memory
        } else {
            data = nullptr; // If no string is provided, set data to nullptr
        }
        std::cout << "Constructor called, data address is " << static_cast<void*>(data) << std::endl;
    }

    // Copy constructor for deep copying
    DeepCopy(const DeepCopy& other) {
        if (other.data != nullptr) {
            data = new char[strlen(other.data) + 1]; // Allocate memory for the copy
            strcpy(data, other.data); // Copy the actual data, not just the pointer
        } else {
            data = nullptr; // If the source object's data is nullptr, set to nullptr
        }
        std::cout << "Deep Copy constructor called, data address is " << static_cast<void*>(data) << std::endl;
    }

    // Destructor to free the dynamically allocated memory
    ~DeepCopy() {
        delete[] data; // Release the allocated memory
        std::cout << "Destructor called, data address was " << static_cast<void*>(data) << std::endl;
    }

    // Display the data
    void print() const {
        std::cout << "Data: " << (data ? data : "null") << std::endl;
    }
};

int main() {
    DeepCopy obj1("Deep Copy Example"); // Create object with data
    DeepCopy obj2 = obj1; // Invoke deep copy constructor

    std::cout << "Object 1: ";
    obj1.print();

    std::cout << "Object 2: ";
    obj2.print();

    // Modify obj1 to see if it affects obj2
    // This part of the code would try to modify the string if it was not a demonstration
    // In this case, we simply print the statement for educational purposes
    std::cout << "Modifying object 1's data does not affect object 2's data due to deep copying." << std::endl;

    // When main returns, both obj1 and obj2 will go out of scope and their destructors will be called
    // Each destructor deletes its own unique memory allocation, preventing any "double delete" scenarios
    return 0;
}
