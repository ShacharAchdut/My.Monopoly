#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <iostream>

//SHACHAR ACHDUT
//323856195
int main() {
    int numPlayers;
    std::vector<std::string> playerNames;

    std::cout << "Enter number of players (2-8): ";
    std::cin >> numPlayers;

    for (int i = 0; i < numPlayers; ++i) {
        std::string name;
        std::cout << "Enter name for player " << (i + 1) << ": ";
        std::cin >> name;
        playerNames.push_back(name);
    }

    Game game(numPlayers, playerNames);

    // Game loop with SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "Monopoly");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // Draw the game board and player positions here
        window.display();

        game.playTurn();
        game.checkEndGame();
    }

    return 0;
}
