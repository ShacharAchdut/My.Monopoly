#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include "Property.hpp"

class Player {
private:
    std::string name;
    int money;
    std::vector<Property*> ownedProperties; // List of properties owned by the player
    int position; // Player's current position on the board
    int jailTurns; // Number of turns in jail
    int surpriseTickets; // Number of surprise "get out of jail" tickets

public:
    Player(std::string name);

    std::string getName() const;
    int getMoney() const;
    int getPosition() const;
    int getJailTurns() const;
    int getSurpriseTickets() const;
    
    bool canAfford(int cost) const;

    void addMoney(int amount);
    void deductMoney(int amount);
    void buyProperty(Property& property);
    void payRent(int rent);
    void move(int steps);
    void goToJail();
    void useSurpriseTicket();

    const std::vector<Property*>& getOwnedProperties() const;
};

#endif // PLAYER_HPP
