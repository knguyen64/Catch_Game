//
// Created by Kathleen Nguyen on 12/4/21.
//

#include "PowerUpDisplay.h"

PowerUpDisplay::PowerUpDisplay() : powerUp1(NOTHING), powerUp2(NOTHING)
{
    circle1.setOrigin(circle1.getRadius(), circle1.getRadius());
    circle1.setRadius(100);
    circle1.setPosition(2320,1350);


    circle2.setOrigin(circle1.getRadius(), circle1.getRadius());
    circle2.setRadius(80);
    circle2.setPosition(2300,1410);


    powerUp1.setScale(0.12, 0.12);
    powerUp1.setOrigin(powerUp1.getGlobalBounds().width/2, powerUp1.getGlobalBounds().height/2);
    powerUp1.setPosition(38, 38);

    powerUp2.setScale(0.1, 0.1);
    powerUp2.setOrigin(powerUp2.getGlobalBounds().width/2, powerUp2.getGlobalBounds().height/2);
    powerUp2.setPosition(29, 29);
}

void PowerUpDisplay::update(Queue<FallingObject>& powerUps)
{
    powerUp1.setTexture(Files<File, sf::Texture>::getFile(NOTHING_FILE));
    powerUp2.setTexture(Files<File, sf::Texture>::getFile(NOTHING_FILE));

    if(powerUps.size() >= 1)
        powerUp1.setTexture(Files<File, sf::Texture>::getFile(powerUps.getItem(0).getFileName()));

    if(powerUps.size() >= 2)
        powerUp2.setTexture(Files<File, sf::Texture>::getFile(powerUps.getItem(1).getFileName()));
}

void PowerUpDisplay::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(circle1);
    window.draw(circle2);

    states = circle1.getTransform();
    window.draw(powerUp1, states);

    states = circle2.getTransform();
    window.draw(powerUp2, states);
}