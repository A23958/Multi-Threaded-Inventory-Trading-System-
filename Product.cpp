#include "Product.h"


Product::Product(int id,std::string name, double price, int quantity){
    this->id = id;
    this->ProductName = name;
    this->price = price;
    this->quantity = quantity;
}


bool Product::reduceStock(int amount){
    if(amount <= quantity){
        quantity -= amount;
        return true;
    }
    return false;
}


int Product::getId() const {
    return id;
    }

std::string Product::getName() const {
     return ProductName;
    }
double Product::getPrice() const {
    return price;
    }
int Product::getQuantity() const {
    return quantity;
     }
Product::~Product() {}
