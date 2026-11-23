# Parameters and return values

> **Goal:** pass values into a function and get a result back.

## Values in, a result out

Most functions need values from the caller and give an answer back.

**`delivery.cpp`**
<!-- file: delivery.cpp -->
```cpp
#include <iostream>

int totalCost(int price, int quantity) {
    return price * quantity;
}

bool isBigOrder(int amount) {
    return amount >= 50000;
}

int deliveryFee(int amount) {
    if (isBigOrder(amount)) {
        return 0;               // the function ends here
    }
    return 15000;
}

int main() {
    int cost = totalCost(12000, 3);
    std::cout << "Goods:    " << cost << " so'm\n";
    std::cout << "Delivery: " << deliveryFee(cost) << " so'm\n";
    std::cout << "To pay:   " << cost + deliveryFee(cost) << " so'm\n";
}
```

<!-- output: delivery -->
```text
Goods:    36000 so'm
Delivery: 15000 so'm
To pay:   51000 so'm
```

```text
int totalCost(int price, int quantity)     parameters: variables of the function
                  ↑          ↑
        totalCost(12000,     3)            arguments: values from the caller
```

- A **parameter** is a variable in the function's first line. An **argument** is a value in
  the call. Each argument is copied into the parameter at the same position.
- `return` ends the function at once and hands a value back to the caller. So in
  `deliveryFee`, the line `return 15000;` runs only when the `if` was false.
- The type in front of the name (`int`, `bool`) is the type of that value.
- The call stands for the value: store it, print it, or calculate with it. A call that
  gives a `bool` can be the condition of an `if`.

## A path without `return`

**`delivery_bug.cpp`**
<!-- file: delivery_bug.cpp -->
```cpp
#include <iostream>

int deliveryFee(int amount) {
    if (amount >= 50000) {
        return 0;
    }
    // BUG: no return for a smaller amount
}

int main() {
    std::cout << deliveryFee(80000) << '\n';
    std::cout << deliveryFee(36000) << '\n';
}
```

<!-- errors: delivery_bug -->
```text
delivery_bug.cpp: In function ‘int deliveryFee(int)’:
delivery_bug.cpp:8:1: warning: control reaches end of non-void function [-Wreturn-type]
    8 | }
      | ^
```

As the warning says, for a small amount the function reaches its last `}` without a
`return`. That is undefined behaviour. With g++ on Linux the second call stops the program:

```text
0
Illegal instruction (core dumped)
```

Other compilers may print a garbage number instead. Make every path end in a `return`.

## Watch out

- Printing is not returning. A function that only prints its result gives the caller
  nothing to calculate with.
- A `void` function gives nothing back. `return;` without a value ends it early.

## Try it

1. Predict the output of `difference.cpp`. Then run it.

   **`difference.cpp`**
   <!-- file: difference.cpp -->
   ```cpp
   #include <iostream>

   int difference(int a, int b) {
       return a - b;
   }

   int main() {
       int a = 2;
       int b = 10;
       std::cout << difference(a, b) << '\n';
       std::cout << difference(b, a) << '\n';
       std::cout << difference(b, difference(b, a)) << '\n';
   }
   ```

2. Write `bool isEven(int number)`. Use it in `main` to print the even numbers from 1 to 10.

<details>
<summary>Answers</summary>

1. Arguments go by position, not by name: `difference(b, a)` is 10 - 2. In the last line
   the inner call runs first and gives 8.

   <!-- output: difference -->
   ```text
   -8
   8
   2
   ```

2. The whole body is `return number % 2 == 0;`. In the loop in `main`, write
   `if (isEven(number))`.
</details>

**Next:** [Pass by value and by reference](../03-pass-by-value-and-by-reference/README.md)
