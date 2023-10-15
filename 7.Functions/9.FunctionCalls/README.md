
# Function Calls in C++

In C++, functions are fundamental building blocks that allow us to modularize and reuse code. Function calls are the means by which we invoke these functions, passing control from one part of a program to another. This guide will explore the different types of function calls and their intricacies.

## Table of Contents

1. [What is a Function Call?](#what-is-a-function-call)
2. [Types of Function Calls](#types-of-function-calls)
    - [Call by Value](#call-by-value)
    - [Call by Reference](#call-by-reference)
    - [Call by Pointer](#call-by-pointer)
3. [Recursive Calls](#recursive-calls)
4. [Examples](#examples)
5. [Key Takeaways](#key-takeaways)

## What is a Function Call?

A function call is an instruction to execute a specific function. It provides a mechanism to pass input parameters (arguments) to a function and receive output (return values).

## Types of Function Calls

### Call by Value

In this method, the actual value of an argument is passed to the function. Changes made to the parameter inside the function do not affect the original value.

```c++
void modify(int x) {
    x = x + 10;  // This will not affect the original value
}
```

### Call by Reference

Here, a reference to the argument, rather than a copy, is passed to the function. Thus, changes inside the function will reflect in the original variable.

```c++
void modify(int &x) {
    x = x + 10;  // This will affect the original value
}
```

### Call by Pointer

In this approach, the address of the variable (pointer) is passed to the function. Changes made using this pointer will affect the original variable.

```c++
void modify(int *x) {
    *x = *x + 10;  // This will affect the original value
}
```

## Recursive Calls

A function that calls itself is termed as recursive. It's essential to have a termination condition in recursive functions to prevent infinite loops.

```c++
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n-1);
}
```

## Examples

1. **Simple Function Call**

```c++
void greet() {
    std::cout << "Hello, World!" << std::endl;
}

int main() {
    greet();  // Function call
}
```

2. **Function Call with Return Value**

```c++
int square(int num) {
    return num * num;
}

int main() {
    int result = square(5);  // Function call with return value
    std::cout << result << std::endl;  // Outputs: 25
}
```

## Key Takeaways

1. Functions modularize and enhance the reusability of code.
2. A function call transfers control to a specific function.
3. There are various methods of function calls like call by value, call by reference, and call by pointer.
4. Recursive functions can be powerful but require careful handling to prevent infinite loops.

