# 14 · Templates

After this chapter you can write one function or class that works for many types. Such a
pattern is called a **template**.

| # | Lesson | You learn to |
|---|--------|--------------|
| 1 | [Function templates](01-function-templates/README.md) | write one function for many types, and read the errors of a call that does not fit |
| 2 | [Class templates](02-class-templates/README.md) | write a class that holds values of any type, and put it in a header |

**Practice:** [Exercises](exercises/README.md)

## Key terms

| Term | Meaning |
|------|---------|
| template | a pattern from which the compiler writes real functions or classes, one for each type you use |
| function template | a pattern for functions: the body is written once and the type is left open |
| template parameter | a name in a template, usually `T`, that stands for a type |
| deduction | the compiler works out a template parameter from the arguments of a call |
| instantiation | the compiler writes a real function or class from a template, for one type |
| class template | a pattern for classes with a type left open, such as `std::vector` |
| template argument | the type that takes the place of a template parameter: the `int` in `Box<int>` |
