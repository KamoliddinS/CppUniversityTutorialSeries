//! # Comments and Documentation Example
//!
//! This module demonstrates various comment styles in Rust.
//! This is an inner documentation comment (note the `!`).

// Regular single-line comment - compiler ignores this

/*
 * Multi-line block comment
 * Can span multiple lines
 * Useful for longer explanations
 */

/// A simple structure representing a point in 2D space.
///
/// # Examples
///
/// ```
/// let origin = Point::new(0.0, 0.0);
/// let point = Point::new(3.0, 4.0);
/// let distance = origin.distance_to(&point);
/// assert_eq!(distance, 5.0);
/// ```
pub struct Point {
    /// The x-coordinate of the point
    pub x: f64,
    /// The y-coordinate of the point
    pub y: f64,
}

impl Point {
    /// Creates a new Point with the given coordinates.
    ///
    /// # Arguments
    ///
    /// * `x` - The x-coordinate
    /// * `y` - The y-coordinate
    ///
    /// # Returns
    ///
    /// A new `Point` instance
    pub fn new(x: f64, y: f64) -> Self {
        Point { x, y }
    }

    /// Calculates the Euclidean distance to another point.
    ///
    /// # Arguments
    ///
    /// * `other` - The other point to measure distance to
    ///
    /// # Examples
    ///
    /// ```
    /// let p1 = Point::new(0.0, 0.0);
    /// let p2 = Point::new(3.0, 4.0);
    /// assert_eq!(p1.distance_to(&p2), 5.0);
    /// ```
    pub fn distance_to(&self, other: &Point) -> f64 {
        let dx = self.x - other.x;
        let dy = self.y - other.y;
        (dx * dx + dy * dy).sqrt()
    }
}

/// Calculates the factorial of a number.
///
/// # Arguments
///
/// * `n` - A non-negative integer
///
/// # Returns
///
/// The factorial of n (n!)
///
/// # Panics
///
/// Panics if n > 20 due to integer overflow
///
/// # Examples
///
/// ```
/// assert_eq!(factorial(0), 1);
/// assert_eq!(factorial(5), 120);
/// ```
pub fn factorial(n: u64) -> u64 {
    // Base case: 0! = 1! = 1
    match n {
        0 | 1 => 1,
        // Recursive case: n! = n * (n-1)!
        _ => n * factorial(n - 1),
    }
}

fn main() {
    // Create some points
    let origin = Point::new(0.0, 0.0);
    let point = Point::new(3.0, 4.0); // A 3-4-5 right triangle

    // Calculate distance using Pythagorean theorem
    // Distance = sqrt((x2-x1)^2 + (y2-y1)^2)
    let distance = origin.distance_to(&point);

    println!("Distance from origin to ({}, {}): {}", point.x, point.y, distance);

    /*
     * Demonstrate factorial function
     * This block comment explains the following code section
     */
    for n in 0..=10 {
        println!("{}! = {}", n, factorial(n));
    }
}
