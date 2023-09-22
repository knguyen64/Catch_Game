//
// Created by Kathleen Nguyen on 11/27/21.
//

#include "PowerUp.h"
PowerUp::PowerUp()
{
    music.openFromFile("smb_powerup.wav");
}

void PowerUp::editPowerUps(FallingObject& object)
{
    if(powerUps.size() < 2)
    {
        powerUps.push(object);
        display.update(powerUps);
    }
}

void PowerUp::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !powerUps.empty() && (clock.getElapsedTime().asSeconds() > 5
       || !firstTime2))
    {
        enableState(ACTIVATED_POWER_UP);
        activatedPowerUp = powerUps.pop().getType();
        display.update(powerUps);
        firstTime2 = true;
        clock.restart();
        if(music.getStatus() != sf::SoundSource::Playing)
            music.play();
    }
    if(music.getStatus() != sf::SoundSource::Playing)
        music.stop();
}

void PowerUp::update(Player &player)
{
    if(isEnabled(ACTIVATED_POWER_UP))
    {
        if(clock.getElapsedTime().asSeconds() > 5)
        {
            disableState(ACTIVATED_POWER_UP);
            player.resetPlayer();
        }
        if(isEnabled(ACTIVATED_POWER_UP))
        {
            if(activatedPowerUp == MEGA_MUSHROOM)
                Mega_Mushroom::growPlayer(player);
            else if (activatedPowerUp == BLUE_MUSHROOM)
                Blue_Mushroom::speedUp(player);
        }
    }
}

void PowerUp::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(display, states);
}
