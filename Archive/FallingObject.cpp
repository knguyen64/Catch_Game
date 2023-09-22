//
// Created by Kathleen Nguyen on 11/20/21.
//

#include "FallingObject.h"
#include <cstdlib>
#include <ctime>

FallingObject::FallingObject(ObjectName object) : type(object)
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);

   switch(object)
   {
       case RED_MUSHROOM: setTexture(Files<File,sf::Texture>::getFile(MUSHROOM_FILE)); break;
       case POISON_MUSHROOM: setTexture(Files<File,sf::Texture>::getFile(POISON_MUSHROOM_FILE)); break;
       case MEGA_MUSHROOM: setTexture(Files<File,sf::Texture>::getFile(MEGA_MUSHROOM_FILE)); break;
       case GREEN_MUSHROOM: setTexture(Files<File, sf::Texture>::getFile(GREEN_MUSHROOM_FILE)); break;
       case BLUE_MUSHROOM: setTexture(Files<File, sf::Texture>::getFile(BLUE_MUSHROOM_FILE)); break;
       case NOTHING: setTexture(Files<File, sf::Texture>::getFile(NOTHING_FILE)); break;
   }
   setPosition(rand()% 2260 + 100, 0);
   setScale(.1,.1);
}

bool FallingObject::isValidPosition(std::vector<sf::FloatRect> bounds)
{
    for(int i=0; i < bounds.size(); i++)
    {
        if(bounds[i].intersects(getGlobalBounds()))
        {
            setColor(sf::Color::Transparent);
            return false;
        }
    }
    return true;
}

void FallingObject::movement()
{
    move(0, 10);
}

bool FallingObject::intersectsPlayer(Player player)
{

    if(player.getGlobalBounds().intersects(getGlobalBounds()))
    {
        setColor(sf::Color::Transparent);
        return true;
    }

    return false;
}

ObjectName FallingObject::getType() const{
    return type;
}

int FallingObject::getPoints() const {
    return points;
}

void FallingObject::setPoints(int points) {
    FallingObject::points = points;
}

bool operator==(const FallingObject lhs, const FallingObject rhs)
{
    return (lhs.getPoints() == rhs.getPoints() && lhs.getType() == rhs.getType());
}

bool operator!=(const FallingObject lhs, const FallingObject rhs)
{
    return (lhs.getPoints() != rhs.getPoints() && lhs.getType() != rhs.getType());
}

ObjectCategory FallingObject::getCategory() const {
    return category;
}

void FallingObject::setCategory(ObjectCategory category) {
    FallingObject::category = category;
}

File FallingObject::getFileName()
{
    switch(type)
    {
        case RED_MUSHROOM: return MUSHROOM_FILE;
        case POISON_MUSHROOM: return POISON_MUSHROOM_FILE;
        case MEGA_MUSHROOM: return MEGA_MUSHROOM_FILE;
        case GREEN_MUSHROOM: return GREEN_MUSHROOM_FILE;
        case BLUE_MUSHROOM: return BLUE_MUSHROOM_FILE;
    }
}

