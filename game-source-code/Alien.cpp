#include "Alien.h"

Alien::Alien(int x, int y)
    : GameEntity{ x, y, 4, true }
    , alienRightDirection{ true }
{
}

void Alien::move(Direction _direction)
{
    auto leftBoundary = 0;
    auto rightBoundary = 380;
    auto upperBoundary = 20;
    auto bottomBoundary = 360;

    switch(_direction) {
    case LEFT:
        if(getEntityCoordinates().getXposition() > leftBoundary) {
            setXposition(getEntityCoordinates().getXposition() - getEntitySpeed());
        }
        break;
    case RIGHT:
        if(getEntityCoordinates().getXposition() < rightBoundary) {
            setXposition(getEntityCoordinates().getXposition() + getEntitySpeed());
        }
        break;
    case UP:
        if(getEntityCoordinates().getYposition() > upperBoundary) {
            setYposition(getEntityCoordinates().getYposition() - getEntitySpeed());
        }
        break;
    case DOWN:
        if(getEntityCoordinates().getYposition() < bottomBoundary) {
            setYposition(getEntityCoordinates().getYposition() + getEntitySpeed());
        }
        break;
    default:
        break;
    }
}

void Alien::setAlienRightDirection(bool rightDirection)
{
    alienRightDirection = rightDirection;
}

bool Alien::getAlienRightDirection() const
{
    return alienRightDirection;
}