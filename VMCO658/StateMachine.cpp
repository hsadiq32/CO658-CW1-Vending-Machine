#include "StateMachine.h"

// Constructor initialises the state machine with the Idle state and admin pin
StateMachine::StateMachine() : currentState(State::Idle), adminOperations("1234") {}

// Function to transition to a new state
void StateMachine::transitionTo(State state) {
    currentState = state; // Set the current state to the new state
    processState(); // Process the new state
}

// Function to process the current state
void StateMachine::processState() {
    // Switch statement to handle different states
    switch (currentState) {
    case State::Idle:
        showIdleStateMenu(); // Show the idle state menu
        break;
    case State::UserMenu:
        showUserMenu(); // Show the user menu
        break;
    case State::AdminMenu:
        showAdminMenu(); // Show the admin menu
        break;
    default:
        break; // Do nothing for other states
    }
}

// Function to show the idle state menu
void StateMachine::showIdleStateMenu() {
    // Print the menu options
    std::cout << "Welcome to the Vending Machine!" << std::endl;
    std::cout << "Please select an option:" << std::endl;
    std::cout << "1. User Menu" << std::endl;
    std::cout << "2. Admin Menu" << std::endl;
    std::cout << "0. Exit" << std::endl;

    int choice; // Variable to store the user's choice
    std::cin >> choice; // Get the user's choice

    // Switch statement to handle the user's choice
    switch (choice) {
    case 1:
        transitionTo(State::UserMenu); // Transition to the user menu
        break;
    case 2:
        adminLogin(); // Perform admin login
        break;
    case 0:
        exit(0); // Exit the program
    default:
        std::cout << "Invalid choice. Please try again." << std::endl;
        transitionTo(State::Idle); // Transition back to the idle state
        break;
    }
}

// Function to show the user menu
void StateMachine::showUserMenu() {
    // Print the menu options
    std::cout << "User Menu:" << std::endl;
    std::cout << "1. Display Products" << std::endl;
    std::cout << "2. Insert Coin" << std::endl;
    std::cout << "3. Insert Card" << std::endl;
    std::cout << "4. Make Purchase" << std::endl;
    std::cout << "5. Get Balance" << std::endl;
    std::cout << "0. Go back" << std::endl;

    int choice; // Variable to store the user's choice
    std::cin >> choice; // Get the user's choice

    // Switch statement to handle the user's choice
    switch (choice) {
    case 1:
        // Get sorting preferences from user
        std::cout << "Sort by price (0 for no, 1 for yes): ";
        int sortByPrice;
        std::cin >> sortByPrice;
        std::cout << "Sort in ascending order (0 for descending, 1 for ascending): ";
        int ascending;
        std::cin >> ascending;
        // Display products based on user's sorting preferences
        productManagement.getProducts(sortByPrice != 0, ascending != 0);
        break;
    case 2:
        insertCoin(); // Perform coin insertion
        break;
    case 3:
        insertCard(); // Perform card insertion
        break;
    case 4:
        makePurchase(); // Perform purchase
        break;
    case 5:
        getBalance(); // Get the current balance
        break;
    case 0:
        transitionTo(State::Idle); // Go back to the idle state
        break;
    default:
        std::cout << "Invalid choice. Please try again." << std::endl;
        break;
    }

    transitionTo(State::UserMenu); // Transition back to the user menu
}

// Function to show the admin menu
void StateMachine::showAdminMenu() {
    // Print the menu options
    std::cout << "Admin Menu:" << std::endl;
    std::cout << "1. Add Product" << std::endl;
    std::cout << "2. Remove Product" << std::endl;
    std::cout << "3. Modify Product" << std::endl;
    std::cout << "4. Restock Product" << std::endl;
    std::cout << "5. Search Product by Name" << std::endl;
    std::cout << "6. Search Product by Location" << std::endl;
    std::cout << "7. Print Coin Inventory" << std::endl;
    std::cout << "8. Add Coins" << std::endl;
    std::cout << "9. Remove Coins" << std::endl;
    std::cout << "10. Calculate Revenue" << std::endl;
    std::cout << "11. Reset Revenue" << std::endl;
    std::cout << "0. Go back" << std::endl;

    int choice; // Variable to store the admin's choice
    std::cin >> choice; // Get the admin's choice

    // Switch statement to handle the admin's choice
    switch (choice) {
    case 1:
        addProduct(); // Add a new product
        break;
    case 2:
        removeProduct(); // Remove a product
        break;
    case 3:
        modifyProduct(); // Modify a product
        break;
    case 4:
        restockProduct(); // Restock a product
        break;
    case 5:
        searchProductByName(); // Search for a product by name
        break;
    case 6:
        searchProductByLocation(); // Search for a product by location
        break;
    case 7:
        inventoryManagement.printInventory(); // Print the coin inventory
        break;
    case 8:
        addCoins(); // Add coins to the inventory
        break;
    case 9:
        removeCoins(); // Remove coins from the inventory
        break;
    case 10:
        calculateRevenue(); // Calculate the total revenue
        break;
    case 11:
        resetRevenue(); // Reset the revenue
        break;
    case 0:
        adminLogout(); // Perform admin logout
        break;
    default:
        std::cout << "Invalid choice. Please try again." << std::endl;
        break;
    }

    transitionTo(State::AdminMenu); // Transition back to the admin menu
}

