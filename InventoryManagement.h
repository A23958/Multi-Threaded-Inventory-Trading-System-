#ifndef INVENTORYMANAGEMENT_H
#define INVENTORYMANAGEMENT_H

class Inventory;  // forward declaration

class InventoryManagement
{
private:
    Inventory& invent;

public:
    InventoryManagement(Inventory& invt);

    void showMenu() const;
    void handleUserChoice(int choice);
    void run();

    ~InventoryManagement();
};

#endif
