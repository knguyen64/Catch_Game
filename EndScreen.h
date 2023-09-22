//
// Created by Kathleen Nguyen on 11/28/21.
//

#ifndef CATCHASE_ENDSCREEN_H
#define CATCHASE_ENDSCREEN_H
#include <SFML/Graphics.hpp>
#include "Files.h"
#include "File.h"
#include "FallingObjects.h"

class EndScreen : public sf::Transformable, public sf::Drawable
{
private:
    sf::Text title, score;
    sf::Sprite background;
public:
    EndScreen();
    EndScreen(sf::Vector2u windowSize);
    void update(int points, sf::Vector2u windowSize);
    bool gameEnded(sf::Clock& clock, FallingObjects& objects, int maxPoints);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CATCHASE_ENDSCREEN_H
