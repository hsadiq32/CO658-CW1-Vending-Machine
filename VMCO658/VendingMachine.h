#pragma once

#include "StateMachine.h"
#include "ProductManagement.h"
#include "InventoryManagement.h"

class VendingMachine {
private:
    StateMachine stateMachine;  // Private member variable to manage the states of the vending machine
    ProductManagement productManagement;  // Private member variable t manage the products
    InventoryManagement inventoryManagement;  // Private member variable to manage the inverntory

public:
    VendingMachine();  // Constructor to initialize the state machine, product management, and inventory management
    ProductManagement& getProductManagement();  // Getter method to return the product management
    InventoryManagement& getInventoryManagement();  // Getter method to return the inventory management
    void start();  // Method to start the vending machine
    StateMachine& getStateMachine();  // Getter method to return the state machine
};
