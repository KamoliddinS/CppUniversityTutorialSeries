
# Understanding Number Systems

Welcome! This guide will help you understand different number systems used in computing.

## 1. What are Number Systems?

A number system is a way to represent numbers. We use different number systems in computing, like Decimal, Binary, Octal, and Hexadecimal.

## 2. Types of Number Systems:

### Decimal (Base 10):
- **Used in**: Everyday counting
- **Digits**: 0 to 9
- **Example**: 159 is \(1 * 10<sup>2</sup> + 5 * 10<sup>1</sup> + 9 * 10<sup>0</sup>\)

### Binary (Base 2):
- **Used in**: Computers at the basic level
- **Digits**: 0 and 1
- **Example**: 1011 is \(1 * 2<sup>3</sup> + 0 * 2<sup>2</sup> + 1 * 2<sup>1</sup> + 1 * 2<sup>0</sup>\)  is equal to 11 in decimal

### Octal (Base 8):
- **Used in**: Some computer systems
- **Digits**: 0 to 7
- **Example**: 547 is \(5 * 8<sup>2</sup> + 4 * 8<sup>1</sup> + 7 * 8<sup>0</sup>\) is equal to 363 in decimal
### Hexadecimal (Base 16):
- **Used in**: Representing binary numbers in a shorter form
- **Digits**: 0 to 9 and A to F (A=10, B=11, ..., F=15)
- **Example**: 2AF is \(2 * 16<sup>2</sup> + 10 * 16<sup>1</sup> + 15 * 16<sup>0</sup>\) is equal to 687 in decimal

## 3. Why Different Number Systems?

- **Binary** is basic for computers. Everything inside a computer is binary.
- **Octal** and **Hexadecimal** are shorter ways to show binary numbers. They are easier to read than long binary numbers.
- **Decimal** is what we use every day for counting.





## 4. How to Convert Between Them?

We have provided a simple C++ code in this repository to help you convert between these number systems. Check the code, try it out, and learn!

## 5. Number Systems in C++: Usage and Encounters

In C++, developers often come across different number systems, especially when dealing with low-level programming, memory management, or bitwise operations. Here's where you might see or use them:

### Decimal (Base 10):

- **Usage in C++**: This is the default number system for integer and floating-point literals.
- **Where You'll See It**: Almost everywhere in code, from loop counters to array indices.
  ```cpp
  int decimalNumber = 123;
  ```

### Binary (Base 2):

- **Usage in C++**: Introduced in C++14, you can represent binary literals using the `0b` or `0B` prefix.
- **Where You'll See It**: Bitwise operations, flags, or when directly manipulating bits.
  ```cpp
  int binaryNumber = 0b1011;  // Equivalent to decimal 11
  ```

### Octal (Base 8):

- **Usage in C++**: Octal literals are prefixed with a `0`.
- **Where You'll See It**: Less common in modern C++ code, but sometimes used in file permissions or representing certain character codes.
  ```cpp
  int octalNumber = 0754;  // Equivalent to decimal 492
  ```

### Hexadecimal (Base 16):

- **Usage in C++**: Hexadecimal literals use the `0x` or `0X` prefix.
- **Where You'll See It**: Memory addresses, color codes, bitwise operations, or when interfacing with certain hardware or external systems.
  ```cpp
  int hexNumber = 0x2AF;  // Equivalent to decimal 687
  ```

### Encounters in C++:

- **Memory Addresses**: When you use pointers, the addresses are often displayed in hexadecimal.
  
- **Bit Manipulation**: When working with individual bits of data, you might use binary or hexadecimal to set or check specific bits.
  
- **File Permissions**: On UNIX-like systems, file permissions are often represented in octal.
  
- **Color Representation**: In graphics programming, colors might be represented as hexadecimal values, e.g., `0xFF5733` for a specific shade of orange.

