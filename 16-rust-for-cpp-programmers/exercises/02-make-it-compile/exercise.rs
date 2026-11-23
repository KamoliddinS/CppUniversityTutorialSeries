// Exercise 2: Make it compile
// This file does not compile yet. Fixing it is the exercise.
// Keep the tests at the bottom, and the parameter types of label, total and repeat_first.

// Returns the number of letters in a name.
fn letters(name: String) -> usize {
    name.chars().count()
}

// Returns a label such as "Aziz (4 letters)".
fn label(name: String) -> String {
    let count = letters(name);
    format!("{name} ({count} letters)")     // format! works like println!, but returns a String
}

// Returns the sum of all prices.
fn total(prices: &Vec<u32>) -> u32 {
    let sum = 0;
    for price in prices {
        sum += price;
    }
    sum
}

// Adds the first price once more at the end of the list, and returns it.
fn repeat_first(prices: &mut Vec<u32>) -> u32 {
    let first = &prices[0];
    prices.push(*first);
    *first
}

fn main() {
    let mut prices = vec![4000, 9000];
    println!("{}", label(String::from("Dilnoza")));
    println!("repeated: {}", repeat_first(&mut prices));
    println!("total: {}", total(&prices));
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn label_counts_the_letters() {
        assert_eq!(label(String::from("Aziz")), "Aziz (4 letters)");
    }

    #[test]
    fn total_adds_all_prices() {
        assert_eq!(total(&vec![4000, 9000, 500]), 13500);
    }

    #[test]
    fn repeat_first_adds_one_price() {
        let mut prices = vec![4000, 9000];
        assert_eq!(repeat_first(&mut prices), 4000);
        assert_eq!(prices, vec![4000, 9000, 4000]);
    }
}
