#include "Alien.h"
#include <iostream>
using namespace std;

Alien::Alien(int x, int y, int _rightBoundary, int _leftBoundary)
    : GameEntity{ x, y, 3, true }
    , numberOfAliens{ 5 }
    , rightBoundary{ _rightBoundary }
    , leftBoundary{ _leftBoundary }
    , upperBoundary{ 20 }
    , bottomBoundary{ 360 }
    , alienRightDirection{ true }
{

    if(x < 0 || x > 380)
	throw InvalidAlienCoordinates{};
}

int Alien::getNumberOfAliens() const
{
    return numberOfAliens;
}

tuple<int, int, int, int> Alien::getBoundaries() const
{
    return { leftBoundary, rightBoundary, upperBoundary, bottomBoundary };
}

void Alien::move(Direction _direction)
{
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
	    setYposition(getEntityCoordinates().getYposition() - 2 * getEntitySpeed());
	}
	break;
    case DOWN:
	if(getEntityCoordinates().getYposition() < bottomBoundary) {
	    setYposition(getEntityCoordinates().getYposition() + 2 * getEntitySpeed());
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