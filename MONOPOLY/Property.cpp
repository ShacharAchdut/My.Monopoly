#include "Property.hpp"

Property::Property(std::string name, int price, int rent, int housePrice, int rentWithHouses, int rentWithHotel)
    : name(name), price(price), rent(rent), housePrice(housePrice),
      rentWithHouses(rentWithHouses), rentWithHotel(rentWithHotel), houses(0), available(true), owner("") {}

std::string Property::getName() const { return name; }
int Property::getPrice() const { return price; }
int Property::getRent() const { return rent; }
int Property::getHousePrice() const { return housePrice; }
int Property::getRentWithHouses() const { return rentWithHouses; }
int Property::getRentWithHotel() const { return rentWithHotel; }
int Property::getHouses() const { return houses; }
bool Property::isAvailable() const { return available; }
std::string Property::getOwner() const { return owner; }

void Property::setOwner(const std::string& newOwner) {
    owner = newOwner;
    available = false;
}

void Property::addHouse() {
    if (houses < 4) {
        houses++;
    }
}

void Property::addHotel() {
    if (houses == 4) {
        houses = 5; // Indicating the property has a hotel
    }
}

int Property::calculateRent() const {
    if (houses == 0) return rent;
    else if (houses > 0 && houses < 5) return rentWithHouses * (1 << (houses - 1));
    else return rentWithHotel;
}
