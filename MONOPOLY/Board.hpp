#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "Slot.hpp"

class Board {
public:
    Board();
    void draw(sf::RenderWindow& window);
    Slot& getSlot(int index);
    void resetBoard();

private:
    std::vector<Slot*> slots; // Vector of pointers to slots
    void initializeSlots(); // Initializes the board slots
};

#endif // BOARD_HPP
