#include "LaserCanon.h"

LaserCanon::LaserCanon(int x, int y, int canonNumber)
    : MovingEntity{ x, y, 5, true }
{
    /*switch(canonNumber) {
    case 1:
	if(x < 0 || x > 380 || y != 380) {
	    throw InvalidLaserCanonCoordinates{};
	}
	break;
    case 2:
	if(x < 0 || x > 380 || y != 0) {

	    throw InvalidLaserCanonCoordinates{};
	}
	break;
    default:
	break;
    }*/
}

void LaserCanon::move(Direction _direction)
{
    auto leftBoundary = 0;
    auto rightBoundary = 380;

    switch(_direction) {
    case LEFT:
	if(getEntityCoordinates().getXposition() - getEntitySpeed() > leftBoundary) {
	    setXposition(getEntityCoordinates().getXposition() - getEntitySpeed());
	}
	break;
    case RIGHT:
	if(getEntityCoordinates().getXposition() + getEntitySpeed() < rightBoundary) {
	    setXposition(getEntityCoordinates().getXposition() + getEntitySpeed());
	}
	break;
    default:
	break;
    }
}

