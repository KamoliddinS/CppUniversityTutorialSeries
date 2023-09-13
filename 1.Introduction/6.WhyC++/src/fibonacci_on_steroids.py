import ctypes

# Load the shared library
libfib = ctypes.CDLL('./libfibonacci.so')

# Define the argument and return types
libfib.fibonacci.argtypes = [ctypes.c_int]
libfib.fibonacci.restype = ctypes.c_int

# Call the function
n = 35
print(libfib.fibonacci(n))