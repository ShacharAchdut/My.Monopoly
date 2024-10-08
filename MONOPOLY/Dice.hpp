#ifndef DICE_HPP
#define DICE_HPP

#include <random>

class Dice : public Button {
private:
    std::random_device rd;                                    // ליצירת מספרים אקראיים
    std::mt19937 gen;                                         // גנרטור של מספרים אקראיים
    std::uniform_int_distribution<> dis;                      // תחום ההגרלה: 1 עד 6

public:
    Dice(float size, sf::Font &font, const sf::Color &color); // קונסטרקטור
    void roll();                                              // פונקציה שמגרילה מספר אקראי
};

#endif // DICE_HPP
