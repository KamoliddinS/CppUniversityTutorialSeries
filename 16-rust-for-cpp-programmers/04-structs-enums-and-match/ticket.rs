enum Ticket {
    Metro,
    Bus,
    Train { km: u32 },                  // this variant carries a number
}

fn price(ticket: Ticket) -> u32 {
    match ticket {
        Ticket::Metro => 3000,
        Ticket::Bus => 2000,
        Ticket::Train { km } => 400 * km,   // km comes out of the variant
    }
}

fn discount(code: &str) -> Option<u32> {    // a percentage, or nothing
    match code {
        "STUDENT" => Some(50),
        "NAVRUZ" => Some(20),
        _ => None,
    }
}

fn main() {
    for ticket in [Ticket::Metro, Ticket::Bus, Ticket::Train { km: 300 }] {
        println!("{} so'm", price(ticket));
    }
    for code in ["STUDENT", "HELLO"] {
        match discount(code) {
            Some(percent) => println!("{code}: {percent}% off"),
            None => println!("{code}: no such code"),
        }
    }
}
