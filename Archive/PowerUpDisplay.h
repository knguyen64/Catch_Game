//
// Created by Kathleen Nguyen on 12/4/21.
//

#ifndef CATCHASE_POWERUPDISPLAY_H
#define CATCHASE_POWERUPDISPLAY_H
#include <SFML/Graphics.hpp>
#include "FallingObject.h"
#include "Queue.h"

class PowerUpDisplay : public sf::Drawable, public sf::Transformable
{
private:
    Queue<FallingObject> powerUps;
    FallingObject powerUp1, powerUp2;
    sf::CircleShape circle1, circle2;

public:
    PowerUpDisplay();
    void update(Queue<FallingObject>& powerUps);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CATCHASE_POWERUPDISPLAY_H
