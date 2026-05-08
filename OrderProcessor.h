#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include <iostream>
#include <vector>
#include <thread>
#include <iomanip>
#include <mutex>
#include <random>
#include "Order.h"
#include "Inventory.h"

using namespace std;

class OrderProcessor {
private:
    vector<Order> orders;
    mutex orderMutex;
    Inventory& inventory;


public:
    OrderProcessor(Inventory& inv) : inventory(inv) {}
    int failedOrders=0;
    int successfuulOrders=0;

    void addOrder(const Order& order){
        lock_guard<mutex> lock(orderMutex);
        orders.push_back(order);
    }

    void processOrdersMultithread(){
        vector<thread> threads;
        random_device rd;
        mt19937 gen(rd());
        int size =inventory.getProductsSize();
        uniform_int_distribution<> productDist(1,size);
        uniform_int_distribution<> quantityDist(1, 20);

        for(int i=1; i<=15; i++){
            threads.emplace_back([this, i, &gen, &productDist, &quantityDist](){
                int productID = productDist(gen);
                int quantity = quantityDist(gen);

                bool success = inventory.processOrder(productID, quantity);
                Order order(i, productID, quantity);
                if(success){
                    order.setStatus("SUCCESS");
                    successfuulOrders++;
                }
                else{
                    order.setStatus("FAILED");
                   failedOrders++;
            }

                addOrder(order);

lock_guard<mutex> lock(orderMutex);

cout << left
     << setw(6) << "Thread "
     << setw(6)  << i
     << " | "
     << setw(6) << "OrderID "
     << setw(6)  << i
     << " | "
     << setw(6) << "ProductID "
     << setw(6) << productID
     << " | "
     << setw(6)  << "Qty "
     << setw(6)  << quantity
     << " ->  "
     << setw(6) << order.getStatus()
     << endl;
            });
        }

        for(thread &t : threads) t.join();
    }

    void displayOrders(){
        lock_guard<mutex> lock(orderMutex);
        for(auto &o : orders) o.display();
    }
    int getSuccsesfulOrders(){
     return successfuulOrders;
    }int getFailedOrders(){
       return failedOrders;
    }

    int totalOrders(){
        lock_guard<mutex> lock(orderMutex);
        return orders.size();
    }
};

#endif
