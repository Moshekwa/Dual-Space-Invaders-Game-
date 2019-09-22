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
    if(x < 0 || x > 380 || y < 40 || y > 480)
	throw InvalidAlienCoordinates{};
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
    auto [x_position, y_position] = entityPosition();
    switch(_direction) {
    case LEFT:
	if(x_position > leftBoundary) {
	    setXposition(x_position - getEntitySpeed());
	}
	break;
    case RIGHT:
	if(x_position < rightBoundary) {
	    setXposition(x_position + getEntitySpeed());
	}
	break;
    case UP:
	if(y_position > upperBoundary) {
	    setYposition(y_position - 2 * getEntitySpeed());
	}
	break;
    case DOWN:
	if(y_position < bottomBoundary) {
	    setYposition(y_position + 2 * getEntitySpeed());
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