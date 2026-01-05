# 🔴 Compiler Errors

## Overview

Rust is famous for its helpful error messages. The compiler acts as your first line of defense, catching bugs at compile time that would be runtime errors in other languages. Learning to read and understand Rust's error messages is a crucial skill.

## 🎯 Types of Errors

### 1. Syntax Errors

The most basic errors - when your code doesn't follow Rust's grammar.

```rust
// Error: missing semicolon
fn main() {
    let x = 5
}
```

**Error Message:**
```
error: expected `;`, found `}`
 --> src/main.rs:3:14
  |
3 |     let x = 5
  |              ^ help: add `;` here
```

### 2. Type Errors

When types don't match up.

```rust
fn main() {
    let x: i32 = "hello"; // Can't assign string to integer
}
```

**Error Message:**
```
error[E0308]: mismatched types
 --> src/main.rs:2:18
  |
2 |     let x: i32 = "hello";
  |            ---   ^^^^^^^ expected `i32`, found `&str`
  |            |
  |            expected due to this
```

### 3. Borrow Checker Errors

Rust's unique ownership system errors.

```rust
fn main() {
    let s = String::from("hello");
    let s2 = s;      // s is moved to s2
    println!("{}", s); // Error! s no longer valid
}
```

**Error Message:**
```
error[E0382]: borrow of moved value: `s`
 --> src/main.rs:4:20
  |
2 |     let s = String::from("hello");
  |         - move occurs because `s` has type `String`
3 |     let s2 = s;
  |              - value moved here
4 |     println!("{}", s);
  |                    ^ value borrowed here after move
  |
help: consider cloning the value if the performance cost is acceptable
  |
3 |     let s2 = s.clone();
  |               ++++++++
```

### 4. Lifetime Errors

When references outlive the data they point to.

```rust
fn main() {
    let r;
    {
        let x = 5;
        r = &x; // Error! x doesn't live long enough
    }
    println!("{}", r);
}
```

**Error Message:**
```
error[E0597]: `x` does not live long enough
 --> src/main.rs:5:13
  |
5 |         r = &x;
  |             ^^ borrowed value does not live long enough
6 |     }
  |     - `x` dropped here while still borrowed
7 |     println!("{}", r);
  |                    - borrow later used here
```

## 📖 Reading Error Messages

Rust error messages have a consistent format:

```
error[E0308]: mismatched types        <- Error code and title
 --> src/main.rs:2:18                 <- File location
  |
2 |     let x: i32 = "hello";         <- The problematic code
  |            ---   ^^^^^^^ expected `i32`, found `&str`  <- Explanation
  |            |
  |            expected due to this   <- Additional context

For more information about this error, try `rustc --explain E0308`
```

### Key Components:

| Part | Description |
|------|-------------|
| `error[EXXXX]` | Error code for looking up documentation |
| `-->` | Points to the exact file and line |
| `^^` | Underlines the problematic code |
| `help:` | Suggests how to fix the issue |
| `note:` | Provides additional context |

## 🔧 Common Errors and Fixes

### E0308: Mismatched Types

**Problem:**
```rust
let x: i32 = 3.14; // Type mismatch
```

**Fix:**
```rust
let x: f64 = 3.14; // Use correct type
// OR
let x: i32 = 3;    // Use integer value
```

### E0382: Use of Moved Value

**Problem:**
```rust
let s1 = String::from("hello");
let s2 = s1;
println!("{}", s1); // s1 was moved!
```

**Fix:**
```rust
let s1 = String::from("hello");
let s2 = s1.clone(); // Clone instead of move
println!("{}", s1);  // Now works!
```

### E0502: Cannot Borrow as Mutable

**Problem:**
```rust
let mut v = vec![1, 2, 3];
let first = &v[0];
v.push(4);          // Can't mutate while borrowed
println!("{}", first);
```

**Fix:**
```rust
let mut v = vec![1, 2, 3];
let first = v[0];   // Copy the value instead
v.push(4);          // Now we can mutate
println!("{}", first);
```

### E0425: Cannot Find Value

**Problem:**
```rust
fn main() {
    println!("{}", x); // x doesn't exist
}
```

**Fix:**
```rust
fn main() {
    let x = 5;
    println!("{}", x);
}
```

### E0433: Cannot Find Module

**Problem:**
```rust
use std::collections::Hashmap; // Wrong case
```

**Fix:**
```rust
use std::collections::HashMap; // Correct: HashMap
```

## 🛠️ Error Investigation Tools

### Get Detailed Explanation

```bash
rustc --explain E0308
```

### Use cargo check (Faster)

```bash
cargo check  # Faster than cargo build for finding errors
```

### Enable More Warnings

```rust
#![warn(unused_variables)]
#![warn(dead_code)]
```

### Use Clippy for Better Suggestions

```bash
cargo clippy
```

## 🎓 Learning from Errors

### Strategy 1: Read Top to Bottom

Errors are reported in order. Fix the first one, as later errors might be caused by earlier ones.

### Strategy 2: Focus on the First Line

The error message title usually tells you exactly what's wrong.

### Strategy 3: Use the Help Section

Rust often tells you exactly how to fix the problem.

### Strategy 4: Look Up the Error Code

```bash
rustc --explain E0308
```

## 💡 Warnings vs Errors

| Type | Behavior |
|------|----------|
| **Error** | Compilation fails, must be fixed |
| **Warning** | Compilation succeeds, should be fixed |

### Common Warnings

```rust
fn main() {
    let unused = 5;     // Warning: unused variable
    // Warning: this function is never used
}

fn never_called() {}
```

Suppress warnings (use sparingly):
```rust
#[allow(dead_code)]
fn unused_function() {}

let _intentionally_unused = 5; // Prefix with _ to silence warning
```

## 🏋️ Exercises

1. Write code that produces E0308 (type mismatch) and fix it
2. Create a borrow checker error (E0382) and understand the solution
3. Use `rustc --explain` to learn about 3 different error codes

## 📂 Example Code

Navigate to [src/](./src/) to see examples of common errors and their fixes.

---

[← Previous: Comments and Documentation](../4.Comments/README.md) | [Next Lesson: Data Types and Variables →](../../2.DataTypesVariables/README.md)
