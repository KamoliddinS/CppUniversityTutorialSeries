def fib(n):
    if n < 2:
        return n
    return fib(n - 1) + fib(n - 2)


n = 27  # raise this to 35 when you measure the time
print(f"fib({n}) = {fib(n)}")
