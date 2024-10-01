#include "Board.hpp"


std::vector<Slots*> Board::Slotss;

Board::Board() = default;

void Board::createBoard(sf::RenderWindow& window)
{
    initializeKindSlots(window);
    int index = 0;
    while(index < 40)
    {
        Slots* slots = new Slots(index, kinds[index],colors[index]);
        Slots.push_back(slots); // Store the dynamically allocated Slots's pointer
        index++;
    }
}
std::vector<Slots*> Board::getSlots()
{
    return Slots;
}
void Board::initializeKindSlots(sf::RenderWindow &window)
{
    // Initialize kinds and create graphical slotss
    kinds.push_back(new Go());
    createGraphicalSlots(0, "GO", sf::Color::White, window);
    colors.push_back("White");

    kinds.push_back(new Street("Mediterranean Avenue", 60, 54, 108, 97, 388, ColorGroup::Brown));
    createGraphicalSlots(1, "Mediter-\nranean\nAvenue\n$60", sf::Color(139, 69, 19), window); // Brown color
    colors.push_back("Brown");

    kinds.push_back(new CommunityChest());
    createGraphicalSlots(2, "Community\nChest", sf::Color(255, 192, 203), window);
    colors.push_back("Pink");

    kinds.push_back(new Street("Baltic Avenue", 60, 54, 108, 97, 388, ColorGroup::Brown));
    createGraphicalSlots(3, "Baltic\nAvenue\n$60", sf::Color(139, 69, 19), window); // Brown color
    colors.push_back("Brown");

    kinds.push_back(new Tax("Income Tax", 200));
    createGraphicalSlots(4, "Income\nTax\n$200", sf::Color::Red, window);
    colors.push_back("Red");

    kinds.push_back(new Train("Reading Railroad", 200));
    createGraphicalSlots(5, "Reading\nRailroad\n$200", sf::Color(211, 211, 211), window);
    colors.push_back("Gray");

    kinds.push_back(new Street("Oriental Avenue", 100, 90, 180, 162, 648, ColorGroup::LightBlue));
    createGraphicalSlots(6, "Oriental\nAvenue\n$100", sf::Color::Cyan, window);
    colors.push_back("Light Blue");

    kinds.push_back(new Chance());
    createGraphicalSlots(7, "Chance", sf::Color(255, 192, 203), window);
    colors.push_back("Pink");

    kinds.push_back(new Street("Vermont Avenue", 100, 90, 180, 162, 648, ColorGroup::LightBlue));
    createGraphicalSlots(8, "Vermont\nAvenue\n$100", sf::Color::Cyan, window);
    colors.push_back("Light Blue");

    kinds.push_back(new Street("Connecticut Avenue", 120, 108, 216, 194, 778, ColorGroup::LightBlue));
    createGraphicalSlots(9, "Connecticut\nAvenue\n$120", sf::Color::Cyan, window);
    colors.push_back("Light Blue");

    kinds.push_back(new Jail());
    createGraphicalSlots(10, "Jail", sf::Color::White, window);
    colors.push_back("White");

    kinds.push_back(new Street("St. Charles Place", 140, 126, 252, 227, 907, ColorGroup::Blue));
    createGraphicalSlots(11, "St. Charles\nPlace\n$140", sf::Color::Magenta, window);
    colors.push_back("Magenta");

    kinds.push_back(new Utility("Electric Company", 150));
    createGraphicalSlots(12, "Electric\nCompany\n$150", sf::Color(204, 153, 255), window);
    colors.push_back("Light Purple");

    kinds.push_back(new Street("States Avenue", 140, 126, 252, 227, 907, ColorGroup::Blue));
    createGraphicalSlots(13, "States\nAvenue\n$140", sf::Color::Magenta, window);
    colors.push_back("Magenta");

    kinds.push_back(new Street("Virginia Avenue", 160, 144, 288, 259, 1037, ColorGroup::Blue));
    createGraphicalSlots(14, "Virginia\nAvenue\n$160", sf::Color::Magenta, window);
    colors.push_back("Magenta");

    kinds.push_back(new Train("Pennsylvania Railroad", 200));
    createGraphicalSlots(15, "Pennsylvania\nRailroad\n$200", sf::Color(211, 211, 211), window);
    colors.push_back("Gray");

    kinds.push_back(new Street("St. James Place", 180, 162, 324, 292, 1166, ColorGroup::Orange));
    createGraphicalSlots(16, "St. James\nPlace\n$180", sf::Color(255, 165, 0), window); // Orange
    colors.push_back("Orange");

    kinds.push_back(new CommunityChest());
    createGraphicalSlots(17, "Community\nChest", sf::Color(255, 192, 203), window);
    colors.push_back("Pink");

    kinds.push_back(new Street("Tennessee Avenue", 180, 162, 324, 292, 1166, ColorGroup::Orange));
    createGraphicalSlots(18, "Tennessee\nAvenue\n$180", sf::Color(255, 165, 0), window); // Orange
    colors.push_back("Orange");

    kinds.push_back(new Street("New York Avenue", 200, 180, 360, 324, 1296, ColorGroup::Orange));
    createGraphicalSlots(19, "New York\nAvenue\n$200", sf::Color(255, 165, 0), window); // Orange
    colors.push_back("Orange");

    kinds.push_back(new FreeParking());
    createGraphicalSlots(20, "Free\nParking", sf::Color::White, window);
    colors.push_back("White");

    kinds.push_back(new Street("Kentucky Avenue", 220, 198, 396, 356, 1426, ColorGroup::Red));
    createGraphicalSlots(21, "Kentucky\nAvenue\n$220", sf::Color::Red, window);
    colors.push_back("Red");

    kinds.push_back(new Chance());
    createGraphicalSlots(22, "Chance", sf::Color(255, 192, 203), window);
    colors.push_back("Pink");

    kinds.push_back(new Street("Indiana Avenue", 220, 198, 396, 356, 1426, ColorGroup::Red));
    createGraphicalSlots(23, "Indiana\nAvenue\n$220", sf::Color::Red, window);
    colors.push_back("Red");

    kinds.push_back(new Street("Illinois Avenue", 240, 216, 432, 389, 1556, ColorGroup::Red));
    createGraphicalSlots(24, "Illinois\nAvenue\n$240", sf::Color::Red, window);
    colors.push_back("Red");

    kinds.push_back(new Train("B&O Railroad", 200));
    createGraphicalSlots(25, "B&O\nRailroad\n$200", sf::Color(211, 211, 211), window);
    colors.push_back("Gray");

    kinds.push_back(new Street("Atlantic Avenue", 260, 234, 468, 421, 1685, ColorGroup::Yellow));
    createGraphicalSlots(26, "Atlantic\nAvenue\n$260", sf::Color::Yellow, window);
    colors.push_back("Yellow");

    kinds.push_back(new Street("Ventnor Avenue", 260, 234, 468, 421, 1685, ColorGroup::Yellow));
    createGraphicalSlots(27, "Ventnor\nAvenue\n$260", sf::Color::Yellow, window);
    colors.push_back("Yellow");

    kinds.push_back(new Utility("Water Works", 150));
    createGraphicalSlots(28, "Water\nWorks\n$150", sf::Color(204, 153, 255), window);
    colors.push_back("Light Purple");

    kinds.push_back(new Street("Marvin Gardens", 280, 252, 504, 454, 1815, ColorGroup::Yellow));
    createGraphicalSlots(29, "Marvin\nGardens\n$280", sf::Color::Yellow, window);
    colors.push_back("Yellow");

    kinds.push_back(new GoToJail());
    createGraphicalSlots(30, "Go to\nJail", sf::Color::White, window);
    colors.push_back("White");

    kinds.push_back(new Street("Pacific Avenue", 300, 270, 540, 486, 1944, ColorGroup::Green));
    createGraphicalSlots(31, "Pacific\nAvenue\n$300", sf::Color::Green, window);
    colors.push_back("Green");

    kinds.push_back(new Street("North Carolina Avenue", 300, 270, 540, 486, 1944, ColorGroup::Green));
    createGraphicalSlots(32, "North\nCarolina\nAvenue\n$300", sf::Color::Green, window);
    colors.push_back("Green");

    kinds.push_back(new CommunityChest());
    createGraphicalSlots(33, "Community\nChest", sf::Color(255, 192, 203), window);
    colors.push_back("Pink");

    kinds.push_back(new Street("Pennsylvania Avenue", 320, 288, 576, 518, 2074, ColorGroup::Green));
    createGraphicalSlots(34, "Pennsy-\nlvania\nAvenue\n$320", sf::Color::Green, window);
    colors.push_back("Green");

    kinds.push_back(new Train("Short Line Railroad", 200));
    createGraphicalSlots(35, "Short Line\nRailroad\n$200", sf::Color(211, 211, 211), window);
    colors.push_back("Gray");

    kinds.push_back(new Chance());
    createGraphicalSlots(36, "Chance", sf::Color(255, 192, 203), window);
    colors.push_back("Pink");

    kinds.push_back(new Street("Park Place", 350, 315, 630, 567, 2268, ColorGroup::Blue));
    createGraphicalSlots(37, "Park\nPlace\n$350", sf::Color::Blue, window);
    colors.push_back("Blue");

    kinds.push_back(new Tax("Luxury Tax", 100));
    createGraphicalSlots(38, "Luxury\nTax\n$100", sf::Color::Red, window);
    colors.push_back("Red");

    kinds.push_back(new Street("Boardwalk", 400, 360, 720, 648, 2592, ColorGroup::Blue));
    createGraphicalSlots(39, "Boardwalk\n$400", sf::Color::Blue, window);
    colors.push_back("Blue");

    // After creating all slotss, add title
    drawTitle(window);
}


