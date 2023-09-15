# C++ Runtime Errors

## What is a Runtime Error?

A runtime error is a mistake that happens when your C++ program is running. It means your program stops suddenly because of this mistake.

## Common C++ Runtime Errors

1. **Division by Zero**: When you try to divide a number by zero.
   ```cpp
   int a = 5;
   int b = 0;
   int result = a / b; // This will cause a runtime error.

2. **Null Pointer Access**: When you try to use a pointer that doesn't point to anything.

    ```cpp
    int* ptr = nullptr;
    *ptr = 10; // This will cause a runtime error.
    ```
3. **Array Out of Bounds**: When you try to access an element in an array that doesn't exist.

```cpp
int arr[5];
arr[10] = 100; // This will cause a runtime error.
```

4. **Bad Memory Access**: When you try to access memory that your program shouldn't.
    
    ```cpp  
    int* ptr = new int[5];
    delete[] ptr;
    ptr[3] = 50;// This will cause a runtime error because ptr was deleted.
    ``` 


## How to Fix Runtime Errors?

1. **Read the Error Message**: The computer will give a message when there's a runtime error. This message can help you find where the mistake is.

2. **Check Your Code**: Look at the part of your code where the error happened. Think about what your code is doing and if it makes sense.

3. **Ask for Help**: If you can't find the mistake, ask a friend or teacher. Sometimes, another person can see something you missed.

4. **Test Your Code**: After you think you've fixed the error, run your program again to see if it works.

###### For further reading please visit: [geeksforgeeks.com](https://www.geeksforgeeks.org/reason-of-runtime-error-in-c-c/)

