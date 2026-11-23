struct Student {
    name: String,
    score: u32,
}

fn main() {
    let group = vec![
        Student { name: String::from("Aziz"), score: 72 },
        Student { name: String::from("Malika"), score: 95 },
        Student { name: String::from("Jasur"), score: 58 },
    ];
    let pass = 60;

    let passed = group.iter().filter(|s| s.score >= pass).count();
    let total: u32 = group.iter().map(|s| s.score).sum();
    let names: Vec<&String> = group
        .iter()
        .filter(|s| s.score >= pass)
        .map(|s| &s.name)
        .collect();
    println!("{passed} passed, total {total}, names {names:?}");   // {:?} prints a Vec

    let doubled = group.iter().map(|s| {
        println!("  doubling {}", s.score);
        s.score * 2
    });
    println!("nothing has run yet");
    let sum: u32 = doubled.sum();       // now the closure runs, once for each student
    println!("sum = {sum}");
}
