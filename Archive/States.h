//
// Created by Kathleen Nguyen on 11/16/21.
//

#ifndef CATCHASE_STATES_H
#define CATCHASE_STATES_H
#include "State.h"

class States {
private:
    bool states[LAST];
public:
    bool isEnabled(State state);
    void enableState(State state);
    void disableState(State state);
};


#endif //CATCHASE_STATES_H
