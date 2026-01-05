# 🎭 Enums and Pattern Matching

## Overview

Enums (enumerations) allow you to define a type by enumerating its possible variants. Rust enums are much more powerful than enums in most languages because variants can hold data.

## 🔤 Basic Enums

```rust
enum Direction {
    North,
    South,
    East,
    West,
}

let dir = Direction::North;
```

## 📦 Enums with Data

```rust
enum Message {
    Quit,                       // No data
    Move { x: i32, y: i32 },   // Named fields (like struct)
    Write(String),              // Single value (like tuple struct)
    ChangeColor(i32, i32, i32), // Multiple values
}

let msg1 = Message::Quit;
let msg2 = Message::Move { x: 10, y: 20 };
let msg3 = Message::Write(String::from("hello"));
let msg4 = Message::ChangeColor(255, 128, 0);
```

## 🎯 Pattern Matching with match

```rust
fn process_message(msg: Message) {
    match msg {
        Message::Quit => {
            println!("Quitting...");
        }
        Message::Move { x, y } => {
            println!("Moving to ({}, {})", x, y);
        }
        Message::Write(text) => {
            println!("Writing: {}", text);
        }
        Message::ChangeColor(r, g, b) => {
            println!("Changing color to RGB({}, {}, {})", r, g, b);
        }
    }
}
```

## 🌟 The Option Enum

Rust doesn't have null. Instead, it uses `Option<T>`:

```rust
enum Option<T> {
    Some(T),
    None,
}
```

### Using Option

```rust
fn divide(a: f64, b: f64) -> Option<f64> {
    if b == 0.0 {
        None
    } else {
        Some(a / b)
    }
}

fn main() {
    let result = divide(10.0, 2.0);

    match result {
        Some(value) => println!("Result: {}", value),
        None => println!("Cannot divide by zero!"),
    }
}
```

### Option Methods

```rust
let some_number: Option<i32> = Some(5);
let no_number: Option<i32> = None;

// unwrap - panics if None
let value = some_number.unwrap();

// unwrap_or - default if None
let value = no_number.unwrap_or(0);

// map - transform the value if Some
let doubled = some_number.map(|x| x * 2);

// is_some / is_none
if some_number.is_some() {
    println!("Has value!");
}

// if let
if let Some(n) = some_number {
    println!("Number: {}", n);
}
```

## ⚡ The Result Enum

For operations that can fail:

```rust
enum Result<T, E> {
    Ok(T),
    Err(E),
}
```

### Using Result

```rust
use std::fs::File;

fn main() {
    let file_result = File::open("hello.txt");

    let file = match file_result {
        Ok(f) => f,
        Err(e) => {
            println!("Error opening file: {}", e);
            return;
        }
    };
}
```

## 🔧 Methods on Enums

```rust
enum Status {
    Active,
    Inactive,
    Pending,
}

impl Status {
    fn is_active(&self) -> bool {
        matches!(self, Status::Active)
    }

    fn description(&self) -> &str {
        match self {
            Status::Active => "Currently active",
            Status::Inactive => "Not active",
            Status::Pending => "Awaiting activation",
        }
    }
}
```

## 🎨 Pattern Matching Features

### Multiple Patterns

```rust
match number {
    1 | 2 | 3 => println!("One, two, or three"),
    4..=10 => println!("Four through ten"),
    _ => println!("Something else"),
}
```

### Destructuring

```rust
let point = (3, 5);

match point {
    (0, 0) => println!("Origin"),
    (x, 0) => println!("On x-axis at {}", x),
    (0, y) => println!("On y-axis at {}", y),
    (x, y) => println!("At ({}, {})", x, y),
}
```

### Guards

```rust
let num = Some(4);

match num {
    Some(x) if x < 5 => println!("Less than five: {}", x),
    Some(x) => println!("Greater or equal: {}", x),
    None => println!("No value"),
}
```

## 📂 Example Code

```rust
#[derive(Debug)]
enum Shape {
    Circle { radius: f64 },
    Rectangle { width: f64, height: f64 },
    Triangle { base: f64, height: f64 },
}

impl Shape {
    fn area(&self) -> f64 {
        match self {
            Shape::Circle { radius } => std::f64::consts::PI * radius * radius,
            Shape::Rectangle { width, height } => width * height,
            Shape::Triangle { base, height } => 0.5 * base * height,
        }
    }

    fn name(&self) -> &str {
        match self {
            Shape::Circle { .. } => "Circle",
            Shape::Rectangle { .. } => "Rectangle",
            Shape::Triangle { .. } => "Triangle",
        }
    }
}

fn main() {
    let shapes = vec![
        Shape::Circle { radius: 5.0 },
        Shape::Rectangle { width: 10.0, height: 20.0 },
        Shape::Triangle { base: 6.0, height: 8.0 },
    ];

    for shape in &shapes {
        println!("{}: area = {:.2}", shape.name(), shape.area());
    }

    // Option example
    let numbers = vec![1, 2, 3];
    let first = numbers.first();

    if let Some(&n) = first {
        println!("First number: {}", n);
    }

    // Result example
    let parse_result: Result<i32, _> = "42".parse();
    match parse_result {
        Ok(n) => println!("Parsed: {}", n),
        Err(e) => println!("Parse error: {}", e),
    }
}
```

---

[← Previous: Defining Structs](../1.Structs/README.md) | [Next Lesson: Error Handling →](../../7.ErrorHandling/README.md)
