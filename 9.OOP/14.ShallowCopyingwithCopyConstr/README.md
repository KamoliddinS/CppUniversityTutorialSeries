
# Shallow Copying with The Copy Constructor in C++

As part of our Computer Programming with C++ course, this section explores the concept of shallow copying in the context of copy constructors.

## Understanding Shallow Copy

A shallow copy occurs when a copy constructor duplicates field values of an object. For fields that are pointers, shallow copy replicates the pointer's address, not the actual data it points to. As a result, both the original and the copied object point to the same memory location for their data.

## Implications of Shallow Copy

Shallow copying can lead to issues, such as:
- **Dangling Pointers**: If one object is deleted, the memory is freed, and the other object's pointer becomes a dangling pointer.
- **Unexpected Mutations**: Modifying the data in one object can inadvertently change it for the other.
- **Double Free Errors**: If both objects go out of scope, the destructor will try to free the same memory location twice, which can cause a program crash.

## The Default Copy Constructor

By default, C++ provides a copy constructor that performs a shallow copy. This is sufficient for classes without dynamic memory allocation or resources like file handles or network connections.

## Example of Shallow Copying

```cpp
#include <iostream>

class Shallow {
public:
    int* data;

    // Constructor
    Shallow(int d) {
        data = new int; // allocate memory
        *data = d;
        std::cout << "Constructor called. Data: " << *data << std::endl;
    }

    // Default Copy Constructor provided by C++ does a shallow copy
    // Shallow(const Shallow& source) = default;

    // Destructor
    ~Shallow() {
        delete data; // free memory
        std::cout << "Destructor called." << std::endl;
    }

    // Function to display the value
    void display() {
        std::cout << "Data: " << *data << std::endl;
    }
};

int main() {
    Shallow obj1(100);
    Shallow obj2 = obj1; // Shallow copy

    obj1.display();
    obj2.display();

    // Altering obj1 data also alters obj2
    *obj1.data = 200;
    std::cout << "After modification:" << std::endl;
    obj1.display();
    obj2.display();

    return 0; // obj1 and obj2 are destructed
}
```

## Conclusion

A shallow copy is straightforward and automatic with the default copy constructor, but care must be taken with objects that manage resources. It is often necessary to implement a custom copy constructor to avoid the pitfalls of shallow copying.

Remember, the rule of three in C++ states that if you need to explicitly declare either the destructor, copy constructor, or copy assignment operator yourself, you should probably explicitly declare all three.

