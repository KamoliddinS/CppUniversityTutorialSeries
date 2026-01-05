# 📋 Vectors

## Overview

`Vec<T>` is a growable array type. Unlike arrays, vectors can change size at runtime.

## 🔤 Creating Vectors

```rust
// Empty vector
let v: Vec<i32> = Vec::new();

// With vec! macro
let v = vec![1, 2, 3];

// With capacity
let mut v = Vec::with_capacity(10);
```

## 📝 Basic Operations

```rust
let mut numbers = vec![1, 2, 3];

// Add elements
numbers.push(4);
numbers.push(5);

// Remove last element
let last = numbers.pop();  // Some(5)

// Access elements
let first = numbers[0];        // 1 (panics if out of bounds)
let second = numbers.get(1);   // Some(&2) (safe)

// Length
println!("Length: {}", numbers.len());

// Check if empty
println!("Empty: {}", numbers.is_empty());
```

## 🔧 Modifying Vectors

```rust
let mut v = vec![1, 2, 3, 4, 5];

// Insert at index
v.insert(2, 10);  // [1, 2, 10, 3, 4, 5]

// Remove at index
v.remove(2);      // [1, 2, 3, 4, 5]

// Clear all
v.clear();        // []

// Extend from another collection
let mut a = vec![1, 2];
let b = vec![3, 4];
a.extend(b);      // [1, 2, 3, 4]

// Append (moves elements)
let mut a = vec![1, 2];
let mut b = vec![3, 4];
a.append(&mut b); // a: [1, 2, 3, 4], b: []
```

## 🔄 Iterating

```rust
let numbers = vec![1, 2, 3, 4, 5];

// Immutable iteration
for n in &numbers {
    println!("{}", n);
}

// Mutable iteration
let mut numbers = vec![1, 2, 3, 4, 5];
for n in &mut numbers {
    *n *= 2;
}

// With enumerate
for (i, n) in numbers.iter().enumerate() {
    println!("[{}] = {}", i, n);
}
```

## 🎯 Common Methods

```rust
let numbers = vec![3, 1, 4, 1, 5, 9, 2, 6];

// Sorting
let mut sorted = numbers.clone();
sorted.sort();           // [1, 1, 2, 3, 4, 5, 6, 9]

// Reverse
sorted.reverse();        // [9, 6, 5, 4, 3, 2, 1, 1]

// Contains
numbers.contains(&5);    // true

// Find position
numbers.iter().position(|&x| x == 5);  // Some(4)

// Filter and collect
let evens: Vec<_> = numbers.iter().filter(|&&x| x % 2 == 0).collect();

// Map and collect
let doubled: Vec<_> = numbers.iter().map(|x| x * 2).collect();

// Sum
let sum: i32 = numbers.iter().sum();
```

## 📂 Example Code

```rust
fn main() {
    // Creating and modifying
    let mut fruits = vec!["apple", "banana"];
    fruits.push("cherry");
    fruits.insert(1, "blueberry");
    println!("Fruits: {:?}", fruits);

    // Safe access
    match fruits.get(10) {
        Some(fruit) => println!("Found: {}", fruit),
        None => println!("No fruit at that index"),
    }

    // Iterating
    for (i, fruit) in fruits.iter().enumerate() {
        println!("{}: {}", i, fruit);
    }

    // Functional style
    let numbers = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let sum_of_evens: i32 = numbers
        .iter()
        .filter(|&&x| x % 2 == 0)
        .sum();
    println!("Sum of evens: {}", sum_of_evens);
}
```

---

[Next: Strings →](../2.Strings/README.md)
