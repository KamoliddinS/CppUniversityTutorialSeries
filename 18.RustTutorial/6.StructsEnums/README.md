# 🏗️ Lesson 6: Structs and Enums

Welcome to Lesson 6! In this lesson, you'll learn how to create custom data types using structs and enums.

## 📚 Table of Contents

1. [Defining Structs](./1.Structs/README.md)
2. [Enums and Pattern Matching](./2.Enums/README.md)

## 🎯 Learning Objectives

By the end of this lesson, you will be able to:

- Define and instantiate structs
- Add methods to structs using impl blocks
- Define and use enums
- Use pattern matching with enums

## 🔍 Quick Overview

### Structs

```rust
struct User {
    username: String,
    email: String,
    active: bool,
}

impl User {
    fn new(username: String, email: String) -> Self {
        User { username, email, active: true }
    }

    fn deactivate(&mut self) {
        self.active = false;
    }
}
```

### Enums

```rust
enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(i32, i32, i32),
}

fn process(msg: Message) {
    match msg {
        Message::Quit => println!("Quit"),
        Message::Move { x, y } => println!("Move to ({}, {})", x, y),
        Message::Write(text) => println!("Write: {}", text),
        Message::ChangeColor(r, g, b) => println!("Color: RGB({},{},{})", r, g, b),
    }
}
```

## 📖 Lesson Topics

### [1. Defining Structs](./1.Structs/README.md)
Learn how to create custom data types with structs.

### [2. Enums and Pattern Matching](./2.Enums/README.md)
Master enums and their powerful pattern matching capabilities.

---

[← Previous Lesson: Ownership and Borrowing](../5.OwnershipBorrowing/README.md) | [Next Lesson: Error Handling →](../7.ErrorHandling/README.md)
