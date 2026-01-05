# ⏳ Lesson 10: Lifetimes

Welcome to Lesson 10! Lifetimes ensure that references are always valid. They're part of what makes Rust memory-safe without garbage collection.

## 🎯 Learning Objectives

By the end of this lesson, you will be able to:

- Understand what lifetimes are and why they matter
- Use lifetime annotations in functions and structs
- Apply lifetime elision rules
- Work with the `'static` lifetime

## 🔍 What Are Lifetimes?

Every reference in Rust has a lifetime - the scope for which the reference is valid. Usually lifetimes are implicit and inferred, but sometimes we need to annotate them.

## ❓ The Problem Lifetimes Solve

```rust
// This won't compile - dangling reference
fn main() {
    let r;
    {
        let x = 5;
        r = &x;
    } // x dropped here
    println!("{}", r); // Error! r references dropped value
}
```

## 📝 Lifetime Annotations

Lifetime annotations describe the relationships between the lifetimes of multiple references:

```rust
// 'a is a lifetime parameter
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}
```

### Reading Lifetime Annotations

- `'a` is a lifetime name (like a generic type parameter)
- `&'a str` means "a string slice that lives at least as long as `'a`"
- The return type `&'a str` will live at least as long as the shorter of the two input lifetimes

## 🔧 Lifetime Rules

### In Function Signatures

```rust
// Both parameters and return have same lifetime
fn first_word<'a>(s: &'a str) -> &'a str {
    // ...
}

// Different lifetimes
fn mix<'a, 'b>(x: &'a str, y: &'b str) -> &'a str {
    x  // Only returns from 'a, so only 'a needed in return
}

// Multiple references with same lifetime
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() { x } else { y }
}
```

### In Structs

```rust
// Struct holding a reference needs lifetime
struct Excerpt<'a> {
    part: &'a str,
}

impl<'a> Excerpt<'a> {
    fn level(&self) -> i32 {
        3
    }

    fn announce(&self, announcement: &str) -> &str {
        println!("Attention: {}", announcement);
        self.part
    }
}
```

## ✨ Lifetime Elision

The compiler can infer lifetimes in common cases:

```rust
// These are equivalent:
fn first_word(s: &str) -> &str { /* ... */ }
fn first_word<'a>(s: &'a str) -> &'a str { /* ... */ }
```

### Elision Rules

1. Each reference parameter gets its own lifetime
2. If there's exactly one input lifetime, it's assigned to all output lifetimes
3. If there's a `&self` or `&mut self`, its lifetime is assigned to all output lifetimes

## 🌟 The 'static Lifetime

The `'static` lifetime means the reference lives for the entire program:

```rust
// String literals have 'static lifetime
let s: &'static str = "Hello, world!";

// Owned types can be stored as 'static
static GREETING: &str = "Hello";
```

### When to Use 'static

```rust
// Error messages often use 'static
fn error_message() -> &'static str {
    "Something went wrong"
}

// Thread spawning requires 'static
use std::thread;

fn spawn_thread() {
    let data = String::from("hello");
    thread::spawn(move || {
        println!("{}", data);  // data is moved, becomes 'static
    });
}
```

## 📊 Combining Generics, Traits, and Lifetimes

```rust
use std::fmt::Display;

fn longest_with_announcement<'a, T>(
    x: &'a str,
    y: &'a str,
    ann: T,
) -> &'a str
where
    T: Display,
{
    println!("Announcement: {}", ann);
    if x.len() > y.len() { x } else { y }
}
```

## 📂 Example Code

```rust
// Function with lifetime annotations
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

// Struct with lifetime
struct ImportantExcerpt<'a> {
    part: &'a str,
}

impl<'a> ImportantExcerpt<'a> {
    fn excerpt(&self) -> &str {
        self.part
    }

    fn announce_and_return(&self, announcement: &str) -> &str {
        println!("Attention: {}", announcement);
        self.part
    }
}

fn main() {
    // Using longest function
    let string1 = String::from("long string is long");
    let result;
    {
        let string2 = String::from("xyz");
        result = longest(string1.as_str(), string2.as_str());
        println!("Longest: {}", result);
    }

    // Using struct with lifetime
    let novel = String::from("Call me Ishmael. Some years ago...");
    let first_sentence = novel.split('.').next().unwrap();
    let excerpt = ImportantExcerpt {
        part: first_sentence,
    };
    println!("Excerpt: {}", excerpt.excerpt());

    // Static lifetime
    let static_str: &'static str = "I live forever!";
    println!("{}", static_str);
}
```

## 💡 Best Practices

1. **Let elision work** - Don't add lifetimes unless the compiler asks
2. **Keep structs simple** - Avoid storing references when you can own data
3. **Use 'static carefully** - It's powerful but can be restrictive
4. **Trust the compiler** - Lifetime errors prevent real bugs

---

[← Previous Lesson: Traits and Generics](../9.TraitsGenerics/README.md) | [Back to Main →](../README.md)
