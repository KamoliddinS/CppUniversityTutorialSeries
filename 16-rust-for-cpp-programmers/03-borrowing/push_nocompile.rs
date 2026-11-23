fn main() {
    let mut scores = vec![70, 85, 90];
    let first = &scores[0];     // a & borrow into the vector
    scores.push(60);            // push needs a &mut borrow
    println!("{first}");
}
