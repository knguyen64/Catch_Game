//
// Created by Kathleen Nguyen on 11/20/21.
//

#ifndef CATCHASE_FALLINGOBJECT_H
#define CATCHASE_FALLINGOBJECT_H
#include <SFML/Graphics.hpp>
#include "File.h"
#include "Files.h"
#include "Player.h"
#include "ObjectName.h"
#include "ObjectCategory.h"

class FallingObject : public sf::Sprite
{
private:
    ObjectName type;
    ObjectCategory category;
    int points;
public:
    FallingObject(ObjectName object);

    ObjectName getType() const;
    File getFileName();
    int getPoints() const;
    ObjectCategory getCategory() const;

    void setPoints(int points);
    void setCategory(ObjectCategory category);

    bool isValidPosition(std::vector<sf::FloatRect> bounds);
    bool intersectsPlayer(Player player);
    void movement();

    friend bool operator==(const FallingObject lhs, const FallingObject rhs);
    friend bool operator!=(const FallingObject lhs, const FallingObject rhs);
};


#endif //CATCHASE_FALLINGOBJECT_H
