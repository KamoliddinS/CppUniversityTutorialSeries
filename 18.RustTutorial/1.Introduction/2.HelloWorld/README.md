# 👋 Hello World in Rust

## Overview

Every programming journey begins with "Hello, World!" Let's write your first Rust program and understand every part of it.

## 🚀 Your First Program

### Using rustc (The Compiler)

Create a file called `main.rs`:

```rust
fn main() {
    println!("Hello, World!");
}
```

Compile and run:
```bash
rustc main.rs
./main
```

Output:
```
Hello, World!
```

### Using Cargo (Recommended)

```bash
cargo new hello_world
cd hello_world
cargo run
```

## 🔍 Code Breakdown

Let's analyze each part of our Hello World program:

```rust
fn main() {
    println!("Hello, World!");
}
```

### `fn main()`

| Part | Meaning |
|------|---------|
| `fn` | Keyword to define a function |
| `main` | Function name (special - entry point) |
| `()` | Parameter list (empty = no parameters) |
| `{}` | Function body |

The `main` function is special - it's always the first code that runs in every executable Rust program.

### `println!("Hello, World!");`

| Part | Meaning |
|------|---------|
| `println!` | A macro (note the `!`) that prints to console |
| `"Hello, World!"` | A string literal |
| `;` | Statement terminator |

**Why `println!` and not `println`?**

The `!` indicates this is a **macro**, not a regular function. Macros can:
- Accept variable number of arguments
- Generate code at compile time
- Do things functions cannot

## 📝 Variations

### Print Without Newline

```rust
fn main() {
    print!("Hello, ");
    print!("World!");
    println!(); // Just prints a newline
}
```

### Print with Variables

```rust
fn main() {
    let name = "Rustacean";
    println!("Hello, {}!", name);
}
```

### Multiple Placeholders

```rust
fn main() {
    let language = "Rust";
    let year = 2015;
    println!("{} was released in {}", language, year);
}
```

### Named Placeholders

```rust
fn main() {
    println!("{language} is {adjective}!",
             language = "Rust",
             adjective = "awesome");
}
```

### Debug Printing

```rust
fn main() {
    let numbers = [1, 2, 3, 4, 5];
    println!("{:?}", numbers);  // Debug format
    println!("{:#?}", numbers); // Pretty debug format
}
```

## 🎯 Key Points

1. **File Extension**: Rust files use `.rs` extension
2. **Main Function**: Every executable needs a `main()` function
3. **Semicolons**: Most statements end with `;`
4. **Curly Braces**: Used to define code blocks
5. **Macros**: Identified by `!` suffix

## 💡 Common Mistakes

### Missing Semicolon
```rust
fn main() {
    println!("Hello")  // Error! Missing semicolon
}
```

### Wrong Quotes
```rust
fn main() {
    println!('Hello');  // Error! Use double quotes for strings
}
```

### Forgetting the Exclamation Mark
```rust
fn main() {
    println("Hello");  // Error! println is a macro, use println!
}
```

## 🏋️ Exercises

1. **Basic**: Modify the program to print your name
2. **Intermediate**: Print multiple lines with different messages
3. **Advanced**: Use variables and placeholders to create a formatted greeting

## 📂 Example Code

Navigate to [src/](./src/) to see the complete example:
- [main.rs](./src/main.rs) - Hello World program

---

[← Previous: What is Rust?](../1.WhatIsRust/README.md) | [Next: Understanding Cargo →](../3.Cargo/README.md)
