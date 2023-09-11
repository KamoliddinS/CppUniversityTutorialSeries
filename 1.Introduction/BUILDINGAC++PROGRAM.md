
# Building a C++ Program from Source to Executable

The process of building a C++ program can be broken down into a series of steps. Here's an overview of the process:

1. **Preprocessing**
    - This stage involves expanding macros, including header files, and performing conditional compilation. The preprocessor takes the source code (`*.cpp` file) and produces an intermediate expanded source code.

2. **Compilation**
    - During this stage, the expanded source code is translated into assembly code by the compiler. The output of this phase is an assembly code file, typically with a `.s` or `.asm` extension.

3. **Assembly**
    - The assembly code is then converted into machine code by the assembler. This produces an object file, typically with a `.o` or `.obj` extension.

4. **Linking**
    - The linker combines one or more object files with libraries to produce the final executable. The output is typically a binary file with a `.exe` (for Windows) or no extension (for UNIX/Linux) which is ready to be executed.

## Diagram

Here's a simple ASCII-based diagram to represent the process:

```
+-------+     +-------------------+     +-------------+     +-----------+
| *.cpp | --> | Preprocessor      | --> | Compiler    | --> | Assembler |
+-------+     +-------------------+     +-------------+     +-----------+
                                            |                     |
                                            V                     V
                                        +-------+            +---------+
                                        | *.s   |            | *.o     |
                                        +-------+            +---------+
                                                                 |
                                                                 V
                                                           +------------+
                                                           | Linker     |
                                                           +------------+
                                                                 |
                                                                 V
                                                            +------------+
                                                            | Executable |
                                                            +------------+
```
