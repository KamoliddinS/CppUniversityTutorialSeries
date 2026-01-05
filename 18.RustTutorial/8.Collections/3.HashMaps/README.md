# 🗂️ HashMaps

## Overview

`HashMap<K, V>` stores key-value pairs with O(1) average lookup time. Keys must implement `Eq` and `Hash` traits.

## 🔤 Creating HashMaps

```rust
use std::collections::HashMap;

// Empty HashMap
let mut map: HashMap<String, i32> = HashMap::new();

// With capacity
let map: HashMap<&str, i32> = HashMap::with_capacity(10);

// From iterators
let teams = vec![("Blue", 10), ("Red", 20)];
let scores: HashMap<_, _> = teams.into_iter().collect();
```

## 📝 Basic Operations

```rust
use std::collections::HashMap;

let mut scores = HashMap::new();

// Insert
scores.insert("Alice", 100);
scores.insert("Bob", 85);

// Access
let alice_score = scores.get("Alice");  // Some(&100)

// Update
scores.insert("Alice", 105);  // Overwrites

// Remove
scores.remove("Bob");

// Check if key exists
if scores.contains_key("Alice") {
    println!("Alice has a score");
}
```

## 🔧 Entry API

```rust
use std::collections::HashMap;

let mut scores = HashMap::new();

// Insert if not present
scores.entry("Alice").or_insert(100);
scores.entry("Alice").or_insert(200);  // Won't change (already exists)

// Insert with default
scores.entry("Bob").or_default();  // Inserts 0 for i32

// Modify existing
let count = scores.entry("Alice").or_insert(0);
*count += 1;
```

## 🔄 Iterating

```rust
use std::collections::HashMap;

let scores = HashMap::from([
    ("Alice", 100),
    ("Bob", 85),
    ("Charlie", 90),
]);

// Iterate over key-value pairs
for (name, score) in &scores {
    println!("{}: {}", name, score);
}

// Iterate over keys
for name in scores.keys() {
    println!("Player: {}", name);
}

// Iterate over values
for score in scores.values() {
    println!("Score: {}", score);
}

// Mutable iteration
let mut scores = scores;
for score in scores.values_mut() {
    *score += 10;  // Add bonus
}
```

## 🎯 Common Patterns

### Word Counter

```rust
use std::collections::HashMap;

let text = "hello world hello rust hello world";
let mut word_count = HashMap::new();

for word in text.split_whitespace() {
    let count = word_count.entry(word).or_insert(0);
    *count += 1;
}

println!("{:?}", word_count);
// {"hello": 3, "world": 2, "rust": 1}
```

### Grouping

```rust
use std::collections::HashMap;

let numbers = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
let mut grouped: HashMap<&str, Vec<i32>> = HashMap::new();

for n in numbers {
    let key = if n % 2 == 0 { "even" } else { "odd" };
    grouped.entry(key).or_insert(Vec::new()).push(n);
}
```

## 📂 Example Code

```rust
use std::collections::HashMap;

fn main() {
    // Basic usage
    let mut inventory = HashMap::new();
    inventory.insert("apples", 50);
    inventory.insert("oranges", 30);
    inventory.insert("bananas", 40);

    // Access with get
    if let Some(count) = inventory.get("apples") {
        println!("Apples in stock: {}", count);
    }

    // Entry API
    inventory.entry("apples").and_modify(|e| *e -= 5);
    inventory.entry("grapes").or_insert(25);

    // Iteration
    println!("\nInventory:");
    for (item, count) in &inventory {
        println!("  {}: {}", item, count);
    }

    // Word frequency counter
    let text = "the quick brown fox jumps over the lazy dog";
    let freq = word_frequency(text);
    println!("\nWord frequency:");
    for (word, count) in &freq {
        println!("  {}: {}", word, count);
    }
}

fn word_frequency(text: &str) -> HashMap<&str, usize> {
    let mut freq = HashMap::new();
    for word in text.split_whitespace() {
        *freq.entry(word).or_insert(0) += 1;
    }
    freq
}
```

---

[← Previous: Strings](../2.Strings/README.md) | [Next Lesson: Traits and Generics →](../../9.TraitsGenerics/README.md)
