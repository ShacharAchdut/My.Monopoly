#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Slots.hpp"
#include "kindOfSlot.hpp"
#include "Button.hpp"
#include "Dice.hpp"

{
    class Board
    {
    private:
        static std::vector<Slots*> Slots;                   // Stores all the slots on the board
        std::vector<kindSlots*> kinds;                       // Stores all kinds of slots (Street, Go, Jail, etc.)
        std::vector<std::string> colors;
        std::vector<std::pair<sf::RectangleShape, sf::Text>> graphicalSlots;  // Stores the graphical representation of slots
    public:
        Dice rollDice;
        Board();
        void createBoard(sf::RenderWindow& window);           // Function to create and display the board
        void initializeKindSlots(sf::RenderWindow& window);  // Function to initialize the slots and their graphical representations
        void createGraphicalSlots(int i, const std::string& name, sf::Color color, sf::RenderWindow &);  // Function to create and position graphical slots
        void drawTitle(sf::RenderWindow &window);             // Function to draw the title "Monopoly"
        static std::vector<Slots*> getSlots();              // Getter for the slots on the board
    };
}
