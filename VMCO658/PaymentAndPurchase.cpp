#include "PaymentAndPurchase.h"

PaymentAndPurchase::PaymentAndPurchase() : balance(0) {}  // Constructor definition
void PaymentAndPurchase::insertCoin(double amount) {
    balance += amount;  // Add the amount of the inserted coin to the balance
}

void PaymentAndPurchase::insertCard(const Card& card) {
    // Process card information
    balance -= 10; // Dummy deduction as an example
}

bool PaymentAndPurchase::makePurchase(const Product& product, int quantity) {
    double totalCost = product.price * quantity;  // Calculate the total cost of the purchase
    if (balance >= totalCost && product.quantity >= quantity) {  // Check if the balance is sufficient and the product quantity is sufficient
        balance -= totalCost;  // Deduct the total cost from the balance
        return true;  // Return true if the purchase is successful
    }
    return false;  // Return false if the purchase is unsuccessful
}

double PaymentAndPurchase::getBalance() const {
    return balance;  // Return the current balance
}

double PaymentAndPurchase::returnChange() {
    double change = balance;  // Store the current balance as change
    balance = 0;  // Reset the balance to 0
    return change;  // Return the change
}
