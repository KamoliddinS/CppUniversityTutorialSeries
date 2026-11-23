# Const and pointers

> **Goal:** read `const int*` and `int* const` correctly, and say what each one forbids.

## Two things could change

With a pointer you can change two things: the value it points to (`*p = 5;`) and the
pointer itself (`p = &other;`). `const` can forbid either one. Read a declaration from
right to left:

| Declaration | Read it as | `*p = 5;` | `p = &other;` |
|-------------|------------|-----------|---------------|
| `int* p` | `p` is a pointer to `int` | ok | ok |
| `const int* p` | `p` is a pointer to a `const int` | error | ok |
| `int* const p` | `p` is a `const` pointer to an `int` | ok | error |
| `const int* const p` | `p` is a `const` pointer to a `const int` | error | error |

**`const_pointers.cpp`**
<!-- file: const_pointers.cpp -->
```cpp
#include <iostream>

int main() {
    int price = 500;
    int other = 900;

    const int* look = &price;       // pointer to const: look can only read
    price = 550;                    // fine: price itself is not const
    std::cout << *look << '\n';
    look = &other;                  // fine: look may point elsewhere
    std::cout << *look << '\n';

    int* const fixed = &price;      // const pointer: fixed always points to price
    *fixed = 600;                   // fine: the value may change
    std::cout << price << '\n';
}
```

<!-- output: const_pointers -->
```text
550
900
600
```

- `const int*` is a **pointer to const**. It does not make `price` constant. It only
  forbids changing `price` through `look`.
- Line 8 changes `price` by its own name, and `*look` shows the new value.

## What the compiler rejects

**`const_nocompile.cpp`**
<!-- file: const_nocompile.cpp -->
```cpp
int main() {
    int price = 500;
    int other = 900;

    const int* look = &price;
    *look = 600;                // changes the value through look

    int* const fixed = &price;
    fixed = &other;             // points fixed elsewhere

    int* plain = look;          // plain could change what look protects
    *plain = 700;
}
```

<!-- errors: const_nocompile -->
```text
const_nocompile.cpp: In function ‘int main()’:
const_nocompile.cpp:6:11: error: assignment of read-only location ‘* look’
    6 |     *look = 600;                // changes the value through look
      |     ~~~~~~^~~~~
const_nocompile.cpp:9:11: error: assignment of read-only variable ‘fixed’
    9 |     fixed = &other;             // points fixed elsewhere
      |     ~~~~~~^~~~~~~~
const_nocompile.cpp:11:18: error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
   11 |     int* plain = look;          // plain could change what look protects
      |                  ^~~~
      |                  |
      |                  const int*
```

The last error has a good reason. If `int* plain = look;` were allowed, `*plain = 700`
would change a value that `look` may only read. The other direction is fine: you can give
an `int*` to a `const int*`.

You meet `const int*` most often as a parameter:
`int sum(const int* values, std::size_t size)` promises that `sum` only reads the array.

## Watch out

- `const int* p` and `int const* p` mean the same. Only the side of the `*` matters:
  `const` on the left protects the value, `const` on the right protects the pointer.

## Try it

1. `p` is a `const int*` and `q` is an `int* const`. Which of these lines are errors:
   `p = &b;`, `*p = 5;`, `q = &b;`, `*q = 5;`?
2. After `const int* p = &a;`, is the line `a = 7;` an error?

<details>
<summary>Answers</summary>

1. `*p = 5;` and `q = &b;`. `p` may move but not write. `q` may write but not move.
2. No. `a` itself is not `const`. Only writing through `p` is forbidden.
</details>

**Next:** [Pointers or references](../04-pointers-or-references/README.md)
