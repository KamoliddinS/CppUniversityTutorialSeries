#include <iostream>
#include <list>

int main() {
    std::list<int> scores = {70, 95, 85};
    scores.sort();                             // a member of std::list: it only steps

    for (int score : scores) {
        std::cout << score << ' ';
    }
    std::cout << '\n';
}
