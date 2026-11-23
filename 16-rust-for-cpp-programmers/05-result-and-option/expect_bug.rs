fn main() {
    let text = "4o";            // a typing mistake: the letter o, not zero
    let price = text.parse::<i32>().expect("the price must be a number");
    println!("{price} so'm");
}
