#include <iostream>
#include <vector>
#include <string>

// Abstract class for Member management
class IMemberManager {
public:
    virtual void addMember(const std::string& name, int id) = 0;
    virtual void displayMembers() const = 0;
    virtual ~IMemberManager() = default;
};

// Abstract class for Book management
class IBookManager {
public:
    virtual void addBook(const std::string& title) = 0;
    virtual bool borrowBook(int memberId, const std::string& bookTitle) = 0;
    virtual ~IBookManager() = default;
};

// Concrete implementation of IMemberManager
class MemberManager : public IMemberManager {
public:
    struct Member {
        std::string name;
        int id;
        std::vector<std::string> borrowedBooks;
    };

    void addMember(const std::string& name, int id) override {
        members.push_back({name, id, {}});
    }

    void displayMembers() const override {
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
};

// Concrete implementation of IBookManager
class BookManager : public IBookManager {
public:
    struct Book {
        std::string title;
        bool isBorrowed;
    };

    void addBook(const std::string& title) override {
        books.push_back({title, false});
    }

    bool borrowBook(int memberId, const std::string& bookTitle) override {
        // YOu can write your logic here 
        return true; 
    }

private:
    std::vector<Book> books;
};

// Library class now acts as a facade, coordinating between MemberManager and BookManager
class Library {
public:
    Library(IMemberManager* memberManager, IBookManager* bookManager) 
        : memberManager(memberManager), bookManager(bookManager) {}

    void addMember(const std::string& name, int id) {
        memberManager->addMember(name, id);
    }

    void addBook(const std::string& title) {
        bookManager->addBook(title);
    }

    void borrowBook(int memberId, const std::string& bookTitle) {
        bookManager->borrowBook(memberId, bookTitle);
    }

    void displayMembers() {
        memberManager->displayMembers();
    }

private:
    IMemberManager* memberManager;
    IBookManager* bookManager;
};

int main() {
    MemberManager memberManager;
    BookManager bookManager;
    Library lib(&memberManager, &bookManager);

    lib.addMember("Alice", 1);
    lib.addMember("Bob", 2);
    lib.addBook("C++ Programming");
    lib.addBook("Data Structures");

    lib.borrowBook(1, "C++ Programming");

    lib.displayMembers();

    return 0;
}
