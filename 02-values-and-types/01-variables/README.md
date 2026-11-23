# Variables

> **Goal:** create a variable, give it a starting value, and change it later.

## A named place for a value

A **variable** is a named place in memory that holds one value. Its **type** says what kind
of value fits there: `int` means a whole number.

**`notebooks.cpp`**
<!-- file: notebooks.cpp -->
```cpp
#include <iostream>

int main() {
    int price = 12000;          // type, name, starting value
    int quantity = 3;
    std::cout << "To pay: " << price * quantity << " so'm\n";

    price = 15000;              // the old value is replaced
    quantity = quantity + 1;    // read the old value, store the new one
    std::cout << "To pay: " << price * quantity << " so'm\n";
}
```

<!-- output: notebooks -->
```text
To pay: 36000 so'm
To pay: 60000 so'm
```

After line 5, memory looks like this (ignore the addresses for now):

| Name | Address | Value |
|------|---------|-------|
| `price` | `0x1000` | `12000` |
| `quantity` | `0x1004` | `3` |

- `int price = 12000;` creates the variable and **initialises** it: gives it its first value.
- `price = 15000;` is an **assignment**: it replaces the value. The type is not written again.
- `=` means "store the right side in the left side", not "is equal to". So
  `quantity = quantity + 1;` makes sense: read 3, add 1, store 4.

## Without a starting value

**`no_value_bug.cpp`**
<!-- file: no_value_bug.cpp -->
```cpp
#include <iostream>

int main() {
    int price;                  // no starting value
    int quantity = 3;
    int total = price * quantity;
    std::cout << "To pay: " << total << " so'm\n";
}
```

The compiler warns, because you build with `-Wall`. It still makes a program.

<!-- errors: no_value_bug -->
```text
no_value_bug.cpp: In function ‘int main()’:
no_value_bug.cpp:6:9: warning: ‘price’ is used uninitialized [-Wuninitialized]
    6 |     int total = price * quantity;
      |         ^~~~~
no_value_bug.cpp:4:9: note: ‘price’ was declared here
    4 |     int price;                  // no starting value
      |         ^~~~~
```

`int price;` creates the variable (the compiler says *declares*) but stores nothing in it.
Reading it is undefined behaviour. Usually you get whatever was in that memory before:
garbage. Three runs on one machine printed `1612183224`, `1900556680` and `170719496`.

Assigning later (`price = 12000;`) does not initialise: until that line runs, the variable
holds garbage. So give every variable a starting value in the line that creates it.

## Names

- The rules: letters, digits and `_`; no digit at the start; not a word that C++ uses itself,
  such as `int`. `total` and `Total` are two different names.
- The course style: `camelCase`, and a name that says what the value means: `pricePerKg`, not `p`.

## Try it

1. Predict the output of [`copy.cpp`](copy.cpp). Then run it.

   **`copy.cpp`**
   <!-- file: copy.cpp -->
   ```cpp
   #include <iostream>

   int main() {
       int azizScore = 70;
       int malikaScore = azizScore;
       azizScore = 90;
       std::cout << azizScore << ' ' << malikaScore << '\n';
   }
   ```

2. Which of these names does the compiler accept?
   `2ndPlace`, `second_place`, `total-price`, `double`, `Total`

<details>
<summary>Answers</summary>

1. `int malikaScore = azizScore;` copies the value 70. Later changes to `azizScore` do not
   reach `malikaScore`.

   <!-- output: copy -->
   ```text
   90 70
   ```

2. Only `second_place` and `Total`. In the course style: `secondPlace` and `total`.
</details>

**Next:** [Whole numbers and decimals](../02-whole-numbers-and-decimals/README.md)
