
# Lambda Expressions in C++

## Introduction
Introduced in C++11, lambda expressions are a concise way to write anonymous functions. They are particularly useful in the context of STL algorithms and for creating short, on-the-fly functions. This section covers the syntax and usage of lambda expressions in C++.

## Syntax
A lambda expression in C++ has the following general syntax:
```cpp
[ capture_clause ] ( parameters ) -> return_type {
    // function body
}
```
- **Capture Clause**: Defines what from the outside of the lambda should be available inside the function body and how (by value, by reference).
- **Parameters**: Similar to parameters in regular functions (optional).
- **Return Type**: Optional. If omitted, it's auto-deduced.
- **Function Body**: The code block that defines what the lambda does.

## Examples
1. **Simple Lambda Expression**
   ```cpp
   auto greet = []() { std::cout << "Hello, World!" << std::endl; };
   greet(); // Output: Hello, World!
   ```

2. **Lambda with Parameters**
   ```cpp
   auto add = [](int a, int b) { return a + b; };
   std::cout << add(5, 3) << std::endl; // Output: 8
   ```

3. **Capturing External Variables**
   - By Value:
     ```cpp
     int x = 10;
     auto addX = [x](int a) { return a + x; };
     std::cout << addX(5) << std::endl; // Output: 15
     ```
   - By Reference:
     ```cpp
     int y = 10;
     auto modifyY = [&y]() { y *= 2; };
     modifyY();
     std::cout << y << std::endl; // Output: 20
     ```

4. **Specifying Return Type**
   ```cpp
   auto divide = [](double a, double b) -> double {
       if(b == 0) return 0;
       return a / b;
   };
   std::cout << divide(10.0, 2.0) << std::endl; // Output: 5.0
   ```

## Usage in STL Algorithms
Lambda expressions are often used with STL algorithms for custom operations or predicates.
```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
std::for_each(vec.begin(), vec.end(), [](int& x){ x *= 2; });
```

## Best Practices
- Use lambda expressions for short, simple functions to enhance readability.
- Be cautious with capturing by reference to avoid dangling references.
- Prefer auto for lambda type to handle complex return types.

## Further Reading
- Detailed explanation of lambda expressions on [cppreference.com](https://en.cppreference.com/w/cpp/language/lambda)
- "Effective Modern C++" by Scott Meyers, for best practices and advanced uses of lambda expressions.
