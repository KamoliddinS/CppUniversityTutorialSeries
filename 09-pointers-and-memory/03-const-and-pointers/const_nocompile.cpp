int main() {
    int price = 500;
    int other = 900;

    const int* look = &price;
    *look = 600;                // changes the value through look

    int* const fixed = &price;
    fixed = &other;             // points fixed elsewhere

    int* plain = look;          // plain could change what look protects
    *plain = 700;
}
