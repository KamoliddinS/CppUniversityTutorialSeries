
# Inline Functions in C++

Inline functions are a powerful feature in C++ that can optimize the function call overhead by substituting the function call with the actual function code. Instead of following the traditional function call mechanism, the compiler places a copy of the function's code in place of every call to that function, if it deems suitable.

## Table of Contents

1. [What is an Inline Function?](#what-is-an-inline-function)
2. [Advantages of Inline Functions](#advantages-of-inline-functions)
3. [Limitations](#limitations)
4. [Usage](#usage)
5. [Examples](#examples)
6. [Key Takeaways](#key-takeaways)

## What is an Inline Function?

An inline function is a function that's expanded in line when it's invoked. When the inline function is called, the compiler replaces the function call with the function code itself (inline expansion), which can lead to faster code execution at the cost of increased binary size.

## Advantages of Inline Functions

1. **Faster Execution**: Eliminates the overhead of function calls.
2. **No Push/Pop Operations**: No operations on the stack for passing arguments and retrieving the return value.
3. **Optimization**: Compiler can perform optimizations as the function body is available directly at the call site.

## Limitations

1. **Code Size Increase**: As the function code is duplicated at each call site, it can lead to an increase in the binary size.
2. **Not Always Inlined**: Just because a function is declared `inline` doesn't guarantee that the compiler will inline it.
3. **Not Suitable for Large Functions**: Inlining can cause code bloat, hence it's not advisable for lengthy functions.

## Usage

To make a function inline, you prefix its declaration with the `inline` keyword:

```c++
inline int add(int a, int b) {
    return a + b;
}
```

## Examples

1. **Simple Inline Function**

```c++
inline int square(int n) {
    return n * n;
}

int main() {
    int result = square(5);  // No actual function call here during execution, if inlined
    std::cout << result << std::endl;  // Outputs: 25
}
```

## Key Takeaways

1. Inline functions can speed up execution by avoiding function call overhead.
2. They might increase the binary size due to the duplication of function code.
3. The `inline` keyword is more of a request than a command, and the compiler might choose not to inline a function.
4. They are best used judiciously, especially for small, frequently called functions.

