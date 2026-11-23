// Exercise 1: Predict the output
// Do not run this program yet. Write what it prints into prediction.txt.
struct Guest {
    name: String,
}

impl Drop for Guest {
    fn drop(&mut self) {
        println!("{} leaves", self.name);
    }
}

fn greet(guest: Guest) {
    println!("Hello, {}!", guest.name);
}

fn main() {
    let aziz = Guest { name: String::from("Aziz") };
    let malika = Guest { name: String::from("Malika") };
    let count = 2;
    let copy = count;
    greet(aziz);
    let size = if copy > 1 { "group" } else { "single guest" };
    println!("{count} guests: a {size}");
    println!("{} stays", malika.name);
}
