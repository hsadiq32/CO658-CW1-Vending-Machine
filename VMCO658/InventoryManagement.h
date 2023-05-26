#pragma once

// Including necessary libraries
#include <iostream>
#include <unordered_map>

// Including the Coin class header file
#include "Coin.h"


class InventoryManagement {
private:
    // An unordered map to store coins. The key is the denomination of the coin and the value is the Coin object.
    std::unordered_map<double, Coin> coins;

public:
    // A function to print the current inventory of coins. This function will be defined in the corresponding .cpp file.
    void printInventory();

    // A declared function to add coins to the inventory.
    void addCoins(double denomination, int quantity);

    // A declared function to remove coins from the inventory. 
    void removeCoins(int denomination, int quantity);
};
