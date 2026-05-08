#include "Inventory.h"

#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <memeory>
#include <mutex>
#include "Product.h"
using namespace std;
class Inventory{
    private:
    int nextProductID = 1;

    private:
        map<int,shared_ptr<Product>> Products;
        mutex mut;

    public:
        Inventory();

        void addProduct(shared_ptr<Product> Product){
           //add the producy pair into the map
           Products.insert({Product.id , Product.name});
           cout << "Product added successfully!" << endl;
        }
        bool removeProduct(int ProductID){
           //Search for the product id first if it exits in the map;
            bool isErased = false;
           if(searchProduct(ProductID) != nullptr){
               Products.erase(ProductID);
               isErased = true;
           }
           return isErased;
        }

         void displayProducts(){
          map<int,shared_ptr<Product>>:: iterator it;
            if (Products.empty()){
             cout << "No products yet" << endl;
                return;
              }
            for(it = Products.begin() ; it != Produts.end() ; i++){
                cout << "ProductID: "<< it->first << "Product: " << it->second;

            }

        }

  shared_ptr<Product> searchProduct(int id){
    map<int,shared_ptr<Product>>:: iterator pos = Products.find(id) ; /
    if(pos == Products.end()){
        cout << "Not match for the product";
            return nullptr;
    }else{
        cout << "The product is :" << endl;
            return &(pos->second);
                }
        }
   int getProductsSize(){
      return Products.size();
   }
    public:
    int IncrementID() {        // to auto incrememt product id just in case someone enters a duplicate
        return nextProductID++;
    }

   void sortByPrice(){
    vector<shared_ptr<Product>> temp;
    for(auto &p : Products){
        temp.push_back(p.second);
    }
    sort(temp.begin(), temp.end(), [](shared_ptr<Product> a, shared_ptr<Product> b){
        return a->getPrice() < b->getPrice();
    });

    cout << "\n--- Products Sorted by Price ---\n";

    for(auto &p : temp){
        cout << "ProductID: " << p->getId()
             << " | Name: " << p->getName()
             << " | Price: " << p->getPrice()
             << " | Quantity: " << p->getQuantity()
             << endl;

    }
}

   void sortByQuantity(){

    vector<shared_ptr<Product>> temp;


    for(auto &p : Products){
        temp.push_back(p.second);
    }

    sort(temp.begin(), temp.end(), [](shared_ptr<Product> a, shared_ptr<Product> b){
        return a->quantity < b->quantity;
    });
    for(auto &p : temp){
        cout << "ProductID: " << p->id << " Product: " << p->name
             << " Quantity: " << p->quantity << endl;
    }
}
bool processOrder(int productID,int quantity){

    bool Inventory::processOrder(int productID, int quantity)
{
    std::lock_guard<std::mutex> lock(mtx);

    std::shared_ptr<Product> prod = searchProduct(productID);

    if (prod == nullptr)
        return false;

    if (prod->getQuantity() < quantity){
        return false;
}else{
    prod->reduceQuantity(quantity);
    return true;
}
        virtual ~Inventory();
};
#endif // INVENTORY_H
