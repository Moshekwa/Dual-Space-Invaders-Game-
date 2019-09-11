#include "GameUpdater.h"

GameUpdater::GameUpdater()
{
}

void GameUpdater::updatePlayerLaser(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2)
{
    auto laser1 = 1;
    auto laser2 = 2;

    if(_laserCanon1.getLaser(laser1).isAlive() && _laserCanon1.isAlive()) {
	if(_laserCanon1.getLaser(laser1).getEntityCoordinates().getYposition() == 0) {
	    _laserCanon1.destroyLaser(laser1);
	}
	_laserCanon1.moveLaser();
    }
    _laserCanon1.update_Laser_position(laser1);

    if(_laserCanon2.getLaser(laser2).isAlive() && _laserCanon2.isAlive()) {
	if(_laserCanon2.getLaser(laser2).getEntityCoordinates().getYposition() == 395) {
	    _laserCanon2.destroyLaser(laser2);
	}
	_laserCanon2.moveLaser();
    }
    _laserCanon2.update_Laser_position(laser2);
}

void GameUpdater::updateAlienPosition(Alien& _alien)
{
    if(_alien.isAlive()) {
	if(_alien.getAlienRightDirection()) {
	    _alien.move(Direction::RIGHT);
	    if(_alien.getEntityCoordinates().getXposition() >= get<1>(_alien.getHorizontalBoundaries())) {
		_alien.move(Direction::DOWN);
		_alien.setAlienRightDirection(false);
	    }
	}
	if(!_alien.getAlienRightDirection()) {
	    _alien.move(Direction::LEFT);
	    if(_alien.getEntityCoordinates().getXposition() <= get<0>(_alien.getHorizontalBoundaries())) {
		_alien.move(Direction::DOWN);
		_alien.setAlienRightDirection(true);
		;
	    }
	}
    }
}

void GameUpdater::updateUpAlienPosition(Alien& _alien)
{
    if(_alien.isAlive()) {
	if(_alien.getAlienRightDirection()) {
	    _alien.move(Direction::RIGHT);
	    if(_alien.getEntityCoordinates().getXposition() >= get<1>(_alien.getHorizontalBoundaries())) {
		_alien.move(Direction::UP);
		_alien.setAlienRightDirection(false);
	    }
	}
	if(!_alien.getAlienRightDirection()) {
	    _alien.move(Direction::LEFT);
	    if(_alien.getEntityCoordinates().getXposition() <= get<0>(_alien.getHorizontalBoundaries())) {
		_alien.move(Direction::UP);
		_alien.setAlienRightDirection(true);
		;
	    }
	}
    }
}
