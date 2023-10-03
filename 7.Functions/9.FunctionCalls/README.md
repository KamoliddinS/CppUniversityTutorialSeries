
# Function Calls in C++

In C++, a function call is a fundamental concept that allows you to invoke and execute a function. Function calls are used to perform specific tasks, organize code, and make your programs more modular.

## Syntax of a Function Call

The syntax of a function call in C++ is as follows:

```cpp
return_value = function_name(argument1, argument2, ...);
```

- `return_value`: If the function returns a value, it can be stored in a variable of the appropriate data type.

- `function_name`: The name of the function to be called.

- `argument1, argument2, ...`: The arguments or parameters to be passed to the function. These values can be literals, variables, or expressions.

## Example

```cpp
#include <iostream>

// Function that calculates the square of an integer
int square(int x) {
    return x * x;
}

int main() {
    int number = 5;
    
    // Function call to 'square' with 'number' as the argument
    int result = square(number);
    
    std::cout << "Square of " << number << " is " << result << std::endl;
    
    return 0;
}
```

In this example:

- We define a function named `square` that calculates the square of an integer.

- In the `main` function, we declare an integer variable `number` and assign it the value 5.

- We call the `square` function with `number` as the argument, and the result is stored in the `result` variable.

- We use `std::cout` to display the result, demonstrating a function call.

## Key Concepts

### Passing Arguments

- Arguments are values or expressions passed to a function when it is called. Functions use these arguments to perform specific tasks.

### Return Value

- Functions may return a value. The return value can be of any data type, including custom-defined types. It's specified by the function's return type.

### Function Signature

- A function's signature consists of its name and the types and order of its parameters. It must match the declaration and definition of the function.

### Function Overloading

- Multiple functions can have the same name as long as their signatures (parameter types and order) differ. This is known as function overloading.

### Function Prototypes

- Function prototypes are declarations that provide information about a function's name, return type, and parameter list. They help the compiler understand how to call the function correctly.

### Recursive Function Calls

- A function can call itself, either directly or indirectly. This is known as recursion and is used in various algorithms and problem-solving techniques.

Function calls are fundamental to organizing and structuring code in C++. They allow you to create reusable and modular functions, making your code more readable and maintainable.
