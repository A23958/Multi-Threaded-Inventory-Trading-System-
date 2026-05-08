#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Order {
private:
    int orderId;
    int productId;
    int quantity;
    string status;

public:
    Order(int orderId, int productId, int quantity)
        : orderId(orderId), productId(productId), quantity(quantity), status("PENDING") {}

    int getOrderId() const { return orderId; }
    int getProductId() const { return productId; }
    int getQuantity() const { return quantity; }
    string getStatus() const { return status; }

    void setStatus(const string& newStatus){ status = newStatus; }

      void display() const {
    cout << left
         << setw(6) << "OrderID"   << setw(6)  << orderId
         << " | "
         << setw(6) << "ProductID" << setw(6)  << productId
         << " | "
         << setw(6) << "Qty"       << setw(6)  << quantity
         << " | "
         << setw(6) << "Status"    << setw(10) << status
         << endl;
}
};

#endif
