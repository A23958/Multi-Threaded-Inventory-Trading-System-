
#ifndef DISCOUNTEDPRODUCT_H
#define DISCOUNTEDPRODUCT_H

#include "Product.h"
class DiscountedProduct : public Product{
private:
    double discountRate;

public:
    DiscountedProduct(int id, std::string ProductName, double price, int quantity, double discountRate);

    double calculateFinalPrice() override;

    ~DiscountedProduct();
};

#endif
