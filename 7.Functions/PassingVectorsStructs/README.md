
# Passing Vectors and Structs to Functions in C++

In C++, `vector` is a dynamic array, and `struct` is a way to group related variables of different data types. Both can be passed to functions, allowing for more flexible and complex operations. This guide delves into the mechanics and nuances of passing vectors and structs to functions.

## Table of Contents

1. [Passing Vectors to Functions](#passing-vectors-to-functions)
2. [Passing Structs to Functions](#passing-structs-to-functions)
3. [Examples](#examples)
4. [Key Takeaways](#key-takeaways)

## Passing Vectors to Functions

Vectors can be passed to functions similarly to arrays but with greater flexibility:

1. **By Value:** The function gets a copy of the vector, and modifications inside the function won't affect the original vector.
2. **By Reference:** The function operates on the original vector, and modifications will reflect outside.

## Passing Structs to Functions

Structures can also be passed to functions either by value or by reference:

1. **By Value:** The function receives a copy of the struct. Changes made inside the function won't affect the original struct.
2. **By Reference:** The function works with the original struct. Changes made inside the function will be reflected outside.

## Examples

1. **Passing Vector by Value**

```c++
void processVector(std::vector<int> vec);
```

2. **Passing Vector by Reference**

```c++
void modifyVector(std::vector<int>& vec);
```

3. **Passing Struct by Value**

```c++
struct Point {
    int x, y;
};
void displayPoint(Point p);
```

4. **Passing Struct by Reference**

```c++
void modifyPoint(Point& p);
```

## Key Takeaways

1. Vectors and structs can be passed to functions both by value and by reference.
2. Passing by value creates a copy, ensuring the original data remains unchanged.
3. Passing by reference allows the function to modify the original data.
4. Choose the method of passing based on the requirements of your application.
