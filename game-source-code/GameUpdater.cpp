#include "GameUpdater.h"

GameUpdater::GameUpdater()
{
}

void GameUpdater::updateLaser1Position(LaserCanon& _laserCanon1, Laser& _laser1)
{
    if(_laser1.isAlive()) {
        if(get<1>(_laserCanon1.entityPosition()) == 40) {
            if(get<1>(_laser1.entityPosition()) >= 490) {
                _laser1.destroyEntity();
            } else {
                _laser1.move(DOWN);
            }
        } else {
            if(get<1>(_laser1.entityPosition()) <= 40) {
                _laser1.destroyEntity();
            } else {
                _laser1.move(UP);
            }
        }
    } else {
        _laser1.moveLaserWithCanon(_laserCanon1);
    }
}

/*
void updateDiagonalLaserPosition(LaserCanon& _LaserCanon& _laserCanon1, DiagonalLaser& _diagonalLaser)
{
        if(_diagonalLaser.isAlive()) {
        if(get<1>(_diagonalLaser.entityPosition()) <= 40) {
            _diagonalLaser.destroyEntity();
        } else {
            _diagonalLaser.move(UP);
        }
    } else {
        _diagonalLaser.moveDiagonalLaserWithCanon(_laserCanon1);
    }
}
*/

void GameUpdater::updateLaser2Position(LaserCanon& _laserCanon2, Laser& _laser2)
{
    if(_laser2.isAlive()) {
        if(get<1>(_laserCanon2.entityPosition()) == 480) {
            if(get<1>(_laser2.entityPosition()) <= 40) {
                _laser2.destroyEntity();
            } else {
                _laser2.move(UP);
            }
        } else {
            if(get<1>(_laser2.entityPosition()) >= 490) {
                _laser2.destroyEntity();
            } else {
                _laser2.move(DOWN);
            }
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

void GameUpdater::updateCanon1_ScoreAndHighScore(ScoreBoard& _scoreBoard1, Alien& _alien)
{
    auto newScore = _scoreBoard1.getScore() + _alien.alienPoints(_alien.getAlienColour());
    _scoreBoard1.setScore(newScore);
    _scoreBoard1.readHighScoreIntoFile(1);
}

void GameUpdater::updateCanon2_ScoreAndHighScore(ScoreBoard& _scoreBoard2, Alien& _alien)
{
    auto newScore = _scoreBoard2.getScore() + _alien.alienPoints(_alien.getAlienColour());
    _scoreBoard2.setScore(newScore);
    _scoreBoard2.readHighScoreIntoFile(2);
}