#include <iostream>
#include <cstring>

// A simple class that represents a dynamic string
class DynamicString {
private:
    char* data; // Pointer to dynamic array for string data

public:
    // Parametrized constructor for creating a new DynamicString
    DynamicString(const char* str) {
        data = new char[strlen(str) + 1]; // Allocate memory
        strcpy(data, str); // Copy the string into the newly allocated memory
        std::cout << "Constructed: " << data << std::endl;
    }

    // Copy constructor for creating a copy of an existing DynamicString
    DynamicString(const DynamicString& other) {
        data = new char[strlen(other.data) + 1]; // Allocate memory for the copy
        strcpy(data, other.data); // Perform the deep copy
        std::cout << "Copy Constructed: " << data << std::endl;
    }

    // Destructor for cleaning up dynamic memory
    ~DynamicString() {
        delete[] data; // Release the allocated memory
        std::cout << "Destructed: " << data << std::endl;
    }

    // Utility function to print the string
    void print() const {
        std::cout << "DynamicString: " << data << std::endl;
    }
};

void createAndPrint() {
    DynamicString localString("Temporary String");
    localString.print();
    // localString is destructed when this function exits and its scope ends
}

int main() {
    DynamicString myString("Hello, World!");
    myString.print();

    // Creating a copy of myString using the copy constructor
    DynamicString myStringCopy = myString;
    myStringCopy.print();

    // The copy constructor will also be called in the following situations:
    createAndPrint(); // When passing by value

    // The destructor is called for myStringCopy and myString
    // when they go out of scope at the end of the main function
    return 0;
}