// Exercise 5: Count the owners
// Do not run this program yet. Write what it prints into prediction.txt.
#include <iostream>
#include <memory>
#include <string>

struct Book {
    std::string title;
    explicit Book(const std::string& bookTitle) : title(bookTitle) {}
    ~Book() { std::cout << title << " is destroyed\n"; }
};

void look(const std::shared_ptr<Book>& book) {
    std::cout << "A " << book.use_count() << '\n';
}

void borrow(std::shared_ptr<Book> book) {
    std::cout << "B " << book.use_count() << '\n';
}

int main() {
    auto aziz = std::make_shared<Book>("Algebra");
    auto malika = aziz;
    std::weak_ptr<Book> shelf = aziz;
    std::cout << "C " << aziz.use_count() << '\n';

    look(aziz);
    borrow(aziz);
    std::cout << "D " << aziz.use_count() << '\n';

    aziz.reset();
    std::cout << "E " << malika.use_count() << '\n';
    malika.reset();
    if (shelf.lock() == nullptr) {
        std::cout << "F the book is gone\n";
    }
    std::cout << "end of main\n";
}
