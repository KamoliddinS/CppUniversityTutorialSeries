#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int pages;
};

void printBookDetails(const Book& b) {
    cout << "Title: " << b.title << ", Author: " << b.author << ", Pages: " << b.pages << endl;
}

int main() {
    Book book1; 
    book1 = {"Harry Potter", "JK Rowling", 500};
    Book book2 = {"1984", "George Orwell", 328};

    printBookDetails(book1);
    printBookDetails(book2);

    return 0;
}
