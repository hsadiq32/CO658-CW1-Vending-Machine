#include "ProductManagement.h"

// Function to get products
void ProductManagement::getProducts(bool sortByPrice, bool ascending) {
    std::vector<Product> productList; // Vector to store the products
    for (const auto& pair : products) { // Loop through the unordered map of products
        const Product& product = pair.second; // Get the product from the pair
        productList.push_back(product); // Add the product to the vector
    }
    if (sortByPrice) { // If the products should be sorted by price
        EnhancedBubbleSort(productList, ascending); // Perform an enhanced bubble sort on the vector of products
    }
    for (const Product& product : productList) { // Loop through the vector of products
        // Print the name, price, and quantity of each product
        std::cout << "Name: " << product.name << ", Price: " << product.price << ", Quantity: " << product.quantity << std::endl;
    }
}

// Function to add a product
void ProductManagement::addProduct(const std::string& name, double price, int quantity, int row, int column) {
    Product product; // Create a new product
    product.name = name; // Set the name of the product
    product.price = price; // Set the price of the product
    product.quantity = quantity; // Set the quantity of the product
    product.row = row; // Set the row of the product in the vending machine
    product.column = column; // Set the column of the product in the vending machine

    products[name] = product; // Add the product to the unordered map of products with its name as the key
    locationTable[row][column] = name; // Add the name of the product to the unordered map of product locations with its row and column as the keys
}

// Function to remove a product
void ProductManagement::removeProduct(int row, int column) {
    // If the row exists in the unordered map of product locations and the column exists in the unordered map of the row
    if (locationTable.count(row) && locationTable[row].count(column)) {
        std::string name = locationTable[row][column]; // Get the name of the product
        products.erase(name); // Remove the product from the unordered map of products
        locationTable[row].erase(column); // Remove the column from the unordered map of the row
    }
}

// Function to modify a product
bool ProductManagement::modifyProduct(int row, int column, double newPrice, int newQuantity) {
    // If the row exists in the unordered map of product locations and the column exists in the unordered map of the row
    if (locationTable.count(row) && locationTable[row].count(column)) {
        std::string name = locationTable[row][column]; // Get the name of```cpp
        // the product
        Product& product = products[name]; // Get the product from the unordered map of products
        product.price = newPrice; // Set the new price of the product
        product.quantity = newQuantity; // Set the new quantity of the product
        return true; // Return true as the product was found and modified
    }
    else {
        return false;  // Product not found at the specified location
    }
}

// Function to restock a product
void ProductManagement::restockProduct(int row, int column, int quantity) {
    // If the row exists in the unordered map of product locations and the column exists in the unordered map of the row
    if (locationTable.count(row) && locationTable[row].count(column)) {
        std::string name = locationTable[row][column]; // Get the name of the product
        Product& product = products[name]; // Get the product from the unordered map of products
        product.quantity += quantity; // Increase the quantity of the product
    }
}

// Function to search for a product by name
Product* ProductManagement::searchProductByName(const std::string& name) {
    if (products.count(name)) { // If the product exists in the unordered map of products
        return &products[name]; // Return a pointer to the product
    }
    return nullptr; // Return a null pointer as the product was not found
}

// Function to search for a product by row and column
Product* ProductManagement::searchProductByRowAndColumn(int row, int column) {
    // If the row exists in the unordered map of product locations and the column exists in the unordered map of the row
    if (locationTable.count(row) && locationTable[row].count(column)) {
        std::string name = locationTable[row][column]; // Get the name of the product
        return &products[name]; // Return a pointer to the product
    }
    return nullptr; // Return a null pointer as the product was not found
}
