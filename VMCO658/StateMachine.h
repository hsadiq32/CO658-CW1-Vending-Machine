#pragma once

#include <iostream>

#include "ProductManagement.h"
#include "InventoryManagement.h"
#include "RevenueCalculation.h"
#include "PaymentAndPurchase.h"
#include "AdminOperations.h"

//```cpp
// Defining an enum class State with states Idle, UserMenu, and AdminMenu
enum class State {
    Idle,
    UserMenu,
    AdminMenu
};

// Defining a class StateMachine with private and public access modifiers
class StateMachine {
private:
    State currentState; // Current state
    ProductManagement productManagement; // Product management
    InventoryManagement inventoryManagement; // Inventory management
    RevenueCalculation revenueCalculation; // Revenue calculation
    PaymentAndPurchase paymentAndPurchase; // Payment and purchase
    AdminOperations adminOperations; // Admin operations

public:
    StateMachine(); // Constructor
    // Function prototypes for transitioning to a state, processing a state, showing the idle state menu, showing the user menu, showing the admin menu, admin login, admin logout, adding a product, removing a product, modifying a product, restocking a product, searching a product by name, searching a product by location, inserting a coin, inserting a card, making a purchase, getting the balance, returning the change, adding coins, removing coins, calculating the revenue, and resetting the revenue
    void transitionTo(State state);
    void processState();
    void showIdleStateMenu();
    void showUserMenu();
    void showAdminMenu();
    void adminLogin();
    void adminLogout();
    void addProduct();
    void removeProduct();
    void modifyProduct();
    void restockProduct();
    void searchProductByName();
    void searchProductByLocation();
    void insertCoin();
    void insertCard();
    void makePurchase();
    void getBalance();
    void returnChange();
    void addCoins();
    void removeCoins();
    void calculateRevenue();
    void resetRevenue();
};
