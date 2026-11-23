# Ownership and moves

> **Goal:** predict when `=` moves a value in Rust, and compare that with copies and `std::move` in C++.

## In C++ `=` copies

In C++ you copy a string with `=`, and both variables stay usable. After `std::move(a)` the
compiler still lets you use `a`
([Moving objects](../../10-resource-management/03-moving-objects/README.md)).

**`copy_and_move.cpp`**
<!-- file: copy_and_move.cpp -->
```cpp
#include <iostream>
#include <string>
#include <utility>

int main() {
    std::string a = "Samarkand";
    std::string b = a;                // copy: a and b each have the text
    std::string c = std::move(a);     // move: c takes the text out of a
    std::cout << "b = " << b << ", c = " << c << '\n';
    std::cout << "a has " << a.size() << " letters\n";   // builds without a warning
}
```

<!-- output: copy_and_move -->
```text
b = Samarkand, c = Samarkand
a has 0 letters
```

After the move, the standard only promises that `a` is valid; what it holds is unspecified.
With `g++` it is empty.

## In Rust `=` moves

Every Rust value has exactly one owner, usually the variable that holds it. This rule is
called **ownership**. `let c = a;` is a **move**: `c` becomes the owner, and `a` cannot be
used any more.

**`moves.rs`**
<!-- file: moves.rs -->
```rust
#[derive(Clone, Copy)]          // marks Point as Copy; without this line a Point moves
struct Point {
    x: i32,
    y: i32,
}

fn main() {
    let a = String::from("Samarkand");
    let b = a.clone();          // a copy, because you asked for one
    let c = a;                  // move: c owns the text now, a is gone
    println!("b = {b}, c = {c}");

    let n = 5;
    let m = n;                  // i32 is Copy: n stays usable
    let p = Point { x: 3, y: 4 };
    let q = p;                  // Point is Copy too
    println!("n = {n}, m = {m}, p.x = {}, q.y = {}", p.x, q.y);
}
```

<!-- output: moves -->
```text
b = Samarkand, c = Samarkand
n = 5, m = 5, p.x = 3, q.y = 4
```

- `String` is Rust's `std::string`. `.clone()` makes the copy, and you must ask for it.
- Only types marked `Copy` are copied by `=`, such as integers, floats, `bool`, `char`, and
  structs that you mark yourself.

Using a moved value is a compile error:

**`use_after_move_nocompile.rs`**
<!-- file: use_after_move_nocompile.rs -->
```rust
fn main() {
    let a = String::from("Samarkand");
    let c = a;
    println!("c = {c}");
    println!("a = {a}");
}
```

<!-- errors: use_after_move_nocompile -->
```text
error[E0382]: borrow of moved value: `a`
 --> use_after_move_nocompile.rs:5:20
  |
2 |     let a = String::from("Samarkand");
  |         - move occurs because `a` has type `String`, which does not implement the `Copy` trait
3 |     let c = a;
  |             - value moved here
4 |     println!("c = {c}");
5 |     println!("a = {a}");
  |                    ^ value borrowed here after move
  |
help: consider cloning the value if the performance cost is acceptable
  |
3 |     let c = a.clone();
  |              ++++++++

error: aborting due to 1 previous error

For more information about this error, try `rustc --explain E0382`.
```

| Part of the message | Meaning |
|---------------------|---------|
| `error[E0382]` | the kind of error; `rustc --explain E0382` prints a longer text |
| `--> ...:5:20` | file, line and column |
| the three notes under the code | where `a` got its value, where it moved, where you used it |
| `help:` | a fix that the compiler suggests |

## Dropped once, at the end of scope

When the owner goes out of scope, the value is destroyed: Rust says it is **dropped**. This is
[RAII](../../10-resource-management/01-raii/README.md), and `drop` is the destructor.
([Lesson 6](../06-traits-and-generics/README.md) explains the `impl ... for` line.)

**`drop_order.rs`**
<!-- file: drop_order.rs -->
```rust
struct Door {
    name: String,
}

impl Drop for Door {
    fn drop(&mut self) {                // Rust's destructor
        println!("closing the {}", self.name);
    }
}

fn lock(door: Door) {                   // a parameter by value takes ownership
    println!("locking the {}", door.name);
}                                       // door is dropped here

fn main() {
    let front = Door { name: String::from("front door") };
    let back = Door { name: String::from("back door") };
    lock(front);                        // front moves into the function
    println!("the {} is still open", back.name);
}                                       // back is dropped here; front is not dropped again
```

<!-- output: drop_order -->
```text
locking the front door
closing the front door
the back door is still open
closing the back door
```

A moved value is dropped by its new owner only: `main` does not drop `front` again. (In C++
the destructor of a moved-from object still runs.) A value that is not `Copy` behaves like
the object behind a [`std::unique_ptr`](../../10-resource-management/05-unique-ptr/README.md):
it has exactly one owner, and `=` moves it.

## Watch out

- Move or copy does not depend on stack or heap. It depends only on `Copy`.
- Passing a value to a function moves it too, unless its type is `Copy`.

## Try it

1. Predict the output of `drop_order.rs` when `lock(front);` comes after the `println!` line.
2. `point_nocompile.rs` has a `Point` without the `derive` line. Which error do you expect?

<details>
<summary>Answers</summary>

1. `the back door is still open`, `locking the front door`, `closing the front door`,
   `closing the back door`.
2. ``error[E0382]: borrow of moved value: `p` ``. A struct of two integers is moved too, unless it
   is marked `Copy`.
</details>

**Next:** [Borrowing](../03-borrowing/README.md)
