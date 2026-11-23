# Stack and heap

> **Goal:** create objects that outlive a function with `new`, and give the memory back with `delete`.

## Two places for objects

A local variable is destroyed when its function ends. An object that must live longer
needs another place in memory.

| | Stack | Heap |
|---|---|---|
| What lives there | local variables and parameters | objects created with `new` |
| Destroyed | automatically, at the closing `}` | only when you write `delete` |
| How you reach it | by its name | only through a pointer |

`Reporter` (from [Destructors and lifetime](../../07-classes/03-destructors-and-lifetime/README.md))
prints when an object is created and when it is destroyed.

**`lifetime.cpp`**
<!-- file: lifetime.cpp -->
```cpp
#include <iostream>
#include <string>

class Reporter {
public:
    explicit Reporter(const std::string& name) : name_(name) {
        std::cout << "create " << name_ << '\n';
    }

    ~Reporter() {
        std::cout << "destroy " << name_ << '\n';
    }

private:
    std::string name_;
};

Reporter* make() {
    Reporter local("stack object");
    return new Reporter("heap object");
}   // local is destroyed here; the heap object lives on

int main() {
    Reporter* p = make();
    std::cout << "back in main\n";
    delete p;               // the heap object is destroyed here
    std::cout << "end of main\n";
}
```

<!-- output: lifetime -->
```text
create stack object
create heap object
destroy stack object
back in main
destroy heap object
end of main
```

- `local` lives on the **stack**. It is destroyed at the `}` of `make`.
- `new Reporter("heap object")` creates an object on the **heap** and gives back its
  address. The object outlives the function that created it.
- `delete p` destroys that object and gives its memory back.

## An array on the heap

**`squares.cpp`**
<!-- file: squares.cpp -->
```cpp
#include <cstddef>
#include <iostream>

// Returns an array of count squares. The caller owns it and must delete[] it.
int* makeSquares(std::size_t count) {
    int* squares = new int[count]{};        // count ints on the heap, all 0
    int number = 0;
    for (std::size_t i = 0; i < count; ++i) {
        squares[i] = number * number;
        ++number;
    }
    return squares;                         // the array lives on after this function
}

int main() {
    std::cout << "How many squares? ";
    std::size_t count = 0;
    std::cin >> count;
    if (count > 20) {
        count = 20;                         // keeps the example small
    }

    int* squares = makeSquares(count);
    for (std::size_t i = 0; i < count; ++i) {
        std::cout << squares[i] << ' ';
    }
    std::cout << '\n';

    delete[] squares;                       // new[] pairs with delete[]
}
```

<!-- session: squares -->
```text
How many squares? 3
0 1 4
```

Memory after `makeSquares` has returned, in two parts. The stack:

| Name | Address | Value |
|------|---------|-------|
| `count` | `0x7000` | `3` |
| `squares` | `0x7008` | `0x2000` (points to the heap) |

The heap, which stays until `delete[]`:

| Name | Address | Value |
|------|---------|-------|
| (no name) | `0x2000` | `0` |
| (no name) | `0x2004` | `1` |
| (no name) | `0x2008` | `4` |

- `new int[count]{}` creates `count` ints. `{}` sets them to 0: without it they hold
  garbage. `count` may be known only while the program runs.
- `new` pairs with `delete`, and `new[]` with `delete[]`.
- Heap memory needs an **owner**: the part of the program that must delete it, exactly
  once. Here the comment says that the caller owns the array.

## When you need the heap

1. An object must outlive the function that creates it.
2. A size is known only while the program runs.

`std::vector` and `std::string` use the heap for you and delete what they created. That is
why you did not need `new` until now.

## Watch out

- `new int(5)` is one `int` with the value 5. `new int[5]` is five `int`s.

## Try it

Remove `delete p;` from `lifetime.cpp`. Predict the output, then run it.

<details>
<summary>Answer</summary>

The line `destroy heap object` is gone. Nobody destroys the heap object. This is a memory
leak, the first bug of the next lesson.
</details>

**Next:** [What goes wrong](../06-what-goes-wrong/README.md)
