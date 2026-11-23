# Borrowing

> **Goal:** borrow a value with `&` and `&mut`, and name the C++ bugs that the borrow rules make impossible.

## A reference that the compiler checks

In C++ you pass `const std::vector<int>&` to read a value without copying it. But a C++
reference or pointer can dangle, and the compiler does not stop you
([What goes wrong](../../09-pointers-and-memory/06-what-goes-wrong/README.md)).

A Rust reference is a **borrow**: it uses a value that another variable owns. The compiler
checks every borrow.

| You write | Closest C++ | The borrower may |
|-----------|-------------|------------------|
| `&T` | `const T&` | read; any number of borrows at the same time |
| `&mut T` | `T&` | read and change; only one borrow, and no `&T` at the same time |

**`borrow.rs`**
<!-- file: borrow.rs -->
```rust
fn total(prices: &Vec<i32>) -> i32 {        // a & borrow: may only read
    let mut sum = 0;
    for price in prices {
        sum += price;
    }
    sum
}

fn add_delivery(prices: &mut Vec<i32>) {    // a &mut borrow: may change
    prices.push(15000);
}

fn main() {
    let mut prices = vec![12000, 8000];     // a Vec<i32>, Rust's std::vector<int>
    add_delivery(&mut prices);              // the call shows that prices may change
    println!("total: {}", total(&prices));
    println!("prices: {}", prices.len());   // main is still the owner
}
```

<!-- output: borrow -->
```text
total: 35000
prices: 3
```

## The vector bug cannot happen

In C++ the bug from [Choose a container](../../15-standard-library/01-choose-a-container/README.md)
builds without a warning:

**`push_bug.cpp`**
<!-- file: push_bug.cpp -->
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> scores = {70, 85, 90};
    const int& first = scores[0];     // a reference into the vector
    scores.push_back(60);             // the block is full: every element moves
    std::cout << first << '\n';       // first still refers to the old block
}
```

`first` refers to freed memory: undefined behaviour. The program may print a random number,
or it may print `70`, and then the bug stays hidden.

Rust rejects the same program:

**`push_nocompile.rs`**
<!-- file: push_nocompile.rs -->
```rust
fn main() {
    let mut scores = vec![70, 85, 90];
    let first = &scores[0];     // a & borrow into the vector
    scores.push(60);            // push needs a &mut borrow
    println!("{first}");
}
```

<!-- errors: push_nocompile -->
```text
error[E0502]: cannot borrow `scores` as mutable because it is also borrowed as immutable
 --> push_nocompile.rs:4:5
  |
3 |     let first = &scores[0];     // a & borrow into the vector
  |                  ------ immutable borrow occurs here
4 |     scores.push(60);            // push needs a &mut borrow
  |     ^^^^^^^^^^^^^^^ mutable borrow occurs here
5 |     println!("{first}");
  |                ----- immutable borrow later used here

error: aborting due to 1 previous error

For more information about this error, try `rustc --explain E0502`.
```

The message calls `&` an immutable borrow and `&mut` a mutable borrow. Read the three
notes in order: `first` borrows `scores` on line 3 and is used again on line 5. In between,
`push` needs `&mut`. A writer and a reader at the same time are not allowed.

## A reference cannot outlive its value

**`dangling_nocompile.rs`**
<!-- file: dangling_nocompile.rs -->
```rust
fn shout(word: &str) -> &str {
    let loud = word.to_uppercase();     // a new String, owned by this function
    &loud
}                                       // loud is dropped here

fn main() {
    println!("{}", shout("plov"));
}
```

<!-- errors: dangling_nocompile -->
```text
error[E0515]: cannot return reference to local variable `loud`
 --> dangling_nocompile.rs:3:5
  |
3 |     &loud
  |     ^^^^^ returns a reference to data owned by the current function

error: aborting due to 1 previous error

For more information about this error, try `rustc --explain E0515`.
```

In C++ such a function builds; `g++` only warns. The fix in Rust: return the `String`
itself (`-> String`, last line `loud`). The value moves out to the caller.

## `String` and `&str`

| Rust | Closest C++ | Meaning |
|------|-------------|---------|
| `String` | `std::string` | owns its text |
| `&str` | `const std::string&` or `std::string_view` | borrows text that someone else owns |
| `"plov"` | a string literal | is a `&str` |
| `String::from("plov")` | `std::string("plov")` | makes an owned `String` |

A `Vec<i32>` has the same pair: `&[i32]`, a slice, borrows its elements.

## Watch out

- You write `&mut` twice: in the parameter type and at the call. The C++ call
  `addDelivery(prices)` does not show that `prices` may change.
- Only a `let mut` variable can be borrowed with `&mut`.

## Try it

Make `push_nocompile.rs` compile in two different ways.

<details>
<summary>Answer</summary>

1. Write `let first = scores[0];`. An `i32` is `Copy`, so nothing stays borrowed.
2. Or move the `println!` line above `push`. A borrow ends after its last use, so `push` is
   then free to change the vector.
</details>

**Next:** [Structs, enums and match](../04-structs-enums-and-match/README.md)
