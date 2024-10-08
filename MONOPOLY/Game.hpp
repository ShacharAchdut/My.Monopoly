#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "Player.hpp"
#include "Slot.hpp"

class Game {
private:
    std::vector<Player> players;
    std::vector<Slot*> board; // The game board
    int currentPlayerIndex;

public:
    Game(int numPlayers, std::vector<std::string> playerNames);
    void setupBoard();
    void playTurn();
    void checkEndGame();
};

#endif // GAME_HPP
