#pragma once

#include <string>

// Defining a class Card with public acceess modifier
class Card {
public:
    std::string cardNumber; // Card number
    std::string expirationDate; // Expiration date of the card
    int cvv; // CVV of the card
};
