//
// Created by Kathleen Nguyen on 11/26/21.
//

#include "CatchGame.h"

CatchGame::CatchGame()
{

}

void CatchGame::run()
{
    sf::RenderWindow window(sf::VideoMode(2560, 1600, 75), "Catch Game");
    window.setFramerateLimit(75);
    window.setKeyRepeatEnabled(false);

    int maxPoints = 5000;
    sf::Clock clock;
    Player player;
    Score scores;
    FallingObjects objects;

    Gauge gauge(maxPoints);
    PowerUp powerUps;

    EndScreen endScreen(window.getSize());
    TitleScreen titleScreen(window.getSize());

    Background background;
    Platforms platforms;
    platforms.addPlatform(0, 1300, 20,30);
    platforms.addPlatform(300, 900, 3, 3);
    platforms.addPlatform(1600, 900, 3, 3);

    enableState(TITLE_SCREEN);
    disableState(END_SCREEN);

    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            if(isEnabled(TITLE_SCREEN))
                titleScreen.eventHandler(window, event);
        }
        window.clear(sf::Color::Black);
        if(isEnabled(TITLE_SCREEN))
        {
            titleScreen.update();
            if(titleScreen.ended())
                disableState(TITLE_SCREEN);
            window.draw(titleScreen);

        } else if(!isEnabled(END_SCREEN))
        {
            ////Player Movement
            player.controls(window);
            player.checkBounds(platforms.getBounds());

            ////Score Gauge
            gauge.update(scores);

            ////Falling Objects
            objects.addObject(RANDOM);

            ////Update Object movement and count
            objects.fall(player, platforms);
            objects.impact(player);
            objects.update(player, scores, powerUps, maxPoints);

            ////Update Power Ups
            powerUps.eventHandler(window, event);
            powerUps.update(player);

            window.draw(background);
            window.draw(objects);
            window.draw(platforms);
            window.draw(player);
            window.draw(gauge);
            window.draw(powerUps);

            ////Update Screen
            if(endScreen.gameEnded(clock, objects, maxPoints))
                enableState(END_SCREEN);
        } else if (isEnabled(END_SCREEN))
        {
            endScreen.update(scores.getScore(),window.getSize());
            window.draw(endScreen);
        }
        window.display();
    }
}