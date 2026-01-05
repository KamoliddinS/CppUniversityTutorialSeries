# 📝 Defining Functions

## Overview

Functions are the building blocks of Rust programs. They allow you to organize code into reusable pieces.

## 🔤 Basic Syntax

```rust
fn function_name() {
    // function body
}
```

### Simple Function

```rust
fn say_hello() {
    println!("Hello, World!");
}

fn main() {
    say_hello();  // Call the function
}
```

## 📛 Naming Conventions

Rust uses **snake_case** for function names:

```rust
// Good - snake_case
fn calculate_area() {}
fn get_user_name() {}
fn is_valid_input() {}

// Bad - other styles
fn calculateArea() {}   // CamelCase - wrong
fn GetUserName() {}     // PascalCase - wrong
fn IsValidInput() {}    // Wrong
```

## 📍 Function Location

Functions can be defined anywhere in the file:

```rust
fn main() {
    first();   // Can call functions defined below
    second();
}

fn first() {
    println!("First");
}

fn second() {
    println!("Second");
}
```

Unlike C/C++, Rust doesn't need forward declarations.

## 🔗 Calling Functions

```rust
fn greet() {
    println!("Hello!");
}

fn main() {
    // Call multiple times
    greet();
    greet();
    greet();

    // Functions can call other functions
    do_work();
}

fn do_work() {
    greet();  // Call greet from do_work
    println!("Working...");
}
```

## 📦 Functions in Modules

```rust
mod math {
    pub fn add(a: i32, b: i32) -> i32 {
        a + b
    }

    pub fn subtract(a: i32, b: i32) -> i32 {
        a - b
    }
}

fn main() {
    let sum = math::add(5, 3);
    let diff = math::subtract(10, 4);
    println!("Sum: {}, Diff: {}", sum, diff);
}
```

## 🏷️ Function Visibility

| Keyword | Visibility |
|---------|------------|
| (none) | Private to module |
| `pub` | Public |
| `pub(crate)` | Public within crate |
| `pub(super)` | Public to parent module |

```rust
mod my_module {
    // Private - only accessible within this module
    fn private_function() {}

    // Public - accessible from anywhere
    pub fn public_function() {}

    // Public within the crate
    pub(crate) fn crate_function() {}
}
```

## 🎯 Associated Functions

Functions associated with a type:

```rust
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    // Associated function (no self)
    fn new(width: u32, height: u32) -> Rectangle {
        Rectangle { width, height }
    }

    // Method (has self)
    fn area(&self) -> u32 {
        self.width * self.height
    }
}

fn main() {
    let rect = Rectangle::new(10, 20);  // Associated function
    println!("Area: {}", rect.area());   // Method
}
```

## 📂 Example Code

```rust
// Simple function
fn greet() {
    println!("Hello, Rustacean!");
}

// Function calling another function
fn do_twice(f: fn()) {
    f();
    f();
}

// Main function
fn main() {
    // Call simple function
    greet();

    // Call function multiple times
    do_twice(greet);

    // Inline function definition (closure)
    let say_bye = || println!("Goodbye!");
    say_bye();
}

// Module with functions
mod utilities {
    pub fn print_separator() {
        println!("--------------------");
    }

    pub fn print_header(title: &str) {
        print_separator();
        println!("{}", title);
        print_separator();
    }
}
```

---

[Next: Parameters and Arguments →](../2.Parameters/README.md)
