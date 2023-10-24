
# Default Argument Values in C++

In C++, it's possible to specify default values for function parameters. This allows a function to be called with fewer arguments than it is defined with, making the arguments optional.

## Table of Contents

1. [Understanding Default Arguments](#understanding-default-arguments)
2. [How to Specify Default Values?](#how-to-specify-default-values)
3. [Rules and Constraints](#rules-and-constraints)
4. [Examples](#examples)
5. [Key Takeaways](#key-takeaways)

## Understanding Default Arguments

Default arguments provide values that a function uses if the caller doesn't provide them. It's a way to make function calls more flexible and to reduce the number of overloaded functions.

## How to Specify Default Values?

When defining a function, assign the default values to the desired parameters using the assignment (`=`) operator.

```c++
returnType functionName(dataType parameter = defaultValue) {
   // function body
}
```

## Rules and Constraints

1. **Order:** Default arguments must be the trailing ones (i.e., you can't provide a default for the first argument without providing defaults for the second and subsequent arguments).
2. **Declaration:** If a function is declared before it's defined, the default value should be specified in the declaration and not in the definition.
3. **Overloading:** Be cautious when overloading functions that have default arguments, as this can lead to ambiguity.

## Examples

1. **Basic Default Argument**

```c++
void greet(std::string name = "Guest" ) {
    std::cout << "Hello, " << name << "!" << std::endl;
}
```

Calling `greet();` will print "Hello, Guest!", but calling `greet("Alice");` will print "Hello, Alice!".

2. **Multiple Default Arguments**

```c++
void displayBox(int width = 10, int height = 5) {
    // Function body to display a box with given width and height
}
```

Here, both `width` and `height` have default values. The function can be called in various ways: `displayBox()`, `displayBox(15)`, or `displayBox(15, 10)`.

## Key Takeaways

1. Default arguments allow you to provide default values for function parameters.
2. They must be trailing in the list of function parameters.
3. Using default arguments can make your code more flexible but be wary of potential ambiguities, especially when combined with function overloading.

