//
// Created by Kathleen Nguyen on 12/4/21.
//

#ifndef CATCHASE_BLUE_MUSHROOM_H
#define CATCHASE_BLUE_MUSHROOM_H
#include "FallingObject.h"

class Blue_Mushroom : public FallingObject
{
public:
    Blue_Mushroom();
    static void speedUp(Player& player);
};


#endif //CATCHASE_BLUE_MUSHROOM_H
