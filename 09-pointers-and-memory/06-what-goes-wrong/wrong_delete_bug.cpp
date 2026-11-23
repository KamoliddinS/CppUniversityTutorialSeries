int main() {
    int* prices = new int[3]{500, 700, 900};
    delete prices;          // needs delete[]
}
