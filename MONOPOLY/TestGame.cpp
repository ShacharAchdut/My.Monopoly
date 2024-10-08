#include <iostream>
#include <cassert>
#include "Player.hpp"
#include "Board.hpp"
#include "Dice.hpp"
#include "Slot.hpp"
#include "Street.hpp"

// Test function prototypes
void testPlayerMovement();
void testDiceRolls();
void testLandOnProperty();
void testBuyProperty();
void testPayRent();

//SHACHAR ACHDUT
//323856195

int main() {
    // Run all test functions
    testPlayerMovement();
    testDiceRolls();
    testLandOnProperty();
    testBuyProperty();
    testPayRent();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}

void testPlayerMovement() {
    Player player("Test Player");

    // Roll the dice and move the player
    player.move(5);
    assert(player.getPosition() == 5);  // Expected: moved 5 spaces

    player.move(7);
    assert(player.getPosition() == 12);  // Expected: now at position 12

    std::cout << "Player movement test passed." << std::endl;
}

void testDiceRolls() {
    Dice dice;

    for (int i = 0; i < 100; ++i) {
        int roll = dice.rollTwoDice();
        assert(roll >= 2 && roll <= 12);  // The result of two dice should always be between 2 and 12
    }

    std::cout << "Dice roll test passed." << std::endl;
}

void testLandOnProperty() {
    Player player("Test Player");
    Street street("Park Lane", 500);

    // Property slot test
    PropertySlot slot(street);
    assert(slot.getType() == "Street");  // Ensure correct slot type

    slot.landOn(player);
    assert(player.getMoney() == 1500);  // Since player cannot afford, their money shouldn't change

    std::cout << "Landing on Property test passed." << std::endl;
}

void testBuyProperty() {
    Player player("Test Player");
    player.setMoney(1000);  // Set some initial money for the player

    Street street("Park Lane", 200);
    PropertySlot slot(street);

    // Player lands on property and buys it
    slot.landOn(player);

    assert(street.getOwner() == player.getIndex());  // Ensure the player owns the property
    assert(player.getMoney() == 800);  // Player should have spent 200

    std::cout << "Buying property test passed." << std::endl;
}

void testPayRent() {
    Player player1("Player 1");
    Player player2("Player 2");

    player1.setMoney(1000);  // Set initial money for player1
    player2.setMoney(1000);  // Set initial money for player2

    Street street("Park Lane", 200);
    street.setOwner(player1.getIndex());  // Player1 owns the property

    PropertySlot slot(street);
    int rent = street.calculateRent();

    // Player2 lands on player1's property and pays rent
    slot.landOn(player2);

    assert(player2.getMoney() == 1000 - rent);  // Player2 should pay rent
    assert(player1.getMoney() == 1000 + rent);  // Player1 should receive rent

    std::cout << "Paying rent test passed." << std::endl;
}
