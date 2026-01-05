# 🎭 Traits

## Overview

Traits define shared behavior. They're similar to interfaces in other languages but more powerful. Traits enable polymorphism in Rust.

## 🔤 Defining Traits

```rust
trait Summary {
    fn summarize(&self) -> String;
}
```

### With Default Implementation

```rust
trait Summary {
    fn summarize(&self) -> String {
        String::from("(Read more...)")
    }

    fn author(&self) -> String;  // Required

    // Default using another method
    fn full_summary(&self) -> String {
        format!("By {}: {}", self.author(), self.summarize())
    }
}
```

## 📝 Implementing Traits

```rust
trait Summary {
    fn summarize(&self) -> String;
}

struct Article {
    title: String,
    author: String,
    content: String,
}

impl Summary for Article {
    fn summarize(&self) -> String {
        format!("{}, by {}", self.title, self.author)
    }
}

struct Tweet {
    username: String,
    content: String,
}

impl Summary for Tweet {
    fn summarize(&self) -> String {
        format!("@{}: {}", self.username, self.content)
    }
}
```

## 🎯 Trait Bounds

```rust
// Using trait bound syntax
fn notify<T: Summary>(item: &T) {
    println!("Breaking news! {}", item.summarize());
}

// Using impl Trait syntax (simpler)
fn notify(item: &impl Summary) {
    println!("Breaking news! {}", item.summarize());
}

// Multiple trait bounds
fn process<T: Summary + Clone>(item: &T) {
    // Can use both Summary and Clone methods
}

// Using where clause (cleaner for complex bounds)
fn complex<T, U>(t: &T, u: &U) -> i32
where
    T: Summary + Clone,
    U: Clone + Debug,
{
    // ...
}
```

## 📤 Returning Traits

```rust
// Return type implements trait
fn create_summary() -> impl Summary {
    Article {
        title: String::from("News"),
        author: String::from("Reporter"),
        content: String::from("Something happened..."),
    }
}
```

## 🎪 Trait Objects

For dynamic dispatch (runtime polymorphism):

```rust
// Trait object using dyn
fn print_summaries(items: &[&dyn Summary]) {
    for item in items {
        println!("{}", item.summarize());
    }
}

// Box for ownership
fn get_items() -> Vec<Box<dyn Summary>> {
    vec![
        Box::new(Article { /* ... */ }),
        Box::new(Tweet { /* ... */ }),
    ]
}
```

## 📊 Common Standard Library Traits

| Trait | Purpose | Methods |
|-------|---------|---------|
| `Clone` | Deep copy | `.clone()` |
| `Copy` | Implicit copy | (marker trait) |
| `Debug` | Debug formatting | `{:?}` |
| `Display` | User formatting | `{}` |
| `Default` | Default value | `::default()` |
| `PartialEq` | Equality | `==`, `!=` |
| `PartialOrd` | Ordering | `<`, `>`, `<=`, `>=` |
| `Iterator` | Iteration | `.next()` |

## 🔧 Deriving Traits

```rust
#[derive(Debug, Clone, PartialEq)]
struct Point {
    x: i32,
    y: i32,
}
```

## 📂 Example Code

```rust
use std::fmt::{Display, Formatter, Result};

// Define trait
trait Drawable {
    fn draw(&self);
    fn area(&self) -> f64;
}

// Implement for Circle
struct Circle {
    radius: f64,
}

impl Drawable for Circle {
    fn draw(&self) {
        println!("Drawing circle with radius {}", self.radius);
    }

    fn area(&self) -> f64 {
        std::f64::consts::PI * self.radius * self.radius
    }
}

// Implement for Rectangle
struct Rectangle {
    width: f64,
    height: f64,
}

impl Drawable for Rectangle {
    fn draw(&self) {
        println!("Drawing rectangle {}x{}", self.width, self.height);
    }

    fn area(&self) -> f64 {
        self.width * self.height
    }
}

// Generic function with trait bound
fn print_area<T: Drawable>(shape: &T) {
    println!("Area: {:.2}", shape.area());
}

// Trait objects for heterogeneous collection
fn draw_all(shapes: &[&dyn Drawable]) {
    for shape in shapes {
        shape.draw();
    }
}

fn main() {
    let circle = Circle { radius: 5.0 };
    let rect = Rectangle { width: 10.0, height: 5.0 };

    print_area(&circle);
    print_area(&rect);

    let shapes: Vec<&dyn Drawable> = vec![&circle, &rect];
    draw_all(&shapes);
}
```

---

[← Previous: Generics](../1.Generics/README.md) | [Next Lesson: Lifetimes →](../../10.Lifetimes/README.md)
