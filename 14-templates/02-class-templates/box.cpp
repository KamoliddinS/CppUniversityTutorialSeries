#include <iostream>
#include <string>

template <typename T>
class Box {
public:
    explicit Box(const T& value) : value_(value) {}

    const T& get() const { return value_; }
    void set(const T& value) { value_ = value; }

private:
    T value_;
};

int main() {
    Box<int> number(42);
    Box<std::string> city("Khiva");
    city.set("Bukhara");

    std::cout << number.get() << '\n';
    std::cout << city.get() << '\n';
}
