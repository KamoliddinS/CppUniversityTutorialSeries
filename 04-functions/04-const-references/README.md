# Const references

> **Goal:** pass a big value to a function without copying it and without the risk of changing it.

## Two ways, two problems

A `std::string` can hold a whole page of text.

- By value, `std::string title`, the call `printTitle(city)` copies every character of
  `city`. That is wasted work.
- By reference, `std::string& title`, nothing is copied. But the function could change
  your text by mistake, and the last call below does not build.

**`title_nocompile.cpp`**
<!-- file: title_nocompile.cpp -->
```cpp
#include <iostream>
#include <string>

void printTitle(std::string& title) {       // a plain reference
    std::cout << "== " << title << " ==\n";
}

int main() {
    std::string city = "Samarkand";
    printTitle(city);
    printTitle(city + " 2026");
}
```

<!-- errors: title_nocompile -->
```text
title_nocompile.cpp: In function ‘int main()’:
title_nocompile.cpp:11:21: error: cannot bind non-const lvalue reference of type ‘std::string&’ {aka ‘std::__cxx11::basic_string<char>&’} to an rvalue of type ‘std::__cxx11::basic_string<char>’
   11 |     printTitle(city + " 2026");
      |                ~~~~~^~~~~~~~~
title_nocompile.cpp:4:30: note:   initializing argument 1 of ‘void printTitle(std::string&)’
    4 | void printTitle(std::string& title) {       // a plain reference
      |                 ~~~~~~~~~~~~~^~~~~
```

Read the first error line only. A reference without `const` needs a variable. The result
of `city + " 2026"` is a value without a name, which the compiler calls an *rvalue*. A
literal such as `"Khiva"` fails the same way. (`basic_string<char>` is the compiler's long
name for `std::string`.)

## `const` and `&` together

**`title.cpp`**
<!-- file: title.cpp -->
```cpp
#include <iostream>
#include <string>

void printTitle(const std::string& title) {     // no copy, no change
    std::cout << "== " << title << " ==\n";
}

int main() {
    std::string city = "Samarkand";
    printTitle(city);               // a variable
    printTitle(city + " 2026");     // a result that has no name
    printTitle("Khiva");            // a literal
}
```

<!-- output: title -->
```text
== Samarkand ==
== Samarkand 2026 ==
== Khiva ==
```

- `&` makes `title` a reference, so the text of `city` is not copied.
- `const` means the function may read `title` but not change it. An assignment to `title`
  inside the function does not compile, as with a
  [constant](../../02-values-and-types/06-constants/README.md).
- Because the function cannot change anything, the compiler also accepts a value without
  a name and a literal.

## Which one to use

| The function | Parameter | Example |
|--------------|-----------|---------|
| reads a small value: `int`, `double`, `char`, `bool` | by value | `int price` |
| reads a big value: `std::string`, later vectors and your own types | by `const` reference | `const std::string& name` |
| must change the caller's variable | by reference | `int& score` |

## Watch out

- `const std::string title` without `&` builds, but it copies again. You need both.

## Try it

1. Which parameter do you write for a function that (a) prints a name, (b) adds 1 to the
   caller's counter, (c) returns the square of a number, (d) reads a city into the
   caller's variable?
2. In `title.cpp`, remove `const`. Which of the three calls still build?

<details>
<summary>Answers</summary>

1. (a) `const std::string& name`, (b) `int& counter`, (c) `int number`, (d) `std::string& city`.
2. Only `printTitle(city)`. The other two give the error from the top of this page.
</details>

**Next:** [Function declarations](../05-function-declarations/README.md)
