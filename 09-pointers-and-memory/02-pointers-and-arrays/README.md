# Pointers and arrays

> **Goal:** walk through an array with a pointer, and say why a function needs the size as well.

## An array name turns into a pointer

In most expressions the name of an array turns into a pointer to its first element.
This is called **decay**.

**`decay.cpp`**
<!-- file: decay.cpp -->
```cpp
#include <iostream>

int main() {
    int prices[4] = {500, 700, 900, 1200};
    int* p = prices;        // decay: p points to prices[0]

    std::cout << "sizeof(prices): " << sizeof(prices) << '\n';
    std::cout << "sizeof(p):      " << sizeof(p) << '\n';

    std::cout << p << " holds " << *p << '\n';
    std::cout << p + 1 << " holds " << *(p + 1) << '\n';
    std::cout << p + 2 << " holds " << p[2] << '\n';
}
```

<!-- output: decay -->
```text
sizeof(prices): 16
sizeof(p):      8
0x7db1e0100020 holds 500
0x7db1e0100024 holds 700
0x7db1e0100028 holds 900
```

The same memory with short made-up addresses:

| Name | Address | Value |
|------|---------|-------|
| `prices[0]` | `0x1000` | `500` |
| `prices[1]` | `0x1004` | `700` |
| `prices[2]` | `0x1008` | `900` |
| `prices[3]` | `0x100c` | `1200` |
| `p` | `0x1010` | `0x1000` (points to `prices[0]`) |

- An array is not a pointer. `sizeof` shows it: `prices` is four `int`s, `p` is one address.
- `p + 1` points to the next **element**, not the next byte: the address grows by 4,
  the size of one `int`.
- `p[2]` means `*(p + 2)`.

## A function gets only the pointer

**`walk.cpp`**
<!-- file: walk.cpp -->
```cpp
#include <cstddef>
#include <iostream>

int sum(int values[], std::size_t size) {       // values is really an int*
    int total = 0;
    for (std::size_t i = 0; i < size; ++i) {
        total += values[i];
    }
    return total;
}

int main() {
    const std::size_t size = 4;
    int prices[size] = {500, 700, 900, 1200};
    std::cout << "Sum: " << sum(prices, size) << '\n';

    int* end = prices + size;                   // one past the last element
    for (int* p = prices; p != end; ++p) {
        std::cout << *p << ' ';
    }
    std::cout << '\n';
    std::cout << "Elements: " << end - prices << '\n';
}
```

<!-- output: walk -->
```text
Sum: 3300
500 700 900 1200
Elements: 4
```

- The parameter `int values[]` means `int* values`. The function gets an address: no copy
  of the array and no size. So the size must come separately. A `std::vector` knows its
  own size.
- `prices + size` points one past the last element. You may store and compare such a
  pointer, but never dereference it.
- `end - prices` counts the elements between two pointers. Both must point into the same
  array; for two different arrays the result is undefined behaviour.

## C-style strings

**`c_string.cpp`**
<!-- file: c_string.cpp -->
```cpp
#include <iostream>

int main() {
    const char* city = "Khiva";                 // points to the 'K'
    std::cout << sizeof("Khiva") << '\n';       // five letters and '\0'

    int letters = 0;
    for (const char* p = city; *p != '\0'; ++p) {
        ++letters;
    }
    std::cout << city << " has " << letters << " letters\n";
}
```

<!-- output: c_string -->
```text
6
Khiva has 5 letters
```

Text in double quotes is an array of `const char` that ends with a hidden `'\0'`. A `const char*`
points to its first letter, and only the `'\0'` marks the end. `std::string` handles this
for you, so prefer it. (The [next lesson](../03-const-and-pointers/README.md) explains the `const`.)

The `argv` of [Program arguments](../../06-structs-and-files/06-program-arguments/README.md)
is an array of pointers to such texts, one for each word.

## Watch out

- Inside `sum`, `sizeof(values)` is 8, not 16. g++ warns:
  `'sizeof' on array function parameter 'values' will return size of 'int*'`.

## Try it

1. With `p` as in `decay.cpp`, predict the values of `*(p + 3)` and `*p + 3`.
2. Rewrite the loop in `sum` so that it walks with a pointer, like the loop in `main`.

<details>
<summary>Answers</summary>

1. `1200` and `503`. `*(p + 3)` moves three elements, then reads. `*p + 3` reads
   `prices[0]`, then adds 3.
2. `for (int* p = values; p != values + size; ++p) { total += *p; }`
</details>

**Next:** [Const and pointers](../03-const-and-pointers/README.md)
