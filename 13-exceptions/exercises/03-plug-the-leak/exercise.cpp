// Exercise 3: Plug the leak
// The report "timetable" is opened but never closed. Find out why.
// Then change printReport so that every report is closed. Do not change Report or main.
#include <iostream>
#include <stdexcept>
#include <string>

class Report {
public:
    explicit Report(const std::string& title) : title_(title) {
        std::cout << "open " << title_ << '\n';
    }
    ~Report() { std::cout << "close " << title_ << '\n'; }

    void print(int pages) const {
        if (pages > 10) {
            throw std::runtime_error("not enough paper");
        }
        std::cout << "print " << title_ << ": " << pages << " pages\n";
    }

private:
    std::string title_;
};

void printReport(const std::string& title, int pages) {
    Report* report = new Report(title);
    report->print(pages);
    delete report;
}

int main() {
    try {
        printReport("grades", 4);
        printReport("timetable", 25);
        printReport("menu", 2);
    } catch (const std::runtime_error& e) {
        std::cout << "error: " << e.what() << '\n';
    }
}
