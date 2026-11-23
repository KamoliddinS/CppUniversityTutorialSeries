#[derive(Clone, Copy)]          // marks Point as Copy; without this line a Point moves
struct Point {
    x: i32,
    y: i32,
}

fn main() {
    let a = String::from("Samarkand");
    let b = a.clone();          // a copy, because you asked for one
    let c = a;                  // move: c owns the text now, a is gone
    println!("b = {b}, c = {c}");

    let n = 5;
    let m = n;                  // i32 is Copy: n stays usable
    let p = Point { x: 3, y: 4 };
    let q = p;                  // Point is Copy too
    println!("n = {n}, m = {m}, p.x = {}, q.y = {}", p.x, q.y);
}
