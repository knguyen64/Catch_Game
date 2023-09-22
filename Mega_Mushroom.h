//
// Created by Kathleen Nguyen on 11/20/21.
//

#ifndef CATCHASE_MEGA_MUSHROOM_H
#define CATCHASE_MEGA_MUSHROOM_H
#include "FallingObject.h"
#include <iostream>

class Mega_Mushroom : public FallingObject
{
public:
    Mega_Mushroom();
    static void growPlayer(Player& player);
};


#endif //CATCHASE_MEGA_MUSHROOM_H
