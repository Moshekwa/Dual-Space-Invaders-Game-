#include "GameUpdater.h"
#include <iostream>
using namespace std;

GameUpdater::GameUpdater()
{
}

void GameUpdater::updateLaser1Position(LaserCanon& _laserCanon1, Laser& _laser1)
{
    if(_laser1.isAlive()) {
        if(_laser1.getEntityCoordinates().getYposition() == 0) {
            _laser1.destroyEntity();
        } else {
            _laser1.move(UP);
        }
    } else {
        _laser1.moveLaserWithCanon(_laserCanon1);
    }
}

void GameUpdater::updateLaser2Position(LaserCanon& _laserCanon2, Laser& _laser2)
{
    cout << _laser2.isAlive() << endl;
    if(_laser2.isAlive()) {
        if(_laser2.getEntityCoordinates().getYposition() == 0) {
            _laser2.destroyEntity();
        } else {
            _laser2.move(DOWN);
        }
    } else {
        _laser2.moveLaserWithCanon(_laserCanon2);
    }
}

void GameUpdater::updateAlienPosition(Alien& _alien)
{
    if(_alien.isAlive()) {
        if(_alien.getAlienRightDirection()) {
            _alien.move(Direction::RIGHT);
            if(_alien.getEntityCoordinates().getXposition() >= get<1>(_alien.getBoundaries())) {
                _alien.move(Direction::DOWN);
                _alien.setAlienRightDirection(false);
            }
        }
        if(!_alien.getAlienRightDirection()) {
            _alien.move(Direction::LEFT);
            if(_alien.getEntityCoordinates().getXposition() <= get<0>(_alien.getBoundaries())) {
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
            if(_alien.getEntityCoordinates().getXposition() >= get<1>(_alien.getBoundaries())) {
                _alien.move(Direction::UP);
                _alien.setAlienRightDirection(false);
            }
        }
        if(!_alien.getAlienRightDirection()) {
            _alien.move(Direction::LEFT);
            if(_alien.getEntityCoordinates().getXposition() <= get<0>(_alien.getBoundaries())) {
                _alien.move(Direction::UP);
                _alien.setAlienRightDirection(true);
                ;
            }
        }
    }
}
