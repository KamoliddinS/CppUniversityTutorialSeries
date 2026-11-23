#include "discount.h"

int priceAfterDiscount(int price, int percent) {
    return price - price * percent / 100;
}
