// Exercise 6: Undo and redo
// Read commands until the input ends: type WORD, undo, redo, show.
// The exercise text says what each command does.
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

// One typed word. An Edit cannot be copied, so create it on the heap
// and let a std::unique_ptr own it.
struct Edit {
    std::string word;
    inline static int alive = 0;        // how many Edit objects exist right now
    explicit Edit(const std::string& text) : word(text) { ++alive; }
    ~Edit() { --alive; }
    Edit(const Edit& other) = delete;
    Edit& operator=(const Edit& other) = delete;
};

int main() {
    {
        // TODO: keep the edits of the text in one std::vector<std::unique_ptr<Edit>>
        //       and the undone edits in another one.
        std::string command;
        while (std::cin >> command) {
            // TODO: handle type, undo, redo and show.
        }
    }   // the vectors are destroyed here, with every Edit they own
    std::cout << "Edits in memory at the end: " << Edit::alive << '\n';
}
