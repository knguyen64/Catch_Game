//
// Created by Kathleen Nguyen on 11/20/21.
//

#ifndef CATCHASE_SCORE_H
#define CATCHASE_SCORE_H
#include <SFML/Graphics.hpp>
#include "FallingObject.h"
#include "States.h"
#include "Stack.h"

class Score : public States
{
private:
    Stack<FallingObject> scores;
    int score = 0;

public:
    Score();

    int getScore();
    const Stack<FallingObject> &getScores() const;
    void editScore(FallingObject &object, int maxPoints);
};


#endif //CATCHASE_SCORE_H
