# Addresses and pointers

> **Goal:** store the address of a variable in a pointer, and read or change the variable through it.

## Every variable has an address

Every variable lives somewhere in memory. That place has a number: its **address**. It is
the Address column of the memory tables you know. A **pointer** is a variable that holds
an address.

**`pointer.cpp`**
<!-- file: pointer.cpp -->
```cpp
#include <iostream>

int main() {
    int count = 42;
    int* p = &count;        // p holds the address of count

    std::cout << "count:  " << count << '\n';
    std::cout << "&count: " << &count << '\n';
    std::cout << "p:      " << p << '\n';
    std::cout << "*p:     " << *p << '\n';

    *p = 50;                // changes count through the pointer
    std::cout << "count:  " << count << '\n';
}
```

<!-- output: pointer -->
```text
count:  42
&count: 0x7e2b23900020
p:      0x7e2b23900020
*p:     42
count:  50
```

| Code | Meaning |
|------|---------|
| `&count` | the address of `count` |
| `int* p` | `p` is a pointer to an `int` |
| `*p` | the variable that `p` points to |

Memory after line 5, with short made-up addresses:

| Name | Address | Value |
|------|---------|-------|
| `count` | `0x1000` | `42` |
| `p` | `0x1008` | `0x1000` (points to `count`) |

- `&count` and `p` print the same address. It is written in
  [hexadecimal](../../appendix/number-systems-and-bits/README.md): the digits are `0` to
  `9` and `a` to `f`. Yours will be different.
- `*p = 50` changed `count`. Following a pointer with `*` is called **dereferencing** it.

## A pointer to nothing

`nullptr` is the value that means "points to nothing". A pointer that holds it is a
**null pointer**.

**`null_bug.cpp`**
<!-- file: null_bug.cpp -->
```cpp
#include <iostream>

int main() {
    int* p = nullptr;               // p points to nothing
    std::cout << "Before\n";
    std::cout << *p << '\n';        // there is no int to read
    std::cout << "After\n";
}
```

It builds. On Linux a run looks like this:

```text
Before
Segmentation fault (core dumped)
```

Dereferencing a null pointer is undefined behaviour. The usual result is this crash, and it
names no line. The [sanitizer](../../01-first-programs/06-find-bugs-with-tools/README.md) does:

```text
null_bug.cpp:6:24: runtime error: load of null pointer of type 'int'
```

When a pointer may be null, test it before you use it:

```cpp
if (p != nullptr) {
    std::cout << *p << '\n';
}
```

## Watch out

- A local `int* p;` is **not** a null pointer. It holds garbage: an address that nobody
  chose. Using `*p` is undefined behaviour again, and it may print nonsense instead of
  crashing. Give every pointer a starting value: an address, or `nullptr`.
- `int* a, b;` makes `a` a pointer and `b` a plain `int`. Declare one pointer per line.

## Try it

1. Predict what this program prints. Draw the memory table first, then run it.

   **`retarget.cpp`**
   <!-- file: retarget.cpp -->
   ```cpp
   #include <iostream>

   int main() {
       int a = 1;
       int b = 2;
       int* p = &a;

       *p = 10;
       p = &b;
       *p = *p + 20;

       std::cout << a << ' ' << b << '\n';
   }
   ```

2. Put the test `if (p != nullptr)` around line 6 of `null_bug.cpp`. What does it print now?

<details>
<summary>Answers</summary>

1. `*p = 10` changes `a`. Then `p = &b` gives the pointer a new target, so
   `*p = *p + 20` changes `b` to 22.

   <!-- output: retarget -->
   ```text
   10 22
   ```

2. `Before` and `After`. The pointer is null, so the line with `*p` is skipped.
</details>

**Next:** [Pointers and arrays](../02-pointers-and-arrays/README.md)
