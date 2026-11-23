# Function templates

> **Goal:** write one function that works for many types.

## The same body, three times

With [overloading](../../04-functions/06-default-arguments-and-overloading/README.md),
you write `larger` once for each type:

<!-- snippet: overloads.cpp -->
```cpp
int larger(int a, int b) {
    return (a > b) ? a : b;
}

double larger(double a, double b) {
    return (a > b) ? a : b;
}

std::string larger(std::string a, std::string b) {
    return (a > b) ? a : b;
}
```

<!-- no-output: overloads -->

Only the type differs. A **function template** is a pattern for such functions: you write
the body once and leave the type open.

**`larger.cpp`**
<!-- file: larger.cpp -->
```cpp
#include <iostream>
#include <string>

template <typename T>
T larger(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::string first = "Samarkand";
    std::string second = "Tashkent";

    std::cout << larger(3, 7) << '\n';            // T is int
    std::cout << larger(2.5, 1.5) << '\n';        // T is double
    std::cout << larger(first, second) << '\n';   // T is std::string
}
```

<!-- output: larger -->
```text
7
2.5
Tashkent
```

- `template <typename T>` makes `T` a **template parameter**: a name that stands for a type.
- The compiler works out `T` from the arguments of each call: **deduction**.
- For each `T` you use, the compiler writes one real function from the pattern:
  **instantiation**.

## Two arguments, two answers for T

<!-- snippet: mixed_nocompile.cpp -->
```cpp
std::cout << larger(1, 2.5) << '\n';   // is T int or double?
```

<!-- errors: mixed_nocompile -->
```text
mixed_nocompile.cpp: In function ‘int main()’:
mixed_nocompile.cpp:9:24: error: no matching function for call to ‘larger(int, double)’
    9 |     std::cout << larger(1, 2.5) << '\n';   // is T int or double?
      |                  ~~~~~~^~~~~~~~
mixed_nocompile.cpp:4:3: note: candidate: ‘template<class T> T larger(T, T)’
    4 | T larger(T a, T b) {
      |   ^~~~~~
mixed_nocompile.cpp:4:3: note:   template argument deduction/substitution failed:
mixed_nocompile.cpp:9:24: note:   deduced conflicting types for parameter ‘T’ (‘int’ and ‘double’)
    9 |     std::cout << larger(1, 2.5) << '\n';   // is T int or double?
      |                  ~~~~~~^~~~~~~~
```

Read the last note: `1` says `int`, `2.5` says `double`. The compiler does not convert
while it deduces, so it stops. Say the type yourself: in `larger<double>(1, 2.5)` the `1`
is converted to `1.0`.

## A type that cannot do what the body needs

The parameters are now `const T&`, so a big `T` is not copied
([Const references](../../04-functions/04-const-references/README.md)).

**`no_operator_nocompile.cpp`**
<!-- file: no_operator_nocompile.cpp -->
```cpp
#include <iostream>
#include <string>

struct Book {
    std::string title;
    int pages = 0;
};

template <typename T>
T larger(const T& a, const T& b) {
    return (a > b) ? a : b;   // needs > for T
}

int main() {
    Book atlas{"Atlas", 120};
    Book novel{"O'tkan kunlar", 400};
    Book thicker = larger(atlas, novel);
    std::cout << thicker.title << '\n';
}
```

<!-- errors: no_operator_nocompile -->
```text
no_operator_nocompile.cpp: In instantiation of ‘T larger(const T&, const T&) [with T = Book]’:
no_operator_nocompile.cpp:17:26:   required from here
no_operator_nocompile.cpp:11:15: error: no match for ‘operator>’ (operand types are ‘const Book’ and ‘const Book’)
   11 |     return (a > b) ? a : b;   // needs > for T
      |            ~~~^~~~
```

| In the message | Meaning |
|----------------|---------|
| `In instantiation of ... [with T = Book]` | the compiler was writing `larger` for `Book` |
| `17:26: required from here` | because of **your** call on line 17 |
| `11:15: error: no match for 'operator>'` | on line 11, `a > b` does not work for a `Book` |

The template is correct. When an error is reported inside a template, look for
`required from here`: that line is yours. Here, `Book` needs an `operator>`
([Comparison operators](../../08-operator-overloading/03-comparison-operators/README.md)).

## Two other spellings

- C++20 short form: `auto larger(auto a, auto b)` is a function template too. Each `auto`
  is a template parameter of its own, so `larger(1, 2.5)` builds.
- Old code uses macros (`#define`) instead: plain text replacement with no type checking.

## Watch out

- Do not name a template `max` or `min`: `std::max` and `std::min` exist already. A call
  with `std::string` arguments finds both: `call of overloaded 'max(...)' is ambiguous`.
- Text in quotes is not a `std::string`. With `larger.cpp`, `larger("pear", "apple")`
  builds, but it compares two addresses, not the texts. Write
  `larger<std::string>("pear", "apple")`.

## Try it

1. Predict what each call returns, then check: `larger('a', 'b')` and `larger<int>(1, 2.5)`.
2. Make `no_operator_nocompile.cpp` build: give `Book` an `operator>` that compares `pages`.

<details>
<summary>Answers</summary>

1. `b`, then `2`: you said `int`, so `2.5` is converted to `2`.
2. After the struct: `bool operator>(const Book& a, const Book& b) { return a.pages > b.pages; }`
   The program prints `O'tkan kunlar`.
</details>

**Next:** [Class templates](../02-class-templates/README.md)
