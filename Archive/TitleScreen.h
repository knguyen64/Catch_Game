//
// Created by Kathleen Nguyen on 12/4/21.
//

#ifndef CATCHASE_TITLESCREEN_H
#define CATCHASE_TITLESCREEN_H
#include <SFML/Graphics.hpp>
#include "Files.h"
#include "File.h"
#include "Button.h"

class TitleScreen : public sf::Transformable, public sf::Drawable
{
private:
    sf::Text title, info;
    sf::Sprite background, gamePreview;
    sf::RectangleShape outline;
    Button start;
public:
    TitleScreen();
    TitleScreen(sf::Vector2u windowSize);
    void update();
    bool ended();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CATCHASE_TITLESCREEN_H
