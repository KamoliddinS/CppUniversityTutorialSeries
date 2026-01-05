# 📤 Return Values

## Overview

Functions can return values to the caller. In Rust, you specify the return type with `->` and return values either explicitly with `return` or implicitly with the last expression.

## 🔤 Basic Return Syntax

```rust
fn add(a: i32, b: i32) -> i32 {
    a + b  // No semicolon = return this value
}

fn main() {
    let sum = add(5, 3);
    println!("Sum: {}", sum);  // Sum: 8
}
```

## ⚠️ Expression vs Statement

### Expression (Returns Value)

```rust
fn five() -> i32 {
    5  // Expression - returns 5
}
```

### Statement (No Value)

```rust
fn five() -> i32 {
    5;  // Statement - returns () (unit type)
}  // Error! Expected i32, found ()
```

## 🔙 Explicit Return

Use `return` for early returns:

```rust
fn absolute(n: i32) -> i32 {
    if n < 0 {
        return -n;  // Early return
    }
    n  // Implicit return
}

fn find_first_negative(numbers: &[i32]) -> Option<i32> {
    for &n in numbers {
        if n < 0 {
            return Some(n);  // Early return
        }
    }
    None  // Return if no negative found
}
```

## 📦 Return Types

### Primitive Types

```rust
fn get_number() -> i32 { 42 }
fn get_float() -> f64 { 3.14 }
fn get_bool() -> bool { true }
fn get_char() -> char { 'R' }
```

### String Types

```rust
fn get_string() -> String {
    String::from("Hello")
}

fn get_str() -> &'static str {
    "Hello"  // String literal has 'static lifetime
}
```

### Tuples

```rust
fn min_max(numbers: &[i32]) -> (i32, i32) {
    let min = *numbers.iter().min().unwrap();
    let max = *numbers.iter().max().unwrap();
    (min, max)
}

fn main() {
    let (min, max) = min_max(&[3, 1, 4, 1, 5, 9]);
    println!("Min: {}, Max: {}", min, max);
}
```

### Option

```rust
fn divide(a: f64, b: f64) -> Option<f64> {
    if b == 0.0 {
        None
    } else {
        Some(a / b)
    }
}

fn main() {
    match divide(10.0, 2.0) {
        Some(result) => println!("Result: {}", result),
        None => println!("Cannot divide by zero"),
    }
}
```

### Result

```rust
fn parse_number(s: &str) -> Result<i32, std::num::ParseIntError> {
    s.parse()
}

fn main() {
    match parse_number("42") {
        Ok(n) => println!("Parsed: {}", n),
        Err(e) => println!("Error: {}", e),
    }
}
```

## 🚫 The Never Type `!`

Functions that never return:

```rust
fn infinite_loop() -> ! {
    loop {
        // Never returns
    }
}

fn always_panic() -> ! {
    panic!("This function always panics!");
}
```

## 📊 Returning References

Must have explicit lifetimes:

```rust
// Return reference to input
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() { x } else { y }
}

// Return reference to static data
fn get_greeting() -> &'static str {
    "Hello"
}
```

## 🎯 Functions Returning Functions

```rust
fn make_adder(n: i32) -> impl Fn(i32) -> i32 {
    move |x| x + n
}

fn main() {
    let add_five = make_adder(5);
    println!("{}", add_five(10));  // 15
}
```

## 💡 Best Practices

### Return Early for Errors

```rust
fn process_data(data: &str) -> Result<String, &str> {
    if data.is_empty() {
        return Err("Empty data");
    }

    if !data.starts_with("DATA:") {
        return Err("Invalid format");
    }

    // Main logic
    Ok(data[5..].to_string())
}
```

### Use Option/Result Instead of Sentinel Values

```rust
// Bad - sentinel value
fn find_index_bad(haystack: &[i32], needle: i32) -> i32 {
    for (i, &item) in haystack.iter().enumerate() {
        if item == needle {
            return i as i32;
        }
    }
    -1  // Magic number indicating "not found"
}

// Good - Option
fn find_index(haystack: &[i32], needle: i32) -> Option<usize> {
    for (i, &item) in haystack.iter().enumerate() {
        if item == needle {
            return Some(i);
        }
    }
    None
}
```

## 📂 Example Code

```rust
fn main() {
    // Basic return
    let sum = add(5, 3);
    println!("5 + 3 = {}", sum);

    // Tuple return
    let (min, max) = bounds(&[3, 1, 4, 1, 5, 9, 2, 6]);
    println!("Min: {}, Max: {}", min, max);

    // Option return
    if let Some(result) = safe_divide(10.0, 3.0) {
        println!("10 / 3 = {:.2}", result);
    }

    // Result return
    match parse_positive("42") {
        Ok(n) => println!("Parsed positive: {}", n),
        Err(e) => println!("Error: {}", e),
    }

    // Early return
    println!("Grade: {}", get_grade(85));
}

fn add(a: i32, b: i32) -> i32 {
    a + b
}

fn bounds(numbers: &[i32]) -> (i32, i32) {
    let mut min = numbers[0];
    let mut max = numbers[0];

    for &n in numbers {
        if n < min { min = n; }
        if n > max { max = n; }
    }

    (min, max)
}

fn safe_divide(a: f64, b: f64) -> Option<f64> {
    if b == 0.0 { None } else { Some(a / b) }
}

fn parse_positive(s: &str) -> Result<u32, String> {
    match s.parse::<i32>() {
        Ok(n) if n > 0 => Ok(n as u32),
        Ok(_) => Err("Number must be positive".to_string()),
        Err(e) => Err(e.to_string()),
    }
}

fn get_grade(score: u32) -> char {
    if score >= 90 { return 'A'; }
    if score >= 80 { return 'B'; }
    if score >= 70 { return 'C'; }
    if score >= 60 { return 'D'; }
    'F'
}
```

---

[← Previous: Parameters](../2.Parameters/README.md) | [Next: Closures →](../4.Closures/README.md)
