# 🔧 Lesson 4: Functions

Welcome to Lesson 4! In this lesson, you'll learn how to define and use functions in Rust.

## 📚 Table of Contents

1. [Defining Functions](./1.DefiningFunctions/README.md)
2. [Parameters and Arguments](./2.Parameters/README.md)
3. [Return Values](./3.ReturnValues/README.md)
4. [Closures](./4.Closures/README.md)

## 🎯 Learning Objectives

By the end of this lesson, you will be able to:

- Define and call functions
- Work with parameters and arguments
- Return values from functions
- Use closures (anonymous functions)

## 🔍 Quick Overview

### Basic Function

```rust
fn greet() {
    println!("Hello!");
}

fn main() {
    greet();
}
```

### With Parameters

```rust
fn greet(name: &str) {
    println!("Hello, {}!", name);
}
```

### With Return Value

```rust
fn add(a: i32, b: i32) -> i32 {
    a + b  // No semicolon = return value
}
```

### Closures

```rust
let add = |a, b| a + b;
let result = add(5, 3);
```

## 📖 Lesson Topics

### [1. Defining Functions](./1.DefiningFunctions/README.md)
Learn the syntax for creating functions in Rust.

### [2. Parameters and Arguments](./2.Parameters/README.md)
Understand how to pass data to functions.

### [3. Return Values](./3.ReturnValues/README.md)
Learn how functions return data.

### [4. Closures](./4.Closures/README.md)
Master anonymous functions and their power.

---

[← Previous Lesson: Control Flow](../3.ControlFlow/README.md) | [Next Lesson: Ownership and Borrowing →](../5.OwnershipBorrowing/README.md)
