# 📊 Lesson 2: Data Types and Variables

Welcome to Lesson 2! In this lesson, you'll learn about Rust's type system, variables, and how to store data.

## 📚 Table of Contents

1. [Variables and Mutability](./1.VariablesMutability/README.md)
2. [Primitive Types](./2.PrimitiveTypes/README.md)
3. [Compound Types](./3.CompoundTypes/README.md)
4. [Constants and Statics](./4.ConstantsStatics/README.md)
5. [Type Inference and Annotations](./5.TypeInference/README.md)

## 🎯 Learning Objectives

By the end of this lesson, you will be able to:

- Declare and use variables in Rust
- Understand mutability and immutability
- Use all primitive data types
- Work with compound types (tuples, arrays)
- Define constants and static variables
- Understand Rust's type inference

## 🔍 Quick Overview

### Variables in Rust

```rust
let x = 5;           // Immutable by default
let mut y = 10;      // Mutable
y = 20;              // OK

const MAX: i32 = 100; // Constant
static COUNT: i32 = 0; // Static
```

### Primitive Types

| Category | Types |
|----------|-------|
| **Integers** | `i8`, `i16`, `i32`, `i64`, `i128`, `isize` |
| **Unsigned** | `u8`, `u16`, `u32`, `u64`, `u128`, `usize` |
| **Floats** | `f32`, `f64` |
| **Boolean** | `bool` |
| **Character** | `char` |

### Compound Types

```rust
// Tuple - fixed size, different types
let tuple: (i32, f64, char) = (42, 3.14, 'x');

// Array - fixed size, same type
let array: [i32; 5] = [1, 2, 3, 4, 5];
```

## 📖 Lesson Topics

### [1. Variables and Mutability](./1.VariablesMutability/README.md)
Learn how Rust handles variable declarations and why immutability is the default.

### [2. Primitive Types](./2.PrimitiveTypes/README.md)
Explore integers, floating-point numbers, booleans, and characters.

### [3. Compound Types](./3.CompoundTypes/README.md)
Work with tuples and arrays for grouping multiple values.

### [4. Constants and Statics](./4.ConstantsStatics/README.md)
Understand the difference between `const` and `static` values.

### [5. Type Inference and Annotations](./5.TypeInference/README.md)
Learn when to let Rust infer types and when to annotate them.

---

[← Previous Lesson: Introduction](../1.Introduction/README.md) | [Next Lesson: Control Flow →](../3.ControlFlow/README.md)