// Function to perform admin login
void StateMachine::adminLogin() {
    // Check if the admin is already logged in
    if (adminOperations.isAdminLoggedIn()) {
        std::cout << "Admin is already logged in." << std::endl;
    }
    else {
        std::string pin; // Variable to store the admin pin
        std::cout << "Enter admin PIN: ";
        std::cin >> pin; // Get the admin pin
        adminOperations.adminLogin
            (pin); // Perform admin login

        // Check if the admin login was successful
        if (adminOperations.isAdminLoggedIn()) {
            transitionTo(State::AdminMenu); // Transition to the admin menu
        }
        else {
            transitionTo(State::Idle); // Transition back to the idle state
        }
    }
}

// Function to perform admin logout
void StateMachine::adminLogout() {
    // Check if the admin is logged in
    if (adminOperations.isAdminLoggedIn()) {
        adminOperations.adminLogout(); // Perform admin logout
        transitionTo(State::Idle); // Transition back to the idle state
    }
    else {
        std::cout << "Admin is not currently logged in." << std::endl;
    }
}

// Function to add a new product
void StateMachine::addProduct() {
    // Check if the admin is logged in
    if (adminOperations.isAdminLoggedIn()) {
        std::string name; // Variable to store the product name
        double price; // Variable to store the product price
        int quantity, row, column; // Variables to store the product quantity, row, and column

        // Get the product details from the admin
        std::cout << "Enter product name: ";
        std::cin >> name;
        std::cout << "Enter price: ";
        std::cin >> price;
        std::cout << "Enter quantity: ";
        std::cin >> quantity;
        std::cout << "Enter row: ";
        std::cin >> row;
        std::cout << "Enter column: ";
        std::cin >> column;

        // Add the new product
        productManagement.addProduct(name, price, quantity, row, column);
        std::cout << "Product added successfully." << std::endl;
    }
    else {
        std::cout << "Admin login required to perform this operation." << std::endl;
    }
}

// Function to remove a product
void StateMachine::removeProduct() {
    // Check if the admin is logged in
    if (adminOperations.isAdminLoggedIn()) {
        int row, column; // Variables to store the product row and column

        // Get the product location from the admin
        std::cout << "Enter row: ";
        std::cin >> row;
        std::cout << "Enter column: ";
        std::cin >> column;

        // Remove the product
        productManagement.removeProduct(row, column);
        std::cout << "Product removed successfully." << std::endl;
    }
    else {
        std::cout << "Admin login required to perform this operation." << std::endl;
    }
}

// Function to modify a product
void StateMachine::modifyProduct() {
    // Check if the admin is logged in
    if (adminOperations.isAdminLoggedIn()) {
        int row, column; // Variables to store the product row and column
        double newPrice; // Variable to store the new product price
        int newQuantity; // Variable to store the new product quantity

        // Get the product location and new details from the admin
        std::cout << "Enter row: ";
        std::cin >> row;
        std::cout << "Enter column: ";
        std::cin >> column;
        std::cout << "Enter new price: ";
        std::cin >> newPrice;
        std::cout << "Enter new quantity: ";
        std::cin >> newQuantity;

        // Modify the product
        bool modificationSuccessful = productManagement.modifyProduct(row, column, newPrice, newQuantity);
        if (modificationSuccessful) {
            std::cout << "Product modified successfully." << std::endl;
        }
        else {
            std::cout
                << "Product not found at the specified location." << std::endl;
        }
    }
    else {
        std::cout << "Admin login required to perform this operation." << std::endl;
    }
}

// Function to restock a product
void StateMachine::restockProduct() {
    // Check if the admin is logged in
    if (adminOperations.isAdminLoggedIn()) {
        int row, column; // Variables to store the product row and column
        int quantity; // Variable to store the quantity to restock

        // Get the product location and quantity to restock from the admin
        std::cout << "Enter row: ";
        std::cin >> row;
        std::cout << "Enter column: ";
        std::cin >> column;
        std::cout << "Enter quantity to restock: ";
        std::cin >> quantity;

        // Restock the product
        productManagement.restockProduct(row, column, quantity);
        std::cout << "Product restocked successfully." << std::endl;
    }
    else {
        std::cout << "Admin login required to perform this operation." << std::endl;
    }
}

