enum Ticket {
    Metro,
    Bus,
    Train { km: u32 },
}

fn price(ticket: Ticket) -> u32 {
    match ticket {
        Ticket::Metro => 3000,
        Ticket::Train { km } => 400 * km,
    }
}

fn main() {
    println!("{} so'm", price(Ticket::Bus));
}
