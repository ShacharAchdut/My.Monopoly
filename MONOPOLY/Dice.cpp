#include "Dice.hpp"

// Constructor
Dice::Dice() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator
}

// Roll a single die (returns a value between 1 and 6)
int Dice::roll() {
    return (std::rand() % 6) + 1; // Generate a random number between 1 and 6
}

// Roll two dice and return the total
int Dice::rollTwoDice() {
    int die1 = roll();  // Roll the first die
    int die2 = roll();  // Roll the second die
    return die1 + die2; // Return the total of both dice
}
