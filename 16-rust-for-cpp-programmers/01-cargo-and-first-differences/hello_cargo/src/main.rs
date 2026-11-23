// fn name(parameter: type) -> return type.  f64 is double, i32 is a 32-bit int.
fn delivery_fee(distance_km: f64) -> i32 {
    if distance_km > 10.0 { 15000 } else { 8000 }   // `if` gives a value: no `return`, no `;`
}

fn main() {
    let shop = "Chorsu";                // cannot be changed
    let mut items = 0;                  // `mut`: can be changed
    for day in 1..=3 {                  // 1, 2, 3
        items += day;                   // there is no `++`
    }

    let size = match items {            // every possible value must be covered
        0 => "empty",
        1..=5 => "small",
        _ => "large",                   // `_` means: everything else
    };

    let weight_kg = items as f64 * 1.5; // i32 to f64: you must write the conversion
    println!("{shop}: {items} items, a {size} order, {weight_kg} kg");
    println!("Delivery: {} so'm", delivery_fee(12.0));
}
