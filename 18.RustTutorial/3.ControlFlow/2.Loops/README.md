# 🔄 Loops

## Overview

Rust has three kinds of loops: `loop`, `while`, and `for`. Each has its use case, and understanding when to use which will make your code cleaner and more efficient.

## 🔁 The `loop` Keyword

An infinite loop that runs until explicitly stopped:

```rust
loop {
    println!("Forever!");
    break;  // Exit the loop
}
```

### Returning Values from Loop

```rust
let mut counter = 0;

let result = loop {
    counter += 1;
    if counter == 10 {
        break counter * 2;  // Returns 20
    }
};

println!("Result: {}", result);  // 20
```

### Loop Labels

Use labels for nested loops:

```rust
'outer: loop {
    println!("Outer loop");

    'inner: loop {
        println!("Inner loop");
        break 'outer;  // Breaks the outer loop
    }
}
```

```rust
let mut count = 0;

'counting: loop {
    let mut remaining = 10;

    loop {
        if remaining == 0 {
            break;  // Breaks inner loop
        }
        if count == 5 {
            break 'counting;  // Breaks outer loop
        }
        remaining -= 1;
        count += 1;
    }
}

println!("Count: {}", count);
```

## ⏳ While Loops

Loop while a condition is true:

```rust
let mut number = 3;

while number != 0 {
    println!("{}!", number);
    number -= 1;
}

println!("LIFTOFF!");
```

### While Let

Similar to `if let`, but loops:

```rust
let mut stack = vec![1, 2, 3, 4, 5];

while let Some(top) = stack.pop() {
    println!("Popped: {}", top);
}
```

## 🔢 For Loops

The most common loop, used to iterate over collections:

### Range Iteration

```rust
// 0 to 4 (exclusive)
for i in 0..5 {
    println!("{}", i);
}

// 1 to 5 (inclusive)
for i in 1..=5 {
    println!("{}", i);
}

// Reverse
for i in (1..5).rev() {
    println!("{}", i);  // 4, 3, 2, 1
}
```

### Iterating Over Collections

```rust
let array = [10, 20, 30, 40, 50];

// By reference (doesn't move)
for element in &array {
    println!("{}", element);
}

// By mutable reference
let mut numbers = vec![1, 2, 3];
for num in &mut numbers {
    *num *= 2;
}

// By value (moves ownership)
for element in array {
    println!("{}", element);
}
// array is no longer accessible
```

### With Index

```rust
let fruits = ["apple", "banana", "cherry"];

for (index, fruit) in fruits.iter().enumerate() {
    println!("{}: {}", index, fruit);
}
```

### Iterating Over Strings

```rust
let text = "hello";

// Characters
for c in text.chars() {
    println!("{}", c);
}

// Bytes
for b in text.bytes() {
    println!("{}", b);
}
```

## 🎯 Continue and Break

### Continue

Skip to the next iteration:

```rust
for i in 0..10 {
    if i % 2 == 0 {
        continue;  // Skip even numbers
    }
    println!("{}", i);  // Only prints odd: 1, 3, 5, 7, 9
}
```

### Break

Exit the loop early:

```rust
for i in 0..100 {
    if i > 5 {
        break;  // Exit when i > 5
    }
    println!("{}", i);  // Prints 0, 1, 2, 3, 4, 5
}
```

### With Labels

```rust
'outer: for i in 0..3 {
    for j in 0..3 {
        if i == 1 && j == 1 {
            continue 'outer;  // Skip to next outer iteration
        }
        println!("({}, {})", i, j);
    }
}
```

## 📊 Comparison of Loop Types

| Loop | Use Case | Returns Value | Condition |
|------|----------|---------------|-----------|
| `loop` | Infinite loops, retry logic | Yes | None (explicit break) |
| `while` | Unknown iterations | No | Boolean |
| `for` | Known iterations, collections | No | Iterator |

## 💡 Best Practices

### Use `for` When Possible

```rust
// Good - idiomatic Rust
for i in 0..5 {
    println!("{}", i);
}

// Avoid - C-style loop
let mut i = 0;
while i < 5 {
    println!("{}", i);
    i += 1;
}
```

### Prefer Iterators Over Indexing

```rust
let items = vec![1, 2, 3, 4, 5];

// Good - iterator
for item in &items {
    println!("{}", item);
}

// Avoid - indexing
for i in 0..items.len() {
    println!("{}", items[i]);
}
```

### Use `loop` for Retry Logic

```rust
let result = loop {
    match try_operation() {
        Ok(value) => break value,
        Err(_) => {
            println!("Retrying...");
            continue;
        }
    }
};
```

## 📂 Example Code

```rust
fn main() {
    // Loop with break value
    let mut count = 0;
    let result = loop {
        count += 1;
        if count == 10 {
            break count * 2;
        }
    };
    println!("Loop result: {}", result);

    // While loop
    let mut number = 5;
    while number > 0 {
        println!("Countdown: {}", number);
        number -= 1;
    }
    println!("Blastoff!");

    // For loop with range
    println!("\nFor loop:");
    for i in 1..=5 {
        println!("  {}", i);
    }

    // For loop with collection
    let animals = ["cat", "dog", "bird"];
    println!("\nAnimals:");
    for animal in &animals {
        println!("  {}", animal);
    }

    // Enumerate
    println!("\nWith index:");
    for (i, animal) in animals.iter().enumerate() {
        println!("  {}: {}", i, animal);
    }

    // Nested loops with labels
    println!("\nMultiplication table (partial):");
    'outer: for i in 1..=10 {
        for j in 1..=10 {
            if i * j > 25 {
                println!("  Stopping at {} x {}", i, j);
                break 'outer;
            }
            print!("{:4}", i * j);
        }
        println!();
    }

    // While let
    let mut optional = Some(0);
    println!("\nWhile let:");
    while let Some(i) = optional {
        if i > 3 {
            optional = None;
        } else {
            println!("  i = {}", i);
            optional = Some(i + 1);
        }
    }
}
```

---

[← Previous: If Expressions](../1.IfExpressions/README.md) | [Next: Pattern Matching →](../3.PatternMatching/README.md)
