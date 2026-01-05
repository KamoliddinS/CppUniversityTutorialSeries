# 📐 Generic Types

## Overview

Generics allow you to write code that works with multiple types while still being type-safe. They're resolved at compile time with zero runtime cost.

## 🔤 Generic Functions

```rust
fn largest<T: PartialOrd>(list: &[T]) -> &T {
    let mut largest = &list[0];
    for item in list {
        if item > largest {
            largest = item;
        }
    }
    largest
}

fn main() {
    let numbers = vec![34, 50, 25, 100, 65];
    println!("Largest: {}", largest(&numbers));

    let chars = vec!['y', 'm', 'a', 'q'];
    println!("Largest: {}", largest(&chars));
}
```

## 📦 Generic Structs

```rust
struct Point<T> {
    x: T,
    y: T,
}

// Multiple type parameters
struct Pair<T, U> {
    first: T,
    second: U,
}

fn main() {
    let int_point = Point { x: 5, y: 10 };
    let float_point = Point { x: 1.0, y: 4.0 };
    let pair = Pair { first: 5, second: "hello" };
}
```

## 🔧 Methods on Generic Types

```rust
struct Point<T> {
    x: T,
    y: T,
}

impl<T> Point<T> {
    fn new(x: T, y: T) -> Self {
        Point { x, y }
    }

    fn x(&self) -> &T {
        &self.x
    }
}

// Specific implementation for f64
impl Point<f64> {
    fn distance_from_origin(&self) -> f64 {
        (self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}
```

## 🎭 Generic Enums

```rust
// Option and Result are generic enums
enum Option<T> {
    Some(T),
    None,
}

enum Result<T, E> {
    Ok(T),
    Err(E),
}

// Custom generic enum
enum Container<T> {
    Empty,
    Single(T),
    Multiple(Vec<T>),
}
```

## 📊 Multiple Type Parameters

```rust
struct Converter<I, O> {
    input: I,
    output: O,
}

impl<I, O> Converter<I, O> {
    fn new(input: I, output: O) -> Self {
        Converter { input, output }
    }
}

// Mixed generic and concrete
impl<T> Point<T> {
    fn mix<U>(self, other: Point<U>) -> Point<T> {
        Point {
            x: self.x,
            y: other.y,  // Error! Types don't match
        }
    }
}
```

## 📂 Example Code

```rust
// Generic stack implementation
struct Stack<T> {
    items: Vec<T>,
}

impl<T> Stack<T> {
    fn new() -> Self {
        Stack { items: Vec::new() }
    }

    fn push(&mut self, item: T) {
        self.items.push(item);
    }

    fn pop(&mut self) -> Option<T> {
        self.items.pop()
    }

    fn is_empty(&self) -> bool {
        self.items.is_empty()
    }

    fn len(&self) -> usize {
        self.items.len()
    }
}

fn main() {
    let mut int_stack = Stack::new();
    int_stack.push(1);
    int_stack.push(2);
    int_stack.push(3);

    while let Some(value) = int_stack.pop() {
        println!("Popped: {}", value);
    }

    let mut string_stack = Stack::new();
    string_stack.push(String::from("hello"));
    string_stack.push(String::from("world"));

    println!("String stack size: {}", string_stack.len());
}
```

---

[Next: Traits →](../2.Traits/README.md)
