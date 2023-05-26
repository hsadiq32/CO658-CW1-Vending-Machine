#pragma once

#include <iostream>
#include <string>

#include "Admin.h"

class AdminOperations {
private:
    Admin admin; // Admin

public:
    AdminOperations(const std::string& pin); // Constructor
    // Function prototypes for admin login, admin logout, and checking if the admin is logged in
    void adminLogin(const std::string& inputPin);
    void adminLogout();
    bool isAdminLoggedIn() const;
};
