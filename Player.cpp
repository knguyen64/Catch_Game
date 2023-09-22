//
// Created by Kathleen Nguyen on 11/13/21.
//

#include "Player.h"

Player::Player()
{
    setTexture(Files<File,sf::Texture>::getFile(PLAYER_RUNNING));
    disableState(JUMPED);
    setPosition({500,1000});
    imageCount = 8;

    setBox();
    Player::animation = {box};

    setTextureRect(box);
}

void Player::controls(sf::RenderWindow& window)
{
    flipTexture();
    setOffset(window);

    if(isWithinWindow(window))
        enableState(VALID_POSITION);
    else
        disableState(VALID_POSITION);

    if(clock.getElapsedTime().asMilliseconds() >= 10)
    {
        setTexture(Files<File,sf::Texture>::getFile(PLAYER_RUNNING));
        imageCount = 8;

        if(isEnabled(COLLIDED_T) && offsetY > 0)
            offsetY = 30;
        if (isEnabled(COLLIDED_B) && offsetY > 0)
            offsetY = 0;
        if((isEnabled(COLLIDED_L) && offsetX < 0) || (isEnabled(COLLIDED_R) && offsetX > 0))
            offsetX = 0;

        if(offsetX == 0 && offsetY == 0)
            setTextureRect(box);
        else if (isEnabled(VALID_POSITION) || getPosition().y + offsetY < box.height)
        {
            if(isEnabled(JUMPED))
            {
                setTexture(Files<File,sf::Texture>::getFile(PLAYER_JUMPING));
                imageCount = 3;
                jump(window);
            } else if(offsetY > 0)
            {
                setTexture(Files<File,sf::Texture>::getFile(PLAYER_JUMPING));
                imageCount = 3;
                animation.animate(*this, 20, imageCount);
            }
            else
                animation.animate(*this, 40, imageCount);

            movePlayer(offsetX, offsetY);
            clock.restart();

        } else
        {
            animation.animate(*this, 40, imageCount);
            clock.restart();
        }
        setBounds();

        State arr[] = {COLLIDED_L, COLLIDED_R, COLLIDED_T, COLLIDED_B};
        for(int i=0; i < 4; i++)
            disableState(arr[i]);
    }
}

void Player::setBounds()
{
    L.setSize(sf::Vector2f(10 ,box.height*scaleY-20));
    L.setOrigin(L.getSize().x/2 - 10, L.getSize().y/2);
    L.setPosition(getPosition().x - (box.width*scaleX) + 30, getPosition().y - 10);

    R.setSize(sf::Vector2f(10,box.height*scaleY-20));
    R.setOrigin(R.getSize().x/2 - 10, R.getSize().y/2);
    R.setPosition(getPosition().x + (box.width*scaleX) - 30, getPosition().y - 20);

    T.setSize(sf::Vector2f((box.width*2*scaleX) - 100,10));
    T.setOrigin(T.getSize().x/2, T.getSize().y/2);
    T.setPosition(getPosition().x, getPosition().y - box.height*scaleY);

    B.setSize(sf::Vector2f((box.width*2*scaleX) - 100,10));
    B.setOrigin(B.getSize().x/2, B.getSize().y/2);
    B.setPosition(getPosition().x, getPosition().y + (box.height*scaleY) - 40);
}

void Player::setBox()
{
    box.width  = getGlobalBounds().width/imageCount;
    box.height = getGlobalBounds().height;
    box.left = 0;
}

void Player::setOffset(sf::RenderWindow& window)
{
    offsetX = 0, offsetY = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        offsetX = -20*distanceMultiplier;
        disableState(FACING_RIGHT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        offsetX = 20*distanceMultiplier;
        enableState(FACING_RIGHT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        offsetY = 20;

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isEnabled(COLLIDED_B)) || isEnabled(JUMPED)) {
        offsetY = -40;
        enableState(JUMPED);
    } else if(getPosition().y + box.height < window.getSize().y)
    {
        offsetY = 20;
        enableState(MOVE_DOWN);
    }
}

void Player::jump(sf::RenderWindow& window)
{
    int elapsedTime = clock.getElapsedTime().asMilliseconds();
    if(elapsedTime > 5)
    {
        jumpHeight += 50;
        if(jumpHeight > 600 || !isEnabled(VALID_POSITION))
        {
            offsetY *= -1;
            imageCount = -1;
        }
        ////No collision with platforms
        //if(jumpHeight > 600 || !isEnabled(VALID_POSITION) || isEnabled(COLLIDED_T))
        //        {
        //            offsetY *= -1;
        //            imageCount = -1;
        //        }

        if((offsetY > 0 && isEnabled(COLLIDED_B)))
        {
            disableState(JUMPED);
            jumpHeight = 0;
            offsetY = 0;
        }
        animation.animate(*this, 20, imageCount);
    }
}


void Player::flipTexture()
{
    setOrigin(getTextureRect().width/2, getTextureRect().height/2);
    setScale(2.0f, 2.0f);
    if(!isEnabled(FACING_RIGHT))
        setScale(-2.0f, 2.0f);
}


bool Player::isWithinWindow(sf::RenderWindow& window) {
    if (offsetX < 0)
    {
        if (getPosition().x + offsetX < box.width)
            return false;
    } else
    {
        if (getPosition().x + offsetX + box.width > window.getSize().x)
            return false;
    }

    if (offsetY < 0)
    {
        if (getPosition().y + offsetY < box.height)
            return false;
    } else {
    if (getPosition().y + offsetY + box.height > window.getSize().y + 1)
        return false;
    }
    return true;
}

void Player::isColliding(sf::FloatRect boundsRect)
{
    if(boundsRect.intersects(L.getGlobalBounds()))
        enableState(COLLIDED_L);
    else if(boundsRect.intersects(R.getGlobalBounds()))
        enableState(COLLIDED_R);
    if(boundsRect.intersects(T.getGlobalBounds()))
        enableState(COLLIDED_T);
    else if(boundsRect.intersects(B.getGlobalBounds()))
        enableState(COLLIDED_B);
}

void Player::movePlayer(float offsetX, float offsetY)
{
    move(offsetX, offsetY);
}

void Player::scale(float x, float y)
{
    sf::Transformable::scale({x, y});
    scaleX = x;
    scaleY = y;
    if(scaleClock.getElapsedTime().asSeconds() > reset && isEnabled(COLLIDED_B))
    {
        move(0,-60);
        reset = 5;
        scaleClock.restart();
    }
}

void Player::checkBounds(std::vector<sf::FloatRect> bounds)
{
    for(int i=0; i < bounds.size(); i++)
        isColliding(bounds[i]);
}

void Player::setScaleSize(float scaleX, float scaleY)
{
    Player::scaleX = scaleX;
    Player::scaleY = scaleY;
}

void Player::setDistanceMultiplier(int distanceMultiplier)
{
    Player::distanceMultiplier = distanceMultiplier;
}

void Player::resetPlayer()
{
    setScaleSize(1,1);
    distanceMultiplier = 1;
}
