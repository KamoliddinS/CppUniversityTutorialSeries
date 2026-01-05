# 📦 Defining Structs

## Overview

Structs (structures) let you create custom data types by grouping related data together. They're similar to classes in other languages.

## 🔤 Defining a Struct

```rust
struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}
```

## 📝 Creating Instances

```rust
let user = User {
    username: String::from("alice"),
    email: String::from("alice@example.com"),
    sign_in_count: 1,
    active: true,
};
```

### Field Init Shorthand

```rust
fn create_user(username: String, email: String) -> User {
    User {
        username,        // Same as username: username
        email,           // Same as email: email
        sign_in_count: 1,
        active: true,
    }
}
```

### Struct Update Syntax

```rust
let user2 = User {
    email: String::from("bob@example.com"),
    ..user  // Use remaining fields from user
};
```

## 🔧 Accessing Fields

```rust
let mut user = User {
    username: String::from("alice"),
    email: String::from("alice@example.com"),
    sign_in_count: 1,
    active: true,
};

println!("Username: {}", user.username);

user.email = String::from("new_email@example.com");
```

## 🎯 Tuple Structs

Structs without named fields:

```rust
struct Color(i32, i32, i32);
struct Point(f64, f64, f64);

let black = Color(0, 0, 0);
let origin = Point(0.0, 0.0, 0.0);

println!("R: {}, G: {}, B: {}", black.0, black.1, black.2);
```

## 📐 Unit-Like Structs

Structs without any fields:

```rust
struct AlwaysEqual;

let subject = AlwaysEqual;
```

## 🔨 Methods with impl

```rust
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    // Method - takes &self
    fn area(&self) -> u32 {
        self.width * self.height
    }

    // Method - takes &mut self
    fn double(&mut self) {
        self.width *= 2;
        self.height *= 2;
    }

    // Method with parameters
    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}

fn main() {
    let rect = Rectangle { width: 30, height: 50 };
    println!("Area: {}", rect.area());
}
```

## 🏭 Associated Functions

Functions that don't take `self`:

```rust
impl Rectangle {
    // Associated function (constructor)
    fn new(width: u32, height: u32) -> Self {
        Rectangle { width, height }
    }

    fn square(size: u32) -> Self {
        Rectangle { width: size, height: size }
    }
}

fn main() {
    let rect = Rectangle::new(30, 50);
    let square = Rectangle::square(10);
}
```

## 📊 Multiple impl Blocks

```rust
impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }
}

impl Rectangle {
    fn perimeter(&self) -> u32 {
        2 * (self.width + self.height)
    }
}
```

## 🖨️ Derived Traits

```rust
#[derive(Debug, Clone, PartialEq)]
struct Point {
    x: f64,
    y: f64,
}

fn main() {
    let p1 = Point { x: 1.0, y: 2.0 };
    let p2 = p1.clone();

    println!("{:?}", p1);       // Debug output
    println!("{}", p1 == p2);   // PartialEq comparison
}
```

### Common Derive Traits

| Trait | Purpose |
|-------|---------|
| `Debug` | Enable `{:?}` formatting |
| `Clone` | Enable `.clone()` |
| `Copy` | Enable implicit copying |
| `PartialEq` | Enable `==` comparison |
| `Default` | Enable `Default::default()` |

## 📂 Example Code

```rust
#[derive(Debug, Clone)]
struct Person {
    name: String,
    age: u32,
}

impl Person {
    fn new(name: &str, age: u32) -> Self {
        Person {
            name: name.to_string(),
            age,
        }
    }

    fn greet(&self) {
        println!("Hello, my name is {} and I'm {} years old.", self.name, self.age);
    }

    fn have_birthday(&mut self) {
        self.age += 1;
        println!("{} is now {} years old!", self.name, self.age);
    }
}

fn main() {
    let mut alice = Person::new("Alice", 30);
    alice.greet();
    alice.have_birthday();

    let bob = Person {
        name: String::from("Bob"),
        ..alice.clone()
    };
    println!("{:?}", bob);
}
```

---

[Next: Enums and Pattern Matching →](../2.Enums/README.md)
