# 09 · Pointers and memory

After this chapter you can read and write code that uses addresses, and you know what can go wrong.

| # | Lesson | You learn to |
|---|--------|--------------|
| 1 | [Addresses and pointers](01-addresses-and-pointers/README.md) | store the address of a variable in a pointer and use it |
| 2 | [Pointers and arrays](02-pointers-and-arrays/README.md) | walk through an array with a pointer |
| 3 | [Const and pointers](03-const-and-pointers/README.md) | read `const int*` and `int* const` correctly |
| 4 | [Pointers or references](04-pointers-or-references/README.md) | choose between a pointer and a reference |
| 5 | [Stack and heap](05-stack-and-heap/README.md) | create objects that outlive a function with `new` and `delete` |
| 6 | [What goes wrong](06-what-goes-wrong/README.md) | recognise leaks, dangling pointers and double deletes, and find them with the sanitizer |
| 7 | [Function pointers](07-function-pointers/README.md) | pass a function to another function |

**Practice:** [Exercises](exercises/README.md)

## Key terms

| Term | Meaning |
|------|---------|
| address | the number of the place in memory where a variable lives |
| pointer | a variable that holds an address |
| dereference | follow a pointer to the variable it points to: `*p` |
| null pointer | a pointer that points to nothing; its value is `nullptr` |
| decay | an array name turning into a pointer to its first element |
| pointer to const | a pointer that cannot be used to change its target: `const int* p` |
| stack | the memory for local variables; cleaned up automatically at the closing `}` |
| heap | the memory for objects created with `new`; they live until `delete` |
| owner | the part of the program that must delete a heap object, exactly once |
| memory leak | heap memory that is never given back |
| dangling pointer | a pointer that holds the address of an object that no longer exists |
| function pointer | a pointer that holds the address of a function |
