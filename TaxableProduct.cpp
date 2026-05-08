#include "TaxableProduct.h"

TaxableProduct::TaxableProduct(int id, std::string ProductName, double price, int quantity, double taxRate)
: Product(id, ProductName, price, quantity){
    this->taxRate = taxRate;
}

double TaxableProduct::calculateFinalPrice(){
    return price + (price * taxRate);
}

TaxableProduct::~TaxableProduct(){}
