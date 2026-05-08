#include "DiscountedProduct.h"

DiscountedProduct::DiscountedProduct(int id, std::string ProductName, double price, int quantity, double discountRate)
: Product(id, ProductName, price, quantity){
    this->discountRate = discountRate;
}

double DiscountedProduct::calculateFinalPrice(){
    return price - (price * discountRate);
}

DiscountedProduct::~DiscountedProduct(){}