// Function to search for a product by name
void StateMachine::searchProductByName() {
    std::string name; // Variable to store the product name
    std::cout << "Enter product name to search: ";
    std::cin >> name; // Get the product name from the user

    // Search for the product
    Product* product = productManagement.searchProductByName(name);
    if (product != nullptr) {
        // Print the product details if found
        std::cout << "Name: " << product->name << ", Price: " << product->price << ", Quantity: " << product->quantity << std::endl;
    }
    else {
        std::cout << "Product not found." << std::endl;
    }
}

// Function to search for a product by location
void StateMachine::searchProductByLocation() {
    int row, column; // Variables to store the product row and column
    std::cout << "Enter row: ";
    std::cin >> row; // Get the product row from the user
    std::cout << "Enter column: ";
    std::cin >> column; // Get the product column from the user

    // Search for the product
    Product* product = productManagement.searchProductByRowAndColumn(row, column);
    if (product != nullptr) {
        // Print the product details if found
        std::cout << "Name: " << product->name << ", Price: " << product->price << ", Quantity: " << product->quantity << std::endl;
    }
    else {
        std::cout << "Product not found." << std::endl;
    }
}

// Function to insert a coin
void StateMachine::insertCoin() {
    double amount; // Variable to store the coin amount
    std::cout << "Enter coin amount: ";
    std::cin >> amount; // Get the coin amount from the user

    // Insert the coin
    paymentAndPurchase.insertCoin(amount);
    std::cout << "Coin inserted." << std::endl;
}

// Function to insert a card
void StateMachine::insertCard() {
    Card card; // Variable to store the card details
    std::cout << "Enter card number: ";
    std::cin >> card.cardNumber; // Get the card number from the user
    std::cout << "Enter expiration date: ";
    std::cin >> card.expirationDate; // Get the card expiration date from the user
    std::cout << "Enter CV:";
        std::cin >> card.cvv; // Get the card CVV from the user

    // Insert the card
    paymentAndPurchase.insertCard(card);
    std::cout << "Card inserted." << std::endl;
}

// Function to make a purchase
void StateMachine::makePurchase() {
    std::string name; // Variable to store the product name
    int quantity; // Variable to store the quantity to purchase
    std::cout << "Enter product name: ";
    std::cin >> name; // Get the product name from the user
    std::cout << "Enter quantity: ";
    std::cin >> quantity; // Get the quantity to purchase from the user

    // Search for the product
    Product* product = productManagement.searchProductByName(name);
    if (product != nullptr) {
        // Check if the purchase is successful
        if (paymentAndPurchase.makePurchase(*product, quantity)) {
            // Calculate the revenue and update the product quantity
            revenueCalculation.calculateRevenue(*product, quantity);
            product->quantity -= quantity;
            std::cout << "Purchase successful." << std::endl;
            std::cout << "Change: " << paymentAndPurchase.returnChange() << std::endl;
        }
        else {
            std::cout << "Insufficient balance or quantity." << std::endl;
        }
    }
    else {
        std::cout << "Product not found." << std::endl;
    }
}

// Function to get the current balance
void StateMachine::getBalance() {
    double balance = paymentAndPurchase.getBalance(); // Get the current balance
    std::cout << "Balance: " << balance << std::endl;
}

// Function to return the change
void StateMachine::returnChange() {
    double change = paymentAndPurchase.returnChange(); // Get the change
    std::cout << "Change: " << change << std::endl;
}

// Function to add coins to the inventory
void StateMachine::addCoins() {
    int denomination, quantity; // Variables to store the coin denomination and quantity
    std::cout << "Enter coin denomination: ";
    std::cin >> denomination; // Get the coin denomination from the admin
    std::cout << "Enter quantity: ";
    std::cin >> quantity; // Get the quantity from the admin

    // Add the coins to the inventory
    inventoryManagement.addCoins(denomination, quantity);
    std::cout << "Coins added to inventory." << std::endl;
}

// Function to remove coins from the inventory
void StateMachine::removeCoins() {
    int denomination, quantity; // Variables to store the coin denomination and quantity
    std::cout << "Enter coin denomination: ";
    std::cin >> denomination; // Get the coin denomination from the admin
    std::cout << "Enter quantity: ";
    std::cin >> quantity; // Get the quantity from the admin

    // Remove the coins from the inventory
    inventoryManagement.removeCoins(denomination, quantity);
    std::cout << "Coins removed from inventory." << std::endl;
}

// Function to calculate the total revenue
void StateMachine::calculateRevenue() {
    double revenue = revenueCalculation.getRevenue(); // Get the total revenue
    std::cout << "Total revenue: " << revenue << std::endl;
}

// Function to reset the revenue
void StateMachine::resetRevenue() {
    revenueCalculation.resetRevenue(); // Reset the revenue
    std::cout << "Revenue reset." << std::endl;
}

