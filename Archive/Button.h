//
// Created by Kathleen Nguyen on 11/17/21.
//

#ifndef CATCHASE_BUTTON_H
#define CATCHASE_BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "States.h"
#include "Files.h"
#include "File.h"

class Button :public States, public sf::Transformable, public sf::Drawable
{
private:
    sf::RectangleShape background;
    sf::Text text;
    sf::Music music;

public:
    Button();
    Button(std::string text);
    Button(std::string text, sf::Color color, sf::Color textColor, sf::Vector2f size);

    void move(float x, float y);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    bool isClicked();
};


#endif //CATCHASE_BUTTON_H
