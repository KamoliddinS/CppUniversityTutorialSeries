
# Structure of a C++ Program

Welcome to the guide on the structure of a C++ program. This document provides an overview of the fundamental components and organization of a typical C++ program.
## 
1. [**CPP keywords**](https://en.cppreference.com/w/cpp/keyword)
This is a list of reserved keywords in C++. Since they are used by the language, these keywords are not available for re-definition or overloading.

2. **Idetifiers**: These are names given to entities such as variables, functions, classes, etc. They must follow certain rules and conventions.

   ```cpp
   int myVariable;

    void displayMessage() {
         // code
    }
   ```
3. **Statements**: These are instructions that perform a specific task. They must end with a semicolon. A statement is a single line of code that does something. Or small piece of code that does something.

   ```cpp
    std::cout << "Hello, C++!";

    int myVariable = 10;

    if (myVariable > 5) { //this is expression
        // code
    }

    return 0;

    ```
3. **Expressions**: These are combinations of operators, constants, and variables that produce a value.

   ```cpp
    2 + 3;

    myVariable + 5;

    myVariable > 5;
    ```
4. **Punctuators**: These are symbols that are used to separate or combine expressions. Examples include brackets, commas, colons, and more.

   ```cpp
    int myVariable = 10;

    if (myVariable > 5) {
        // code
    }
    ```



## Basic Structure

A C++ program consists of one or more source files (`.cpp` extensions). Each source file contains:

1. **Headers/Includes**: These are files that provide declarations for functions, classes, and variables that can be used in the program. They typically have a `.h` or `.hpp` extension.

   ```cpp
   #include <iostream>
   ```

2. **Main Function**: Every C++ program must have a `main` function. It's the entry point where the program starts execution.

   ```cpp
   int main() {
       // code
       return 0;
   }
   ```

3. **Function Definitions**: A C++ program can contain multiple functions. These functions are defined with a return type, name, parameters, and a body.

   ```cpp
   void displayMessage() {
       std::cout << "Hello, C++!";
   }
   ```

4. **Class Definitions**: If the program is using object-oriented programming, it will contain class definitions.

   ```cpp
   class MyClass {
       int data;
   public:
       void setData(int d) {
           data = d;
       }
   };
   ```

5. **Global and Local Variables**: Variables can be defined globally (outside any function or class) or locally (inside functions or classes).

6. **Comments**: Comments are used to describe the code and are ignored by the compiler.

   ```cpp
   // This is a single-line comment
   
   /* 
   This is a 
   multi-line comment
   */
   ```

## Program Flow

1. **Sequential Execution**: By default, statements in C++ are executed sequentially from top to bottom.

2. **Control Structures**: These alter the flow of execution. Examples include `if`, `switch`, `while`, `for`, and more.

3. **Function Calls**: When a function is called, the flow of execution moves to that function. Once the function completes, execution returns to the point where the function was called.

## Compilation and Linking

1. **Compilation**: The C++ compiler translates the source code into machine code, producing an object file (`.o` or `.obj` extension).

2. **Linking**: The linker combines multiple object files and external libraries to produce the final executable.

## Conclusion

Understanding the basic structure and flow of a C++ program is crucial for effective programming. This guide provides a foundational overview, and as you delve deeper into C++, you'll encounter more advanced structures and concepts.
