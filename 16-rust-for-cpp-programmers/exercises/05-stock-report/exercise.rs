// Exercise 5: Stock report
// Write the six bodies marked todo!(). The tests at the bottom say what is expected.

#[derive(Debug, PartialEq)]     // lets the tests print and compare values
struct Item {
    name: String,
    price: u32,                 // price of one piece in so'm
    count: u32,                 // pieces in stock
}

#[derive(Debug, PartialEq)]
enum LineError {
    WrongWordCount,             // the line does not have exactly three words
    BadNumber(String),          // this word should be a number, but it is not
}

trait Describe {
    fn describe(&self) -> String;
}

// 1. An item is described like this: "bread: 12 x 4000 so'm".
impl Describe for Item {
    fn describe(&self) -> String {
        todo!()
    }
}

// 2. Reads one whole number such as "4000".
//    On failure the error is LineError::BadNumber with the text inside.
fn number(text: &str) -> Result<u32, LineError> {
    todo!()
}

// 3. Reads a line such as "bread 4000 12": name, price, count.
//    Use `number` and `?` for the two numbers.
fn parse_item(line: &str) -> Result<Item, LineError> {
    let words: Vec<&str> = line.split_whitespace().collect();
    todo!()
}

// 4. The descriptions of all things, in the same order. Works for every type that
//    implements Describe.
fn describe_all<T: Describe>(things: &[T]) -> Vec<String> {
    todo!()
}

// 5. The value of the whole stock: the sum of price * count.
fn stock_value(items: &[Item]) -> u32 {
    todo!()
}

// 6. The item with the highest price, or None when there are no items.
fn most_expensive(items: &[Item]) -> Option<&Item> {
    todo!()
}

fn main() {
    let mut items = Vec::new();
    for line in ["bread 4000 12", "tea 3000 many", "plov 35000 4"] {
        match parse_item(line) {
            Ok(item) => items.push(item),
            Err(error) => println!("skipped \"{line}\": {error:?}"),
        }
    }
    for text in describe_all(&items) {
        println!("{text}");
    }
    println!("stock value: {} so'm", stock_value(&items));
    match most_expensive(&items) {
        Some(item) => println!("most expensive: {}", item.name),
        None => println!("no items"),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn item(name: &str, price: u32, count: u32) -> Item {
        Item { name: String::from(name), price, count }
    }

    #[test]
    fn describe_an_item() {
        assert_eq!(item("bread", 4000, 12).describe(), "bread: 12 x 4000 so'm");
    }

    #[test]
    fn number_reads_or_reports() {
        assert_eq!(number("4000"), Ok(4000));
        assert_eq!(number("many"), Err(LineError::BadNumber(String::from("many"))));
    }

    #[test]
    fn parse_item_reads_a_line() {
        assert_eq!(parse_item("bread 4000 12"), Ok(item("bread", 4000, 12)));
        assert_eq!(parse_item("  plov   35000 4 "), Ok(item("plov", 35000, 4)));
    }

    #[test]
    fn parse_item_reports_errors() {
        assert_eq!(parse_item("bread 4000"), Err(LineError::WrongWordCount));
        assert_eq!(parse_item("bread 4000 12 fresh"), Err(LineError::WrongWordCount));
        assert_eq!(parse_item("tea 3000 many"), Err(LineError::BadNumber(String::from("many"))));
        assert_eq!(parse_item("tea cheap many"), Err(LineError::BadNumber(String::from("cheap"))));
    }

    #[test]
    fn describe_all_keeps_the_order() {
        let items = [item("tea", 3000, 2), item("plov", 35000, 4)];
        assert_eq!(describe_all(&items), ["tea: 2 x 3000 so'm", "plov: 4 x 35000 so'm"]);
    }

    #[test]
    fn stock_value_adds_everything() {
        let items = [item("bread", 4000, 12), item("plov", 35000, 4)];
        assert_eq!(stock_value(&items), 188000);
        assert_eq!(stock_value(&[]), 0);
    }

    #[test]
    fn most_expensive_item() {
        let items = [item("bread", 4000, 12), item("plov", 35000, 4), item("tea", 3000, 2)];
        assert_eq!(most_expensive(&items), Some(&items[1]));
        assert_eq!(most_expensive(&[]), None);
    }
}
