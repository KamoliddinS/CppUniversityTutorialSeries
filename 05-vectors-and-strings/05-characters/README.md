# Characters

> **Goal:** test what kind of character you have, and change single characters.

## Test a character

A `char` holds one character: `'a'`, `'7'`, `' '`. A string is a row of `char`s, so a loop
over a string gives you one `char` at a time. The header `<cctype>` has functions that tell
you what kind of character it is.

**`count.cpp`**
<!-- file: count.cpp -->
```cpp
#include <cctype>
#include <iostream>
#include <string>

int main() {
    std::cout << "Type a line: ";
    std::string line;
    std::getline(std::cin, line);

    int letters = 0;
    int spaces = 0;
    int digitSum = 0;
    for (unsigned char c : line) {      // unsigned char: see Watch out
        if (std::isalpha(c)) {
            ++letters;
        } else if (std::isspace(c)) {
            ++spaces;
        } else if (std::isdigit(c)) {
            digitSum += c - '0';        // '7' - '0' is the number 7
        }
    }
    std::cout << letters << " letters, " << spaces << " spaces, digit sum " << digitSum << '\n';
}
```

<!-- session: count -->
```text
Type a line: Room 204, Tashkent
12 letters, 2 spaces, digit sum 6
```

| Function | Asks |
|----------|------|
| `std::isalpha(c)` | is `c` a letter? |
| `std::isdigit(c)` | is `c` a digit, `0` to `9`? |
| `std::isspace(c)` | is `c` whitespace? |

- The loop variable is an `unsigned char`: the same character, but its code is never
  negative, always 0 to 255. These functions need that (see Watch out).
- A character is stored as a small number,
  [its code](../../02-values-and-types/03-text-characters-and-booleans/README.md). The codes
  of `'0'` to `'9'` follow each other, so `c - '0'` turns a digit character into the number
  it shows: `'7' - '0'` is 7.

## Change a character

**`name_case.cpp`**
<!-- file: name_case.cpp -->
```cpp
#include <cctype>
#include <iostream>
#include <string>

int main() {
    unsigned char letter = 'm';
    std::cout << std::toupper(letter) << '\n';                        // an int: prints a number
    std::cout << static_cast<char>(std::toupper(letter)) << '\n';     // a char again

    std::string name = "mALIKA";
    std::string fixed;                                                // starts empty
    for (unsigned char c : name) {
        if (fixed.empty()) {
            fixed += static_cast<char>(std::toupper(c));              // the first letter
        } else {
            fixed += static_cast<char>(std::tolower(c));              // all the others
        }
    }
    std::cout << fixed << '\n';
}
```

<!-- output: name_case -->
```text
77
M
Malika
```

- `std::toupper` and `std::tolower` return an `int`: the code of the new character. Printed
  as it is, you see a number. `static_cast<char>` makes it a character again.
- A character that is not a letter is returned unchanged.
- The loop builds a new string: `fixed` starts empty, and `+=` adds each new character.

## Watch out

- The test functions answer with a number: 0 for "no", some other number for "yes". Write
  `if (std::isdigit(c))`. Never compare the answer with `true`.
- `'7'` is a character and `7` is a number. `'7' + 1` is 56, not 8.
- Give these functions an `unsigned char`, not a plain `char`. A letter such as `ў` takes
  two `char`s, and on most computers their codes are negative. A negative code is undefined
  behaviour here. With `unsigned char` the call is safe, but the answer is still "not a
  letter": the functions know the English letters only.

## Try it

1. Predict the output of `puzzle.cpp`:

   **`puzzle.cpp`**
   <!-- file: puzzle.cpp -->
   ```cpp
   #include <cctype>
   #include <iostream>
   #include <string>

   int main() {
       std::string code = "ab12";
       std::string letters;
       int sum = 0;
       for (unsigned char c : code) {
           if (std::isdigit(c)) {
               sum += c - '0';
           } else {
               letters += static_cast<char>(std::toupper(c));
           }
       }
       std::cout << letters << ' ' << sum << '\n';
   }
   ```

2. Change `count.cpp` so that it also counts the vowels (`a`, `e`, `i`, `o`, `u`), capital
   or small.

<details>
<summary>Answers</summary>

1. Only the letters go into `letters`, as capitals. The digits are added up as numbers,
   1 + 2:

   <!-- output: puzzle -->
   ```text
   AB 3
   ```

2. Make the character small first, then compare. For `Room 204, Tashkent` the answer is 4.

   ```cpp
   char low = static_cast<char>(std::tolower(c));
   if (low == 'a' || low == 'e' || low == 'i' || low == 'o' || low == 'u') {
       ++vowels;
   }
   ```
</details>

**Next:** [Arrays](../06-arrays/README.md)
