//
// Created by Kathleen Nguyen on 11/20/21.
//

#include "Score.h"
Score::Score()
{

}

const Stack<FallingObject> &Score::getScores() const {
    return scores;
}

void Score::editScore(FallingObject &object, int maxPoints)
{
    if(object.getType() != POISON_MUSHROOM)
    {
        if(getScore() + object.getPoints() > maxPoints)
            object.setPoints(maxPoints-getScore());
        scores.push(object);
    }
    else if(object.getType() == POISON_MUSHROOM && !scores.empty())
    {
        for(int i=0; i < 3 && !scores.empty(); i++)
            scores.pop();
    }
}

int Score::getScore()
{
    score = 0;
    for(int i=0; i < scores.size(); i++)
        score += scores.peek(i).getPoints();

    return score;
}