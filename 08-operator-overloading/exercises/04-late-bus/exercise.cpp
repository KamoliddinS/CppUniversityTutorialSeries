// Exercise 4: Late bus
// This program builds without a warning, but three of its operators are wrong.
// Find them and fix them. Do not change main.
#include <iostream>

class Time {
public:
    Time(int hour, int minute) : hour_(hour), minute_(minute) {}

    Time& operator+=(int minutes) {
        int all = hour_ * 60 + minute_ + minutes;
        hour_ = all / 60 % 24;
        minute_ = all % 60;
        return *this;
    }

    Time& operator+(int minutes) {
        *this += minutes;
        return *this;
    }

    Time& operator++() {
        *this += 1;
        return *this;
    }

    Time operator++(int) {
        ++*this;
        return *this;
    }

    bool operator<(const Time& other) const {
        if (minute_ != other.minute_) {
            return minute_ < other.minute_;
        }
        return hour_ < other.hour_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Time& t);

private:
    int hour_ = 0;
    int minute_ = 0;
};

std::ostream& operator<<(std::ostream& out, const Time& t) {
    out << t.hour_ << ':';
    if (t.minute_ < 10) {
        out << '0';
    }
    out << t.minute_;
    return out;
}

int main() {
    Time first(6, 30);
    Time second = first + 45;
    std::cout << "The buses leave at " << first << " and " << second << ".\n";

    Time now(6, 50);
    if (now < second) {
        std::cout << "At " << now << " you still catch the second bus.\n";
    } else {
        std::cout << "At " << now << " the second bus is gone.\n";
    }

    Time before = now++;
    std::cout << "One minute later: " << before << " -> " << now << '\n';
}
