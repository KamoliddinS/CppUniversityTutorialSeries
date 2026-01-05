# 🎯 Pattern Matching

## Overview

Pattern matching is one of Rust's most powerful features. The `match` expression allows you to compare a value against patterns and execute code based on which pattern matches.

## 🔍 Basic Match

```rust
let number = 7;

match number {
    1 => println!("One"),
    2 => println!("Two"),
    3 => println!("Three"),
    _ => println!("Something else"),
}
```

### Match is Exhaustive

You must handle all possible values:

```rust
let boolean = true;

// ✅ All cases covered
match boolean {
    true => println!("True"),
    false => println!("False"),
}

// The wildcard _ matches anything not covered
match number {
    1 => println!("One"),
    _ => println!("Not one"),  // Catches everything else
}
```

## 📊 Match as an Expression

```rust
let number = 3;

let description = match number {
    1 => "one",
    2 => "two",
    3 => "three",
    _ => "many",
};

println!("The number is {}", description);
```

## 🎨 Pattern Types

### Literal Patterns

```rust
let x = 1;

match x {
    1 => println!("One"),
    2 => println!("Two"),
    _ => println!("Other"),
}
```

### Multiple Patterns with `|`

```rust
let x = 2;

match x {
    1 | 2 => println!("One or Two"),
    3 | 4 | 5 => println!("Three, Four, or Five"),
    _ => println!("Other"),
}
```

### Range Patterns

```rust
let x = 5;

match x {
    1..=5 => println!("One through Five"),
    6..=10 => println!("Six through Ten"),
    _ => println!("Out of range"),
}

// Works with chars too
let c = 'g';

match c {
    'a'..='f' => println!("Early alphabet"),
    'g'..='z' => println!("Late alphabet"),
    _ => println!("Not a lowercase letter"),
}
```

### Destructuring Tuples

```rust
let point = (3, 5);

match point {
    (0, 0) => println!("Origin"),
    (x, 0) => println!("On x-axis at {}", x),
    (0, y) => println!("On y-axis at {}", y),
    (x, y) => println!("At ({}, {})", x, y),
}
```

### Destructuring Structs

```rust
struct Point {
    x: i32,
    y: i32,
}

let p = Point { x: 0, y: 7 };

match p {
    Point { x: 0, y } => println!("On y-axis at {}", y),
    Point { x, y: 0 } => println!("On x-axis at {}", x),
    Point { x, y } => println!("At ({}, {})", x, y),
}
```

### Destructuring Enums

```rust
enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(i32, i32, i32),
}

let msg = Message::Move { x: 10, y: 20 };

match msg {
    Message::Quit => println!("Quit"),
    Message::Move { x, y } => println!("Move to ({}, {})", x, y),
    Message::Write(text) => println!("Write: {}", text),
    Message::ChangeColor(r, g, b) => println!("Color: RGB({}, {}, {})", r, g, b),
}
```

## 🛡️ Match Guards

Add extra conditions with `if`:

```rust
let num = Some(4);

match num {
    Some(x) if x < 5 => println!("Less than five: {}", x),
    Some(x) => println!("Greater or equal to five: {}", x),
    None => println!("No value"),
}
```

```rust
let pair = (2, -2);

match pair {
    (x, y) if x == y => println!("Equal"),
    (x, y) if x + y == 0 => println!("Opposite"),
    (x, _) if x % 2 == 0 => println!("First is even"),
    _ => println!("No match"),
}
```

## 📌 The `@` Binding

Bind a value while also testing it:

```rust
let num = 5;

match num {
    n @ 1..=5 => println!("Got {} in range 1-5", n),
    n @ 6..=10 => println!("Got {} in range 6-10", n),
    n => println!("Got {} out of range", n),
}

// With enums
enum Message {
    Hello { id: i32 },
}

let msg = Message::Hello { id: 5 };

match msg {
    Message::Hello { id: id_variable @ 3..=7 } => {
        println!("Found id in range: {}", id_variable)
    }
    Message::Hello { id } => println!("Found other id: {}", id),
}
```

## 🔄 Ignoring Values

### Underscore `_`

```rust
let numbers = (1, 2, 3, 4, 5);

match numbers {
    (first, _, third, _, fifth) => {
        println!("First: {}, Third: {}, Fifth: {}", first, third, fifth);
    }
}
```

### Double Dot `..`

```rust
let numbers = (1, 2, 3, 4, 5);

match numbers {
    (first, .., last) => {
        println!("First: {}, Last: {}", first, last);
    }
}

struct Point3D { x: i32, y: i32, z: i32 }

let point = Point3D { x: 1, y: 2, z: 3 };

match point {
    Point3D { x, .. } => println!("x is {}", x),
}
```

## 🎯 Common Match Patterns

### Option

```rust
let maybe_number: Option<i32> = Some(42);

match maybe_number {
    Some(n) => println!("Number: {}", n),
    None => println!("No number"),
}
```

### Result

```rust
let result: Result<i32, &str> = Ok(42);

match result {
    Ok(value) => println!("Success: {}", value),
    Err(error) => println!("Error: {}", error),
}
```

### References

```rust
let reference = &4;

match reference {
    &val => println!("Got value: {}", val),
}

// Or dereference first
match *reference {
    val => println!("Got value: {}", val),
}
```

## 💡 Best Practices

### Be Specific First

```rust
// Good - specific cases first
match value {
    0 => println!("Zero"),
    1 => println!("One"),
    _ => println!("Other"),
}

// Avoid - catch-all too early
match value {
    _ => println!("Anything"),  // This matches everything!
    0 => println!("Zero"),      // Never reached
}
```

### Use Match for Complex Logic

```rust
// Good - clear intent
let description = match (has_access, is_admin) {
    (true, true) => "Admin with access",
    (true, false) => "User with access",
    (false, true) => "Admin without access",
    (false, false) => "No access",
};
```

## 📂 Example Code

```rust
fn main() {
    // Basic match
    let day = 3;
    let day_name = match day {
        1 => "Monday",
        2 => "Tuesday",
        3 => "Wednesday",
        4 => "Thursday",
        5 => "Friday",
        6 | 7 => "Weekend",
        _ => "Invalid day",
    };
    println!("Day: {}", day_name);

    // Match with ranges
    let score = 85;
    let grade = match score {
        90..=100 => 'A',
        80..=89 => 'B',
        70..=79 => 'C',
        60..=69 => 'D',
        _ => 'F',
    };
    println!("Score {} = Grade {}", score, grade);

    // Destructuring
    let point = (0, 5);
    match point {
        (0, 0) => println!("Origin"),
        (0, y) => println!("On Y axis at {}", y),
        (x, 0) => println!("On X axis at {}", x),
        (x, y) => println!("Point at ({}, {})", x, y),
    }

    // Match guards
    let num = Some(4);
    match num {
        Some(x) if x < 5 => println!("{} is less than 5", x),
        Some(x) => println!("{} is 5 or more", x),
        None => println!("No value"),
    }

    // @ bindings
    let age = 25;
    match age {
        n @ 0..=12 => println!("Child aged {}", n),
        n @ 13..=19 => println!("Teenager aged {}", n),
        n @ 20..=64 => println!("Adult aged {}", n),
        n => println!("Senior aged {}", n),
    }
}
```

---

[← Previous: Loops](../2.Loops/README.md) | [Next Lesson: Functions →](../../4.Functions/README.md)
