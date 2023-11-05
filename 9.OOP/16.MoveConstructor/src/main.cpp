#include <iostream>
#include <vector>

// A class that contains a dynamic array
class DynamicArray {
private:
    int* data;
    size_t length;

public:
    // Standard constructor that allocates memory for the array
    DynamicArray(size_t len) : length(len), data(new int[len]) {
        std::cout << "Constructor allocating " << length << " integers." << std::endl;
    }

    // Move constructor that takes an rvalue reference to another DynamicArray
    DynamicArray(DynamicArray&& other) noexcept
        : data(nullptr), length(0) {
        std::cout << "Move constructor invoked." << std::endl;

        // Transfer ownership of the data from the source object
        data = other.data;
        length = other.length;

        // Leave the source object in a safe state to avoid double free during destruction
        other.data = nullptr;
        other.length = 0;
    }

    // Destructor to free the allocated memory
    ~DynamicArray() {
        std::cout << "Destructor freeing data." << std::endl;
        delete[] data;
    }

    // A method to print the array's elements
    void print() const {
        for (size_t i = 0; i < length; ++i) {
            std::cout << data[i] << ' ';
        }
        std::cout << std::endl;
    }

    // Disable copy operations to enforce move semantics
    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;
};

// Function to generate a temporary DynamicArray
DynamicArray createArray(size_t len) {
    DynamicArray temp(len);
    for (size_t i = 0; i < len; ++i) {
        // Initialize array with some values
        // For simplicity we're just using the index as the value
        temp.print(); // Just for demonstration purposes
    }
    return temp; // This will invoke the move constructor
}

int main() {
    size_t arraySize = 10;

    // Create an array with 'arraySize' elements
    DynamicArray arr = createArray(arraySize);

    // The contents of 'arr' are now the moved resources from the temporary array
    std::cout << "Array after move:" << std::endl;
    arr.print();

    // No need to manually delete anything, the destructor will be called
    // for 'arr' when it goes out of scope, freeing the resources

    return 0;
}
