//
// Created by Kathleen Nguyen on 11/27/21.
//

#ifndef CATCHASE_FALLINGOBJECTS_H
#define CATCHASE_FALLINGOBJECTS_H
#include "FallingObject.h"
#include "Red_Mushroom.h"
#include "Mega_Mushroom.h"
#include "Poison_Mushroom.h"
#include "Green_Mushroom.h"
#include "Blue_Mushroom.h"
#include "ObjectName.h"
#include "Platforms.h"
#include "States.h"
#include "Score.h"
#include "PowerUp.h"

class FallingObjects : public States, public sf::Drawable
{
private:
    sf::Clock clock;
    std::vector<FallingObject> objects;
    int totalPoints = 0;
    sf::Sound music;
    sf::SoundBuffer buffer;
public:
    FallingObjects();
    int size() const;
    int getTotalPoints() const;
    std::vector<FallingObject> &getObjects();
    void addObject(ObjectName object);
    void fall(Player player, Platforms platforms);
    void impact(Player player);
    void update(Player&  player, Score& score, PowerUp& powerUps, int maxPoints);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CATCHASE_FALLINGOBJECTS_H
