# Result and Option

> **Goal:** report a failure with `Result`, handle it with `match`, and pass it on with `?`.

## A failure is a return value

In C++ you report a failure with `throw`. The signature of the function does not show
that, and the exception travels up until a `catch` stops it
([Throw and catch](../../13-exceptions/01-throw-and-catch/README.md)).

**`stoi_throws.cpp`**
<!-- file: stoi_throws.cpp -->
```cpp
#include <iostream>
#include <stdexcept>
#include <string>

int total(const std::string& a, const std::string& b) {
    return std::stoi(a) + std::stoi(b);     // std::stoi throws when the text is not a number
}

int main() {
    try {
        std::cout << "40 + 2 = " << total("40", "2") << '\n';
        std::cout << "40 + two = " << total("40", "two") << '\n';
    } catch (const std::invalid_argument&) {
        std::cout << "not a number\n";
    }
}
```

<!-- output: stoi_throws -->
```text
40 + 2 = 42
40 + two = not a number
```

`40 + two = ` was already printed when `total` threw. Rust has no exceptions. A function that can fail returns a **`Result`**: `Ok(value)` or
`Err(error)`. The return type shows it, and the caller cannot reach the value without saying
what happens on `Err`. Below, `parse::<i32>()` does the work of `std::stoi`.

**`parse.rs`**
<!-- file: parse.rs -->
```rust
use std::num::ParseIntError;        // the error type that parse::<i32>() gives

fn total(a: &str, b: &str) -> Result<i32, ParseIntError> {
    let x = a.parse::<i32>()?;      // on Err: return the error to the caller right now
    let y = b.parse::<i32>()?;
    Ok(x + y)
}

fn report(a: &str, b: &str) {
    match total(a, b) {
        Ok(sum) => println!("{a} + {b} = {sum}"),
        Err(error) => println!("{a} + {b}: {error}"),
    }
}

fn main() {
    report("40", "2");
    report("40", "two");

    let quantity = "three".parse::<i32>().unwrap_or(1);     // on Err: use 1
    println!("quantity: {quantity}");
}
```

<!-- output: parse -->
```text
40 + 2 = 42
40 + two: invalid digit found in string
quantity: 1
```

| You write | With `Ok(v)` or `Some(v)` | With `Err(e)` or `None` |
|-----------|---------------------------|-------------------------|
| `match r { ... }` | the `Ok` or `Some` arm runs | the `Err` or `None` arm runs |
| `r?` | gives `v` | the function returns the `Err` or `None` to its caller at once |
| `r.unwrap_or(1)` | gives `v` | gives `1` |
| `r.unwrap()` or `r.expect("why")` | gives `v` | **panic** |

`?` does the work of an exception that travels up one function. But you see every place
where it can happen. `Option` ([lesson 4](../04-structs-enums-and-match/README.md)) has the
same four tools.

## Panic is for bugs

A **panic** stops the program with a message that names the file and the line. This
program panics on line 3:

**`expect_bug.rs`**
<!-- file: expect_bug.rs -->
```rust
fn main() {
    let text = "4o";            // a typing mistake: the letter o, not zero
    let price = text.parse::<i32>().expect("the price must be a number");
    println!("{price} so'm");
}
```

| Use | For |
|-----|-----|
| `Result` | failures the caller should handle: wrong input, a missing file |
| a panic | bugs: something that must never happen |

`unwrap()` and `expect()` are fine in examples and tests. In a real program, return the
`Result` or handle it.

## Watch out

- `?` works only in a function that returns `Result` or `Option`: the error needs a place
  to go. The `main` here returns nothing, so it uses `match`.
- An index past the end of a `Vec` is a panic. In C++, `v[i]` past the end is undefined
  behaviour.

## Try it

1. Predict what `parse.rs` prints for `report("x", "2")` and for `report("4", "")`.
2. Build and run `expect_bug.rs` and read the message. Then replace `expect` with a `match`
   that prints `not a price` instead.

<details>
<summary>Answers</summary>

1. `x + 2: invalid digit found in string` and `4 + : cannot parse integer from empty string`.
   In the first call, `?` returns before `b` is parsed.
2. The message names line 3 and repeats your text. The fix:

   ```rust
   match text.parse::<i32>() {
       Ok(price) => println!("{price} so'm"),
       Err(_) => println!("not a price"),
   }
   ```
</details>

**Next:** [Traits and generics](../06-traits-and-generics/README.md)
