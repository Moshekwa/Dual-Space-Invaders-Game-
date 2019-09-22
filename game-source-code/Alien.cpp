#include "Alien.h"
#include <iostream>
using namespace std;

Alien::Alien(int x, int y, int _rightBoundary, int _leftBoundary, int numberOfLives)
    : MovingEntity{ x, y, 2, true, numberOfLives }
    , rightBoundary{ _rightBoundary }
    , leftBoundary{ _leftBoundary }
    , upperBoundary{ 70 }
    , bottomBoundary{ 450 }
    , alienRightDirection{ true }
{

    //if(x < 0 || x > 380)
	//throw InvalidAlienCoordinates{};
}

const int Alien::numberOfAliens{3};

int Alien::getNumberOfAliens() 
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