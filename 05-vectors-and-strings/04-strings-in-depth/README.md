# Strings in depth

> **Goal:** search, cut and compare text, and read a whole line without surprises.

## A string is a row of characters

To split `malika@cau.uz` into a user and a site, you have to look inside the string.

**`email.cpp`**
<!-- file: email.cpp -->
```cpp
#include <cstddef>
#include <iostream>
#include <string>

int main() {
    std::string email = "malika";
    email += '@';                               // += adds one character at the end
    email += "cau.uz";                          // or a whole text

    for (char c : email) {                      // one character after the other
        std::cout << c << ' ';
    }
    std::cout << '\n';
    std::cout << email.size() << " characters, the first is " << email[0] << '\n';

    std::size_t atSign = email.find('@');       // the position of the first @
    if (atSign == std::string::npos) {          // npos means "not found"
        std::cout << "No @ in this address.\n";
    } else {
        // substr(position, length): 6 characters from position 0
        std::cout << "User: " << email.substr(0, atSign) << '\n';
        // substr(position): from position 7 to the end
        std::cout << "Site: " << email.substr(atSign + 1) << '\n';
    }
}
```

<!-- output: email -->
```text
m a l i k a @ c a u . u z
13 characters, the first is m
User: malika
Site: cau.uz
```

```text
position:   0  1  2  3  4  5  6  7  8  9 10 11 12
email:      m  a  l  i  k  a  @  c  a  u  .  u  z
                              ↑
                        find('@') is 6
```

| Code | Gives |
|------|-------|
| `s.size()` | the number of characters (`char`s) |
| `s[i]` | the character at position `i`; no checking, as with a vector |
| `s.find(t)` | the position where `t` first starts, or **`std::string::npos`** when `t` is not in `s` |
| `s.substr(pos, n)` | `n` characters from position `pos`; without `n`, all the rest |
| `s == t`, `s < t` | compare the text itself; `<` is the order of a dictionary, but capital letters come before small ones |
| `std::stoi("42")` | the `int` 42; a text that does not start with a number stops the program |
| `std::to_string(42)` | the string `"42"` |

## Words and lines

`std::cin >> word` reads one word: it stops at a space. `std::getline(std::cin, line)`
takes the whole line. Using both in one program has a trap:

**`skipped_line.cpp`**
<!-- file: skipped_line.cpp -->
```cpp
#include <iostream>
#include <string>

int main() {
    std::cout << "Age: ";
    int age = 0;
    std::cin >> age;

    std::cout << "Full name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Name: [" << name << "], age: " << age << '\n';
}
```

<!-- session: skipped_line -->
```text
Age: 19
Full name: Name: [], age: 19
```

The program did not wait for the name. `>>` took `19` and left the end of the line in the
input. `getline` reads up to the next line end. It found one immediately and returned an
empty line. The fix is one change:

<!-- snippet: fixed_line.cpp -->
```cpp
std::getline(std::cin >> std::ws, name);    // first skip the whitespace
```

<!-- session: fixed_line -->
```text
Age: 19
Full name: Malika Karimova
Name: [Malika Karimova], age: 19
```

**Whitespace** means spaces, tabs and line ends. `std::cin >> std::ws` skips it.

## Watch out

- Compare the result of `find` with `std::string::npos` before you use it. `npos` is a huge
  number, not a position in the text.
- `==` and `<` compare the text only if one side is a `std::string`. Two texts in quotes,
  as in `"abc" == "abc"`, are not compared letter by letter.

## Try it

1. Predict the output of `puzzle.cpp`:

   **`puzzle.cpp`**
   <!-- file: puzzle.cpp -->
   ```cpp
   #include <iostream>
   #include <string>

   int main() {
       std::string first = "bukhara";
       std::string second = "Samarkand";

       if (first < second) {
           std::cout << first << " comes first\n";
       } else {
           std::cout << second << " comes first\n";
       }
       if (first == "Bukhara") {
           std::cout << "same\n";
       } else {
           std::cout << "different\n";
       }
   }
   ```

2. Run `skipped_line.cpp` and answer the first question with `19 Malika Karimova`.
   What is the name now?

<details>
<summary>Answers</summary>

1. `S` is a capital letter, so it comes before `b`. `b` and `B` are different characters,
   so `==` is false:

   <!-- output: puzzle -->
   ```text
   Samarkand comes first
   different
   ```

2. `[ Malika Karimova]`, with a space in front. `>>` stopped after `19`, and `getline` took
   the rest of that line. `fixed_line.cpp` skips the space too.
</details>

**Next:** [Characters](../05-characters/README.md)
