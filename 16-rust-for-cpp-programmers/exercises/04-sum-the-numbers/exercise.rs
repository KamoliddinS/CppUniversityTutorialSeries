// Exercise 4: Sum the numbers
// Write the bodies of the three functions. The tests at the bottom say what is expected.
// todo!() marks code that is not written yet: it compiles, and it panics when it runs.
use std::num::ParseIntError;

// The sum of all words, read as whole numbers.
// If a word is not a number: the error of the first such word.
fn sum_all(words: &[&str]) -> Result<i32, ParseIntError> {
    todo!()
}

// The sum of the words that are numbers. Other words are skipped.
fn sum_valid(words: &[&str]) -> i32 {
    todo!()
}

// The position of the first word that is not a number (0 is the first word),
// or None when every word is a number.
fn first_bad(words: &[&str]) -> Option<usize> {
    todo!()
}

fn main() {
    let words = ["12", "x", "30", "7.5"];
    println!("sum of the numbers: {}", sum_valid(&words));
    println!("first bad word: {:?}", first_bad(&words));
    match sum_all(&words) {
        Ok(sum) => println!("sum of all: {sum}"),
        Err(error) => println!("no sum of all: {error}"),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn sum_all_adds_every_word() {
        assert_eq!(sum_all(&["12", "30", "-2"]), Ok(40));
        assert_eq!(sum_all(&[]), Ok(0));
    }

    #[test]
    fn sum_all_returns_the_first_error() {
        assert!(sum_all(&["12", "x", "30"]).is_err());
        // "" and "x" give different errors: the one of "" must come back.
        assert_eq!(sum_all(&["1", "", "x"]), "".parse::<i32>());
    }

    #[test]
    fn sum_valid_skips_bad_words() {
        assert_eq!(sum_valid(&["12", "x", "30", "7.5"]), 42);
        assert_eq!(sum_valid(&["x", "y"]), 0);
    }

    #[test]
    fn first_bad_finds_the_position() {
        assert_eq!(first_bad(&["12", "30", "x", "y"]), Some(2));
        assert_eq!(first_bad(&["x"]), Some(0));
        assert_eq!(first_bad(&["12", "30"]), None);
    }
}
