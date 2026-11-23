# Cargo and first differences

> **Goal:** build and run a Rust program with Cargo, and name what is different from C++.

## One tool for the whole build

In C++ you call `g++` yourself or describe the build for CMake
([Hello, world](../../01-first-programs/01-hello-world/README.md)).
Rust comes with **Cargo**: one tool that creates, builds, runs and tests a project.

Install Rust from the [official install page](https://www.rust-lang.org/tools/install).
The course's dev container has it already.

1. Linux or macOS: run the one-line `rustup` command shown there.
2. Windows: run `rustup-init.exe` from that page. Rust also needs the Microsoft C++ build
   tools; the installer offers to install them.
3. Open a new terminal and check: `cargo --version`.

| You want to | C++ | Rust |
|-------------|-----|------|
| start a project | – | `cargo new hello_cargo` |
| build | `g++ main.cpp -o hello` | `cargo build` (the program goes to `target/debug/`) |
| build and run | `g++ ...`, then `./hello` | `cargo run` |
| only look for errors | – | `cargo check` |
| run the tests | `ctest --test-dir build` | `cargo test` |

`cargo new` makes a folder with `Cargo.toml`, which describes the project, and
`src/main.rs`, the program. `edition` picks the language rules, like `-std=c++20`.

**`hello_cargo/Cargo.toml`**
<!-- file: hello_cargo/Cargo.toml -->
```toml
[package]
name = "hello_cargo"
version = "0.1.0"
edition = "2024"

[dependencies]
```

**`hello_cargo/src/main.rs`**
<!-- file: hello_cargo/src/main.rs -->
```rust
// fn name(parameter: type) -> return type.  f64 is double, i32 is a 32-bit int.
fn delivery_fee(distance_km: f64) -> i32 {
    if distance_km > 10.0 { 15000 } else { 8000 }   // `if` gives a value: no `return`, no `;`
}

fn main() {
    let shop = "Chorsu";                // cannot be changed
    let mut items = 0;                  // `mut`: can be changed
    for day in 1..=3 {                  // 1, 2, 3
        items += day;                   // there is no `++`
    }

    let size = match items {            // every possible value must be covered
        0 => "empty",
        1..=5 => "small",
        _ => "large",                   // `_` means: everything else
    };

    let weight_kg = items as f64 * 1.5; // i32 to f64: you must write the conversion
    println!("{shop}: {items} items, a {size} order, {weight_kg} kg");
    println!("Delivery: {} so'm", delivery_fee(12.0));
}
```

<!-- output: hello_cargo -->
```text
Chorsu: 6 items, a large order, 9 kg
Delivery: 15000 so'm
```

## What is different from C++

| In C++ | In Rust |
|--------|---------|
| variables change unless `const` | variables are fixed unless `let mut` |
| `int` becomes `double` silently | no silent number conversion: write `as f64` |
| overloading: one name, several functions | one name, one function |
| `if` is a statement | `if` and `{ }` give a value: the last expression, without `;` |
| `switch` falls through without `break`, and need not cover every case | `match` never falls through and must cover every case |
| `count++` | `count += 1` |
| `nullptr` | no null: [lesson 4](../04-structs-enums-and-match/README.md) |
| exceptions | no exceptions: [lesson 5](../05-result-and-option/README.md) |
| classes and inheritance | structs and traits: [lesson 6](../06-traits-and-generics/README.md) |

## Watch out

- `println!` is a macro, not a function: keep the `!`. `{items}` or `{}` marks where a value goes.
- Variables and functions are named `like_this`. The compiler warns about `likeThis`.
- The next lessons use single files. Build one without Cargo:
  `rustc --edition 2024 moves.rs`, then run `./moves`.

## Try it

1. Run `cargo run` inside `hello_cargo`. Then delete `mut` and run `cargo check`. What does
   the compiler suggest?
2. Predict the first output line when the loop is `for day in 1..3`.

<details>
<summary>Answers</summary>

1. `cannot assign twice to immutable variable`, and below it
   `help: consider making this binding mutable`.
2. `Chorsu: 3 items, a small order, 4.5 kg`. `1..3` stops before 3; `1..=3` includes it.
</details>

**Next:** [Ownership and moves](../02-ownership-and-moves/README.md)
