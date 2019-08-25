#include "Player.h"

Player::Player(int x, int y)
    : GameEntity{ 0, 0 }
{
    setXposition(x);
    setYposition(y);
}

 void Player::move(Direction _direction)
{
    auto leftBoundary = 0;
    auto rightBoundary = 380;
    auto speed = 5;

    switch(_direction) {
    case LEFT:
        if(getXposition() != leftBoundary) {
            setXposition(getXposition() - speed);
        }
        break;
    case RIGHT:
        if(getXposition() != rightBoundary) {
            setXposition(getXposition() + speed);
        }
        break;
    default:
        break;
    }
}
