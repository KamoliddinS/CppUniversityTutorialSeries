// Compiler Errors Examples
// This file demonstrates CORRECT code that avoids common errors
// See the README for examples of what NOT to do

fn main() {
    // Example 1: Correct type usage
    // Wrong: let x: i32 = "hello";
    // Right:
    let x: i32 = 42;
    let greeting: &str = "hello";
    println!("x = {}, greeting = {}", x, greeting);

    // Example 2: Correct ownership handling
    // Wrong: use after move
    // Right: clone or borrow
    let s1 = String::from("hello");
    let s2 = s1.clone(); // Clone to avoid move
    println!("s1 = {}, s2 = {}", s1, s2);

    // Or use borrowing
    let s3 = String::from("world");
    let s4 = &s3; // Borrow, don't move
    println!("s3 = {}, s4 = {}", s3, s4);

    // Example 3: Correct borrowing
    // Wrong: mutable and immutable borrow at same time
    // Right: don't overlap borrows
    let mut numbers = vec![1, 2, 3];

    // First, use immutable borrow
    let first = numbers[0]; // Copy the value
    println!("First number: {}", first);

    // Then, do mutable operations
    numbers.push(4);
    println!("After push: {:?}", numbers);

    // Example 4: Correct lifetime handling
    // Wrong: reference outlives data
    // Right: ensure data lives long enough
    let outer_value = 10;
    let reference = &outer_value;
    println!("Reference points to: {}", reference);
    // reference is still valid here because outer_value is still in scope

    // Example 5: Variables must be declared before use
    // Wrong: println!("{}", undeclared);
    // Right:
    let declared = "I exist!";
    println!("{}", declared);

    // Example 6: Unused variables - prefix with _
    let _intentionally_unused = 42;

    // Example 7: Correct module paths
    use std::collections::HashMap;
    let mut map = HashMap::new();
    map.insert("key", "value");
    println!("Map contains: {:?}", map);

    demonstrate_common_fixes();
}

/// Demonstrates common error fixes
fn demonstrate_common_fixes() {
    println!("\n--- Common Error Fixes ---");

    // Fix for "cannot move out of borrowed content"
    // Use references and cloning appropriately
    let items = vec![String::from("a"), String::from("b"), String::from("c")];

    // Wrong: for item in items { ... } then use items again
    // Right: iterate by reference
    for item in &items {
        println!("Item: {}", item);
    }
    println!("Items still available: {:?}", items);

    // Fix for "expected X, found Y"
    // Ensure function return types match
    let result = safe_divide(10.0, 2.0);
    match result {
        Some(value) => println!("10 / 2 = {}", value),
        None => println!("Division error!"),
    }

    // Fix for "pattern does not cover"
    // Always handle all enum variants
    let maybe_number: Option<i32> = Some(42);
    match maybe_number {
        Some(n) => println!("Got number: {}", n),
        None => println!("Got nothing"),
    }
}

/// Safe division that returns None for division by zero
fn safe_divide(a: f64, b: f64) -> Option<f64> {
    if b == 0.0 {
        None
    } else {
        Some(a / b)
    }
}

// This function demonstrates allowing dead code
#[allow(dead_code)]
fn unused_but_allowed() {
    // This function is intentionally unused
    // The #[allow(dead_code)] attribute suppresses the warning
}
