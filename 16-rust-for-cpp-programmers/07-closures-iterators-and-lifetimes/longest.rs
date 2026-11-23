fn longest<'a>(a: &'a str, b: &'a str) -> &'a str {
    if a.len() >= b.len() { a } else { b }
}

fn first_word(text: &str) -> &str {     // one reference comes in: no annotation needed
    text.split(' ').next().unwrap_or("")
}

fn main() {
    println!("{}", longest("Samarkand", "Khiva"));
    println!("{}", first_word("Registan Square"));
}
