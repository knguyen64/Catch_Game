//
// Created by Kathleen Nguyen on 11/17/21.
//
#ifndef CATCHASE_FILES_CPP
#define CATCHASE_FILES_CPP

#include "Files.h"
template <class T, class S>
std::map<T, S> Files<T, S>::files;

template <class T, class S>
std::string Files<T, S>::getFilePath(T fileName)
{
    switch(fileName)
    {
        case PLAYER_RUNNING: return "Player/PlayerRunning.png";
        case PLAYER_JUMPING: return "Player/PlayerJumping.png";
        case PLATFORM: return "Platform.png";
        case MUSHROOM_FILE: return "Red_Mushroom.png";
        case POISON_MUSHROOM_FILE: return "Poison_Mushroom.png";
        case MEGA_MUSHROOM_FILE: return "Mega_Mushroom.png";
        case GREEN_MUSHROOM_FILE: return "Green_Mushroom.png";
        case BLUE_MUSHROOM_FILE: return "Blue_Mushroom.png";
        case BACKGROUND: return "Background.jpeg";
        case LETTERING: return "Lettering.otf";
        case MENLO: return "Menlo.ttc";
        case NOTHING_FILE: return "Transparent.png";
        case TITLE_FONT: return "ALBAS___.TTF";
        case GAME_PREVIEW: return "Game_Preview.png";
    }
    return std::string();
}

template <class T, class S>
void Files<T, S>::loadFile(T fileName)
{
    files[fileName].loadFromFile(getFilePath(fileName));
}

template <class T, class S>
S& Files<T, S>::getFile(T fileName)
{
    loadFile(fileName);
    return files[fileName];
}
#endif //CATCHASE_FILES_CPP
