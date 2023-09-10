
# Statements in C++

In C++, a **statement** is a fundamental building block of a program. It represents an instruction to the computer to carry out a specific action. Statements form the backbone of a program, controlling its flow and structure.

## Types of Statements

### 1. **Expression Statements**
Expression statements are expressions followed by a semicolon. These are the most common type of statement.

Example:
```cpp
x = 5 + 6;   // Assignment statement
func();      // [Function call]
```
[is function call an expression statement ? ](./FUNCTIONCALL.md)

### 2. **Compound Statements (Blocks)**
A block is a group of zero or more statements enclosed in curly braces `{ }`. They allow multiple statements to be treated as one.

Example:
```cpp
{
    int x = 5;
    x++;
    std::cout << x;
}
```

### 3. **Selection Statements**
These are used for decision making, like `if`, `if-else`, and `switch`.

Example:
```cpp
if (x > 5) {
    std::cout << "x is greater than 5";
}
```

### 4. **Iteration Statements (Loops)**
Used to execute a block of code multiple times. Examples are `for`, `while`, and `do-while`.

Example:
```cpp
for (int i = 0; i < 10; i++) {
    std::cout << i << "\n";
}
```

### 5. **Jump Statements**
These allow transferring control to another part of the program. Examples are `break`, `continue`, `return`, and `goto`.

Example:
```cpp
if (x == 5) {
    return;
}
```

### 6. **Declaration Statements**
Declaring a variable or a function.

Example:
```cpp
int x;
double func();
```

## Conclusion

Statements are crucial in defining the behavior and flow of a C++ program. Understanding different types of statements is essential for effective programming in C++.
