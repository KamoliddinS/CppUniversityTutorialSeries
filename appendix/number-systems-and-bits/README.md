# Number systems and bits

> **Goal:** read binary and hexadecimal numbers, and switch single bits on and off.

## One value, three ways to write it

A computer stores every value as **bits**: digits that are `0` or `1`.
People write the same value in three ways.

| System | Digits | Place values | Thirteen |
|--------|--------|--------------|----------|
| decimal | `0` to `9` | ... 100, 10, 1 | `13` |
| **binary** | `0` and `1` | ... 8, 4, 2, 1 | `1101` |
| **hexadecimal** (hex) | `0` to `9`, then `A` to `F` | ... 256, 16, 1 | `D` |

```text
binary 1101  =  8 + 4 + 0 + 1    =  13
hex      1F  =  1*16 + 15*1      =  31        A is 10, B is 11, ... F is 15
```

To convert to binary by hand, divide by 2 until you reach 0. Then read the remainders
from the bottom up.

```text
13 / 2 = 6   remainder 1
 6 / 2 = 3   remainder 0
 3 / 2 = 1   remainder 1
 1 / 2 = 0   remainder 1      →  1101
```

One hex digit stands for four bits, so hex is a short way to write binary:
`0001 1111` is `1F`.

## Write and print them in C++

**`bases.cpp`**
<!-- file: bases.cpp -->
```cpp
#include <bitset>
#include <iostream>

int main() {
    int binary = 0b1010;
    int hexadecimal = 0x1F;
    int octal = 0547;   // careful: a leading 0 means octal (base 8)
    std::cout << binary << ' ' << hexadecimal << ' ' << octal << '\n';

    int n = 31;
    std::cout << std::bitset<8>(n) << '\n';   // n as 8 bits
    std::cout << std::hex << n << '\n';       // n in hexadecimal
    std::cout << std::dec << n << '\n';       // back to decimal
}
```

<!-- output: bases -->
```text
10 31 359
00011111
1f
31
```

- `0b` starts a binary literal and `0x` a hexadecimal one.
- A leading `0` means octal, base 8: `0547` is 5*64 + 4*8 + 7 = 359, not 547.
- `std::bitset<8>(n)` prints `n` as 8 bits.
- `std::hex` stays on until you send `std::dec`. It prints `1F` as `1f`.

## Negative numbers

C++ stores negative whole numbers in **two's complement**: the leftmost bit has a
negative place value. With 8 bits that is -128, so the range is -128 to 127.

```text
-128   64   32   16    8    4    2    1
   1    1    1    1    1    0    1    0      =  -128 + 64 + 32 + 16 + 8 + 2  =  -6
```

To change the sign of a number, flip every bit (`~`) and add 1.

**`negative.cpp`**
<!-- file: negative.cpp -->
```cpp
#include <bitset>
#include <iostream>

int main() {
    int n = 5;
    std::cout << std::bitset<8>(n) << "  " << n << '\n';
    std::cout << std::bitset<8>(~n) << "  " << ~n << '\n';           // every bit flipped
    std::cout << std::bitset<8>(~n + 1) << "  " << ~n + 1 << '\n';   // flipped, then 1 added
}
```

<!-- output: negative -->
```text
00000101  5
11111010  -6
11111011  -5
```

Now the processor can add negative numbers exactly like positive ones:

```text
  00000101      5
+ 11111011     -5
----------
1 00000000      the ninth bit does not fit and is dropped: 0
```

An `int` works the same way, usually with 32 bits. `std::bitset<8>` shows the rightmost 8.

## Bit operators

| Operator | A bit of the result is 1 when |
|----------|-------------------------------|
| `a & b` (AND) | both bits are 1 |
| `a \| b` (OR) | at least one bit is 1 |
| `a ^ b` (XOR) | the two bits are different |
| `~a` (NOT) | the bit of `a` is 0 |

`a << n` moves the bits `n` places to the left, `a >> n` to the right.
Bits moved out at the end are lost.

```text
  1100        1100        1100        00000101 << 2  =  00010100     5 * 4 = 20
& 1010      | 1010      ^ 1010        00010100 >> 2  =  00000101    20 / 4 = 5
  ----        ----        ----
  1000        1110        0110
```

A practical use: one number holds several on/off options, one bit each.

**`options.cpp`**
<!-- file: options.cpp -->
```cpp
#include <bitset>
#include <iostream>

int main() {
    constexpr int bold = 0b001;        // each option has its own bit
    constexpr int italic = 0b010;
    constexpr int underline = 0b100;

    int style = bold | underline;             // switch two options on
    std::cout << std::bitset<3>(style) << '\n';

    style = style & ~bold;                    // switch one option off
    style = style ^ italic;                   // flip one option
    std::cout << std::bitset<3>(style) << '\n';

    if ((style & underline) != 0) {           // test one option
        std::cout << "underline is on\n";
    }
}
```

<!-- output: options -->
```text
101
110
underline is on
```

## Watch out

- `^` is XOR, not "to the power of": `2 ^ 3` is 1.
- `&` and `|` work on every bit. `&&` and `||` work on `true` and `false`.
- Keep the brackets in `(style & bold) != 0`. Without them `!=` is done first.
- Shifting by a negative amount, or by the number of bits of the type or more
  (`1 << 32` for a 32-bit `int`), is undefined behaviour.

## Try it

1. By hand: write 45 in binary, then in hex.
2. Predict the output of `predict.cpp`. Then run it.

   **`predict.cpp`**
   <!-- file: predict.cpp -->
   ```cpp
   #include <iostream>

   int main() {
       std::cout << (6 & 3) << ' ' << (6 | 3) << ' ' << (6 ^ 3) << ' ' << (3 << 2) << '\n';
   }
   ```

3. Which number is `10000001` in 8-bit two's complement?

<details>
<summary>Answers</summary>

1. `101101` (32 + 8 + 4 + 1). In groups of four: `0010 1101`, so `2D`.
2. In binary, 6 is `110` and 3 is `011`.

   <!-- output: predict -->
   ```text
   2 7 5 12
   ```

3. -127, which is -128 + 1.
</details>
