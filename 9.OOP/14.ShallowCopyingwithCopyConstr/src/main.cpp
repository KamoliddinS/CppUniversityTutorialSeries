#include <iostream>

class ShallowCopy {
public:
    int* data; // Pointer to an int, represents dynamic memory allocation

public:
    // Constructor
    ShallowCopy(int value) {
        data = new int(value); // Allocate memory for int and set value
        std::cout << "Constructor: Memory allocated for data, value = " << *data << std::endl;
    }

    // The Default Copy Constructor performs a shallow copy
    // ShallowCopy(const ShallowCopy& source) = default;

    // Destructor
    ~ShallowCopy() {
        delete data; // Free the allocated memory
        std::cout << "Destructor: Memory freed for data" << std::endl;
    }

    // Display the value
    void print() const {
        std::cout << "Value: " << *data << std::endl;
    }
};

int main() {
    ShallowCopy original(100); // Create an original object with value 100
    original.print();

    ShallowCopy copy = original; // Invoke the default copy constructor
    copy.print();

    // Until this point, everything appears to work fine.
    // However, both 'original' and 'copy' now share the same memory for 'data'.

    // Let's change the value using the 'original' object and see the effect
    std::cout << "Changing value using the original object" << std::endl;
    *original.data = 200; // DANGEROUS: This also affects 'copy' because of the shallow copy

    // Print values after modification
    original.print(); // Will print "Value: 200"
    copy.print();     // Will also print "Value: 200" because of shallow copy

    // When the function exits, both 'original' and 'copy' objects are destroyed.
    // The destructor will be called twice, attempting to free the same memory,
    // which can lead to undefined behavior or a crash (double free corruption).
    return 0;
}
