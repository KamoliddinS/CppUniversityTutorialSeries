# 🔐 Lesson 5: Ownership and Borrowing

Welcome to Lesson 5! This is one of Rust's most unique and important concepts. Ownership is how Rust achieves memory safety without a garbage collector.

## 📚 Table of Contents

1. [Understanding Ownership](./1.Ownership/README.md)
2. [References and Borrowing](./2.Borrowing/README.md)
3. [Slices](./3.Slices/README.md)

## 🎯 Learning Objectives

By the end of this lesson, you will be able to:

- Understand Rust's ownership rules
- Work with references and borrowing
- Use string and array slices
- Avoid common ownership mistakes

## 🔍 Quick Overview

### Ownership Rules

1. Each value in Rust has an **owner**
2. There can only be **one owner** at a time
3. When the owner goes out of scope, the value is **dropped**

### The Three Flavors

```rust
// 1. Ownership (full control)
let s1 = String::from("hello");
let s2 = s1;  // s1 is moved to s2

// 2. Immutable Borrow (read-only access)
let s1 = String::from("hello");
let len = calculate_length(&s1);  // s1 is borrowed

// 3. Mutable Borrow (read-write access)
let mut s1 = String::from("hello");
append_world(&mut s1);  // s1 is mutably borrowed
```

## 📖 Lesson Topics

### [1. Understanding Ownership](./1.Ownership/README.md)
Learn the fundamental rules that govern memory in Rust.

### [2. References and Borrowing](./2.Borrowing/README.md)
Master borrowing - using values without taking ownership.

### [3. Slices](./3.Slices/README.md)
Work with slices - references to contiguous sequences.

---

[← Previous Lesson: Functions](../4.Functions/README.md) | [Next Lesson: Structs and Enums →](../6.StructsEnums/README.md)
