
# Function Parameters and Return Statements in C++

Functions in C++ can receive data (through parameters) and can optionally send data back to the calling function (via return statements). This guide will explore these two core aspects of C++ functions.

## Table of Contents

1. [Function Parameters](#function-parameters)
2. [Return Statements](#return-statements)
3. [Examples](#examples)
4. [Key Takeaways](#key-takeaways)

## Function Parameters

Parameters (often called arguments) are a mechanism to pass values or references from the calling function to the called function.

### Types of Parameters

1. **Value Parameters:** Pass a copy of the data to the function. Changes made inside the function do not affect the original data.
2. **Reference Parameters:** Pass a reference to the data. Changes made inside the function reflect in the original data.

### Syntax:

```c++
returnType functionName(dataType1 parameter1, dataType2 parameter2, ...) {
   // function body
}
```

## Return Statements

Functions in C++ can return a value to the calling function using the `return` statement. The type of the value being returned should match the function's return type.

### Syntax:

```c++
returnType functionName(parameters) {
   // function body
   return value; // 'value' should be of type 'returnType'
}
```

## Examples

1. **Function with Value Parameters**

```c++
int add(int a, int b) {
    return a + b;
}
```

Here, `a` and `b` are value parameters, and the function returns their sum.

2. **Function with Reference Parameters**

```c++
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}
```

`x` and `y` are reference parameters. Swapping them inside the function also swaps the original variables.

3. **Function with No Return Value**

```c++
void displayMessage() {
    std::cout << "Hello, World!";
}
```

This function does not return any value; hence its return type is `void`.

## Key Takeaways

1. Parameters allow functions to receive data, which can either be value parameters or reference parameters.
2. The `return` statement sends a value from the called function back to the calling function.
3. The type of the value returned by the `return` statement should match the function's declared return type.
