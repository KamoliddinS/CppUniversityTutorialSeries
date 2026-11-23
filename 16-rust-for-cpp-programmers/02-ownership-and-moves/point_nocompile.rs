struct Point {                  // two integers, but not marked Copy
    x: i32,
    y: i32,
}

fn main() {
    let p = Point { x: 3, y: 4 };
    let q = p;                  // so this is a move
    println!("p.x = {}, q.y = {}", p.x, q.y);
}
