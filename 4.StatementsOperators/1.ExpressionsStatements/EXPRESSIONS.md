# Expressions in Programming

In programming, an **expression** is a combination of one or more values, variables, operators, and functions that the programming language interprets and computes to produce another value. This means that when an expression is evaluated, it returns a value.
> "a sequence of operators and operands that specifies a computation" - [Wikipedia](https://en.wikipedia.org/wiki/Expression_(computer_science))

Expressions are fundamental elements in most programming languages. They can range from simple values to more complex combinations of values, variables, and operations.

## Types of Expressions

### 1. Literal Expressions

- `42` : Integer literal
- `"Hello, World!"` : String literal

### 2. Arithmetic Expressions

- `x + y`
- `a * (b + c)`

### 3. Relational Expressions

These evaluate to boolean values: true or false.

- `x > y`
- `a == b`

### 4. Logical Expressions

- `x && y` : Logical AND
- `a || b` : Logical OR
- `!a` : Logical NOT

### 5. Function Calls

Assuming a function `f` is defined:
- `f(x)`

[is function call expression ?](FUNCTIONCALL.md)

### 6. Assignment Expressions

In languages where assignment returns a value, such as C or C++:
- `x = y`

## Conclusion

In the context of a program, expressions are often parts of statements. For example, in the statement `int z = x + y;`, the expression `x + y` is evaluated, and its result is assigned to the variable `z`.

The difference between expressions and statements is a key distinction in programming. While expressions always return a value and can be part of larger expressions, statements represent actions or commands and don't inherently have a return value.
