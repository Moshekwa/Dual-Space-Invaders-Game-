#include "Player.h"

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

void Player::shootLaser(int laser_number)
{
    if(laser_number == 1) {
        _laser.setEntityLife(true);
    }
    if(laser_number == 2) {
        _laser2.setEntityLife(true);
    }
}

void Player::moveLaser()
{
    if(_laser.isAlive()) {
        _laser.move(UP);
    }

    if(_laser2.isAlive()) {
        _laser2.move(DOWN);
    }
}

Laser Player::getLaser(int laser_number) const
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

void Player::update_Laser_position(int laser_number)
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
