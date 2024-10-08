#ifndef STREET_HPP
#define STREET_HPP

#include <string>

class Player;  // Forward declaration

class Street {
private:
    std::string name;
    int price;
    int rent;
    int owner; // Index of the player who owns this street
    bool available;

public:
    Street(const std::string& name, int price, int rent);
    
    bool isAvailable() const;         // Check if the street is available
    int getPrice() const;             // Get the price of the street
    void setOwner(int playerIndex);    // Set the owner of the street
    int getOwner() const;              // Get the owner of the street
    int calculateRent() const;         // Calculate the rent for the street
    std::string getName() const;       // Get the name of the street
};

#endif // STREET_HPP
