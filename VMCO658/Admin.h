#pragma once

#include <string>

class Admin {
public:
    // The 'pin' member variable represents the personal identification number for the admin. 
    // It's a string, so it can contain any sequence of characters.
    std::string pin;

    // The 'isLoggedIn' member variable is a boolean that indicates whether the admin is currently logged in.
    // It's true if the admin is logged in, and false otherwise.
    bool isLoggedIn;
};
