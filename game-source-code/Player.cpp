#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(int _xPosition, int _yPosition, bool life)
{
    xPosition = _xPosition;
    yPosition = _yPosition;
    Life = life;
}

void Player::setXposition(int x)
{
    xPosition = x;
}
void Player::setYposition(int y)
{
    yPosition = y;
}
void Player::move(Direction _direction)
{
    auto leftBoundary = 0;
    auto rightBoundary = 380;
    auto gameSpeed = 5;

    switch(_direction) {
    case LEFT:
        if(xPosition != leftBoundary) {
            xPosition = xPosition - gameSpeed;
        }
        break;
    case RIGHT:
        if(xPosition != rightBoundary) {
            xPosition = xPosition + gameSpeed;
        }
        break;
    default:
        break;
    }
}

int Player::getXposition()
{
    return xPosition;
}
int Player::getYposition()
{
    return yPosition;
}

void Player::setLife(bool _life)
{
    Life = _life;
}

bool Player::getLife()
{
    return Life;
}