//
// Created by Kathleen Nguyen on 11/27/21.
//

#include "FallingObjects.h"
FallingObjects::FallingObjects()
{
    buffer.loadFromFile("mixkit-retro-arcade-casino-notification-211.wav");
    music.setBuffer(buffer);
}

void FallingObjects::addObject(ObjectName object)
{
    srand(time(0));
    if(clock.getElapsedTime().asMilliseconds() > (rand()%1050+700))
    {
        switch(object)
        {
            case RED_MUSHROOM:
                objects.push_back(Red_Mushroom());
                totalPoints += Red_Mushroom().getPoints();
                break;
            case MEGA_MUSHROOM:
                objects.push_back(Mega_Mushroom());
                break;
            case POISON_MUSHROOM:
                objects.push_back(Poison_Mushroom());
                break;
            case GREEN_MUSHROOM:
                objects.push_back(Green_Mushroom());
                totalPoints += Green_Mushroom().getPoints();
                break;
            case BLUE_MUSHROOM:
                objects.push_back(Blue_Mushroom());
                break;
            case RANDOM:
                struct timespec ts;
                clock_gettime(CLOCK_MONOTONIC, &ts);
                srand((time_t)ts.tv_nsec);
                int num = rand()%100;
                if(num <= 30)
                    object = ObjectName(RED_MUSHROOM);
                else if (num <= 60)
                    object = ObjectName(GREEN_MUSHROOM);
                else if(num <= 80)
                    object = ObjectName(POISON_MUSHROOM);
                else if(num <= 90)
                    object = ObjectName(MEGA_MUSHROOM);
                else if(num <= 100)
                    object = ObjectName(BLUE_MUSHROOM);
                addObject(object);
                break;
        }
        clock.restart();
    }
}

void FallingObjects::fall(Player player, Platforms platforms)
{
    for(int i=0; i < objects.size(); i++)
    {
        if(objects[i].isValidPosition(platforms.getBounds()))
            objects[i].movement();
        else
            objects.erase(objects.begin()+i);
    }
}

std::vector<FallingObject> &FallingObjects::getObjects() {
    return objects;
}

int FallingObjects::size() const{
    return objects.size();
}

void FallingObjects::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    for(int i=0; i < size(); i++)
        window.draw(objects[i]);
}

int FallingObjects::getTotalPoints() const {
    return totalPoints;
}

void FallingObjects::impact(Player player)
{
    disableState(INTERSECTED);

    for(int i=0; i < objects.size(); i++)
    {
        if(objects[i].intersectsPlayer(player))
        {
            enableState(INTERSECTED);
            music.stop();
            if(music.getStatus() != sf::SoundSource::Status::Playing)
                music.play();
        }
    }

}

void FallingObjects::update(Player& player, Score& score, PowerUp& powerUps, int maxPoints)
{
    for(int i=0; i < objects.size() && isEnabled(INTERSECTED); i++)
    {
        if(objects[i].intersectsPlayer(player))
        {
            if(objects[i].getCategory() == POINTS)
                score.editScore(objects[i], maxPoints);
            else if(objects[i].getCategory() == POWER_UP)
                powerUps.editPowerUps(objects[i]);
            objects.erase(objects.begin()+i);
        }
    }
}