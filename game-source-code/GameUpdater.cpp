#include "GameUpdater.h"

GameUpdater::GameUpdater()
{
}

void GameUpdater::updateLaser1Position(LaserCanon& _laserCanon1, Laser& _laser1)
{
    if(_laser1.isAlive()) {
        if(get<1>(_laser1.entityPosition()) <= 40) {
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
    if(_laser2.isAlive()) {
        if(get<1>(_laser2.entityPosition()) >= 490) {
            _laser2.destroyEntity();
        } else {
            _laser2.move(DOWN);
        }
    } else {
        _laser2.moveLaserWithCanon(_laserCanon2);
    }
}

void GameUpdater::updateAlienLaserPosition(Alien& _alien, Laser& _alienLaser)
{
    if(_alienLaser.isAlive()) {
        if(get<1>(_alienLaser.entityPosition()) >= 490) {
            _alienLaser.destroyEntity();
            _alienLaser.moveLaserWithAlien(_alien);
        } else {
            _alienLaser.move(DOWN);
        }
    } else {
        _alienLaser.moveLaserWithAlien(_alien);
    }
}

void GameUpdater::updateUpAlienLaserPosition(Alien& _alien, Laser& _alienLaser)
{
    if(_alienLaser.isAlive()) {
        if(get<1>(_alienLaser.entityPosition()) <= 40) {
            _alienLaser.destroyEntity();
            _alienLaser.moveLaserWithAlien(_alien);
        } else {
            _alienLaser.move(UP);
        }
    } else {
        _alienLaser.moveLaserWithAlien(_alien);
    }
}

void GameUpdater::updateAlienPosition(Alien& _alien)
{
    if(_alien.isAlive()) {
        if(_alien.getAlienRightDirection()) {
            _alien.move(Direction::RIGHT);
            if(get<0>(_alien.entityPosition()) >= get<1>(_alien.getBoundaries())) {
                _alien.move(Direction::DOWN);
                _alien.setAlienRightDirection(false);
            }
        }
        if(!_alien.getAlienRightDirection()) {
            _alien.move(Direction::LEFT);
            if(get<0>(_alien.entityPosition()) <= get<0>(_alien.getBoundaries())) {
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
            if(get<0>(_alien.entityPosition()) >= get<1>(_alien.getBoundaries())) {
                _alien.move(Direction::UP);
                _alien.setAlienRightDirection(false);
            }
        }
        if(!_alien.getAlienRightDirection()) {
            _alien.move(Direction::LEFT);
            if(get<0>(_alien.entityPosition()) <= get<0>(_alien.getBoundaries())) {
                _alien.move(Direction::UP);
                _alien.setAlienRightDirection(true);
                ;
            }
        }
    }
}

void GameUpdater::updateCanon1_Score(LaserCanon& _laserCanon1, Alien& _alien)
{
    auto newScore = get<0>(_laserCanon1.getScoreAndHighScore()) + _alien.alienPoints(_alien.getAlienColour());
    _laserCanon1.setScore(newScore);
}

void GameUpdater::updateCanon2_Score(LaserCanon& _laserCanon2, Alien& _alien)
{
    auto newScore = get<0>(_laserCanon2.getScoreAndHighScore()) + _alien.alienPoints(_alien.getAlienColour());
    _laserCanon2.setScore(newScore);
}