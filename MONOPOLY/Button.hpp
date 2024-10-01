
#ifndef Button_HPP
#define Button_HPP

#include <SFML/Graphics.hpp>
#include <random>
#include <functional>
#include <string>

class Button {

    private:
    sf::RectangleShape shape;                                 // Button's shape
    sf::Text text;                                            // The text on the Button
    sf::Font &font;                                           // Font of the text
    sf::Color color;                                          // Color
    int currentValue;                                         // The current value of the Button

public:
    Button();
    Button(float size, sf::Font &font, const sf::Color &color); 
    void draw(sf::RenderWindow &window);                      // מצייר את הקוביה
    void setPosition(float x, float y);                       // מגדיר מיקום הקוביה
    bool isMouseOver(sf::RenderWindow &window);               // בודק אם העכבר מעל הקוביה
    bool isClicked(sf::RenderWindow &window);                 // בודק אם לחצו על הקוביה
   
    
};
