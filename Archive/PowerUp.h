//
// Created by Kathleen Nguyen on 11/27/21.
//

#ifndef CATCHASE_POWERUP_H
#define CATCHASE_POWERUP_H
#include <SFML/Audio.hpp>
#include "Queue.h"
#include "States.h"
#include "FallingObject.h"
#include "Mega_Mushroom.h"
#include "Blue_Mushroom.h"
#include "PowerUpDisplay.h"

class PowerUp : public States, public sf::Drawable
{
private:
    sf::Clock clock;
    ObjectName activatedPowerUp;
    Queue<FallingObject> powerUps;
    PowerUpDisplay display;
    bool firstTime,firstTime2;
    sf::Music music;

public:
    PowerUp();
    void editPowerUps(FallingObject& object);
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    void update(Player&  player);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CATCHASE_POWERUP_H
