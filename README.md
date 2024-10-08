Monopoly Game
SHACHAR ACHDUT-323856195
Project Overview

This project is a version of the classic Monopoly game, developed using C++ and the SFML library for GUI rendering. The game simulates the core mechanics of Monopoly, including player movement, buying and selling properties, paying rent and taxes, and interacting with different types of board slots (streets, trains, utilities, taxes, surprise cards, and jail).

Features:

    Dice Rolls: The Players roll two dice to determine their movement across the board.
    Player Movement: Players move around a board with 40 slots, advancing based on dice rolls.
    Property Management: Players can buy properties or pay rent or tax when landing on owned properties.
    Special Slots: Includes slots like "Free Parking", "Jail", "Water & Electriciyu company" and "Go to Jail", as well as Surprise and Tax slots.
    Simple SFML-based GUI: The game is displayed graphically using SFML, showcasing a basic layout of the board and player pieces.

Rules of the Game-
Game Setup:

    Each player starts with a set amount of money ($1,500).
    Players take turns rolling two dices to move around the 40 slots board.
 
Buying Properties:

    When a player lands on an unowned property (streer or train), they can choose to buy it for its listed price.
    When a player owns a property, other players must pay rent (The rent amount is determined by the property's base rent and the number of houses/hotels on the property) when landing on it.


Special Slots:

    Surprise Slots: These slots trigger a random event, such as gaining or losing money or receiving a surprise card.
    Tax Slots: If players landing on a tax slot must pay the specified tax amount to the bank.
    Free Parking: Players that landing on Free Parking do nothing; it's just a safe space.
    Go to Jail: Player that landing on the "Go to Jail" slot are sent directly to jail must stay there for 3 rounds of turns but he can left earlier if he rolls doubles or pay a $50 tax or use a "Get Out of Jail Free" card.

Building on Properties:

    Once a player owns all properties in a color group, they can build houses and hotels on those properties, increasing the rent charged that other players who land there must pay him.

Winning:

If a player cannot pay a debt (rent, taxes, etc.) he lost in the game. The last player remaining after all orthe player that has 4000$ first is declared the winner.
Project Structure

    Board.hpp and Board.cpp: Manages the board structure and all the slots (properties, utilities, trains, special slots). It handles slot initialization and provides methods to interact with the board.

    Slot.hpp and Slot.cpp: Defines the various types of slots in the game, including StreetSlot (formerly Property), TrainSlot, UtilitySlot, SurpriseSlot, FreeParkingSlot, JailSlot, and TaxSlot. Each slot type has its unique behavior when a player lands on it.

    Street.hpp and Street.cpp: Manages individual properties (streets) on the board. Tracks information such as price, rent, and ownership.

    Player.hpp and Player.cpp: Represents players in the game. It stores the player's name, position on the board, and balance, and manages purchasing properties and paying rent.

    Dice.hpp and Dice.cpp: Implements the dice functionality, where two six-sided dice are rolled randomly to move players around the board.

    TestGame.cpp: A test suite that verifies the core mechanics of the game, including player movement, dice rolls, purchasing properties, and paying rent.


     
To run the game in terminal-  ./monopoly-game

to run the test in the terminal- ./testgame  (This will execute a series of tests to verify functionalities like dice rolls, player movement, and property management.)

I hope you will enjoy my MONOPOLY game and I wish you luck!!  (braek a leg and win :)  )
