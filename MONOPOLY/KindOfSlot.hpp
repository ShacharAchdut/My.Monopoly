#ifndef KINDOFSLOT_HPP
#define KINDOFSLOT_HPP

#include <string>
#include <valarray>

{
    // Enumeration for color groups
    enum class ColorGroup
    {
        Brown,
        LightBlue,
        Pink,
        Orange,
        Red,
        Yellow,
        Green,
        Blue,
    };

    // Base abstract class
    class KinfOfSlot
    {
        public:
            virtual ~kindOfSlot() = default; // Virtual destructor for proper cleanup of derived class objects
            process(int money) const = 0; // Pure virtual function for specific behavior of different square types
    };

    // Street class
    class Street : public KinfOfSlot {
    public:
        Street(const std::string &name, int price, int rent, int houseCost, int rentWithHouse, int rentWithHotel,
               ColorGroup colorGroup);

        int process(int) const override; // Pass Player by reference
        int buildHouse(int,int);
        int buyStreet(int);
    private:
        std::string name;                // Name of the street
        int price;                       // Price to buy the street
        int rent;                        // Rent when no houses or hotels are built
        int houseCost;                   // Cost to build a house on the street
        int rentWithHouse;               // Rent with one or more houses
        int rentWithHotel;               // Rent with a hotel
        ColorGroup colorGroup;           // Color group to which the street belongs
    };

    // Train class
    class Train : public kindOfSlot {
    public:
        Train(const std::string &name, int cost); // Constructor declaration
        int process(int numOfTrains) const override; // Pass Player by reference
        int buyTrain(int money);
    private:
        std::string name;                // Name of the train
        int cost;                        // Cost to buy the train
    };

    // GO class
    class Go : public KinfOfSlot {
       public:
        int process(int money) const override; // Pass Player by reference
    };

    // Jail class
    class Jail : public KinfOfSlot {
    public:
        Jail();

        int process(int money) const override; // Pass Player by reference

        int getTurnsInJail() const; // Returns the number of turns the player is in jail
        void incrementTurns();       // Increment the turns spent in jail

    private:
        int turnsInJail; // Number of turns the player is in jail
    };

    // Special square classes
    class Chance : public KinfOfSlot {
    public:
        int process(int money) const override; // Pass Player by reference
    };

    class CommunityChest : public KinfOfSlot {
    public:
        int process(int money) const override; // Pass Player by reference
    };

    class FreeParking : public KinfOfSlot {
    public:
        int process(int money) const override; // Pass Player by reference
    };

    class Tax : public KinfOfSlot {
    public:
        Tax(const std::string &name, int cost); // Constructor declaration
        int process(int money) const override; // Pass Player by reference

    private:
        std::string name;                // Name of the tax
        int cost;                        // Cost to pay
    };

    class GoToJail : public KinfOfSlot {
    public:
        int process(int money) const override; // Pass Player by reference
    };

    class Utility : public KinfOfSlot {
    public:
        Utility(const std::string &name, int cost); // Constructor declaration
        int process(int money) const override; // Pass Player by reference
        int buyUtility(int money);
    private:
        std::string name;                // Name of the utility
        int cost;                        // Cost to buy the utility
    };
}
#endif // KinfOfSlot_HPP