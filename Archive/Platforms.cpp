//
// Created by Kathleen Nguyen on 11/27/21.
//

#include "Platforms.h"
Platforms::Platforms()
{

}
void Platforms::addPlatform(float posX, float posY, float scaleX, float scaleY)
{
    Platform platform;
    platform.scale(.5, .5);
    platform.move(posX, posY);
    platform.scale(scaleX, scaleY);

    platforms.push_back(platform);
    bounds.push_back(platform.getGlobalBounds());
}

std::vector<sf::FloatRect> &Platforms::getBounds()
{
    return bounds;
}

void Platforms::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    for(int i=0; i < platforms.size(); i++)
        window.draw(platforms[i]);
}
