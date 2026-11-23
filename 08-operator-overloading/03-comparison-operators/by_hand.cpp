#include <iostream>

struct Date {
    int day = 1;
    int month = 1;
    int year = 2000;

    bool operator==(const Date& other) const {      // what = default would write
        return day == other.day && month == other.month && year == other.year;
    }

    bool operator<(const Date& other) const {       // year first, day last
        if (year != other.year) {
            return year < other.year;
        }
        if (month != other.month) {
            return month < other.month;
        }
        return day < other.day;
    }
};

int main() {
    Date exam{25, 5, 2026};
    Date holiday{1, 9, 2026};

    if (exam == holiday) {
        std::cout << "Both are on the same day.\n";
    } else if (exam < holiday) {
        std::cout << "The exam comes first.\n";
    } else {
        std::cout << "The holiday comes first.\n";
    }
}
