#include <iostream>

// Function to swap two numbers using pointers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // Declaring and initializing an integer variable
    int var = 10;
    
    // Declaring and initializing a pointer
    int *p = &var;
    
    // Printing the address stored in the pointer
    std::cout << "Address stored in pointer p: " << p << std::endl;
    
    // Accessing and printing the value using the pointer
    int value = *p;
    std::cout << "Value accessed using pointer p: " << value << std::endl;
    
    // Demonstrating pointer arithmetic
    p++;
    std::cout << "Address after pointer arithmetic (p++): " << p << std::endl;
    
    // Demonstrating the swap function
    int num1 = 5, num2 = 10;
    std::cout << "Before swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;
    swap(&num1, &num2);
    std::cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;
    
    // Demonstrating a null pointer
    int *nullPtr = nullptr;
    if (nullPtr == nullptr) {
        std::cout << "nullPtr is a null pointer." << std::endl;
    }

    return 0;
}
