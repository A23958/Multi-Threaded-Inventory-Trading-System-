#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product{
protected:
    int id;
    std::string ProductName;
    double price;
    int quantity;

public:
    Product(int id, std::string ProductName, double price, int quantity);

    virtual double calculateFinalPrice() = 0;

    bool reduceStock(int amount);

    int getId() const;
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;

    virtual ~Product();
};

#endif
