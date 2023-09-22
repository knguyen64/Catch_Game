//
// Created by Kathleen Nguyen on 11/28/21.
//

#ifndef CATCHASE_BACKGROUND_H
#define CATCHASE_BACKGROUND_H
#include <SFML/Graphics.hpp>
#include "States.h"
#include "Files.h"

class Background : public sf::Sprite, public States
{
public:
    Background();
};


#endif //CATCHASE_BACKGROUND_H
