
# Pass By Reference in C++

In C++, when we talk about "pass by reference", it means the function receives a reference to an argument, rather than a copy of its value. This allows functions to modify the original data. This guide will dive deep into the intricacies and advantages of pass by reference.

## Table of Contents

1. [What is Pass By Reference?](#what-is-pass-by-reference)
2. [Advantages](#advantages)
3. [Comparing with Pass By Value](#comparing-with-pass-by-value)
4. [Using `const` with References](#using-const-with-references)
5. [Examples](#examples)
6. [Key Takeaways](#key-takeaways)

## What is Pass By Reference?

When passing by reference, the function gets a reference to the actual variable. Thus, changes made inside the function are reflected in the original variable outside the function. This is achieved using the `&` symbol.

## Advantages

1. **Efficiency:** No copy of the variable is created, which can be beneficial for large data structures.
2. **Modifiability:** Allows the function to alter the original variable's value.
3. **Multiple Returns:** Using pass by reference, a function can "return" multiple values via its parameters.

## Comparing with Pass By Value

In "pass by value", a copy of the variable is created, and operations inside the function do not affect the original data. This contrasts with pass by reference, where the function operates on the original data directly.

## Using `const` with References

If you want to pass by reference but ensure the function doesn't modify the data, you can use `const`.

```c++
void display(const int& num);
```

## Examples

1. **Basic Pass By Reference**

```c++
void modifyValue(int& x) {
    x *= 2;
}
```

2. **Using `const` with Pass By Reference**

```c++
void display(const std::string& str) {
    std::cout << str << std::endl;
}
```

## Key Takeaways

1. Pass by reference allows a function to operate on the actual variable, not a copy.
2. It offers efficiency benefits, especially for large data.
3. The `const` keyword can be used to ensure the referenced variable isn't modified.

