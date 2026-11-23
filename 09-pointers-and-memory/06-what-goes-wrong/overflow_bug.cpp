int main() {
    int* prices = new int[3]{500, 700, 900};
    prices[3] = 1200;       // the last element is prices[2]
    delete[] prices;
}
