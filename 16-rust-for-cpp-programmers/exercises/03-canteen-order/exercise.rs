// Exercise 3: Canteen order
// Complete the three parts marked TODO. The tests at the bottom say what is expected.

enum Dish {
    Bread,
    Tea { sugar: u32 },         // spoons of sugar
    Plov { portions: u32 },
}

struct Order {
    dishes: Vec<Dish>,
}

// The price of one dish in so'm.
fn price(dish: &Dish) -> u32 {
    match dish {
        Dish::Bread => 4000,
        Dish::Tea { sugar } => 3000 + 500 * sugar,
        Dish::Plov { portions } => 35000 * portions,
    }
}

// The text on the bill: "bread", "tea (sugar: 2)" or "plov (portions: 3)".
fn label(dish: &Dish) -> String {
    match dish {
        Dish::Bread => String::from("bread"),
        // TODO 1: add an arm for Tea and an arm for Plov, then delete the `_` arm.
        _ => String::from("?"),
    }
}

impl Order {
    fn new() -> Order {
        Order { dishes: Vec::new() }
    }

    fn add(&mut self, dish: Dish) {
        self.dishes.push(dish);
    }

    // TODO 2: return the sum of the prices of all dishes.
    fn total(&self) -> u32 {
        0
    }

    // TODO 3: return the highest price in the order, or None when the order is empty.
    fn highest_price(&self) -> Option<u32> {
        None
    }
}

fn main() {
    let mut order = Order::new();
    order.add(Dish::Bread);
    order.add(Dish::Tea { sugar: 2 });
    order.add(Dish::Plov { portions: 3 });

    for dish in &order.dishes {
        println!("{}: {} so'm", label(dish), price(dish));
    }
    println!("total: {} so'm", order.total());
    match order.highest_price() {
        Some(price) => println!("highest price: {price} so'm"),
        None => println!("the order is empty"),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn label_of_each_dish() {
        assert_eq!(label(&Dish::Bread), "bread");
        assert_eq!(label(&Dish::Tea { sugar: 2 }), "tea (sugar: 2)");
        assert_eq!(label(&Dish::Plov { portions: 3 }), "plov (portions: 3)");
    }

    #[test]
    fn total_of_an_order() {
        let mut order = Order::new();
        assert_eq!(order.total(), 0);
        order.add(Dish::Bread);
        order.add(Dish::Tea { sugar: 2 });
        order.add(Dish::Plov { portions: 3 });
        assert_eq!(order.total(), 4000 + 4000 + 105000);
    }

    #[test]
    fn highest_price_in_an_order() {
        let mut order = Order::new();
        assert_eq!(order.highest_price(), None);
        order.add(Dish::Tea { sugar: 0 });
        order.add(Dish::Bread);
        order.add(Dish::Tea { sugar: 1 });
        assert_eq!(order.highest_price(), Some(4000));
    }
}
