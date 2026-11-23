#include <iostream>
#include <memory>
#include <string>

struct Song {
    std::string title;
    explicit Song(const std::string& songTitle) : title(songTitle) {}
    ~Song() { std::cout << title << " is destroyed\n"; }
};

void play(std::shared_ptr<Song> song) {     // by value: one more owner while play runs
    std::cout << "playing " << song->title << ", owners: " << song.use_count() << '\n';
}

int main() {
    auto mine = std::make_shared<Song>("Navo");
    std::cout << "owners: " << mine.use_count() << '\n';
    {
        auto yours = mine;                  // a copy: a second owner of the same Song
        std::cout << "owners: " << mine.use_count() << '\n';
        play(yours);
    }                                       // yours is destroyed
    std::cout << "owners: " << mine.use_count() << '\n';
}                                           // mine is destroyed: no owner is left
