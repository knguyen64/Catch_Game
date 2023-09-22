//
// Created by Kathleen Nguyen on 11/27/21.
//

#ifndef CATCHASE_PLATFORMS_H
#define CATCHASE_PLATFORMS_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platform.h"

class Platforms : public sf::Drawable
{
private:
    std::vector<Platform> platforms;
    std::vector<sf::FloatRect> bounds;
public:
    Platforms();
    std::vector<sf::FloatRect> &getBounds();
    void addPlatform(float posX, float posY, float scaleX, float scaleY);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CATCHASE_PLATFORMS_H
