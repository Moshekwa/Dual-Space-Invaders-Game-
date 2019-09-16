#include "Laser.h"
#include <iostream>
using namespace std;

Laser::Laser(LaserCanon& _laserCanon)
    : GameEntity{ _laserCanon.getEntityCoordinates().getXposition(), _laserCanon.getEntityCoordinates().getYposition(),
        5, false }
{
    if(getEntityCoordinates().getXposition() < 0 || getEntityCoordinates().getXposition() > 400 ||
        getEntityCoordinates().getYposition() < 0 || getEntityCoordinates().getYposition() > 400) {
        throw InvalidLaserCoordinates{};
    }
}

void Laser::move(Direction _direction)
{
    switch(_direction) {
    case UP:
        if(getEntityCoordinates().getYposition() != 0) {
            setYposition(getEntityCoordinates().getYposition() - getEntitySpeed());
        }
        break;
    case DOWN:
        if(getEntityCoordinates().getYposition() < 395) {
            cout << getEntityCoordinates().getYposition() << endl;
            setYposition(getEntityCoordinates().getYposition() + getEntitySpeed());
        }
    default:
        break;
    }
}

void Laser::shootLaser()
{
    setEntityLife(true);
}

void Laser::moveLaserWithCanon(LaserCanon& _laserCanon)
{
    setXposition(_laserCanon.getEntityCoordinates().getXposition() + 6);
    setYposition(_laserCanon.getEntityCoordinates().getYposition());
}