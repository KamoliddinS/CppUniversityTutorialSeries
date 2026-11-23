# Text, characters and booleans

> **Goal:** store text in a `std::string`, one character in a `char`, and a yes-or-no answer in a `bool`.

## Text: `std::string`

A **string** is a piece of text. Its type is `std::string`, and it needs `#include <string>`.

**`full_name.cpp`**
<!-- file: full_name.cpp -->
```cpp
#include <iostream>
#include <string>

int main() {
    std::string first = "Malika";
    std::string last = "Karimova";
    std::string full = first + " " + last;      // + joins strings

    std::cout << full << '\n';
    std::cout << full.size() << " characters\n";
}
```

<!-- output: full_name -->
```text
Malika Karimova
15 characters
```

- `+` joins strings. Nothing adds the space for you.
- `full.size()` gives the length of the string. The space counts.

## Joining needs a `std::string`

**`join_nocompile.cpp`**
<!-- file: join_nocompile.cpp -->
```cpp
#include <iostream>
#include <string>

int main() {
    std::string city = "Samar" + "kand";
    std::cout << city << '\n';
}
```

<!-- errors: join_nocompile -->
```text
join_nocompile.cpp: In function ‘int main()’:
join_nocompile.cpp:5:32: error: invalid operands of types ‘const char [6]’ and ‘const char [5]’ to binary ‘operator+’
    5 |     std::string city = "Samar" + "kand";
      |                        ~~~~~~~ ^ ~~~~~~
      |                        |         |
      |                        |         const char [5]
      |                        const char [6]
```

Text in quotes is not a `std::string` yet. The compiler calls it `const char [6]` (five
letters and a hidden end mark), and `+` cannot join two of those. At least one side of `+` must be a `std::string`: store `"Samar"`
in a `std::string` variable first.

## One character: `char`

**`letter.cpp`**
<!-- file: letter.cpp -->
```cpp
#include <iostream>

int main() {
    char grade = 'B';           // single quotes: exactly one character
    int code = grade;           // a char is stored as a small number
    char better = grade - 1;    // so you can calculate with it

    std::cout << grade << " is stored as " << code << '\n';
    std::cout << "One step better: " << better << '\n';
}
```

<!-- output: letter -->
```text
B is stored as 66
One step better: A
```

| You write | Type | Holds |
|-----------|------|-------|
| `'B'` | `char` | exactly one character |
| `"B"` | text | text that is one character long |
| `'\n'` | `char` | the new-line character |

A `char` is really a small number: the code of the character. On all your systems `'A'` is
65, `'B'` is 66, and so on, so `grade - 1` is the letter before.

## True or false: `bool`

**`passed.cpp`**
<!-- file: passed.cpp -->
```cpp
#include <iostream>

int main() {
    bool passed = true;
    bool late = false;

    std::cout << passed << ' ' << late << '\n';
    std::cout << std::boolalpha;                    // from here on: words
    std::cout << passed << ' ' << late << '\n';
}
```

<!-- output: passed -->
```text
1 0
true false
```

A `bool`, short for boolean, holds `true` or `false` and nothing else. It prints as `1`
or `0`. After `std::boolalpha`, `std::cout` prints the words instead. A comparison such as
`score >= 60` gives a `bool`; [chapter 3](../../03-control-flow/README.md) uses that.

## Watch out

- `char grade = "B";` does not compile. Double quotes always mean text.
- `+` does not join text and a number such as `19`. Print them one after the other with `<<`.
- `.size()` counts bytes, not letters. An English letter takes one byte; a letter such as
  `ш` or `ў` usually takes two.

## Try it

1. The program has `std::string a = "10";` and `std::string b = "20";`. Predict what
   `std::cout << a + b;` prints, and what `std::cout << 10 + 20;` prints.
2. Change `full_name.cpp` so that it prints `Karimova, Malika`.

<details>
<summary>Answers</summary>

1. `1020` and `30`. With strings `+` joins. With numbers it adds.
2. `std::string full = last + ", " + first;`
</details>

**Next:** [Arithmetic](../04-arithmetic/README.md)
