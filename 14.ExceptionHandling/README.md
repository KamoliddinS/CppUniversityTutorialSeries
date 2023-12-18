
# Overview of Exception Handling in C++

Exception handling is a robust mechanism in C++ for dealing with runtime errors. It allows a program to catch and handle errors in a controlled and predictable manner. This README provides an overview of the key concepts and examples we've discussed in our Exception Handling series.

## Table of Contents

- [Basic Concepts and Example](#basic-concepts-and-example)
- [Throwing Exceptions from a Function](#throwing-exceptions-from-a-function)
- [Handling Multiple Exceptions](#handling-multiple-exceptions)
- [Stack Unwinding](#stack-unwinding)
- [Creating User-Defined Exception Classes](#creating-user-defined-exception-classes)
- [Class-Level Exceptions](#class-level-exceptions)
- [The C++ `std::exception` Class Hierarchy](#the-c-stdexception-class-hierarchy)

## Basic Concepts and Example

We introduced the fundamentals of exception handling, demonstrating how to throw, catch, and manage exceptions. We explored how exceptions provide a way to react to exceptional circumstances (like runtime errors) without resorting to drastic measures like terminating the program.
[Read more about Basic Concepts and Example](./2.BasicConceptsAndDevidingByZero/README.md)


## Throwing Exceptions from a Function

We examined how functions can throw exceptions to indicate that an error has occurred. This is particularly useful when a function encounters a situation it's not designed to handle.
[Read more about Throwing Exceptions from a Function](./3.ThrowingAnExceptionsFromAFunctions/README.md)

## Handling Multiple Exceptions

We discussed handling multiple types of exceptions and how to write `catch` blocks for specific exceptions. This enables more granular control over error management and allows for different responses to different error conditions.
[Read more about Handling Multiple Exceptions](./4.HandlingMultpleExceptions/README.md)

## Stack Unwinding

Stack unwinding is a process during which the C++ runtime system cleans up the stack, unwinding it to the state before the exception was thrown. We covered how local objects are destructed in the reverse order of their construction.
[Read more about Stack Unwinding](./5.StackUnwindingAndHowItWorks/README.md)

## Creating User-Defined Exception Classes

We went through the creation of user-defined exceptions by inheriting from the standard `std::exception` class. This allows for custom error messages and handling mechanisms tailored to specific application needs.
[Read more about Creating User-Defined Exception Classes](./6.CreatingUserDefinedExceptionsClasses/README.md)

## Class-Level Exceptions

We provided an example of implementing class-level exceptions, which are exceptions thrown from member functions of a class that also contains nested exception classes.
[Read more about Class-Level Exceptions](./7.ClassLevelExceptions/README.md)

## The C++ `std::exception` Class Hierarchy

Lastly, we explored the hierarchy of standard exception classes provided by the C++ standard library. We discussed how to use these built-in exceptions and how to extend them with custom exception classes for application-specific error handling.
[Read more about The C++ `std::exception` Class Hierarchy](./8.TheC++std::exceptionsClassHierarchy/README.md)