#include "Game.hpp"
#include <iostream>
#include <cstdlib>

Game::Game(int numPlayers, std::vector<std::string> playerNames)
    : currentPlayerIndex(0) {
    for (const auto& name : playerNames) {
        players.emplace_back(name);
    }
    setupBoard();
}

void Game::setupBoard() {
    // Setup properties, trains, etc. on the board
    board.push_back(new PropertySlot(Property("Mediterranean Avenue", 100, 6, 50, 30, 100)));
    // Add more properties, trains, etc.
}

void Game::playTurn() {
    Player& currentPlayer = players[currentPlayerIndex];
    
    // Simulate rolling two dice
    int roll = (rand() % 6 + 1) + (rand() % 6 + 1);
    std::cout << currentPlayer.getName() << " rolls " << roll << std::endl;

    // Move player
    currentPlayer.move(roll);
    
    // Land on the slot
    board[currentPlayer.getPosition()]->landOn(currentPlayer);

    // Check if the player is bankrupt
    if (currentPlayer.getMoney() <= 0) {
        std::cout << currentPlayer.getName() << " is bankrupt!" << std::endl;
        players.erase(players.begin() + currentPlayerIndex);
        if (currentPlayerIndex >= players.size()) currentPlayerIndex = 0; // Adjust index
    } else {
        currentPlayerIndex = (currentPlayerIndex + 1) % players.size(); // Next player's turn
    }
}

void Game::checkEndGame() {
    if (players.size() == 1) {
        std::cout << players[0].getName() << " wins!" << std::endl;
        exit(0); // End the game
    }
}
