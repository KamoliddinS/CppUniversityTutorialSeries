# ❓ If Expressions

## Overview

In Rust, `if` is an **expression**, not just a statement. This means it can return a value, making it more powerful than in many other languages.

## 🔤 Basic If Statement

```rust
let number = 7;

if number > 5 {
    println!("Greater than 5");
}
```

### With Else

```rust
let number = 3;

if number > 5 {
    println!("Greater than 5");
} else {
    println!("5 or less");
}
```

### With Else If

```rust
let number = 6;

if number % 4 == 0 {
    println!("Divisible by 4");
} else if number % 3 == 0 {
    println!("Divisible by 3");
} else if number % 2 == 0 {
    println!("Divisible by 2");
} else {
    println!("Not divisible by 4, 3, or 2");
}
```

## ⚠️ Conditions Must Be Boolean

Unlike some languages, Rust doesn't implicitly convert values to boolean:

```rust
let number = 3;

// ❌ Error: expected `bool`, found integer
if number {
    println!("Non-zero");
}

// ✅ Correct: explicit comparison
if number != 0 {
    println!("Non-zero");
}
```

## 📊 If as an Expression

Since `if` is an expression, it returns a value:

```rust
let condition = true;
let number = if condition { 5 } else { 6 };

println!("Number: {}", number);  // Prints: 5
```

### Rules for If Expressions

Both branches must return the same type:

```rust
// ✅ Both branches return i32
let value = if true { 5 } else { 10 };

// ❌ Error: different types
let value = if true { 5 } else { "six" };

// ✅ Both branches return &str
let value = if true { "five" } else { "six" };
```

### Using If Expressions

```rust
fn abs(x: i32) -> i32 {
    if x >= 0 { x } else { -x }
}

fn max(a: i32, b: i32) -> i32 {
    if a > b { a } else { b }
}

fn grade(score: u32) -> &'static str {
    if score >= 90 {
        "A"
    } else if score >= 80 {
        "B"
    } else if score >= 70 {
        "C"
    } else if score >= 60 {
        "D"
    } else {
        "F"
    }
}
```

## 🔗 Nested If Expressions

```rust
let a = 5;
let b = 10;
let c = 15;

let largest = if a > b {
    if a > c { a } else { c }
} else {
    if b > c { b } else { c }
};

println!("Largest: {}", largest);
```

## 🎯 If Let

A shorthand for matching a single pattern:

```rust
let optional = Some(7);

// Using match
match optional {
    Some(value) => println!("Got: {}", value),
    None => (),
}

// Using if let - more concise
if let Some(value) = optional {
    println!("Got: {}", value);
}

// With else
if let Some(value) = optional {
    println!("Got: {}", value);
} else {
    println!("Got nothing");
}
```

### If Let with Enums

```rust
enum Color {
    Red,
    Green,
    Blue,
    Rgb(u8, u8, u8),
}

let color = Color::Rgb(255, 128, 0);

if let Color::Rgb(r, g, b) = color {
    println!("RGB: {}, {}, {}", r, g, b);
}
```

## 📊 Comparison: If vs Match

| Feature | If | Match |
|---------|-----|-------|
| **Condition Type** | Boolean | Pattern |
| **Exhaustiveness** | Not required | Required |
| **Multiple Patterns** | Use else if | Natural |
| **Use Case** | Boolean conditions | Pattern matching |

## 💡 Best Practices

### Keep Conditions Simple

```rust
// Good
let is_valid = user.age >= 18 && user.has_consent;
if is_valid {
    process(user);
}

// Avoid deeply nested conditions
// Bad
if user.age >= 18 {
    if user.has_consent {
        if user.is_verified {
            process(user);
        }
    }
}

// Better
if user.age >= 18 && user.has_consent && user.is_verified {
    process(user);
}
```

### Use If Let for Option/Result

```rust
// Good - if you only care about Some
if let Some(value) = some_option {
    use_value(value);
}

// Use match when you need both cases
match some_option {
    Some(value) => use_value(value),
    None => handle_none(),
}
```

## 📂 Example Code

```rust
fn main() {
    // Basic if/else
    let temperature = 25;

    if temperature > 30 {
        println!("It's hot!");
    } else if temperature > 20 {
        println!("It's nice!");
    } else if temperature > 10 {
        println!("It's cool.");
    } else {
        println!("It's cold!");
    }

    // If as expression
    let weather = if temperature > 20 { "warm" } else { "cold" };
    println!("The weather is {}", weather);

    // If let
    let maybe_number: Option<i32> = Some(42);

    if let Some(num) = maybe_number {
        println!("Found number: {}", num);
    }

    // Chained if let
    let result: Result<i32, &str> = Ok(100);

    if let Ok(value) = result {
        println!("Success: {}", value);
    } else {
        println!("Error occurred");
    }

    // Complex condition
    let age = 25;
    let has_license = true;

    if age >= 16 && has_license {
        println!("Can drive");
    }
}
```

---

[Next: Loops →](../2.Loops/README.md)
