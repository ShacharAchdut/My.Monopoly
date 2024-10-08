#include "Board.hpp"
#include "Street.hpp"
#include "Train.hpp"
#include "Utility.hpp"
#include "Surprise.hpp"
#include "Tax.hpp"
#include "FreeParking.hpp"
#include "Jail.hpp"
#include "GoToJail.hpp"
#include <iostream>

// Constants for the board size
const int BOARD_WIDTH = 800;
const int BOARD_HEIGHT = 800;
const double SQUARE_SIZE = 73; // Adjusted for 11 squares

// Constructor
Board::Board() {
    // Load font for drawing text
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    
    // Initialize the board with all the slots
    initializeBoardSlots();
}

void Board::initializeBoardSlots() {
    // Slot 0: Go
    slots.push_back(new Slot("Go", 0));

    // Slots 1-9: Streets and other types
    slots.push_back(new Street("Street A", "Brown", 60, 2, 50, 50, 250, 10, true));
    slots.push_back(new Surprise("Surprise Slot 1"));
    slots.push_back(new Street("Street B", "Brown", 60, 4, 50, 50, 450, 20, true));
    slots.push_back(new Tax("Tax Slot 1", 100));
    slots.push_back(new Train("Train 1", 200));
    slots.push_back(new Street("Street C", "Light Blue", 100, 6, 50, 50, 550, 30, true));
    slots.push_back(new Surprise("Surprise Slot 2"));
    slots.push_back(new Street("Street D", "Light Blue", 100, 6, 50, 50, 650, 40, true));
    slots.push_back(new Street("Street E", "Light Blue", 120, 8, 50, 50, 750, 50, true));

    // Slot 10: Jail
    slots.push_back(new Jail("Jail Slot"));

    // Slots 11-19: Streets, utilities, and trains
    slots.push_back(new Street("Street F", "Pink", 140, 10, 100, 100, 850, 60, true));
    slots.push_back(new Utility("Electric Company", 150));
    slots.push_back(new Street("Street G", "Pink", 140, 10, 100, 100, 950, 70, true));
    slots.push_back(new Street("Street H", "Pink", 160, 12, 100, 100, 1050, 80, true));
    slots.push_back(new Train("Train 2", 200));
    slots.push_back(new Street("Street I", "Orange", 180, 14, 100, 100, 1150, 90, true));
    slots.push_back(new Surprise("Surprise Slot 3"));
    slots.push_back(new Street("Street J", "Orange", 180, 14, 100, 100, 1250, 100, true));
    slots.push_back(new Street("Street K", "Orange", 200, 16, 100, 100, 1350, 110, true));

    // Slot 20: Free Parking
    slots.push_back(new FreeParking());

    // Slots 21-29: Streets, utilities, and trains
    slots.push_back(new Street("Street L", "Red", 220, 18, 150, 150, 1450, 120, true));
    slots.push_back(new Surprise("Surprise Slot 4"));
    slots.push_back(new Street("Street M", "Red", 220, 18, 150, 150, 1550, 130, true));
    slots.push_back(new Street("Street N", "Red", 240, 20, 150, 150, 1650, 140, true));
    slots.push_back(new Train("Train 3", 200));
    slots.push_back(new Street("Street O", "Yellow", 260, 22, 150, 150, 1750, 150, true));
    slots.push_back(new Street("Street P", "Yellow", 260, 22, 150, 150, 1850, 160, true));
    slots.push_back(new Utility("Water Company", 150));
    slots.push_back(new Street("Street Q", "Yellow", 280, 24, 150, 150, 1950, 170, true));

    // Slot 30: Go to Jail
    slots.push_back(new GoToJail());

    // Slots 31-39: Streets, trains, and tax
    slots.push_back(new Street("Street R", "Green", 300, 26, 200, 200, 2050, 180, true));
    slots.push_back(new Street("Street S", "Green", 300, 26, 200, 200, 2150, 190, true));
    slots.push_back(new Surprise("Surprise Slot 5"));
    slots.push_back(new Street("Street T", "Green", 320, 28, 200, 200, 2250, 200, true));
    slots.push_back(new Train("Train 4", 200));
    slots.push_back(new Surprise("Surprise Slot 6"));
    slots.push_back(new Street("Street U", "Blue", 350, 35, 250, 250, 2450, 210, true));
    slots.push_back(new Tax("Tax Slot 2", 100));
    slots.push_back(new Street("Street V", "Blue", 400, 50, 250, 250, 2750, 250, true));
}

// Destructor
Board::~Board() {
    // Delete dynamically allocated slots
    for (Slot* slot : slots) {
        delete slot;
    }
}

void Board::draw(sf::RenderWindow& window) {
    // You can add logic here to visually draw the board slots using SFML
    // For now, this is just an example of drawing text in each slot
    for (size_t i = 0; i < slots.size(); i++) {
        sf::Text slotText;
        slotText.setFont(font);
        slotText.setString(slots[i]->getName());
        slotText.setCharacterSize(15);
        slotText.setFillColor(sf::Color::Black);
        // Calculate position based on square size
        slotText.setPosition((i % 11) * SQUARE_SIZE + 10, (i / 11) * SQUARE_SIZE + 10); // Adjust position for better layout

        window.draw(slotText);
    }
}
