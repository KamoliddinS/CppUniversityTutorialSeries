# Introduction to C++ Programming

Welcome to the world of C++ programming! This guide will help you set up, compile, and run your first C++ program.

## 1. What is C++?

- C++ is a computer programming language.
- It is used to instruct the computer on what actions to perform.
- C++ is versatile and is used in various applications ranging from games to banking systems and even space missions!

## 2. Why Learn C++?

- It's a powerful language that allows for a wide range of applications.
- Many companies and industries use C++.
- Learning C++ enhances problem-solving skills.

## 3. Basic Concepts in C++

- **Program:** A set of instructions for the computer.
- **Compiler:** A tool that translates your C++ program into machine code.
- **Code:** The set of instructions you write in C++.

## 4. Your First C++ Program

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, World!";
    return 0;
}
```

## 5. Compiling and Running the Program

### please refer to the [link](./HOWTO.md) for the full instructions

## 6. Important Points to Remember

- **Errors:** If the computer doesn't understand the code, it will show an error. It's a part of the learning process. Fix the errors and try again.
- **Practice:** The more you code, the better you'll get.
- **Ask Questions:** If something is unclear, always ask. Learning is a collaborative process.

## 7. Conclusion

C++ is a fascinating and powerful language. With practice and dedication, you can master it and use it to create amazing applications. Happy coding!





## Build System Overview

When working on software projects, understanding the build system in use is crucial. This section provides a brief overview of two commonly encountered components: `Makefile` and `CMakeLists.txt`.

### `Makefile`

- **What is it?** A script used by the `make` build automation tool. It defines rules to build and link the source code files in a project.
  
- **Key Components:**
  - **Targets:** Desired output files (e.g., executables or object files).
  - **Dependencies:** Files that the targets rely on.
  - **Commands:** Shell commands executed to produce the targets from the dependencies.

- **Usage:** Run the `make` command in a directory containing a `Makefile`. The `make` tool reads the file, checks the dependencies of the targets, and executes the necessary commands.

- **Limitations:** `Makefile`s can be platform-specific. For cross-platform projects, you might need multiple `Makefile`s or a complex one to handle different platforms.

### `CMakeLists.txt`

- **What is it?** A configuration file for the `CMake` build system generator. Instead of directly building the project, CMake uses `CMakeLists.txt` to generate platform-specific build scripts.

- **Key Components:**
  - **Project Configuration:** Details about the project, such as its name and the required C++ standard.
  - **Source Files:** Lists of source and header files.
  - **Dependencies:** External libraries or packages the project needs.
  - **Build Instructions:** Directions on building the project, including compiler flags, include directories, and link libraries.

- **Usage:** Execute `cmake` in a directory (preferably a separate "build" directory) pointing to the directory with `CMakeLists.txt`. CMake then produces the build scripts for your platform, which can be a `Makefile`, Visual Studio project files, etc. After this, you can run `make` or the equivalent build command for your system.

- **Advantages:** CMake offers platform independence. With a single `CMakeLists.txt`, CMake can produce build scripts for a vast range of platforms and compilers.

---

Remember, understanding your build system is essential for efficient development and troubleshooting. Whether you're using `make`, `CMake`, or another system, always refer to the documentation and best practices for optimal results.




## C++ Naming Conventions

Maintaining a consistent naming convention is crucial for readability and maintainability. While C++ doesn't enforce any specific naming rules, the following conventions are commonly adopted in the community:

### 1. **Camel Case**:
- **Upper Camel Case (Pascal Case):** Each word starts with a capital letter. 
  - Example: `ClassName`, `FunctionName`.
- **Lower Camel Case:** The first word is lowercase, but subsequent words are capitalized.
  - Example: `localVariable`, `functionArgument`.

### 2. **Snake Case**:
- Words are separated by underscores and are all lowercase.
  - Example: `local_variable`, `function_name`, `class_name`.

### 3. **Hungarian Notation** (less popular in modern C++):
- Variables are prefixed with letters indicating their type or scope.
  - Example: `pPointer`, `iInteger`, `strString`.

### Specific Naming Patterns:

- **Classes and Structs:** Typically use Upper Camel Case.
  - Example: `MyClass`, `CarEngine`.
  
- **Functions and Methods:** Can be either Upper Camel Case or snake_case.
  - Example: `DoSomething()` or `do_something()`.
  
- **Variables:** Typically use lower camel case or snake_case.
  - Example: `localVariable` or `local_variable`.
  
- **Constants:** Often all uppercase with underscores.
  - Example: `PI`, `MAX_VALUE`.
  
- **Member Variables:** Some conventions include prefixes like `_`, `m_`, or `m`.
  - Example: `_memberVariable`, `m_memberVariable`, `mMemberVariable`.
  
- **Global Variables:** Some conventions include prefixes like `g_` or `g`.
  - Example: `g_globalVariable` or `gGlobalVariable`.
  
- **Namespaces:** Typically lowercase.
  - Example: `namespace utilities`.
  
- **Template Parameters:** Often a single uppercase letter or Upper Camel Case.
  - Example: `T` or `ValueType`.
  
- **Macros:** Typically all uppercase with underscores.
  - Example: `#define MAX_LENGTH 100`.

### Recommendations:

1. **Prioritize Consistency:** Ensure naming conventions are consistent throughout the project.
2. **Use Descriptive Names:** Names should clearly convey the purpose or usage.
3. **Limit Abbreviations:** Use full words unless the abbreviation is widely recognized.
4. **Follow Project Guidelines:** If contributing to an existing project, adhere to its established conventions.

By adhering to these conventions, we aim to keep our codebase clear, readable, and easy to maintain.
