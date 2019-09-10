#include "Alien.h"

Alien::Alien(int x, int y, int _rightBoundary, int _leftBoundary)
    : GameEntity{ x, y, 2, true }
    , numberOfAliens {5}
    , rightBoundary { _rightBoundary}
    , leftBoundary {_leftBoundary}
    , alienRightDirection{ true }
{
}

int Alien::getNumberOfAliens() const
{
    return numberOfAliens;
}

int Alien::getRightBoundary() const
{
    return rightBoundary;
}

int Alien::getLeftBoundary() const
{
    return leftBoundary;
}

void Alien::move(Direction _direction)
{
    //auto leftBoundary = 0;
    //auto rightBoundary = 380;
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
            setYposition(getEntityCoordinates().getYposition() - 2*getEntitySpeed());
        }
        break;
    case DOWN:
        if(getEntityCoordinates().getYposition() < bottomBoundary) {
            setYposition(getEntityCoordinates().getYposition() + 2*getEntitySpeed());
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