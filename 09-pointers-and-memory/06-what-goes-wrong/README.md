# What goes wrong

> **Goal:** recognise five memory bugs, and find each one with the sanitizer.

C++ does not check what you do with `new`, `delete` and pointers. Each program below builds,
and each has one bug. Build it with the sanitizer from
[Find bugs with tools](../../01-first-programs/06-find-bugs-with-tools/README.md):

```sh
g++ -std=c++20 -Wall -Wextra -g -fsanitize=address,undefined leak_bug.cpp -o demo
./demo
```

The report is long. The line with `ERROR` names the bug, and the line with your file name
gives the line number. Below, each report is cut down to its important lines.

## 1. Memory leak: never deleted

**`leak_bug.cpp`**
<!-- file: leak_bug.cpp -->
```cpp
#include <iostream>

int main() {
    int* price = new int(12000);
    std::cout << *price << '\n';
}   // no delete: the int stays on the heap
```

```text
==3023868==ERROR: LeakSanitizer: detected memory leaks
Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #1 0x5b8dd2e8f2bf in main .../leak_bug.cpp:4
```

A **memory leak** is heap memory that is never given back. The report shows the line of
the `new`. (The leak check runs on Linux. On macOS it may be missing.)

## 2. Dangling pointer: used after `delete`

**`use_after_delete_bug.cpp`**
<!-- file: use_after_delete_bug.cpp -->
```cpp
#include <iostream>

int main() {
    int* price = new int(12000);
    delete price;
    std::cout << *price << '\n';    // price still holds the old address
}
```

```text
==3023937==ERROR: AddressSanitizer: heap-use-after-free on address 0x502000000010 ...
    #0 0x64945825c498 in main .../use_after_delete_bug.cpp:6
```

`delete` destroys the `int`, not the pointer. `price` keeps the old address: it dangles.

| Name | Address | Value |
|------|---------|-------|
| `price` | `0x7000` | `0x2000` (the `int` that lived there is gone) |

## 3. Double delete

**`double_delete_bug.cpp`**
<!-- file: double_delete_bug.cpp -->
```cpp
int main() {
    int* price = new int(12000);
    int* copy = price;      // two pointers, one int
    delete price;
    delete copy;            // the same int again
}
```

```text
==3023955==ERROR: AddressSanitizer: attempting double-free on 0x502000000010 in thread T0:
    #1 0x61ab6d08b2db in main .../double_delete_bug.cpp:5
```

## 4. `delete` where `delete[]` was needed

**`wrong_delete_bug.cpp`**
<!-- file: wrong_delete_bug.cpp -->
```cpp
int main() {
    int* prices = new int[3]{500, 700, 900};
    delete prices;          // needs delete[]
}
```

```text
==3023982==ERROR: AddressSanitizer: alloc-dealloc-mismatch (operator new [] vs operator delete) ...
    #1 0x60a0192084a2 in main .../wrong_delete_bug.cpp:3
```

g++ already warns about this one when it builds the program.

## 5. Writing past the end

**`overflow_bug.cpp`**
<!-- file: overflow_bug.cpp -->
```cpp
int main() {
    int* prices = new int[3]{500, 700, 900};
    prices[3] = 1200;       // the last element is prices[2]
    delete[] prices;
}
```

```text
==3024029==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x50200000001c ...
    #0 0x5723d1b0f513 in main .../overflow_bug.cpp:3
```

## Without the sanitizer

Built without it (g++ 13 on Linux), programs 1, 4 and 5 end normally. Program 2 prints a
different meaningless number on every run. Only program 3 is stopped, with
`free(): double free detected in tcache 2`. Bugs 2 to 5 are undefined behaviour, so "it
works on my computer" proves nothing.

This is why modern C++ rarely writes `new` and `delete` by hand.
[Chapter 10](../../10-resource-management/README.md) shows what to do instead.

## Watch out

- No test can tell you whether a pointer dangles. `if (p != nullptr)` finds null pointers only.
- `p = nullptr;` after `delete p;` makes that one pointer safe to test. Copies of it still dangle.

## Try it

1. This program has two of the five bugs. Find both by reading, then check with the sanitizer.

   **`two_bugs_bug.cpp`**
   <!-- file: two_bugs_bug.cpp -->
   ```cpp
   int main() {
       int* a = new int(1);
       int* b = new int(2);
       a = b;
       delete a;
       delete b;
   }
   ```

2. Fix `overflow_bug.cpp` and `wrong_delete_bug.cpp` until the sanitizer prints nothing.

<details>
<summary>Answer to 1</summary>

`a = b` loses the only pointer to the first `int`: a leak. Then lines 5 and 6 delete the
second `int` twice. The sanitizer stops the program at the double delete, so the leak
check at the end never runs. Remove line 6 and run again to see the leak.
</details>

**Next:** [Function pointers](../07-function-pointers/README.md)
