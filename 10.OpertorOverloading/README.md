

# C++ Operator Overloading Overview

Welcome to the C++ Operator Overloading repository. This educational resource is dedicated to providing clear and concise examples of operator overloading in C++. The repository is structured to help both beginners and advanced programmers grasp the concepts of overloading different types of operators in C++.

## What is Operator Overloading?

Operator overloading is a powerful feature in C++ that allows programmers to define custom behavior for operators when they're used with user-defined types (classes and structs). This can significantly enhance the readability and intuitiveness of your code, making it closer to the syntax of built-in types.

## Contents

This repository is organized into several sections, each focusing on different aspects of operator overloading:

### Overloading the Assignment Operator
- [Copy Assignment Operator](./CopyAssignmentOperator.md): Explains how to properly overload the copy assignment operator to ensure objects are copied correctly.
- [Move Assignment Operator](./MoveAssignmentOperator.md): Demonstrates the use of the move assignment operator for efficient object transfers, especially when working with resources.

### Overloading Unary and Binary Operators
- [Unary Operators](./UnaryOperators.md): Covers the overloading of unary operators, such as `++` (increment), `--` (decrement), and `!` (logical NOT).
- [Binary Operators](./BinaryOperators.md): Discusses how to overload binary operators, such as `+`, `-`, `*`, and `/`, ensuring that objects can interact with each other in intuitive ways.

### Overloading Operators as Member and Global Functions
- [Member Functions](./MemberFunctionOperators.md): Details how to implement operators as member functions of a class, encapsulating the behavior within the class itself.
- [Global Functions](./GlobalFunctionOperators.md): Explores the usage of global functions to overload operators, which is especially useful for symmetric operations or when dealing with different types.

### Overloading the Stream Insertion and Extraction Operators
- [Stream Insertion Operator](./StreamInsertionOperator.md): Provides examples of overloading the `<<` operator for outputting object state to streams, such as `std::cout`.
- [Stream Extraction Operator](./StreamExtractionOperator.md): Shows how to overload the `>>` operator to allow for easy and intuitive input of user-defined types from streams like `std::cin`.

