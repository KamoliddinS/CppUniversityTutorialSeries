def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n-1) + fibonacci(n-2)

n = 35  # Adjust this value for longer/shorter computation times
print(fibonacci(n))