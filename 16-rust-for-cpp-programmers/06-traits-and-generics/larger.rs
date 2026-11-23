fn larger<T: PartialOrd>(a: T, b: T) -> T {
    if a > b { a } else { b }
}

fn main() {
    println!("{}", larger(3, 7));
    println!("{}", larger(2.5, 1.5));
    println!("{}", larger("Samarkand", "Tashkent"));
}