void Board::createGraphicalSlots(int i, const std::string &name, sf::Color color, sf::RenderWindow &window)
{
    const int BOARD_WIDTH = 800;
    const int BOARD_HEIGHT = 800;
    const double Slots_SIZE = 73; // Adjusted for 11 slotss

    sf::RectangleShape slotsShape(sf::Vector2f(Slots_SIZE, Slots_SIZE));
    sf::Text slotsText;

    // Load font for the text
    sf::Font font;
    font.loadFromFile("arial.ttf");

    // Set up the slots text
    slotsText.setFont(font);
    slotsText.setString(name);
    slotsText.setCharacterSize(12);
    slotsText.setFillColor(sf::Color::Black);

    // Set the slots's position based on its index (i)
    if (i < 11)
    {
        slotsShape.setPosition(BOARD_WIDTH - (i + 1) * Slots_SIZE+3, BOARD_HEIGHT - Slots_SIZE);
    }
    else if (i < 20)
    {
        slotsShape.setPosition(0, BOARD_HEIGHT - (i - 9) * Slots_SIZE);
    }
    else if (i < 31)
    {
        slotsShape.setPosition((i - 20) * Slots_SIZE, 0);
    }
    else
    {
        slotsShape.setPosition(BOARD_WIDTH - Slots_SIZE+3, (i - 30) * Slots_SIZE-2);
    }

    // Set the slots's color
       slotsShape.setFillColor(color);

    // Position text at the center of the slots
    sf::FloatRect textRect = slotsText.getLocalBounds();
    slotsText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    slotsText.setPosition(slotsShape.getPosition().x + Slots_SIZE / 2, slotsShape.getPosition().y + Slots_SIZE / 2);
    window.draw(slotsShape);  // Draw the rectangle shape
    window.draw(slotsText); // Draw the text on the slots

    // Store the slots and its text
    graphicalSlotss.push_back(std::make_pair(slotsShape, slotsText));
}
void Board::drawTitle(sf::RenderWindow &window)
{
    const int BOARD_WIDTH = 800;
    const int BOARD_HEIGHT = 800;
    const double Slots_SIZE = 73; // Adjusted for 11 slotss
    sf::Font font;
    font.loadFromFile("arial.ttf"); // Load your font

    sf::Text title;
    title.setFont(font);
    title.setString("Monopoly");
    title.setCharacterSize(50); // Large text
    title.setFillColor(sf::Color::Black);
    title.setStyle(sf::Text::Bold);

    // Center the text
    sf::FloatRect textRect = title.getLocalBounds();
    title.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    title.setPosition(BOARD_WIDTH / 2, BOARD_HEIGHT / 2 - 50); // Adjust position

    window.draw(title);
    // Set up the roll dice button
    rollButton = Button(100, 50, "Roll Dice", font, sf::Color::Green, [](){});
    rollButton.setPosition(BOARD_WIDTH / 2 - 50, BOARD_HEIGHT / 2 + 10); // Adjust position
    rollButton.draw(window);

}