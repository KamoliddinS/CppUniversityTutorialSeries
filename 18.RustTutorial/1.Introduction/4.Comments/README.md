# 📝 Comments and Documentation

## Overview

Comments are essential for writing maintainable code. Rust has a sophisticated documentation system that can generate beautiful HTML documentation from your comments.

## 🔤 Comment Types

### Line Comments

```rust
// This is a single-line comment
let x = 5; // This is an inline comment

// Multiple
// line
// comments
```

### Block Comments

```rust
/* This is a block comment
   spanning multiple lines */

let x = /* inline block comment */ 5;

/* Block comments can be /* nested */ in Rust! */
```

### Documentation Comments

```rust
/// This documents the following item
/// Multiple lines are supported
fn documented_function() {}

/** This is also a doc comment
    using block style */
fn another_function() {}
```

### Inner Documentation Comments

```rust
//! This documents the enclosing item (module/crate)
//! Typically used at the top of lib.rs

/*! Block style inner documentation
    for the current module */
```

## 📚 Documentation Comments in Detail

### Documenting Functions

```rust
/// Calculates the factorial of a number.
///
/// # Arguments
///
/// * `n` - The number to calculate factorial for
///
/// # Returns
///
/// The factorial of `n`
///
/// # Examples
///
/// ```
/// let result = factorial(5);
/// assert_eq!(result, 120);
/// ```
///
/// # Panics
///
/// Panics if `n` is greater than 20 (overflow)
fn factorial(n: u64) -> u64 {
    match n {
        0 | 1 => 1,
        _ => n * factorial(n - 1),
    }
}
```

### Common Documentation Sections

| Section | Purpose |
|---------|---------|
| `# Examples` | Code examples (also used as tests!) |
| `# Panics` | Conditions that cause panics |
| `# Errors` | Errors that can be returned |
| `# Safety` | Requirements for `unsafe` code |
| `# Arguments` | Description of parameters |
| `# Returns` | Description of return value |

### Documenting Structs and Enums

```rust
/// A rectangle with width and height.
///
/// # Examples
///
/// ```
/// let rect = Rectangle::new(10, 20);
/// assert_eq!(rect.area(), 200);
/// ```
pub struct Rectangle {
    /// The width of the rectangle
    pub width: u32,
    /// The height of the rectangle
    pub height: u32,
}

impl Rectangle {
    /// Creates a new rectangle with the given dimensions.
    ///
    /// # Arguments
    ///
    /// * `width` - The width of the rectangle
    /// * `height` - The height of the rectangle
    pub fn new(width: u32, height: u32) -> Self {
        Rectangle { width, height }
    }

    /// Calculates the area of the rectangle.
    pub fn area(&self) -> u32 {
        self.width * self.height
    }
}
```

### Documenting Modules

```rust
//! # My Awesome Crate
//!
//! `my_crate` provides utilities for working with data.
//!
//! ## Quick Start
//!
//! ```
//! use my_crate::process;
//! let result = process("data");
//! ```

/// Module for parsing operations.
///
/// This module contains functions for parsing various formats.
pub mod parser {
    /// Parses a string into an integer.
    pub fn parse_int(s: &str) -> Result<i32, std::num::ParseIntError> {
        s.parse()
    }
}
```

## 🔧 Markdown in Documentation

Doc comments support full Markdown:

```rust
/// # Heading Level 1
/// ## Heading Level 2
///
/// Regular paragraph with **bold** and *italic* text.
///
/// - Bullet point 1
/// - Bullet point 2
///   - Nested bullet
///
/// 1. Numbered list
/// 2. Second item
///
/// > Blockquote
///
/// `inline code`
///
/// ```rust
/// // Code block
/// let x = 5;
/// ```
///
/// | Column 1 | Column 2 |
/// |----------|----------|
/// | Data     | More     |
///
/// [Link text](https://example.com)
fn markdown_demo() {}
```

## 📖 Generating Documentation

### Build Documentation

```bash
cargo doc
```

### Build and Open in Browser

```bash
cargo doc --open
```

### Include Private Items

```bash
cargo doc --document-private-items
```

### Documentation for Dependencies

```bash
cargo doc --no-deps  # Only your crate
cargo doc            # Including dependencies
```

## ✅ Doc Tests

Code in documentation is automatically tested!

```rust
/// Adds two numbers together.
///
/// # Examples
///
/// ```
/// let sum = add(2, 3);
/// assert_eq!(sum, 5);
/// ```
pub fn add(a: i32, b: i32) -> i32 {
    a + b
}
```

Run doc tests:
```bash
cargo test --doc
```

### Hiding Code in Doc Tests

```rust
/// # Examples
///
/// ```
/// # // Lines starting with # are hidden but still run
/// # fn main() {
/// let result = my_function();
/// assert_eq!(result, 42);
/// # }
/// ```
```

### Showing Code That Shouldn't Run

```rust
/// # Examples
///
/// ```ignore
/// // This code is shown but not run
/// panic!("This would fail");
/// ```
///
/// ```no_run
/// // This code is compiled but not run
/// loop { }
/// ```
///
/// ```compile_fail
/// // This code should fail to compile
/// let x: i32 = "not a number";
/// ```
```

## 💡 Best Practices

### DO:
- Document all public items
- Include examples in documentation
- Explain the "why", not just the "what"
- Use proper grammar and spelling
- Keep examples simple and focused

### DON'T:
- Over-document obvious code
- Leave TODO comments in production
- Use comments instead of clear code

### Good Comment Example
```rust
// Use binary search for O(log n) complexity
// since the data is already sorted
let index = data.binary_search(&target);
```

### Bad Comment Example
```rust
// Increment i by 1
i += 1;  // The code already says this!
```

## 📂 Example Code

Navigate to [src/](./src/) to see complete examples.

---

[← Previous: Understanding Cargo](../3.Cargo/README.md) | [Next: Compiler Errors →](../5.CompilerErrors/README.md)
