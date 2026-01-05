// Hello World in Rust
// This is your first Rust program!

fn main() {
    // Basic Hello World
    println!("Hello, World!");

    // Using variables
    let name = "Rustacean";
    println!("Hello, {}!", name);

    // Multiple placeholders
    let language = "Rust";
    let year = 2015;
    println!("{} was released in {}", language, year);

    // Named placeholders
    println!(
        "{language} is {adjective}!",
        language = "Rust",
        adjective = "awesome"
    );

    // Debug printing
    let numbers = [1, 2, 3, 4, 5];
    println!("Debug: {:?}", numbers);
    println!("Pretty debug: {:#?}", numbers);

    // Print without newline
    print!("This is on ");
    print!("the same line");
    println!(); // Now add a newline

    // Formatting numbers
    let pi = 3.14159265;
    println!("Pi is approximately {:.2}", pi); // 2 decimal places
    println!("Pi with padding: {:>10.2}", pi); // Right-aligned, width 10

    // Binary, Hex, Octal
    let num = 255;
    println!("Decimal: {}", num);
    println!("Binary: {:b}", num);
    println!("Hexadecimal: {:x}", num);
    println!("Octal: {:o}", num);
}
