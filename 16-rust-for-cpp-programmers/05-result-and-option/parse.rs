use std::num::ParseIntError;        // the error type that parse::<i32>() gives

fn total(a: &str, b: &str) -> Result<i32, ParseIntError> {
    let x = a.parse::<i32>()?;      // on Err: return the error to the caller right now
    let y = b.parse::<i32>()?;
    Ok(x + y)
}

fn report(a: &str, b: &str) {
    match total(a, b) {
        Ok(sum) => println!("{a} + {b} = {sum}"),
        Err(error) => println!("{a} + {b}: {error}"),
    }
}

fn main() {
    report("40", "2");
    report("40", "two");

    let quantity = "three".parse::<i32>().unwrap_or(1);     // on Err: use 1
    println!("quantity: {quantity}");
}
