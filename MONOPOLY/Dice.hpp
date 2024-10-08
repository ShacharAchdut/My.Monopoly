#ifndef DICE_HPP
#define DICE_HPP

#include <cstdlib>
#include <ctime>

class Dice {
public:
    Dice();  // Constructor to initialize the dice
    int roll();  // Method to roll a single die and return the result
    int rollTwoDice();  // Method to roll two dice and return the total
};

#endif // DICE_HPP
