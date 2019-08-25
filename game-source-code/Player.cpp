#include "Player.h"

Player::Player(int x, int y)
    : GameEntity{ 0, 0 }
{
    setXposition(x);
    setYposition(y);
}

void Player::shoot()
{
    _laser.move(UP);
}

Laser Player::getLaser()
{
    return _laser;
}

 void Player::move(Direction _direction)
{
    auto leftBoundary = 0;
    auto rightBoundary = 380;

    switch(_direction) {
    case LEFT:
        if(getXposition() != leftBoundary) {
            setXposition(getXposition() - getEntitySpeed() );
        }
        break;
    case RIGHT:
        if(getXposition() != rightBoundary) {
            setXposition(getXposition() + getEntitySpeed() );
        }
        break;
    default:
        break;
    }
}
