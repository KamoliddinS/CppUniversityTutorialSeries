

# Passing Arrays to Functions in C++

In C++, arrays can be passed to functions as arguments. This allows for efficient manipulation and processing of data stored in arrays without duplicating the data. This guide explores the basics and intricacies of passing arrays to functions.

## Table of Contents

1. [Basics of Passing Arrays](#basics-of-passing-arrays)
2. [Pointers and Arrays](#pointers-and-arrays)
3. [Passing Multi-dimensional Arrays](#passing-multi-dimensional-arrays)
4. [Examples](#examples)
5. [Key Takeaways](#key-takeaways)

## Basics of Passing Arrays

When an array is passed to a function, what's essentially passed is a pointer to the first element of the array. This means:

- The function can modify the original values in the array.
- Passing arrays is efficient since only the address (and not the whole array) is passed.

## Pointers and Arrays

Since passing an array essentially passes the address of its first element, it's crucial to understand the relationship between arrays and pointers:

1. The array name is a constant pointer to the first element.
2. Functions that accept array arguments can also be written to accept pointer arguments.

## Passing Multi-dimensional Arrays

For multi-dimensional arrays, especially 2D arrays, you need to specify the size of all dimensions except the first one.

## Examples

1. **Passing a One-dimensional Array**

```c++
void processArray(int arr[], int size);
```
or
```c++
void processArray(int* arr, int size);
```

2. **Passing a Two-dimensional Array**

```c++
void process2DArray(int arr[][3], int rows);
```

## Key Takeaways

1. When passing arrays to functions, you're essentially passing a pointer to the array's first element.
2. Functions can modify the original content of the passed array.
3. For multi-dimensional arrays, remember to specify the size for all but the first dimension.
