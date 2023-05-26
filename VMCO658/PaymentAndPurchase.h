#pragma once

#include <iostream>

#include "Product.h"
#include "Card.h"

class PaymentAndPurchase {
private:
    double balance;  // Private member variable to store the current balance

public:
    PaymentAndPurchase();  // Constructor to initialize the balance to 0
    void insertCoin(double amount);  // Method to add the amount of the inserted coin to the balance
    void insertCard(const Card& card);  // Method to process the card information and deduct a dummy amount from the balance
    bool makePurchase(const Product& product, int quantity);  // Method to make a purchase by deducting the total cost from the balance and checking if the product quantity is sufficient
    double getBalance() const;  // Getter method to return the current balance
    double returnChange();  // Method to return the remaining balance as change and reset the balance to 0
};
