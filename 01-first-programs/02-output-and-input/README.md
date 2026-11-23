# Output and input

> **Goal:** print text and numbers, and read what the user types.

## Printing

`std::cout` prints whatever you send it with `<<`. You can chain several pieces.

**`print.cpp`**
<!-- file: print.cpp -->
```cpp
#include <iostream>

int main() {
    std::cout << "Tashkent " << 2026 << '\n';
    std::cout << "2 + 3 = " << 2 + 3 << '\n';
    std::cout << "first line\nsecond line\n";
}
```

<!-- output: print -->
```text
Tashkent 2026
2 + 3 = 5
first line
second line
```

- Text goes in double quotes. Numbers and calculations do not.
- `'\n'` starts a new line. Nothing starts one for you.

## Reading

**`greet.cpp`**
<!-- file: greet.cpp -->
```cpp
#include <iostream>
#include <string>

int main() {
    std::cout << "What is your name? ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "How old are you? ";
    int age = 0;
    std::cin >> age;

    std::cout << "Hello, " << name << "! Next year you will be " << age + 1 << ".\n";
}
```

A run looks like this (the user typed the name and the age):

<!-- session: greet -->
```text
What is your name? Malika Karimova
How old are you? 19
Hello, Malika Karimova! Next year you will be 20.
```

| Code | What it reads |
|------|---------------|
| `std::getline(std::cin, name)` | the whole line, spaces included |
| `std::cin >> age` | one value; it stops at a space or the end of the line |

`name` and `age` are **variables**: named places that hold a value.
[Chapter 2](../../02-values-and-types/README.md) explains them.

## Watch out

- `std::cin >> name` would read only `Malika`. Use `std::getline` for text with spaces.
- Print the question *before* you read. The program waits silently otherwise.
- If the user types letters where a number is expected, `age` stays `0`.
  [Safe input](../../03-control-flow/07-safe-input/README.md) shows how to handle that.

## Try it

1. Predict the output, then check by running it:
   `std::cout << "7" << 7 << 7 + 7 << '\n';`
2. Change `greet.cpp` so it also asks for a city and prints it in the last line.

<details>
<summary>Answer to 1</summary>

`7714`. The first `7` is text, the second is a number, and `7 + 7` belongs together
because `+` binds more strongly than `<<`, so it is printed as `14`.
Nothing adds spaces between the pieces.
</details>

**Next:** [From source to program](../03-from-source-to-program/README.md)
