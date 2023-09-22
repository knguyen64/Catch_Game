//
// Created by Kathleen Nguyen on 11/13/21.
//

#ifndef CATCHASE_PLAYER_H
#define CATCHASE_PLAYER_H
#include "Animation.h"
#include "States.h"
#include "Files.h"
#include <vector>

class Player : public sf::Sprite, public States
{
private:
    sf::IntRect box;
    Animation<Player> animation;
    sf::Clock clock, scaleClock;
    int imageCount, distanceMultiplier = 1, reset = 1;
    float offsetX = 0, offsetY = 0, jumpHeight = 0, scaleX = 1, scaleY = 1;
    sf::RectangleShape L, R, T, B;

public:
    Player();
    void setOffset(sf::RenderWindow& window);
    void setBounds();
    void setBox();
    void setDistanceMultiplier(int distanceMultiplier);
    void scale(float x, float y);
    void setScaleSize(float scaleX, float scaleY);
    bool isWithinWindow(sf::RenderWindow& window);
    void flipTexture();
    void movePlayer(float offsetX, float offsetY);
    void controls(sf::RenderWindow& window);
    void jump(sf::RenderWindow& window);
    void isColliding(sf::FloatRect boundsRect);
    void checkBounds(std::vector<sf::FloatRect> bounds);
    void resetPlayer();
};


#endif //CATCHASE_PLAYER_H
