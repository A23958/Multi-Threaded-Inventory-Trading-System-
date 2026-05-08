#ifndef TAXABLEPRODUCT_H
#define TAXABLEPRODUCT_H

#include "Product.h"

class TaxableProduct : public Product{
private:
    double taxRate;

public:
    TaxableProduct(int id, std::string ProductName, double price, int quantity, double taxRate);

    double calculateFinalPrice() override;

    ~TaxableProduct();
};

#endif
