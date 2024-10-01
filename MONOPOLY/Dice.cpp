#include "Dice.hpp"
#include <iostream>

// קונסטרקטור של הקוביה, יוצר את הכפתור עם פונקציונליות של קוביה
Dice::Dice(float size, sf::Font &font, const sf::Color &color)
    : Button(size, font, color), gen(rd()), dis(1, 6) // אתחול הגנרטור והטווח
{
    // קוביה מתחילה עם הערך 1
    currentValue = 1;
    text.setString(std::to_string(currentValue)); // עדכון הטקסט בקוביה לערך ההתחלתי
}

// פונקציה שמגרילה מספר אקראי ומעדכנת את הערך של הקוביה
void Dice::roll() {
    currentValue = dis(gen); // מגריל מספר בין 1 ל-6
    text.setString(std::to_string(currentValue));
}