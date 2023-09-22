//
// Created by Kathleen Nguyen on 11/16/21.
//

#include "States.h"
bool States::isEnabled(State state)
{
    return states[state];
}

void States::enableState(State state)
{
    states[state] = true;
}

void States::disableState(State state)
{
    states[state] = false;
}
