#include "LaserCanon.h"
#include <iostream>
using namespace std;

LaserCanon::LaserCanon(int x, int y, int canonNumber)
    : GameEntity{ x, y, 5, true }
{
    switch(canonNumber) {
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
    }
    auto _coordintates =
        EntityCoordinates{ getEntityCoordinates().getXposition(), getEntityCoordinates().getYposition() };
    _laser = Laser{ _coordintates };
    _laser2 = Laser{ _coordintates };
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

void LaserCanon::shootLaser(int laser_number)
{
    switch(laser_number) {
    case 1:
	_laser.setEntityLife(true);
	break;
    case 2:
	_laser2.setEntityLife(true);
	break;
    default:
	break;
    }
}

void LaserCanon::destroyLaser(int laser_number)
{
    switch(laser_number) {
    case 1:
	_laser.setEntityLife(false);
	break;
    case 2:
	_laser2.setEntityLife(false);
	break;
    default:
	break;
    }
}

void LaserCanon::moveLaser()
{
    if(_laser.isAlive()) {
	_laser.move(UP);
    }

    if(_laser2.isAlive()) {
	_laser2.move(DOWN);
    }
}

Laser LaserCanon::getLaser(int laser_number) const
{

    if(laser_number == 1) {
	return _laser;
    }
    if(laser_number == 2) {
	return _laser2;
    } else {
	auto invalidLaser = Laser{};
	return invalidLaser;
    }
}

void LaserCanon::update_Laser_position(int laser_number)
{
    if(!_laser.isAlive() && laser_number == 1) {
	auto _coordinates =
	    EntityCoordinates{ getEntityCoordinates().getXposition(), getEntityCoordinates().getYposition() };
	_laser.update_position(_coordinates);
    }
    if(!_laser2.isAlive() && laser_number == 2) {
	auto _coordinates =
	    EntityCoordinates{ getEntityCoordinates().getXposition(), getEntityCoordinates().getYposition() };
	_laser2.update_position(_coordinates);
    }
}
