#include "Slot.hpp"
#include <iostream>
#include <cstdlib>

PropertySlot::PropertySlot(const Property& property) : property(property) {}

void PropertySlot::landOn(Player& player) {
    if (property.isAvailable()) {
        if (player.canAfford(property.getPrice())) {
            player.buyProperty(property);
            std::cout << player.getName() << " bought " << property.getName() << std::endl;
        } else {
            std::cout << player.getName() << " cannot afford " << property.getName() << std::endl;
        }
    } else {
        int rent = property.calculateRent();
        player.payRent(rent);
        std::cout << player.getName() << " pays $" << rent << " rent to " << property.getOwner() << std::endl;
    }
}

std::string PropertySlot::getType() const {
    return "Property";
}

Property& PropertySlot::getProperty() {
    return property;
}

TrainSlot::TrainSlot(std::string name, int price) : name(name), price(price), owner(-1), available(true) {}

void TrainSlot::landOn(Player& player) {
    if (available) {
        if (player.canAfford(price)) {
            setOwner(player.getIndex());
            player.deductMoney(price);
            std::cout << player.getName() << " bought " << name << std::endl;
        }
    } else {
        // Calculate rent based on the number of trains owned
        int rent = 50; // Base rent
        // Increase rent based on the owner's trains
        std::cout << player.getName() << " pays $" << rent << " rent to " << getOwner() << std::endl;
        player.deductMoney(rent);
    }
}

std::string TrainSlot::getType() const {
    return "Train";
}

void TrainSlot::setOwner(int playerIndex) {
    owner = playerIndex;
    available = false;
}

int TrainSlot::getOwner() const {
    return owner;
}

void SurpriseSlot::landOn(Player& player) {
    int card = rand() % 5; // Random surprise card
    switch (card) {
        case 0: player.addMoney(100); break;
        case 1: player.addSurpriseTicket(); break;
        case 2: player.deductMoney(100); break;
        case 3: player.deductMoney(200); break;
        case 4: player.addMoney(200); break;
    }
}

std::string SurpriseSlot::getType() const {
    return "Surprise";
}

void FreeParkingSlot::landOn(Player& player) {
    // Do nothing, just end the turn
}

std::string FreeParkingSlot::getType() const {
    return "Free Parking";
}

void TaxSlot::landOn(Player& player) {
    player.deductMoney(100);
}

std::string TaxSlot::getType() const {
    return "Tax";
}

void JailSlot::landOn(Player& player) {
    // Nothing happens, just end the turn
}

std::string JailSlot::getType() const {
    return "Jail";
}

WaterElectricitySlot::WaterElectricitySlot(std::string type, int price) : type(type), price(price), owner(-1), available(true) {}

void WaterElectricitySlot::landOn(Player& player) {
    if (available) {
        if (player.canAfford(price)) {
            setOwner(player.getIndex());
            player.deductMoney(price);
            std::cout << player.getName() << " bought " << type << " company" << std::endl;
        }
    } else {
        // Calculate rent based on dice roll
        int rent = (rand() % 12 + 1) * 10; // Roll two dice
        player.deductMoney(rent);
        std::cout << player.getName() << " pays $" << rent << " rent to " << getOwner() << std::endl;
    }
}

std::string WaterElectricitySlot::getType() const {
    return type;
}

void WaterElectricitySlot::setOwner(int playerIndex) {
    owner = playerIndex;
    available = false;
}

int WaterElectricitySlot::getOwner() const {
    return owner;
}
