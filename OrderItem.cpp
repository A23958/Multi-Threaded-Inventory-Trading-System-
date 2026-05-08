#include "OrderItem.h"

#ifndef ORDERITEM_H
#define ORDERITEM_H

#include <string>

class OrderItem
{
private:
    int productId;
    std::string productName;
    int quantity;

public:
    OrderItem(int productId, std::string productName, int quantity){
        this->productId = productId;
        this->productName = productName;
        this->quantity = quantity;
    }

    int getProductId(){
        return productId;
    }

    int getQuantity(){
        return quantity;
    }

    std::string getProductName(){
        return productName;
    }
};

#endif // ORDERITEM_H
