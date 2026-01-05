# 📥 Parameters and Arguments

## Overview

Parameters allow you to pass data into functions. In Rust, you must always specify the type of each parameter.

## 🔤 Basic Parameters

```rust
fn greet(name: &str) {
    println!("Hello, {}!", name);
}

fn main() {
    greet("Alice");
    greet("Bob");
}
```

## 📊 Multiple Parameters

```rust
fn describe_person(name: &str, age: u32, city: &str) {
    println!("{} is {} years old and lives in {}", name, age, city);
}

fn main() {
    describe_person("Alice", 30, "New York");
}
```

## 🔢 Parameter Types

### Primitive Types

```rust
fn add(a: i32, b: i32) {
    println!("{} + {} = {}", a, b, a + b);
}

fn is_positive(n: f64) -> bool {
    n > 0.0
}
```

### References

```rust
// Immutable reference
fn print_length(s: &String) {
    println!("Length: {}", s.len());
}

// Mutable reference
fn append_exclamation(s: &mut String) {
    s.push('!');
}

fn main() {
    let mut text = String::from("Hello");
    print_length(&text);       // Pass reference
    append_exclamation(&mut text);  // Pass mutable reference
    println!("{}", text);      // Hello!
}
```

### Slices

```rust
fn print_slice(slice: &[i32]) {
    for item in slice {
        println!("{}", item);
    }
}

fn main() {
    let array = [1, 2, 3, 4, 5];
    print_slice(&array);        // Entire array
    print_slice(&array[1..4]);  // Slice [2, 3, 4]
}
```

### Ownership Transfer

```rust
fn take_ownership(s: String) {
    println!("Got: {}", s);
}  // s is dropped here

fn main() {
    let text = String::from("Hello");
    take_ownership(text);
    // println!("{}", text);  // Error! text was moved
}
```

## 🎯 By Value vs By Reference

| Method | Syntax | Ownership | Can Modify |
|--------|--------|-----------|------------|
| By Value | `fn f(x: T)` | Takes | N/A (owns it) |
| By Reference | `fn f(x: &T)` | Borrows | No |
| By Mut Ref | `fn f(x: &mut T)` | Borrows | Yes |

```rust
// By value - takes ownership
fn consume(s: String) {
    println!("{}", s);
}

// By reference - borrows
fn borrow(s: &String) {
    println!("{}", s);
}

// By mutable reference - borrows and can modify
fn modify(s: &mut String) {
    s.push_str(" World");
}
```

## 📦 Struct Parameters

```rust
struct Point {
    x: f64,
    y: f64,
}

// Take ownership
fn print_point(p: Point) {
    println!("({}, {})", p.x, p.y);
}

// Borrow
fn point_distance(p: &Point) -> f64 {
    (p.x * p.x + p.y * p.y).sqrt()
}

// Borrow mutably
fn move_point(p: &mut Point, dx: f64, dy: f64) {
    p.x += dx;
    p.y += dy;
}
```

## 🔄 Generic Parameters

```rust
fn print_anything<T: std::fmt::Display>(item: T) {
    println!("{}", item);
}

fn swap<T>(a: &mut T, b: &mut T) {
    std::mem::swap(a, b);
}

fn main() {
    print_anything(42);
    print_anything("Hello");
    print_anything(3.14);

    let mut x = 5;
    let mut y = 10;
    swap(&mut x, &mut y);
    println!("x={}, y={}", x, y);  // x=10, y=5
}
```

## 🎭 Default Values (Using Option)

Rust doesn't have default parameter values, but you can use Option:

```rust
fn greet(name: Option<&str>) {
    let name = name.unwrap_or("World");
    println!("Hello, {}!", name);
}

fn main() {
    greet(Some("Alice"));  // Hello, Alice!
    greet(None);           // Hello, World!
}
```

### Builder Pattern Alternative

```rust
struct Config {
    name: String,
    age: Option<u32>,
    active: bool,
}

impl Config {
    fn new(name: &str) -> Self {
        Config {
            name: name.to_string(),
            age: None,
            active: true,
        }
    }

    fn age(mut self, age: u32) -> Self {
        self.age = Some(age);
        self
    }

    fn active(mut self, active: bool) -> Self {
        self.active = active;
        self
    }
}

fn main() {
    let config = Config::new("Alice")
        .age(30)
        .active(false);
}
```

## 📂 Example Code

```rust
fn main() {
    // Basic parameters
    greet("World");

    // Multiple parameters
    add(5, 3);

    // References
    let mut text = String::from("Hello");
    print_length(&text);
    append_suffix(&mut text, "!");
    println!("Modified: {}", text);

    // Slices
    let numbers = [1, 2, 3, 4, 5];
    print_sum(&numbers);

    // Generic
    print_twice(42);
    print_twice("Hello");
}

fn greet(name: &str) {
    println!("Hello, {}!", name);
}

fn add(a: i32, b: i32) {
    println!("{} + {} = {}", a, b, a + b);
}

fn print_length(s: &String) {
    println!("Length: {}", s.len());
}

fn append_suffix(s: &mut String, suffix: &str) {
    s.push_str(suffix);
}

fn print_sum(numbers: &[i32]) {
    let sum: i32 = numbers.iter().sum();
    println!("Sum: {}", sum);
}

fn print_twice<T: std::fmt::Display>(item: T) {
    println!("{} {}", item, item);
}
```

---

[← Previous: Defining Functions](../1.DefiningFunctions/README.md) | [Next: Return Values →](../3.ReturnValues/README.md)
