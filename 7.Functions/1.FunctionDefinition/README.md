
# Function Definition in C++

Programming can often involve repeating the same set of instructions multiple times. Instead of writing the same code repeatedly, we use **functions** to group a set of instructions together and then call them whenever needed. In this guide, we will learn about function definitions in C++.

## Table of Contents

1. [What is a Function?](#what-is-a-function)
2. [Why Use Functions?](#why-use-functions)
3. [Function Definition](#function-definition)
4. [Example of a Function](#example-of-a-function)
5. [Key Takeaways](#key-takeaways)

## What is a Function?

A function is a group of related statements that perform a specific task. Think of it as a small machine: you give it some input, and it gives you some output.

## Why Use Functions?

- **Avoid Repetition:** Instead of writing the same code multiple times, write it once inside a function and call the function whenever needed.
- **Modularity:** Break complex problems into smaller, manageable pieces or modules.
- **Easier Maintenance:** If there's a need to make a change, you only have to update the function, not multiple places in your code.

## Function Definition

A function definition in C++ consists of:
- **Return Type:** It signifies what is the type of the result that the function is going to return. It can be an `int`, `float`, `void` (for no return), etc.
- **Function Name:** Name of the function.
- **Parameters:** Values you can pass into the function. They are optional.
- **Function Body:** A set of statements that defines what the function does.

Syntax:
```c++
returnType functionName(parameters) {
   // function body
}
```

## Example of a Function

Let's look at a simple example:

```c++
// This is a function definition
int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(5, 3);  // Calling the function
    cout << "The sum is: " << result << endl;
    return 0;
}
```

Here:
- `int` is the **return type**. This means our function will return an integer value.
- `add` is the **function name**.
- `(int a, int b)` are **parameters**. This function takes two integer values as input.
- The **function body** is `{ return a + b; }`, which simply returns the sum of `a` and `b`.

## Key Takeaways

1. Functions help to organize and reuse code.
2. A function in C++ has a definition that includes a return type, name, parameters, and a body.
3. Use the function name followed by its parameters to call (or use) the function.

