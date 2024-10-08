#ifndef PROPERTY_HPP
#define PROPERTY_HPP

#include <string>

class Property {
private:
    std::string name;
    int price;
    int rent;
    int housePrice;
    int rentWithHouses;
    int rentWithHotel;
    int houses; // Number of houses on the property
    bool available; // Whether the property is available for purchase
    std::string owner; // Name of the owner (empty if available)

public:
    Property(std::string name, int price, int rent, int housePrice, int rentWithHouses, int rentWithHotel);
    
    // Accessors
    std::string getName() const;
    int getPrice() const;
    int getRent() const;
    int getHousePrice() const;
    int getRentWithHouses() const;
    int getRentWithHotel() const;
    int getHouses() const;
    bool isAvailable() const;
    std::string getOwner() const;

    // Mutators
    void setOwner(const std::string& newOwner);
    void addHouse();
    void addHotel();
    
    // Rent calculation
    int calculateRent() const;
};

#endif // PROPERTY_HPP
