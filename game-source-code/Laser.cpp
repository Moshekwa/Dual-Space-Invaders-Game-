#include "Laser.h"

Laser::Laser(LaserCanon& _laserCanon, int numberOfLives)
    : MovingEntity{ _laserCanon.getEntityCoordinates().getXposition(),
        _laserCanon.getEntityCoordinates().getYposition(), 5, false, numberOfLives }
{
    /*if(getEntityCoordinates().getXposition() < 0 || getEntityCoordinates().getXposition() > 400 ||
        getEntityCoordinates().getYposition() < 0 || getEntityCoordinates().getYposition() > 400) {
        throw InvalidLaserCoordinates{};
    }*/
}

Laser::Laser(Alien& _alien, int numberOfLives)
    : MovingEntity{ _alien.getEntityCoordinates().getXposition(), _alien.getEntityCoordinates().getYposition(), 2, false, numberOfLives }
{
}

void Laser::shoot()
{
    giveEntityLife();
}

void Laser::move(Direction _direction)
{
    switch(_direction) {
    case UP:
        setYposition(getEntityCoordinates().getYposition() - getEntitySpeed());
        break;
    case DOWN:
        setYposition(getEntityCoordinates().getYposition() + getEntitySpeed());
    default:
        break;
    }
}

void Laser::moveLaserWithCanon(LaserCanon& _laserCanon)
{
    setXposition(_laserCanon.getEntityCoordinates().getXposition() + 6);
    setYposition(_laserCanon.getEntityCoordinates().getYposition());
}

void Laser::moveLaserWithAlien(Alien& _alien)
{
    setXposition(_alien.getEntityCoordinates().getXposition() + 6);
    setYposition(_alien.getEntityCoordinates().getYposition());
}