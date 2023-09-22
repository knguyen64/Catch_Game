//
// Created by Kathleen Nguyen on 12/4/21.
//

#include "TitleScreen.h"

TitleScreen::TitleScreen() {

}

TitleScreen::TitleScreen(sf::Vector2u windowSize)
: start("Start", sf::Color::White, sf::Color::Red, {500,150})

{
    background.setTexture(Files<File,sf::Texture>::getFile(BACKGROUND));
    background.setScale(3.2,3.2);

    title.setFont(Files<File,sf::Font>::getFile(TITLE_FONT));
    title.setFillColor({200,0,20});
    title.setCharacterSize(350);
    title.setString("Catch");

    info.setFont(Files<File,sf::Font>::getFile(MENLO));
    info.setFillColor(sf::Color::White);
    info.setOutlineThickness(1);
    info.setOutlineColor(sf::Color::Black);
    info.setCharacterSize(32);
    info.setString("Developed by Kathleen Nguyen\nCS 3A - Fundamentals of Computer Science II\nCRN - 76408\nFall 2021");
    info.setPosition(10,5);

    gamePreview.setTexture(Files<File,sf::Texture>::getFile(GAME_PREVIEW));
    gamePreview.setOrigin(gamePreview.getGlobalBounds().width/2, gamePreview.getGlobalBounds().height/2);
    gamePreview.setPosition(windowSize.x / 2, windowSize.y / 2 + 100);
    gamePreview.setScale(.8,.8);

    outline.setSize({gamePreview.getGlobalBounds().width + 10, gamePreview.getGlobalBounds().height + 10});
    outline.setOrigin(outline.getGlobalBounds().width/2, outline.getGlobalBounds().height/2);
    outline.setPosition(windowSize.x / 2, windowSize.y / 2 + 100);

    sf::FloatRect tb = title.getGlobalBounds();
    title.setPosition(windowSize.x / 2 - tb.width/2, windowSize.y / 2 - 750);

    start.move(windowSize.x/2, windowSize.y/2 + 570);
}

void TitleScreen::eventHandler(sf::RenderWindow& window, sf::Event event)
{
    start.eventHandler(window, event);
}

void TitleScreen::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(background);
    window.draw(outline);
    window.draw(gamePreview);
    window.draw(title);
    window.draw(info);
    window.draw(start);
}

void TitleScreen::update()
{
    start.update();
}

bool TitleScreen::ended()
{
    if(start.isClicked())
        return true;
}
