#pragma once

// Include necessary libraries and header files
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "Product.h"  // Include the Product class

// Define the ProductManagement class
class ProductManagement {
private:
    // Private data members
    std::unordered_map<std::string, Product> products;  // Map of products, keyed by product name
    std::unordered_map<int, std::unordered_map<int, std::string>> locationTable;  // Map of product locations, keyed by row and column

public:
    // Public member functions
    void getProducts(bool sortByPrice = true, bool ascending = true);  // Function to get products, optionally sorted by price
    void addProduct(const std::string& name, double price, int quantity, int row, int column);  // Function to add a product
    void removeProduct(int row, int column);  // Function to remove a product by its location
    bool modifyProduct(int row, int column, double newPrice, int newQuantity);  // Function to modify a product's price and quantity
    void restockProduct(int row, int column, int quantity);  // Function to restock a product
    Product* searchProductByName(const std::string& name);  // Function to search for a product by its name
    Product* searchProductByRowAndColumn(int row, int column);  // Function to search for a product by its location
};
