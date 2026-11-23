#include <algorithm>
#include <list>

int main() {
    std::list<int> scores = {70, 95, 85};
    std::sort(scores.begin(), scores.end());   // sort needs iterators that can jump
}
