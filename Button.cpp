//
// Created by Kathleen Nguyen on 11/17/21.
//

#include "Button.h"


Button::Button() : Button("OK", sf::Color::White, sf::Color::Blue, {50,10})
{

}

Button::Button(std::string text) :  Button(text, sf::Color::White, sf::Color::Blue, {50,10})
{

}

Button::Button(std::string text, sf::Color color, sf::Color textColor, sf::Vector2f size)
{
    disableState(CLICKED);
    this->text.setFont(Files<File,sf::Font>::getFile(TITLE_FONT));
    this->text.setFillColor(textColor);
    this->text.setString(text);
    this->text.setCharacterSize(120);
    this->text.setOrigin(text.size()/2, text.size()/2);

    background.setSize(size);
    background.setFillColor(color);
    background.setOrigin(background.getGlobalBounds().width/2,background.getGlobalBounds().height/2);
    background.setOutlineThickness(5);
    background.setOutlineColor({254,180,70, 200});
    music.openFromFile("mixkit-video-game-retro-click-237.wav");
}

void Button::move(float x, float y)
{
    background.move(x, y);
    sf::FloatRect bb = background.getGlobalBounds();
    sf::FloatRect tb = this->text.getGlobalBounds();
    this->text.setPosition(bb.left + bb.width/2-tb.width/2 - 10, bb.top + bb.height/2-tb.height/2-30);
}
void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(background);
    window.draw(text, states);
}

void Button::eventHandler(sf::RenderWindow& window, sf::Event event)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    if(background.getGlobalBounds().contains(mpos))
    {
        enableState(HOVERED);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            enableState(CLICKED);
            if(music.getStatus() != sf::SoundSource::Playing)
                music.play();
        }
        else
        {
            disableState(CLICKED);
            music.stop();
        }
    }
    else
        disableState(HOVERED);
}
#include <iostream>
void Button::update()
{
    if(isEnabled(HOVERED))
    {
        background.setScale(1.1,1.1);
        text.setScale(1.1,1.1);
    }
    else
    {
        background.setScale(1,1);
        text.setScale(1,1);
    }
}

bool Button::isClicked()
{
    if(isEnabled(CLICKED))
        return true;
}
