struct Book {
    title: String,
    pages: u32,
}

fn larger<T: PartialOrd>(a: T, b: T) -> T {
    if a > b { a } else { b }
}

fn main() {
    let atlas = Book { title: String::from("Atlas"), pages: 120 };
    let novel = Book { title: String::from("Novel"), pages: 400 };
    println!("{}", larger(atlas, novel).title);
}
