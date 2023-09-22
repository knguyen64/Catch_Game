//
// Created by Kathleen Nguyen on 12/4/21.
//

#include "Blue_Mushroom.h"

Blue_Mushroom::Blue_Mushroom() : FallingObject(BLUE_MUSHROOM)
{
    setCategory(POWER_UP);
}

void Blue_Mushroom::speedUp(Player &player)
{
    player.setDistanceMultiplier(2);
}
