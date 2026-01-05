# 📚 Lesson 8: Collections

Welcome to Lesson 8! Learn about Rust's standard collection types for storing multiple values.

## 📚 Table of Contents

1. [Vectors](./1.Vectors/README.md)
2. [Strings](./2.Strings/README.md)
3. [HashMaps](./3.HashMaps/README.md)

## 🎯 Learning Objectives

By the end of this lesson, you will be able to:

- Use vectors to store lists of values
- Work with String and &str
- Store key-value pairs in HashMaps
- Iterate over collections

## 🔍 Quick Overview

### Vectors

```rust
let mut numbers = vec![1, 2, 3];
numbers.push(4);
println!("{:?}", numbers);  // [1, 2, 3, 4]
```

### Strings

```rust
let mut s = String::from("Hello");
s.push_str(", World!");
println!("{}", s);  // Hello, World!
```

### HashMaps

```rust
use std::collections::HashMap;

let mut scores = HashMap::new();
scores.insert("Alice", 100);
scores.insert("Bob", 85);
```

## 📖 Lesson Topics

### [1. Vectors](./1.Vectors/README.md)
Dynamic arrays that can grow and shrink.

### [2. Strings](./2.Strings/README.md)
UTF-8 encoded text handling.

### [3. HashMaps](./3.HashMaps/README.md)
Key-value storage for fast lookups.

---

[← Previous Lesson: Error Handling](../7.ErrorHandling/README.md) | [Next Lesson: Traits and Generics →](../9.TraitsGenerics/README.md)
