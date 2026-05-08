#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <mutex>
#include <algorithm>
#include "Product.h"

using namespace std;

class Inventory {
private:
    map<int, shared_ptr<Product>> products;
    mutex mut;
    int nextProductID = 1;

public:
    Inventory() {}

    void addProduct(shared_ptr<Product> product){
        lock_guard<mutex> lock(mut);
        products[product->getId()] = product;
        cout << "Product added: " << product->getName() << endl;
    }
    int IncrementID() {
        return nextProductID++;
    }
bool removeProduct(int ProductID){
    lock_guard<mutex> lock(mut);
    return products.erase(ProductID) > 0;
}
shared_ptr<Product> searchProduct(int id){
    lock_guard<mutex> lock(mut);

    auto pos = products.find(id);

    if(pos == products.end()){
        return nullptr;
    }

    return pos->second;
}
    void displayProducts(){
        lock_guard<mutex> lock(mut);
        for(auto& p : products){
            cout << "ID: " << p.first
                 << " | Name: " << p.second->getName()
                 << " | Price: " << p.second->getPrice()
                 << " | Quantity: " << p.second->getQuantity()
                 << endl;
        }
    }

 void sortByPrice() {
    lock_guard<mutex> lock(mut);
    vector<shared_ptr<Product>> temp;
    for(auto& p : products) temp.push_back(p.second);
    sort(temp.begin(), temp.end(), [](shared_ptr<Product> a, shared_ptr<Product> b){
        return a->getPrice() < b->getPrice();
    });
    cout << "\n--- Products Sorted by Price ---\n";
    for(auto& p : temp){
        cout << "ID: " << p->getId()
             << " | Name: " << p->getName()
             << " | Price: " << p->getPrice()
             << " | Quantity: " << p->getQuantity()
             << endl;
    }
}
   int getProductsSize(){
      return products.size();
   }


void sortByQuantity() {
    lock_guard<mutex> lock(mut);
    vector<shared_ptr<Product>> temp;
    for(auto& p : products) temp.push_back(p.second);
    sort(temp.begin(), temp.end(), [](shared_ptr<Product> a, shared_ptr<Product> b){
        return a->getQuantity() < b->getQuantity();
    });

    cout << "\n--- Products Sorted by Quantity ---\n";
    for(auto& p : temp){
        cout << "ID: " << p->getId()
             << " | Name: " << p->getName()
             << " | Price: " << p->getPrice()
             << " | Quantity: " << p->getQuantity()
             << endl;
    }
}
    bool processOrder(int productID, int quantity){
        lock_guard<mutex> lock(mut);
        auto it = products.find(productID);
        if(it == products.end()) return false;
        if(it->second->getQuantity() < quantity) return false;

        it->second->reduceStock(quantity);
        return true;
    }
};

#endif
