# 📝 Strings

## Overview

Rust has two main string types: `String` (owned, growable) and `&str` (borrowed slice). Both are UTF-8 encoded.

## 📊 String vs &str

| Type | Ownership | Mutability | Storage |
|------|-----------|------------|---------|
| `String` | Owned | Mutable | Heap |
| `&str` | Borrowed | Immutable | Anywhere |

## 🔤 Creating Strings

```rust
// From string literal
let s1 = String::from("hello");
let s2 = "hello".to_string();

// Empty string
let s3 = String::new();

// With capacity
let s4 = String::with_capacity(10);
```

## 📝 Modifying Strings

```rust
let mut s = String::from("Hello");

// Append string slice
s.push_str(", World");

// Append character
s.push('!');

// Using + operator (consumes first string)
let s1 = String::from("Hello, ");
let s2 = String::from("World!");
let s3 = s1 + &s2;  // s1 is moved

// Using format! macro
let s1 = String::from("Hello");
let s2 = String::from("World");
let s3 = format!("{}, {}!", s1, s2);  // Neither consumed
```

## 🔧 String Operations

```rust
let s = String::from("Hello, World!");

// Length (bytes, not characters)
println!("Length: {}", s.len());

// Check if empty
println!("Empty: {}", s.is_empty());

// Contains
println!("Contains 'World': {}", s.contains("World"));

// Replace
let new_s = s.replace("World", "Rust");

// Split
for word in s.split(", ") {
    println!("{}", word);
}

// Trim whitespace
let padded = "  hello  ";
let trimmed = padded.trim();

// Case conversion
let upper = s.to_uppercase();
let lower = s.to_lowercase();
```

## 🔄 Iterating Over Strings

```rust
let s = "hello";

// By characters
for c in s.chars() {
    println!("{}", c);
}

// By bytes
for b in s.bytes() {
    println!("{}", b);
}

// Character indices
for (i, c) in s.char_indices() {
    println!("{}: {}", i, c);
}
```

## ⚠️ String Indexing

Strings cannot be indexed by integer:

```rust
let s = String::from("hello");
// let h = s[0];  // Error!

// Use slices instead
let h = &s[0..1];  // "h"

// Or chars
let first = s.chars().next().unwrap();  // 'h'
```

## 🌐 UTF-8 Considerations

```rust
let hello = "Здравствуйте";  // Russian "hello"

// len() returns bytes
println!("Bytes: {}", hello.len());  // 24

// chars().count() returns characters
println!("Chars: {}", hello.chars().count());  // 12
```

## 📂 Example Code

```rust
fn main() {
    // Building a string
    let mut message = String::new();
    message.push_str("Hello");
    message.push(',');
    message.push_str(" World!");
    println!("{}", message);

    // Concatenation
    let greeting = String::from("Hello");
    let name = String::from("Alice");
    let full = format!("{}, {}!", greeting, name);
    println!("{}", full);

    // String methods
    let text = "  Rust Programming  ";
    println!("Trimmed: '{}'", text.trim());
    println!("Upper: '{}'", text.to_uppercase());
    println!("Contains 'Rust': {}", text.contains("Rust"));

    // Word counting
    let sentence = "The quick brown fox jumps over the lazy dog";
    let word_count = sentence.split_whitespace().count();
    println!("Word count: {}", word_count);

    // Parsing
    let number_str = "42";
    let number: i32 = number_str.parse().unwrap();
    println!("Parsed number: {}", number);
}
```

---

[← Previous: Vectors](../1.Vectors/README.md) | [Next: HashMaps →](../3.HashMaps/README.md)
