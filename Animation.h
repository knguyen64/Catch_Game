//
// Created by Kathleen Nguyen on 11/10/21.
//
//

#ifndef CATCHASE_ANIMATION_H
#define CATCHASE_ANIMATION_H
#include <SFML/Graphics.hpp>
#include <vector>

template <class T>
class Animation : public sf::Transformable
{
private:
    int spriteTurn = 0;
    sf::Clock clock;
    sf::IntRect box;

public:
    Animation();
    Animation(sf::IntRect box);
    void animate(T& image, int pauseTime, int imageCount);
};
#include "Animation.cpp"
#endif //CATCHASE_ANIMATION_H