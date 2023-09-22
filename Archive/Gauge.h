//
// Created by Kathleen Nguyen on 11/27/21.
//

#ifndef CATCHASE_GAUGE_H
#define CATCHASE_GAUGE_H
#include <SFML/Graphics.hpp>
#include "Score.h"

class Gauge : public sf::Drawable
{
private:
    sf::RectangleShape outer;
    sf::RectangleShape inner;
    float multiplier;

public:
    Gauge(int maxPoints);
    void update(Score score);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CATCHASE_GAUGE_H
