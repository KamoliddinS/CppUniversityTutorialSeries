# 07 · Classes

After this chapter you can write your own types that protect their data and are always in a valid state.

| # | Lesson | You learn to |
|---|--------|--------------|
| 1 | [From struct to class](01-from-struct-to-class/README.md) | keep data private and offer functions that keep it valid |
| 2 | [Constructors](02-constructors/README.md) | make sure every object starts valid |
| 3 | [Destructors and lifetime](03-destructors-and-lifetime/README.md) | say when an object is created and destroyed |
| 4 | [Const member functions](04-const-member-functions/README.md) | promise that a function does not change the object |
| 5 | [Static members and friends](05-static-members-and-friends/README.md) | share data between all objects of a class, and let a chosen function use private members |
| 6 | [Headers and source files](06-headers-and-source-files/README.md) | split a class into a `.h` and a `.cpp` file |

**Practice:** [Exercises](exercises/README.md)

## Key terms

| Term | Meaning |
|------|---------|
| class | a type you define that holds data together with the functions that work on it |
| object | a variable whose type is a class |
| member function | a function that belongs to a class and is called on an object: `account.deposit(500)` |
| private | usable only inside the class's own functions; `public` members are usable by all code |
| invariant | a condition that is always true for a valid object, such as "the balance is never negative" |
| constructor | the member function that runs automatically when an object is created and gives the members their first values |
| default constructor | a constructor that can be called without arguments |
| destructor | the member function `~Name()` that runs automatically when an object's life ends |
| const member function | a member function that promises not to change the object; the only kind a const object can call |
| static member | a member that exists once for the whole class, not once for each object |
| friend | a function or class that a class allows to use its private members |
| header file | a file such as `account.h` with the declarations that other files bring in with `#include` |
