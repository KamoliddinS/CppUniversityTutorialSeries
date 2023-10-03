
# Passing Arrays to Functions in C++

In C++, you can pass arrays to functions to perform operations on the elements of the array or to modify the array itself. This allows for better code organization and reusability.

## Passing Arrays as Function Parameters

To pass an array to a function, you can use one of the following methods:

### Method 1: Specify Array Size

```cpp
return_type function_name(data_type array_name[], int array_size);
```

- `return_type`: The data type of the value that the function will return (e.g., `void`, `int`, etc.).

- `function_name`: The name of the function.

- `data_type array_name[]`: The array parameter, which should include the array's data type and a name for the array.

- `int array_size`: An integer parameter specifying the size of the array.

### Method 2: Use Pointers

Alternatively, you can use pointers to pass arrays to functions:

```cpp
return_type function_name(data_type* array_name, int array_size);
```

- `return_type`: The data type of the value that the function will return (e.g., `void`, `int`, etc.).

- `function_name`: The name of the function.

- `data_type* array_name`: A pointer parameter, which is used to pass the array.

- `int array_size`: An integer parameter specifying the size of the array.

## Example

```cpp
#include <iostream>

// Function that computes the sum of all elements in an integer array
int sumArrayElements(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int arraySize = sizeof(numbers) / sizeof(numbers[0]);

    int totalSum = sumArrayElements(numbers, arraySize);

    std::cout << "Sum of array elements: " << totalSum << std::endl;

    return 0;
}
```

In this example:

- We define a function `sumArrayElements` that takes an integer array `arr` and its size as parameters. The function calculates the sum of all elements in the array and returns the result.

- In the `main` function, we create an integer array `numbers` and calculate its size using `sizeof`.

- We then call the `sumArrayElements` function, passing the `numbers` array and its size as arguments.

- Finally, we display the sum of the array elements using `std::cout`.

## Benefits of Passing Arrays to Functions

- **Modularity**: Passing arrays to functions promotes code modularity by encapsulating specific tasks related to arrays within separate functions.

- **Reusability**: Functions that operate on arrays can be reused with different arrays, reducing code duplication.

- **Ease of Maintenance**: Modifications to array-related code can be made in one place (the function) rather than scattered throughout the program.

- **Improved Readability**: Function names can provide meaningful context to the purpose of array operations.

Passing arrays to functions is a fundamental concept in C++ that enhances code organization and maintainability.
