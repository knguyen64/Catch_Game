//
// Created by Kathleen Nguyen on 12/4/21.
//

#ifndef CATCH_BLUE_MUSHROOM_H
#define CATCH_BLUE_MUSHROOM_H
#include "FallingObject.h"

class Blue_Mushroom : public FallingObject
{
public:
    Blue_Mushroom();
    static void speedUp(Player& player);
};


#endif //CATCH_BLUE_MUSHROOM_H
