#pragma once

#include "Product.h"

class RevenueCalculation {
private:
    double revenue;  // Private member variable to store the total revenue

public:
    RevenueCalculation();  // Constructor to initialize the revenue to 0
    void calculateRevenue(const Product& product, int quantity);  // Method to calculate the revenue based on the product price and quantity sold
    double getRevenue() const;  // Getter method to return the current revenue
    void resetRevenue();  // Method to reset the revenue to 0
};
