# 🔒 Variables and Mutability

## Overview

In Rust, variables are **immutable by default**. This is a deliberate design choice that helps prevent bugs and makes code easier to reason about.

## 📝 Declaring Variables

### Basic Declaration

```rust
let x = 5;  // x is immutable
```

### Mutable Variables

```rust
let mut y = 5;  // y is mutable
y = 10;         // OK - y can be changed
```

### Without `mut`, you get an error:

```rust
let x = 5;
x = 10;  // Error: cannot assign twice to immutable variable
```

## 🎯 Why Immutability by Default?

| Benefit | Description |
|---------|-------------|
| **Safety** | Prevents accidental modifications |
| **Concurrency** | Immutable data is thread-safe |
| **Clarity** | Easier to understand code flow |
| **Optimization** | Compiler can optimize better |

## 🔄 Shadowing

You can declare a new variable with the same name:

```rust
let x = 5;
let x = x + 1;     // New variable, shadows the old one
let x = x * 2;     // Another new variable
println!("{}", x); // Prints 12
```

### Shadowing vs Mutability

```rust
// Shadowing - can change type
let spaces = "   ";
let spaces = spaces.len();  // OK - new variable of different type

// Mutability - cannot change type
let mut spaces = "   ";
spaces = spaces.len();  // Error! Can't change type
```

### When to Use Shadowing

- Transforming a value while keeping the same name
- Changing types in a transformation pipeline
- Cleaning up input data

```rust
// Example: Parse user input
let input = "  42  ";
let input = input.trim();     // Still &str, trimmed
let input: i32 = input.parse().unwrap();  // Now i32
```

## 📊 Variable Scope

Variables are valid from declaration until the end of their scope:

```rust
fn main() {
    // x is not valid here
    let x = 5;          // x is valid from here

    {
        let y = 10;     // y is valid from here
        println!("{} {}", x, y);
    }                   // y goes out of scope

    // y is not valid here
    println!("{}", x);  // x is still valid
}                       // x goes out of scope
```

## 🏷️ Naming Conventions

Rust uses **snake_case** for variables and functions:

```rust
// Good
let user_name = "Alice";
let total_count = 42;
let is_active = true;

// Bad (but compiles with warning)
let userName = "Alice";   // Should be user_name
let TotalCount = 42;      // Should be total_count
```

## 💡 Best Practices

### 1. Default to Immutable

Only use `mut` when you need to modify a value:

```rust
// Prefer this
let total = calculate_total();

// Over this (if you don't need to modify)
let mut total = calculate_total();
```

### 2. Use Descriptive Names

```rust
// Good
let user_age = 25;
let is_authenticated = true;
let error_message = "Not found";

// Bad
let a = 25;
let b = true;
let s = "Not found";
```

### 3. Shadow When Appropriate

```rust
// Good - transformation pipeline
let data = fetch_data();
let data = parse(data);
let data = validate(data);

// Also good - when you no longer need the original
let input = "42";
let input: i32 = input.parse().unwrap();
```

## 🏋️ Exercises

1. Create an immutable variable and try to change it (observe the error)
2. Create a mutable variable and modify it
3. Use shadowing to transform a string to its length
4. Practice variable scoping with nested blocks

## 📂 Example Code

```rust
fn main() {
    // Immutable variable
    let age = 25;
    println!("Age: {}", age);

    // Mutable variable
    let mut counter = 0;
    counter += 1;
    counter += 1;
    println!("Counter: {}", counter);

    // Shadowing
    let value = "100";
    let value: i32 = value.parse().unwrap();
    let value = value * 2;
    println!("Value: {}", value);

    // Scope demonstration
    {
        let inner = "I'm inner";
        println!("{}", inner);
    }
    // inner is not accessible here
}
```

---

[Next: Primitive Types →](../2.PrimitiveTypes/README.md)
