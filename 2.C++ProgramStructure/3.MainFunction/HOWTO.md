# How to Compile and Run the C++ Program

This guide provides detailed instructions on how to compile and run the C++ program `main.cpp`. Follow the steps below to successfully compile the source code and execute the resulting binary.

## Prerequisites

1. Ensure you have a C++ compiler installed. This guide assumes you're using the `g++` compiler, which is part of the GNU Compiler Collection (GCC).
2. Ensure you have the source file `main.cpp` available.

## Compilation

1. **Open a Terminal or Command Prompt**: Navigate to the directory containing the `main.cpp` file.

2. **Compile the Source Code**: Use the following command to compile the `main.cpp` file:

   ```bash
   g++ main_demo.cpp -o main_demo
   ```

   This command tells the `g++` compiler to compile the `main.cpp` file and produce an executable named `main_function`.

3. After successful compilation, you should see a new file named `main_function` (or `main_function.exe` on Windows) in the directory. This is the executable binary.

## Execution

1. **Run the Executable**: To run the program without any command-line arguments, use:

   ```bash
   ./main_function
   ```

   On Windows, you can simply use:
   ```bash
   main_function
   ```

2. **Run with Command-Line Arguments**: To provide command-line arguments, append them after the executable's name:

   ```bash
   ./main_function arg1 arg2 arg3
   ```

   This will pass `arg1`, `arg2`, and `arg3` as arguments to the program.

3. Observe the output. If you provided command-line arguments, the program should display the number of arguments and list each argument.

## Conclusion

You've successfully compiled and run the C++ program `main.cpp`. By following this guide, you can easily compile and execute other C++ programs in a similar manner. If you encounter any issues or have further questions, refer to the compiler documentation or seek assistance from online forums and communities.
