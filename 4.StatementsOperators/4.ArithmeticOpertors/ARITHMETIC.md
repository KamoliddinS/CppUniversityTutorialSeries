
# C++ Arithmetic Operators

Arithmetic operators are used to perform mathematical operations on variables and values. In this guide, we'll explore each arithmetic operator and see how to use them in C++.

## List of Arithmetic Operators

- `+` : Addition
- `-` : Subtraction
- `*` : Multiplication
- `/` : Division
- `%` : Modulus (Remainder)

## Usage and Examples

### 1. Addition (`+`)

The `+` operator adds two numbers together.

```cpp
int a = 5;
int b = 3;
int sum = a + b; // sum will be 8
```

### 2. Subtraction (`-`)

The `-` operator subtracts one number from another.

```cpp
int a = 5;
int b = 3;
int difference = a - b; // difference will be 2
```

### 3. Multiplication (`*`)

The `*` operator multiplies two numbers.

```cpp
int a = 5;
int b = 3;
int product = a * b; // product will be 15
```

### 4. Division (`/`)

The `/` operator divides one number by another. Note that if both numbers are integers, the result will also be an integer (floor division).

```cpp
int a = 5;
int b = 2;
int quotient = a / b; // quotient will be 2
```

For floating-point division:

```cpp
float a = 5.0;
float b = 2.0;
float quotient = a / b; // quotient will be 2.5
```

### 5. Modulus (`%`)

The `%` operator returns the remainder of a division.

```cpp
int a = 5;
int b = 2;
int remainder = a % b; // remainder will be 1
```

## PEMDAS

Remember the order of operations from math class? In C++, the same order of operations applies. The acronym PEMDAS is a helpful way to remember the order of operations:

- **P**arentheses
- **E**xponents
- **M**ultiplication
- **D**ivision
- **A**ddition
- **S**ubtraction

## Conclusion

Arithmetic operators are fundamental in C++ programming, allowing for various mathematical operations in your code. It's essential to practice using these operators to understand their behavior, especially when dealing with different data types.
