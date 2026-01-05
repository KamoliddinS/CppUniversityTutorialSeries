# 💥 Unrecoverable Errors with panic!

## Overview

When something goes so wrong that there's no way to recover, Rust uses `panic!`. This immediately stops execution and unwinds the stack.

## 🔤 Using panic!

```rust
fn main() {
    panic!("Something went terribly wrong!");
}
```

Output:
```
thread 'main' panicked at 'Something went terribly wrong!', src/main.rs:2:5
```

## 📊 When to Panic

### Good Use Cases

| Situation | Example |
|-----------|---------|
| Bug in code | Reaching impossible state |
| Contract violation | Invalid arguments to function |
| Prototype/example code | Quick testing |
| Tests | `assert!` and `assert_eq!` |

### Bad Use Cases

| Situation | Better Alternative |
|-----------|-------------------|
| File not found | Return `Result` |
| Network error | Return `Result` |
| User input error | Return `Result` |

## 🔧 Assertions

```rust
fn main() {
    let x = 5;

    // assert! - panics if false
    assert!(x > 0);

    // assert_eq! - panics if not equal
    assert_eq!(x, 5);

    // assert_ne! - panics if equal
    assert_ne!(x, 0);

    // With custom message
    assert!(x > 0, "x must be positive, got {}", x);
}
```

## 🎯 unwrap and expect

```rust
// unwrap - panics on None/Err with generic message
let value: Option<i32> = None;
let x = value.unwrap();  // Panics!

// expect - panics with custom message
let x = value.expect("Value should not be None");
```

## 🔄 Panic Behavior

### Unwinding (Default)

When a panic occurs, Rust:
1. Prints error message
2. Unwinds the stack (runs destructors)
3. Exits the program

### Aborting

In `Cargo.toml`:
```toml
[profile.release]
panic = 'abort'
```

Abort immediately without unwinding (smaller binary).

## 🛡️ Catching Panics

```rust
use std::panic;

fn main() {
    let result = panic::catch_unwind(|| {
        panic!("Oh no!");
    });

    match result {
        Ok(_) => println!("No panic"),
        Err(_) => println!("Caught a panic!"),
    }

    println!("Program continues...");
}
```

**Note**: This should be used sparingly, mainly for:
- FFI boundaries
- Thread pools
- Testing frameworks

## 📊 Result vs Panic

| Criteria | Result | Panic |
|----------|--------|-------|
| Expected failure | ✅ | ❌ |
| Bug/impossible state | ❌ | ✅ |
| Library code | ✅ | ❌ |
| Recoverable | ✅ | ❌ |
| Performance critical | ✅ | ❌ |

## 📂 Example Code

```rust
fn main() {
    // Panic in action
    // panic!("Crash!");  // Uncomment to see panic

    // Safe division
    match divide(10, 2) {
        Some(result) => println!("10 / 2 = {}", result),
        None => println!("Cannot divide by zero"),
    }

    // Assert usage
    let numbers = vec![1, 2, 3];
    assert!(!numbers.is_empty(), "Vector should not be empty");

    // Validate with panic for bugs
    let config = Config::new("production");
    println!("Running in {} mode", config.mode);
}

fn divide(a: i32, b: i32) -> Option<i32> {
    if b == 0 {
        None
    } else {
        Some(a / b)
    }
}

struct Config {
    mode: String,
}

impl Config {
    fn new(mode: &str) -> Self {
        // Panic for invalid configuration (a bug)
        let valid_modes = ["development", "production", "test"];
        if !valid_modes.contains(&mode) {
            panic!("Invalid mode: {}. Must be one of {:?}", mode, valid_modes);
        }
        Config { mode: mode.to_string() }
    }
}
```

---

[← Previous: Recoverable Errors with Result](../1.Result/README.md) | [Next Lesson: Collections →](../../8.Collections/README.md)
