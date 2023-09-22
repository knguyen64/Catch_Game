//
// Created by Kathleen Nguyen on 11/28/21.
//

#include "EndScreen.h"

EndScreen::EndScreen()
{

}

EndScreen::EndScreen(sf::Vector2u windowSize)
{
    background.setTexture(Files<File,sf::Texture>::getFile(BACKGROUND));
    background.setScale(3.2,3.2);

    title.setFont(Files<File,sf::Font>::getFile(LETTERING));
    title.setCharacterSize(300);
    title.setString("SCORE");
    sf::FloatRect tb = title.getGlobalBounds();
    title.setPosition(windowSize.x / 2 - tb.width/2, windowSize.y / 2 - 500);
}

void EndScreen::update(int points, sf::Vector2u windowSize)
{
    score.setFont(Files<File,sf::Font>::getFile(MENLO));
    score.setCharacterSize(250);
    score.setString(std::to_string(points));
    sf::FloatRect sb = score.getGlobalBounds();
    score.setPosition(windowSize.x / 2 - sb.width/2, windowSize.y / 2 - sb.height/2);
}

void EndScreen::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(background);
    window.draw(title);
    window.draw(score);
}

bool EndScreen::gameEnded(sf::Clock& clock, FallingObjects& objects, int maxPoints)
{
    if(clock.getElapsedTime().asSeconds() >= 120 || objects.getTotalPoints() > maxPoints)
        return true;
}
