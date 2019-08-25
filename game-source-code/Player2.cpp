#include "Player2.h"

Player2::Player2(int _xPosition, int _yPosition, bool life)
{
    xPosition = _xPosition;
    yPosition = _yPosition;
    Life = life;
}

void Player2::setXposition(int x)
{
    xPosition = x;
}
void Player2::setYposition(int y)
{
    yPosition = y;
}
void Player2::move(Direction2 _direction)
{
    auto leftBoundary = 0;
    auto rightBoundary = 380;
    auto gameSpeed = 5;

    switch(_direction) {
    case LEFT2:
        if(xPosition != leftBoundary) {
            xPosition = xPosition - gameSpeed;
        }
        break;
    case RIGHT2:
        if(xPosition != rightBoundary) {
            xPosition = xPosition + gameSpeed;
        }
        break;
    default:
        break;
    }
}

int Player2::getXposition()
{
    return xPosition;
}
int Player2::getYposition()
{
    return yPosition;
}

void Player2::setLife(bool _life)
{
    Life = _life;
}

bool Player2::getLife()
{
    return Life;
}