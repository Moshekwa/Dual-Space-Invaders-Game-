#include "GameUpdater.h"

GameUpdater::GameUpdater()
{
}

void GameUpdater::updateLaser1Position(LaserCanon& _laserCanon1, Laser& _laser1)
{
    // getMovementBoundaries returns : leftBoundary, rightBoundary, upperBoundary and bottomBoundary.
    if(_laser1.isAlive()) {
        if(_laserCanon1.getFacedDirection() == Direction::DOWN) {
            if(get<1>(_laser1.entityPosition()) >= get<3>(_laser1.getMovementBoundaries())) {
                _laser1.destroyEntity();
            } else {
                _laser1.move(DOWN);
            }
        } else {
            if(get<1>(_laser1.entityPosition()) <= get<2>(_laser1.getMovementBoundaries())) {
                _laser1.destroyEntity();
            } else {
                _laser1.move(UP);
            }
        }
    } else {
        _laser1.moveLaserWithCanon(_laserCanon1);
    }
}

void GameUpdater::updateLaser2Position(LaserCanon& _laserCanon2, Laser& _laser2)
{
    if(_laser2.isAlive()) {
        if(_laserCanon2.getFacedDirection() == Direction::UP) {
            if(get<1>(_laser2.entityPosition()) <= get<2>(_laser2.getMovementBoundaries())) {
                _laser2.destroyEntity();
            } else {
                _laser2.move(UP);
            }
        } else {
            if(get<1>(_laser2.entityPosition()) >= get<3>(_laser2.getMovementBoundaries())) {
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
        if(get<1>(_alienLaser.entityPosition()) >= get<3>(_alienLaser.getMovementBoundaries())) {
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
        if(get<1>(_alienLaser.entityPosition()) <= get<2>(_alienLaser.getMovementBoundaries())) {
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
            if(get<0>(_alien.entityPosition()) >= get<1>(_alien.getMovementBoundaries())) {
                _alien.move(Direction::DOWN);
                _alien.setAlienRightDirection(false);
            }
        }
        if(!_alien.getAlienRightDirection()) {
            _alien.move(Direction::LEFT);
            if(get<0>(_alien.entityPosition()) <= get<0>(_alien.getMovementBoundaries())) {
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
            if(get<0>(_alien.entityPosition()) >= get<1>(_alien.getMovementBoundaries())) {
                _alien.move(Direction::UP);
                _alien.setAlienRightDirection(false);
            }
        }
        if(!_alien.getAlienRightDirection()) {
            _alien.move(Direction::LEFT);
            if(get<0>(_alien.entityPosition()) <= get<0>(_alien.getMovementBoundaries())) {
                _alien.move(Direction::UP);
                _alien.setAlienRightDirection(true);
                ;
            }
        }
    }
}

void GameUpdater::updateCanon_ScoreAndHighScore(ScoreBoard& _scoreBoard, Alien& _alien)
{
    auto newScore = _scoreBoard.getScore() + _alien.alienPoints(_alien.getAlienColour());
    _scoreBoard.setScore(newScore);
    _scoreBoard.readHighScoreIntoFile();
}

void GameUpdater::updateLaserCanon1Position(LaserCanon& _laserCanon1, Direction _direction)
{
    auto [x_position, y_position] = _laserCanon1.entityPosition();
    auto [leftBoundary, rightBoundary, upperBoundary, bottomBoundary] = _laserCanon1.getMovementBoundaries();
    if(y_position == upperBoundary) {
        _laserCanon1.setFacedDirection(Direction::DOWN);
    }
    if(y_position == bottomBoundary) {
        _laserCanon1.setFacedDirection(Direction::UP);
    }
    switch(_direction) {
    case LEFT:
        if(x_position > leftBoundary && (y_position == upperBoundary || y_position == bottomBoundary)) {
            _laserCanon1.move(LEFT);
        }
        break;
    case RIGHT:
        if(x_position < rightBoundary && (y_position == upperBoundary || y_position == bottomBoundary)) {
            _laserCanon1.move(RIGHT);
        }
        break;
    case UP:
        if(y_position > upperBoundary) {
            _laserCanon1.move(UP);
        }
        break;
    case DOWN:
        if(y_position < bottomBoundary) {
            _laserCanon1.move(DOWN);
        }
    default:
        break;
    }
}

void GameUpdater::updateLaserCanon2Position(LaserCanon& _laserCanon2, Direction _direction)
{
    auto [x_position, y_position] = _laserCanon2.entityPosition();
    auto [leftBoundary, rightBoundary, upperBoundary, bottomBoundary] = _laserCanon2.getMovementBoundaries();

    if(y_position == upperBoundary) {
        _laserCanon2.setFacedDirection(Direction::DOWN);
    }
    if(y_position == bottomBoundary) {
        _laserCanon2.setFacedDirection(Direction::UP);
    }

    switch(_direction) {
    case LEFT:
        if(x_position > leftBoundary && (y_position == upperBoundary || y_position == bottomBoundary)) {
            _laserCanon2.move(LEFT);
        }
        break;
    case RIGHT:
        if(x_position < rightBoundary && (y_position == upperBoundary || y_position == bottomBoundary)) {
            _laserCanon2.move(RIGHT);
        }
        break;
    case UP:
        if(y_position > upperBoundary) {
            _laserCanon2.move(UP);
        }
        break;
    case DOWN:
        if(y_position < bottomBoundary) {
            _laserCanon2.move(DOWN);
        }

    default:
        break;
    }
}
