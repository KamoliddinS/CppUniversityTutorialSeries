

## C++ Vectors

Vectors in C++ are a dynamic array alternative provided by the Standard Template Library (STL). Unlike arrays, vectors can change their size dynamically. This document will introduce you to vectors, including their declaration, initialization, and methods for accessing and modifying elements.

### 1. What is a Vector?

A vector is a template class in the STL. It allows us to store elements (of any type) in a dynamic array, meaning the size can increase or decrease as needed during the runtime of a program.

### 2. Declaring and Initializing Vectors

**Declaration:**

To declare a vector, you need to include the `vector` header:

```cpp
#include <vector>
```

Then, you can declare a vector as:

```cpp
std::vector<data_type> vector_name;
```

**Example:**

```cpp
std::vector<int> numbers;
```

**Initialization:**

At the time of declaration:

```cpp
std::vector<int> numbers = {1, 2, 3, 4, 5};
```

Or using the `push_back` method:

```cpp
numbers.push_back(6);  // Adds 6 to the end of the vector
```

### 3. Accessing and Modifying Vector Elements

**Accessing:**

You can access elements using the index, similar to arrays:

```cpp
int x = numbers[2];  // x will be 3
```

Or using the `at` method:

```cpp
int y = numbers.at(2);  // y will be 3
```

**Modifying:**

Using the index:

```cpp
numbers[2] = 10;  // The third element is now 10
```

Or using the `at` method:

```cpp
numbers.at(2) = 20;  // The third element is now 20
```

**Adding Elements:**

To add elements to a vector:

```cpp
numbers.push_back(6);  // Adds 6 to the end
```

**Removing Elements:**

To remove the last element:

```cpp
numbers.pop_back();
```

### 4. Vector Methods

Vectors come with several built-in methods. Here are some commonly used ones:

- `push_back(element)`: Adds an element to the end.
- `pop_back()`: Removes the last element.
- `size()`: Returns the number of elements.
- `begin()`: Returns an iterator pointing to the first element.
- `end()`: Returns an iterator pointing past the last element.
- `empty()`: Checks if the vector is empty.
- `resize(new_size)`: Resizes the vector to contain the given number of elements.
- `clear()`: Removes all elements from the vector.

### Conclusion

Vectors in C++ offer a flexible and efficient way to store a collection of items. Their dynamic nature, combined with the rich set of member functions, makes them one of the most widely used data structures in C++ programming.

### Extra Resources
GeeksforGeeks: [Vectors in C++ STL](https://www.geeksforgeeks.org/vector-of-vectors-in-c-stl-with-examples/?ref=gcse)