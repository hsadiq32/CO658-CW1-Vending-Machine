#include "AdminOperations.h"

// Constructor
AdminOperations::AdminOperations(const std::string& pin) {
    admin.pin = pin; // Set the pin of the admin
    admin.isLoggedIn = false; // Set the logged in status of the admin to false
}

// Function to login the admin
void AdminOperations::adminLogin(const std::string& inputPin) {
    if (inputPin == admin.pin) { // If the input pin is equal to the pin of the admin
        admin.isLoggedIn = true; // Set the logged in status of the admin to true
        std::cout << "Admin logged in." << std::endl; // Print a message
    }
    else {
        std::cout << "Invalid PIN. Admin login failed." << std::endl; // Print a message
    }
}

// Function to logout the admin
void AdminOperations::adminLogout() {
    admin.isLoggedIn = false; // Set the logged in status of the admin to false
    std::cout << "Admin logged out." << std::endl; // Print a message
}

// Function to check if the admin is logged in
bool AdminOperations::isAdminLoggedIn() const {
    return admin.isLoggedIn; // Return the logged in status of the admin
}
