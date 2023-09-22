//
// Created by Kathleen Nguyen on 11/20/21.
//

#include "Mega_Mushroom.h"

Mega_Mushroom::Mega_Mushroom() : FallingObject(MEGA_MUSHROOM)
{
    setCategory(POWER_UP);
}

void Mega_Mushroom::growPlayer(Player& player)
{
    player.scale(1.5f,1.5f);
}