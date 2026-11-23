int main() {
    int* price = new int(12000);
    int* copy = price;      // two pointers, one int
    delete price;
    delete copy;            // the same int again
}
