# 🎭 Lesson 9: Traits and Generics

Welcome to Lesson 9! Learn how to write flexible, reusable code with generics and traits.

## 📚 Table of Contents

1. [Generic Types](./1.Generics/README.md)
2. [Traits](./2.Traits/README.md)

## 🎯 Learning Objectives

By the end of this lesson, you will be able to:

- Define generic functions, structs, and enums
- Create and implement traits
- Use trait bounds
- Understand trait objects

## 🔍 Quick Overview

### Generics

```rust
// Generic function
fn largest<T: PartialOrd>(list: &[T]) -> &T {
    let mut largest = &list[0];
    for item in list {
        if item > largest {
            largest = item;
        }
    }
    largest
}

// Generic struct
struct Point<T> {
    x: T,
    y: T,
}
```

### Traits

```rust
// Define a trait
trait Summary {
    fn summarize(&self) -> String;
}

// Implement for a type
struct Article {
    title: String,
    content: String,
}

impl Summary for Article {
    fn summarize(&self) -> String {
        format!("{}: {}", self.title, &self.content[..50])
    }
}
```

## 📖 Lesson Topics

### [1. Generic Types](./1.Generics/README.md)
Write code that works with multiple types.

### [2. Traits](./2.Traits/README.md)
Define shared behavior across types.

---

[← Previous Lesson: Collections](../8.Collections/README.md) | [Next Lesson: Lifetimes →](../10.Lifetimes/README.md)
