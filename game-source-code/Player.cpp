#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(int x, int y)
    : GameEntity{ x, y, 5, true } 
{
    auto _coordintates =
        EntityCoordinates{ getEntityCoordinates().getXposition(), getEntityCoordinates().getYposition() };
    _laser = Laser{ _coordintates };
	_laser2 = Laser{ _coordintates };
}

void Player::move(Direction _direction)
{
    auto leftBoundary = 0;
    auto rightBoundary = 380;

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
    default:
        break;
    }
}

void Player::shootLaser()
{
    _laser.setEntityLife(true);
}

void Player::shootLaser2()
{
	_laser2.setEntityLife(true);
}

void Player::moveLaser()
{
    if(_laser.isAlive()){
		_laser.move(UP);
    }
	
	//cout << _laser.isAlive() << endl;
	
	if(!_laser2.isAlive()){
		//cout << _laser.isAlive() << endl;
		_laser2.move(DOWN);
    } 
}

Laser Player::getLaser() const
{
    return _laser;
}

void Player::update_Laser_position()
{
	if(!_laser.isAlive())
	{
		auto _coordinates = EntityCoordinates{getEntityCoordinates().getXposition(),getEntityCoordinates().getYposition()};
		_laser.update_position(_coordinates);
	}
	
}

void Player::update_Laser2_position()
{
	if(!_laser2.isAlive())
	{
		auto _coordinates = EntityCoordinates{getEntityCoordinates().getXposition(),getEntityCoordinates().getYposition()};
		_laser2.update_position(_coordinates);
	}
	
}