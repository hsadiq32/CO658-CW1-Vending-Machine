// This is a preprocessor directive that ensures the header file is included only once in a single compilation.
#pragma once

// These are libraries used for input/output operations, string manipulation, and dynamic arrays.
#include <iostream>
#include <string>
#include <vector>

class Product {
    // This is a class declaration for a Product.

public:
    // These are the public members of the Product class.
    std::string name;
    double price;
    int quantity;
    int row;
    int column;
    // This is the default constructor for the Product class. It does not take any parameters and does not perform any actions.
    Product() {}
    
    // This is a parameterized constructor for the Product class. It takes parameters for each member variable and initializes them.
    Product(const std::string& name, double price, int quantity, int row, int column)
        : name(name), price(price), quantity(quantity), row(row), column(column) {}
    
};
// This is a function declaration for a Swap function. It takes two references to Product objects and swaps their values.
void Swap(Product& a, Product& b);

// This is a function that takes a reference to a vector of Product objects and a boolean indicating whether to sort in ascending order. 
// The boolean has a default value of true.
void EnhancedBubbleSort(std::vector<Product>& data, bool ascending = true);
