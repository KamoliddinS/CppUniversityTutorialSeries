// Exercise 1: Predict the output
// Do not run this program yet. Write what it prints into prediction.txt.
#include <iostream>

class Score {
public:
    Score& operator+=(int points) {
        points_ += points;
        return *this;
    }

    Score& operator++() {
        ++points_;
        return *this;
    }

    Score operator++(int) {
        Score old = *this;
        ++points_;
        return old;
    }

    int points() const { return points_; }

private:
    int points_ = 0;
};

Score operator+(const Score& s, int points) {
    Score result = s;
    result += points;
    return result;
}

std::ostream& operator<<(std::ostream& out, const Score& s) {
    out << '[' << s.points() << ']';
    return out;
}

int main() {
    Score aziz;
    aziz += 10;
    Score malika = aziz + 5;
    std::cout << aziz << ' ' << malika << '\n';

    std::cout << ++aziz << '\n';
    std::cout << aziz++ << '\n';
    std::cout << aziz << '\n';

    (malika += 2) += 3;
    std::cout << malika << '\n';
}
