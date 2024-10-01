#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include <string>
#include <vector>
#include <iostream>
#include "Slots.hpp"
#include "Board.hpp"
#include "Dice.hpp"

{
    class Player
    {
    private:
        std::string name; //the name of the player
        std::string color; //his color
        int currentIndex;
        Slots* currentSlots;
        sf::CircleShape token;
        std::vector<sf::CircleShape> ownershipMarkers; // Vector to store ownership markers
        int sizeMarkers = 0;
        sf::Text playerInfo;
        bool nowBuy;
    public:
        int numberOfTrains = 0;
        int serialNum;
        bool hisTurn = false;
        std::vector<Slots> ownedProperties; // To store owned properties
        int money;
        Player(std::string name, std::string color, sf::RenderWindow &window, int serialNum);
        std::string getName();
        std::string getColor();
        Slots* getCurrentSlots();
        void setCurrentSlots(int numToMove, sf::RenderWindow &window);
        void initializePlayerToken(sf::RenderWindow &window);
        void drawTokenAndInfo(sf::RenderWindow &window);
        void drawBuyButton(sf::RenderWindow &window);
        bool handleBuyButtonClick(sf::RenderWindow &window);
        bool checkIfCanBuildHouse();
        bool checkIfCanBuildHotel();
    };
}

#endif // PLAYER_HPP