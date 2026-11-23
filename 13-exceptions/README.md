# 13 · Exceptions

After this chapter your programs can report errors and recover from them without leaking resources.

| # | Lesson | You learn to |
|---|--------|--------------|
| 1 | [Throw and catch](01-throw-and-catch/README.md) | report an error with `throw` and handle it somewhere else |
| 2 | [Standard exceptions](02-standard-exceptions/README.md) | catch the standard library's error types, the most specific one first |
| 3 | [Stack unwinding](03-stack-unwinding/README.md) | say what is cleaned up while an exception travels, and what leaks |
| 4 | [Your own exceptions](04-your-own-exceptions/README.md) | write an exception class and use `noexcept` |
| 5 | [Exceptions or return values](05-exceptions-or-return-values/README.md) | pick the right way to report a failure |

**Practice:** [Exercises](exercises/README.md)

## Key terms

| Term | Meaning |
|------|---------|
| exception | an object that describes a problem; a function throws it when it cannot do its job |
| `throw` | the statement that leaves a function at once and sends an exception to a handler |
| `try` block | the code that a handler watches |
| handler | a `catch` block: the code that runs when an exception of its type arrives |
| `what()` | the member function that returns the message of a standard exception |
| uncaught exception | an exception that finds no handler; it ends the program |
| rethrow | pass the exception that a handler caught on to the next handler, with `throw;` |
| stack unwinding | destroying the local objects of every function that an exception leaves |
| `noexcept` | a promise that no exception leaves a function; breaking it ends the program |
| `std::optional` | a type that holds either one value or nothing |
