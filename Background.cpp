//
// Created by Kathleen Nguyen on 11/28/21.
//

#include "Background.h"

Background::Background()
{
    setTexture(Files<File,sf::Texture>::getFile(BACKGROUND));
    setScale(3,3);
}
