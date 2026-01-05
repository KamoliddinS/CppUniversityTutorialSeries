# ⚠️ Lesson 7: Error Handling

Welcome to Lesson 7! Learn how Rust handles errors in a safe and explicit way.

## 📚 Table of Contents

1. [Recoverable Errors with Result](./1.Result/README.md)
2. [Unrecoverable Errors with panic!](./2.Panic/README.md)

## 🎯 Learning Objectives

By the end of this lesson, you will be able to:

- Use `Result<T, E>` for recoverable errors
- Understand when to use `panic!`
- Propagate errors with the `?` operator
- Create custom error types

## 🔍 Quick Overview

### Rust's Error Philosophy

| Error Type | Mechanism | Use Case |
|------------|-----------|----------|
| Recoverable | `Result<T, E>` | Expected failures (file not found, parse error) |
| Unrecoverable | `panic!` | Bugs, impossible states |

### The Result Type

```rust
enum Result<T, E> {
    Ok(T),
    Err(E),
}
```

### Basic Error Handling

```rust
use std::fs::File;

fn main() {
    // Handling errors explicitly
    let file = match File::open("data.txt") {
        Ok(f) => f,
        Err(e) => {
            println!("Error: {}", e);
            return;
        }
    };

    // Using ? operator
    fn read_file() -> Result<String, std::io::Error> {
        let content = std::fs::read_to_string("data.txt")?;
        Ok(content)
    }
}
```

## 📖 Lesson Topics

### [1. Recoverable Errors with Result](./1.Result/README.md)
Learn to handle expected errors gracefully.

### [2. Unrecoverable Errors with panic!](./2.Panic/README.md)
Understand when and how to use panic for unrecoverable situations.

---

[← Previous Lesson: Structs and Enums](../6.StructsEnums/README.md) | [Next Lesson: Collections →](../8.Collections/README.md)
