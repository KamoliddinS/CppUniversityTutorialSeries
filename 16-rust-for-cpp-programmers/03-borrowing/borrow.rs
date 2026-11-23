fn total(prices: &Vec<i32>) -> i32 {        // a & borrow: may only read
    let mut sum = 0;
    for price in prices {
        sum += price;
    }
    sum
}

fn add_delivery(prices: &mut Vec<i32>) {    // a &mut borrow: may change
    prices.push(15000);
}

fn main() {
    let mut prices = vec![12000, 8000];     // a Vec<i32>, Rust's std::vector<int>
    add_delivery(&mut prices);              // the call shows that prices may change
    println!("total: {}", total(&prices));
    println!("prices: {}", prices.len());   // main is still the owner
}
