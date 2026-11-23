# 04 · Functions

After this chapter you can split a program into small named pieces that take input and give back results.

| # | Lesson | You learn to |
|---|--------|--------------|
| 1 | [Define and call](01-define-and-call/README.md) | write a function and use it |
| 2 | [Parameters and return values](02-parameters-and-return-values/README.md) | pass values in and get a result back |
| 3 | [Pass by value and by reference](03-pass-by-value-and-by-reference/README.md) | decide whether a function works on a copy or on the original |
| 4 | [Const references](04-const-references/README.md) | pass big values without copying and without the risk of changing them |
| 5 | [Function declarations](05-function-declarations/README.md) | call a function that is defined later in the file |
| 6 | [Default arguments and overloading](06-default-arguments-and-overloading/README.md) | let a call leave out arguments, and give one name to several functions |
| 7 | [Scope and lifetime](07-scope-and-lifetime/README.md) | say where a name can be used and how long its variable exists |
| 8 | [Recursion](08-recursion/README.md) | write a function that calls itself, and make sure that it stops |

**Practice:** [Exercises](exercises/README.md)

## Key terms

| Term | Meaning |
|------|---------|
| function | a named block of code that does one job |
| parameter | a variable in the first line of a function; it gets its value from the call |
| argument | a value written in a call; it goes into the parameter at the same position |
| pass by value | the parameter is a copy of the argument, so the function cannot change the caller's variable |
| reference | another name for an existing variable; a parameter written with `&` is one |
| declaration | the first line of a function followed by `;`; it says that the function exists |
| definition | the function with its body; it says what the function does |
| overloading | giving several functions the same name; their parameter lists must differ |
| scope | the part of the code where a name can be used |
| lifetime | the time during which a variable exists |
| recursion | solving a problem with a function that calls itself |
| base case | the case that a recursive function answers without calling itself |
