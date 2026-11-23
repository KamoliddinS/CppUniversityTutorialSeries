struct Account {
    owner: String,
    balance: i32,
}

impl Account {
    fn new(owner: &str) -> Account {            // no `self`: called as Account::new(...)
        Account { owner: String::from(owner), balance: 0 }
    }

    fn deposit(&mut self, amount: i32) {        // &mut self: may change the object
        self.balance += amount;
    }

    fn balance(&self) -> i32 {                  // &self: may only read it
        self.balance
    }
}

fn main() {
    let mut account = Account::new("Malika");
    account.deposit(50000);
    account.deposit(25000);
    println!("{} has {} so'm", account.owner, account.balance());
}
