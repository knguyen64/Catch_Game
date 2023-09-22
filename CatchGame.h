//
// Created by Kathleen Nguyen on 11/26/21.
//

#ifndef CATCHASE_CATCHGAME_H
#define CATCHASE_CATCHGAME_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platforms.h"
#include "FallingObject.h"
#include "FallingObjects.h"
#include "Score.h"
#include "Gauge.h"
#include "PowerUp.h"
#include "Background.h"
#include "States.h"
#include "EndScreen.h"
#include "TitleScreen.h"

class CatchGame : public States
{
public:
    CatchGame();
    void run();
};


#endif //CATCHASE_CATCHGAME_H
