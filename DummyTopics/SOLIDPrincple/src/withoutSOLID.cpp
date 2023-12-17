#include <iostream>
#include <vector>
#include <string>

class Library {
public:
    struct Member {
        std::string name;
        int id;
        std::vector<std::string> borrowedBooks;
    };

    struct Book {
        std::string title;
        bool isBorrowed;
    };

    void addMember(const std::string& name, int id) {
        members.push_back({name, id, {}});
    }

    void addBook(const std::string& title) {
        books.push_back({title, false});
    }

    bool borrowBook(int memberId, const std::string& bookTitle) {
        for (auto& book : books) {
            if (book.title == bookTitle && !book.isBorrowed) {
                book.isBorrowed = true;
                for (auto& member : members) {
                    if (member.id == memberId) {
                        member.borrowedBooks.push_back(bookTitle);
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void displayMembers() {
        for (const auto& member : members) {
            std::cout << "Member ID: " << member.id << ", Name: " << member.name << std::endl;
            std::cout << "Borrowed Books: ";
            for (const auto& book : member.borrowedBooks) {
                std::cout << book << ", ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<Member> members;
    std::vector<Book> books;
};

int main() {
    Library lib;
    lib.addMember("Alice", 1);
    lib.addMember("Bob", 2);
    lib.addBook("C++ Programming");
    lib.addBook("Data Structures");

    lib.borrowBook(1, "C++ Programming");

    lib.displayMembers();

    return 0;
}
