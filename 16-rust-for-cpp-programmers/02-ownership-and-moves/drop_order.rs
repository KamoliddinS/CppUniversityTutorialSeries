struct Door {
    name: String,
}

impl Drop for Door {
    fn drop(&mut self) {                // Rust's destructor
        println!("closing the {}", self.name);
    }
}

fn lock(door: Door) {                   // a parameter by value takes ownership
    println!("locking the {}", door.name);
}                                       // door is dropped here

fn main() {
    let front = Door { name: String::from("front door") };
    let back = Door { name: String::from("back door") };
    lock(front);                        // front moves into the function
    println!("the {} is still open", back.name);
}                                       // back is dropped here; front is not dropped again
