#include <iostream>

int main() {
    // What is a Pointer?
    std::cout << "---- What is a Pointer? ----" << std::endl;

    // Declaring an integer and a pointer
    int var = 42;
    int* p;

    // Syntax for Declaring Pointers
    std::cout << "Address of var: " << &var << std::endl;

    // Pointer Initialization
    p = &var;
    std::cout << "Pointer p points to the address: " << p << std::endl;
    std::cout << "Value at the address pointed by p: " << *p << std::endl;

    // Null Pointers
    int* nullPointer = nullptr;
    if (nullPointer == nullptr) {
        std::cout << "nullPointer is initialized to nullptr and points to: " << nullPointer << std::endl;
    } else {
        std::cout << "Value at the address pointed by nullPointer: " << *nullPointer << std::endl; // This should not be executed.
    }

    // Key Takeaways
    std::cout << "---- Key Takeaways ----" << std::endl;
    std::cout << "1. Pointers store memory addresses, allowing for indirect variable access." << std::endl;
    std::cout << "2. Use the * symbol to declare a pointer and the & symbol to get the address of a variable." << std::endl;
    std::cout << "3. A pointer should be initialized either to an address or to nullptr to avoid undefined behavior." << std::endl;
    std::cout << "4. Dereferencing a pointer gives the value stored at the memory address it points to." << std::endl;

    return 0;
}
