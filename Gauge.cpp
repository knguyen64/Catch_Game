//
// Created by Kathleen Nguyen on 11/27/21.
//

#include "Gauge.h"

Gauge::Gauge(int maxPoints)
{
    outer.setPosition(50, 50);
    outer.setSize({75, 1200});
    outer.setOutlineColor({254,180,70, 200});
    outer.setOutlineThickness(4);
    multiplier = (outer.getSize().y-(10*2))/maxPoints;

    inner.setScale(1.0, -1.0);
    inner.setPosition(60, 1245);
    inner.setSize({55, 0});
    inner.setFillColor({254,180,50, 200});
}

void Gauge::update(Score score)
{
    inner.setSize({55, score.getScore()*multiplier});
}

void Gauge::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(outer);
    window.draw(inner);
}
