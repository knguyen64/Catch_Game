//
// Created by Kathleen Nguyen on 11/10/21.
//
#ifndef CATCHASE_ANIMATION_CPP
#define CATCHASE_ANIMATION_CPP
#include "Animation.h"
#include <iostream>


template <class T>
Animation<T>::Animation()
{

}

template <class T>
Animation<T>::Animation(sf::IntRect box) : box(box)
{

}

template <class T>
void Animation<T>::animate(T& image, int pauseTime, int imageCount)
{
    if(spriteTurn >= imageCount)
        spriteTurn = 0;
    else
        spriteTurn++;

    if(clock.getElapsedTime().asMilliseconds() > pauseTime)
    {
        box.left = box.width * spriteTurn;
        clock.restart();
    }

    if(box.left >= box.width * imageCount)
        box.left = 0;

    image.setTextureRect(box);
}

#endif //CATCHASE_ANIMATION_CPP

