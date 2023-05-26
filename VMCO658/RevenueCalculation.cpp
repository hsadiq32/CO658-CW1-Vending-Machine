#include "RevenueCalculation.h"

RevenueCalculation::RevenueCalculation() : revenue(0) {}  // Constructor definition initializing revenue to 0

void RevenueCalculation::calculateRevenue(const Product& product, int quantity) {
    revenue += product.price * quantity;  // Calculate the revenue by multiplying the product price with the quantity and add it to the current revenue
}

double RevenueCalculation::getRevenue() const {
    return revenue;  // Return the current revenue
}

void RevenueCalculation::resetRevenue() {
    revenue = 0;  // Reset the revenue to 0
}
