fn shout(word: &str) -> &str {
    let loud = word.to_uppercase();     // a new String, owned by this function
    &loud
}                                       // loud is dropped here

fn main() {
    println!("{}", shout("plov"));
}
