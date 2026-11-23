trait Shape {                           // only says what a shape can do
    fn name(&self) -> &str;
    fn area(&self) -> f64;
}

struct Circle {
    radius: f64,
}

struct Square {
    side: f64,
}

impl Shape for Circle {
    fn name(&self) -> &str {
        "circle"
    }
    fn area(&self) -> f64 {
        std::f64::consts::PI * self.radius * self.radius
    }
}

impl Shape for Square {
    fn name(&self) -> &str {
        "square"
    }
    fn area(&self) -> f64 {
        self.side * self.side
    }
}

fn print_area(shape: &dyn Shape) {      // accepts any type that implements Shape
    println!("{}: {:.2}", shape.name(), shape.area());
}

fn main() {
    let shapes: Vec<Box<dyn Shape>> = vec![
        Box::new(Circle { radius: 1.0 }),
        Box::new(Square { side: 2.5 }),
    ];
    for shape in &shapes {
        print_area(shape.as_ref());     // as_ref: borrow the shape inside the Box
    }
}
