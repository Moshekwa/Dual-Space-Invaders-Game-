#include "Laser.h"

Laser::Laser(LaserCanon& _laserCanon, int numberOfLives)
    : Ammunition{ get<0>(_laserCanon.entityPosition()), get<1>(_laserCanon.entityPosition()), 5, false, numberOfLives }
{
    auto [x_position, y_position] = entityPosition();
    if(x_position < 0 || x_position > 400 || y_position < 40 || y_position > 480) {
        throw InvalidCanonLaserCoordinates{};
    }
    setMovementBoundaries(0,395,40,460);
}

Laser::Laser(Alien& _alien, int numberOfLives)
    : Ammunition{ get<0>(_alien.entityPosition()), get<1>(_alien.entityPosition()), 1, false, numberOfLives }
{
    auto [x_position, y_position] = entityPosition();
    if(x_position < 0 || x_position > 400 || y_position < 40 || y_position > 480) {
        throw InvalidCanonLaserCoordinates{};
    }
    setMovementBoundaries(0,395,40,500);
}

void Laser::move(Direction _direction)
{
    auto y_position = get<1>(entityPosition());
    switch(_direction) {
    case UP:
        setYposition(y_position - getEntitySpeed());
        break;
    case DOWN:
        setYposition(y_position + getEntitySpeed());
    default:
        break;
    }
}

void Laser::moveLaserWithCanon(LaserCanon& _laserCanon)
{
    auto [x_position, y_position] = _laserCanon.entityPosition(); 
    setXposition(x_position + 5);
    setYposition(y_position + 5);
}

void Laser::moveLaserWithAlien(Alien& _alien)
{
    auto [x_position, y_position] = _alien.entityPosition();
    setXposition(x_position + 5);
    setYposition(y_position + 5);
}