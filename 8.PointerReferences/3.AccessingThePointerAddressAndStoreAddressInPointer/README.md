
# Accessing the Pointer Address and Storing Address in Pointer

In C++, pointers play a vital role in managing memory and creating dynamic data structures. An essential aspect of understanding pointers is to know how to access the address a pointer holds and how to store an address in a pointer.

## Table of Contents

1. [Pointer Basics](#pointer-basics)
2. [Accessing the Address of a Pointer](#accessing-the-address-of-a-pointer)
3. [Storing an Address in a Pointer](#storing-an-address-in-a-pointer)
4. [Examples](#examples)
5. [Key Takeaways](#key-takeaways)

## Pointer Basics

A pointer in C++ is a variable that stores the address of another variable. It serves as a direct link or a "pointer" to the memory location of a specific variable.

## Accessing the Address of a Pointer

Every pointer, being a variable, also has its own memory address. While the value stored inside the pointer is the address of another variable, the address of the pointer itself can also be accessed. 

To access the address of a pointer, you can use the `&` (address-of) operator:

```cpp
Type* pointerName;
cout << &pointerName;  // This will display the memory address of the pointer itself.
```

## Storing an Address in a Pointer

Storing an address in a pointer involves two steps:

1. Declaring the pointer.
2. Initializing the pointer with the address of a variable.

You can use the `&` operator to fetch the address of a variable and store it in a pointer:

```cpp
Type variableName;
Type* pointerName = &variableName;  // Storing the address of variableName in pointerName.
```

## Examples

1. **Accessing the Address of a Pointer**

```cpp
int var = 10;
int* p = &var;
cout << "Address of pointer p: " << &p << endl;
```

2. **Storing an Address in a Pointer**

```cpp
int num = 20;
int* numPointer = &num;
cout << "Value pointed by numPointer: " << *numPointer << endl;
```

## Key Takeaways

1. Every variable, including pointers, has a memory address.
2. The value stored inside a pointer is the address of another variable.
3. Use the `&` operator to access the address of a variable or a pointer.
4. Pointers can be dereferenced using the `*` operator to access the value they point to.

