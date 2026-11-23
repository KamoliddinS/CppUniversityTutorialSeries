# While loops

> **Goal:** repeat a block of code as long as a condition is true.

## while: test, then run

A **loop** repeats a block of code. One run of the block is a round, or **iteration**.

**`countdown.cpp`**
<!-- file: countdown.cpp -->
```cpp
#include <iostream>

int main() {
    int count = 3;
    while (count > 0) {                 // tested before every round
        std::cout << count << '\n';
        count = count - 1;
    }
    std::cout << "Go!\n";
}
```

<!-- output: countdown -->
```text
3
2
1
Go!
```

- The condition is tested **before** every round. True: the block runs, and the test comes
  again. False: the loop ends.
- So the block can run zero times. Start with `int count = 0;` and only `Go!` is printed.
- The block must change something that the condition tests. Here `count` gets smaller.

## do-while: run, then test

**`pin.cpp`**
<!-- file: pin.cpp -->
```cpp
#include <iostream>

int main() {
    constexpr int secret = 1234;
    int pin = 0;
    int tries = 0;

    do {
        std::cout << "PIN: ";
        std::cin >> pin;
        tries = tries + 1;
    } while (pin != secret && tries < 3);       // tested after every round

    if (pin == secret) {
        std::cout << "Welcome!\n";
    } else {
        std::cout << "Card blocked.\n";
    }
}
```

<!-- session: pin -->
```text
PIN: 1111
PIN: 1234
Welcome!
```

`do { ... } while (...);` tests **after** every round, so the block runs at least once.
Use it when the test needs something that the block produces: here, the typed PIN.

## while (true): leave from the middle

**`taxi.cpp`**
<!-- file: taxi.cpp -->
```cpp
#include <iostream>

int main() {
    constexpr int pricePerKm = 3000;    // so'm

    while (true) {
        std::cout << "Kilometres (0 to stop): ";
        int km = 0;
        std::cin >> km;
        if (km <= 0) {
            break;                      // leave the loop from the middle
        }
        std::cout << "Fare: " << km * pricePerKm << " so'm\n";
    }
    std::cout << "Have a good trip!\n";
}
```

<!-- session: taxi -->
```text
Kilometres (0 to stop): 7
Fare: 21000 so'm
Kilometres (0 to stop): 0
Have a good trip!
```

`while (true)` never ends by itself. `break` leaves the loop at once. This is a normal
pattern when the exit test belongs in the middle of a round: after reading, before
calculating.

## Watch out

- [`endless_bug.cpp`](endless_bug.cpp) is the countdown without `count = count - 1;`.
  It prints `3` forever: an **endless loop**. Press **Ctrl+C** in the terminal to stop a
  running program.
- Only `do ... while (...);` ends with a `;`. After a plain `while (count > 0)` the `;`
  would be the whole block: `count` cannot change, and the loop never ends.

## Try it

1. Predict: what does `countdown.cpp` print with the condition `count >= 0`?
2. In `pin.cpp` the user types the right PIN on the third try. `Welcome!` or
   `Card blocked.`? Why?
3. Run `endless_bug.cpp`, then stop it.

<details>
<summary>Answers</summary>

1. `3`, `2`, `1`, `0`, `Go!`. There is one more round, because `0 >= 0` is true.
2. `Welcome!`. The loop ends, because `pin != secret` is now false. The `if` after the
   loop tests the PIN, not the number of tries.
</details>

**Next:** [For loops](../05-for-loops/README.md)
