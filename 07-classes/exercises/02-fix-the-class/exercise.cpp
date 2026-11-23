// Exercise 2: Fix the class
// This file does not compile yet. Fixing it is the exercise.
#include <iostream>
#include <string>

class Book {
public:
    void Book(const std::string& title, int copies) : title_(title), copies_(copies) {
        if (copies_ < 0) {
            copies_ = 0;
        }
    }

    bool borrow() {
        if (copies_ == 0) {
            return false;
        }
        --copies_;
        return true;
    }

    std::string title() { return title_; }
    int copies() { return copies_; }

private:
    std::string title_;
    int copies_ = 0;    // never negative
}

void report(const Book& book) {
    std::cout << book.title() << ": " << book.copies() << " left\n";
}

int main() {
    Book book("O'tkan kunlar", 2);
    report(book);
    book.borrow();
    book.copies_ = book.copies_ - 1;
    if (!book.borrow()) {
        std::cout << "No copies left.\n";
    }
    report(book);
}
