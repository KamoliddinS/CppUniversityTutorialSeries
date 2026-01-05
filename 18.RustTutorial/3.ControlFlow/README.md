# 🔀 Lesson 3: Control Flow

Welcome to Lesson 3! In this lesson, you'll learn how to control the flow of your Rust programs using conditionals, loops, and pattern matching.

## 📚 Table of Contents

1. [If Expressions](./1.IfExpressions/README.md)
2. [Loops](./2.Loops/README.md)
3. [Pattern Matching](./3.PatternMatching/README.md)

## 🎯 Learning Objectives

By the end of this lesson, you will be able to:

- Use if/else expressions for conditional logic
- Work with different types of loops (loop, while, for)
- Use pattern matching with match expressions
- Understand how control flow constructs return values

## 🔍 Quick Overview

### If Expressions

```rust
let number = 7;

if number < 5 {
    println!("Less than 5");
} else if number == 5 {
    println!("Equal to 5");
} else {
    println!("Greater than 5");
}

// If as an expression
let result = if number > 0 { "positive" } else { "non-positive" };
```

### Loops

```rust
// Infinite loop
loop {
    break;
}

// While loop
while condition {
    // ...
}

// For loop
for i in 0..5 {
    println!("{}", i);
}
```

### Pattern Matching

```rust
let value = 2;

match value {
    1 => println!("One"),
    2 => println!("Two"),
    3 => println!("Three"),
    _ => println!("Other"),
}
```

## 📖 Lesson Topics

### [1. If Expressions](./1.IfExpressions/README.md)
Learn about conditional logic with if, else if, and else.

### [2. Loops](./2.Loops/README.md)
Master loop, while, and for loops in Rust.

### [3. Pattern Matching](./3.PatternMatching/README.md)
Discover the power of match expressions and patterns.

---

[← Previous Lesson: Data Types and Variables](../2.DataTypesVariables/README.md) | [Next Lesson: Functions →](../4.Functions/README.md)
