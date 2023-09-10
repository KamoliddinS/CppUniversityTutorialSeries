
## C++ Arrays

In C++, an array is a collection of elements of the same type, stored in contiguous memory locations. This document will guide you through the concept of arrays, including their declaration, initialization, accessing elements, and a brief introduction to multidimensional arrays.

### 1. What is an Array?

An array is used to store multiple values of the same type under a single name. It can be thought of as a collection of variables that are accessed through an index number.

### 2. Declaring and Initializing Arrays

**Declaration:**

```cpp
data_type array_name[array_size];
```

**Example:**

```cpp
int numbers[5];
```

**Initialization:**

At the time of declaration:

```cpp
int numbers[5] = {1, 2, 3, 4, 5};
```

Or using an index:

```cpp
numbers[0] = 1;
numbers[1] = 2;
// and so on...
```

If you initialize an array with fewer elements than the specified size, the remaining elements will be set to the default value of the data type (often zero for basic data types).

### 3. Accessing and Modifying Array Elements

To access or modify elements in an array, use the index number. Indexing starts from `0` for the first element.

**Accessing:**

```cpp
int x = numbers[2];  // x will be 3
```

**Modifying:**

```cpp
numbers[2] = 10;  // The third element is now 10
```

### 4. Multidimensional Arrays

Multidimensional arrays can be thought of as "arrays of arrays". The most common is the two-dimensional array (or matrix).

**Declaration:**

```cpp
data_type array_name[size1][size2];
```

**Example:**

```cpp
int matrix[3][3];  // A 3x3 matrix
```

**Initialization:**

```cpp
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```

To access an element:

```cpp
int x = matrix[1][2];  // x will be 6
```

To modify an element:

```cpp
matrix[1][2] = 10;  // The element in the second row and third column is now 10
```



### Conclusion

Arrays in C++ provide a structured method to represent collections of data of the same type. Understanding arrays is fundamental in programming as they form the basis for more complex data structures and are used extensively in algorithm implementations.


### Extra Resources
GeeksForGeeks: [Arrays in C++](https://www.geeksforgeeks.org/cpp-arrays/)
> GeeksForGeeks is a computer science portal for geeks. It contains well written, well thought and well-explained computer science and programming articles. Particulary, this article explains arrays in C++.