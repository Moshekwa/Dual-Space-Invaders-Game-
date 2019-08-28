#include "Player.h"

Player::Player(int x, int y)
    : GameEntity{ x, y, 5, true } 
{
    auto _coordintates =
        EntityCoordinates{ getEntityCoordinates().getXposition(), getEntityCoordinates().getYposition() };
    _laser = Laser{ _coordintates };
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

void Player::moveLaser()
{
    if(_laser.isAlive()){
		_laser.move(UP);
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