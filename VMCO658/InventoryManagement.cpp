// Including the header file for the InventoryManagement class
#include "InventoryManagement.h"

// Definition of the printInventory function
void InventoryManagement::printInventory() {
    // Looping through each pair in the coins unordered map
    for (const auto& pair : coins) {
        // Getting the Coin object from the pair
        const Coin& coin = pair.second;
        // Printing the denomination and quantity of the coin
        std::cout << "Denomination: " << coin.denomination << ", Quantity: " << coin.quantity << std::endl;
    }
}

// Definition of the addCoins function
void InventoryManagement::addCoins(double denomination, int quantity) {
    // Adding the quantity to the coin of the specified denomination in the coins unordered map
    // If the coin of the specified denomination does not exist, it will be created
    coins[denomination].denomination = denomination;
    coins[denomination].quantity += quantity;
}

// Definition of the removeCoins function
void InventoryManagement::removeCoins(int denomination, int quantity) {
    // Checking if the coin of the specified denomination exists in the coins unordered map
    if (coins.count(denomination)) {
        // Getting the coin of the specified denomination
        Coin& coin = coins[denomination];
        coin.quantity -= quantity;
        // If the quantity of the coin becomes negative, setting it to 0
        if (coin.quantity < 0) {
            coin.quantity = 0;
        }
    }
}
