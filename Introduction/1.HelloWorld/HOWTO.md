
# Introduction to C++ Programming

HelloWorld project. This project aims to provide a basic understanding of how a simple C++ program is structured and executed.

## Project Structure

- `src/`: This directory contains the source code for our simple C++ program.
- `CMakeLists.txt`: A configuration file for the CMake build system. It provides instructions on how to build the project.
- `Makefile`: A script for the `make` build automation tool. It defines rules to build and link the source code files in our project.

## The C++ Program

Here's a breakdown of our simple program located in the `src/` directory:

```cpp
#include <iostream> // This tells the computer to use a tool for showing words on the screen.

int main() {  // This is the starting point of our program.
    std::cout << "Hello, World!" << std::endl; // This tells the computer to show "Hello, World!" on the screen.
    return 0;
}
```

- The `#include <iostream>` directive allows us to use tools for input and output operations, like displaying text on the screen.
- The `int main()` function is the starting point of our program. Every C++ program must have a `main` function.
- The `std::cout` statement is used to display the message "Hello, World!" on the screen.

## Building and Running the Program

### Using the Makefile:

If you have a direct `Makefile` set up for the project:

1. Open a terminal or command prompt.
2. Navigate to the project directory:
   ```bash
   cd src
   ```

3. Build the project using the `make` command:
   ```bash
   make
   ```

4. Once built, you can run the generated executable:
   ```bash
   ./helloworld
   ```

### Using CMake:

If you're using the `CMakeLists.txt` to generate build files:

1. Open a terminal or command prompt.
2. Navigate to the project directory:
   ```bash
   cd src
   ```

3. Create a build directory and navigate into it:
   ```bash
   mkdir build
   cd build
   ```

4. Generate the build files using CMake:
   ```bash
   cmake ../src
   ```

5. Build the project:
   ```bash
   make
   ```

6. Once built, you can run the generated executable:
   ```bash
   ./helloworld
   ```

## Conclusion

This project serves as a starting point for understanding the basics of C++ programming. The provided build steps guide you through compiling and running the program. As you progress in the course, you'll explore more advanced concepts and build upon this foundation. Happy coding!
