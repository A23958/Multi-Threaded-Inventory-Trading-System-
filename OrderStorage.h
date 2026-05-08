#ifndef ORDERSTORAGE_H
#define ORDERSTORAGE_H

#include <vector>
#include <memory>
#include "Order.h"
class OrderStorage
{
    private:
        vector<shared_ptr<Order>> orders;
    public:
        OrderStorage();
        void addOrder(shared_ptr<Order> order);
        vector<shared_ptr<Order>> getOrders();
        virtual ~OrderStorage();
};

#endif // ORDERSTORAGE_H

