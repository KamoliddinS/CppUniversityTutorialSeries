// Exercise 1: Copy or move
// Do not run this program yet. Write what it prints into prediction.txt.
#include <iostream>
#include <string>
#include <utility>

class Box {
public:
    explicit Box(const std::string& label) : label_(label) { std::cout << "new " << label_ << '\n'; }
    Box(const Box& other) : label_(other.label_) { std::cout << "copy " << label_ << '\n'; }
    Box(Box&& other) noexcept : label_(other.label_) {
        other.label_ = "nothing";       // the old box is empty now
        std::cout << "move " << label_ << '\n';
    }
    ~Box() { std::cout << "end " << label_ << '\n'; }

private:
    std::string label_;
};

Box makeBox() {
    return Box("pens");
}

int main() {
    Box a("books");
    {
        Box b = a;
    }
    Box c = std::move(a);
    Box d = makeBox();
    std::cout << "end of main\n";
}
