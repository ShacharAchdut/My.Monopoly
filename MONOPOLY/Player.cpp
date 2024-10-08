#include "Player.hpp"
#include <iostream>

Player::Player(std::string name) : name(name), money(1500), position(0), jailTurns(0), surpriseTickets(0) {}

std::string Player::getName() const { return name; }
int Player::getMoney() const { return money; }
int Player::getPosition() const { return position; }
int Player::getJailTurns() const { return jailTurns; }
int Player::getSurpriseTickets() const { return surpriseTickets; }

bool Player::canAfford(int cost) const { return money >= cost; }

void Player::addMoney(int amount) {
    money += amount;
}

void Player::deductMoney(int amount) {
    money -= amount;
}

void Player::buyProperty(Property& property) {
    if (canAfford(property.getPrice()) && property.isAvailable()) {
        ownedProperties.push_back(&property);
        property.setOwner(name); // Set the property owner
        deductMoney(property.getPrice()); // Deduct the property price from player's money
    }
}

void Player::payRent(int rent) {
    if (canAfford(rent)) {
        deductMoney(rent); // Deduct rent
    } else {
        // Handle bankruptcy scenario
        std::cout << name << " cannot afford to pay rent and is bankrupt!" << std::endl;
    }
}

void Player::move(int steps) {
    position = (position + steps) % 40; // Assuming 40 slots in the board
}

void Player::goToJail() {
    position = 10; // Jail position
    jailTurns = 3; // Cannot play for 3 turns
}

void Player::useSurpriseTicket() {
    if (surpriseTickets > 0) {
        surpriseTickets--;
        jailTurns = 0; // Reset jail turns
    }
}

const std::vector<Property*>& Player::getOwnedProperties() const {
    return ownedProperties;
}
