//
// Created by Kathleen Nguyen on 11/14/21.
//

#include "Platform.h"

Platform::Platform()
{
    setTexture(Files<File,sf::Texture>::getFile(PLATFORM));
}