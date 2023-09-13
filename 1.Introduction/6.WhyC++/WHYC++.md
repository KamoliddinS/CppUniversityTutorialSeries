

# Why We Teach C++ Over Simpler Languages

## Performance Comparison

When we executed a simple Fibonacci calculation in both C++ and Python, we observed the following timings:


- **C++**: `0.07s`
- **Python**: `1.76s`

C++ executed the same task around 25 times faster than Python. This demonstrates the raw computational efficiency of languages like C++ over interpreted languages like Python.
plsease refer to src folder for the code used to test the performance.
you can make C++ code run faster by using the following command:
```bash
 make all 
```
then you can run the code by using the following command:
```bash
 time ./fibonacci
```
you can make python code run faster by using the following command:
```bash
 time python3 fibonacci.py
```

## Advantages of C++

1. **Performance**: As demonstrated, C++ offers superior performance, which is critical for applications like gaming, real-time simulations, and high-frequency trading.
2. **Memory Management**: C++ provides fine-grained control over memory management, which is crucial for performance-critical applications.
3. **Systems Programming**: For systems programming and embedded systems, C++ is often preferred due to its performance and control.
4. **Object-Oriented and Low-Level Features**: C++ supports both high-level object-oriented programming and low-level memory operations.
5. **Libraries and Frameworks**: Numerous libraries and frameworks are optimized for C++, particularly in areas like graphics, game development, and high-performance computing.

## Why Not Simpler Languages?

Languages like Python are powerful, flexible, and easy to learn. They're great for rapid development, prototyping, and many applications like web development and data science. However, they don't offer the same level of control and performance optimization as C++. 

When you understand C++, you gain insights into how computers work at a fundamental level. This foundational knowledge can make you a better programmer, even if you work in higher-level languages.

## Combining the Strengths: Using C++ with Python

One of the beautiful things about programming is that you don't always have to choose one language over the other. You can harness the strengths of C++ within a Python environment. Here's how:

### Creating a C++ Shared Library

1. Write your C++ code with a C-style interface.
2. Compile it to a shared library:
   ```bash
   g++ -O2 -fPIC -shared -o your_library_name.so your_cpp_file.cpp
   ```

### Using the C++ Shared Library in Python

1. In Python, use the `ctypes` library to load and call functions from the shared library:

   ```python
   import ctypes
   
   lib = ctypes.CDLL('./your_library_name.so')
   
   # Define the argument and return types
   lib.your_function_name.argtypes = [ctypes.c_int]  # Adjust the types accordingly
   lib.your_function_name.restype = ctypes.c_int    # Adjust the return type
   
   # Call the function
   result = lib.your_function_name(your_argument)
   ```
### Example
to create the sample shared library you can use the following command:
```bash
make libfibonacci.so
```
then you can run the code by using the following command:
```bash
time python3 fibonacci_on_steroids.py
```

This way, you can build high-level applications in Python and offload performance-critical sections to C++ modules. For this example it now takes `0.08s` to execute the Fibonacci calculation in Python, which is the same as the C++ version.
