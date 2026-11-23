int main() {
    int* a = new int(1);
    int* b = new int(2);
    a = b;
    delete a;
    delete b;
}
