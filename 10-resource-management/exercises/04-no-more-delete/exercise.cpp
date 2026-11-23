// Exercise 4: No more delete
// This program builds and runs, but one path through it forgets the delete.
// Rewrite it with std::unique_ptr, so that it contains no new and no delete.
#include <iostream>
#include <string>

class Parcel {
public:
    Parcel(const std::string& city, int grams) : city_(city), grams_(grams) {}
    ~Parcel() { std::cout << "  (parcel for " << city_ << " deleted)\n"; }
    int grams() const { return grams_; }

private:
    std::string city_;
    int grams_ = 0;
};

// Returns a new parcel, or nullptr when the weight is not allowed.
Parcel* makeParcel(const std::string& city, int grams) {
    if (grams <= 0 || grams > 20000) {
        return nullptr;
    }
    return new Parcel(city, grams);
}

int main() {
    int load = 0;                       // grams in the van; it carries 30000 at most
    std::string city;
    int grams = 0;
    while (std::cin >> city >> grams) {
        Parcel* parcel = makeParcel(city, grams);
        if (parcel == nullptr) {
            std::cout << city << ": refused\n";
            continue;
        }
        if (load + parcel->grams() > 30000) {
            std::cout << city << ": the van is full\n";
            break;
        }
        load += parcel->grams();
        std::cout << city << ": loaded\n";
        delete parcel;
    }
    std::cout << "Total: " << load << " g\n";
}
