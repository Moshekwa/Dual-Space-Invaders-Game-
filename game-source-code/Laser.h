#ifndef LASER_H_INCLUDED
#define LASER_H_INCLUDED
#include "EntityCoordinates.h"
#include "GameEntity.h"
#include "LaserCanon.h"
#include "Alien.h"

class InvalidLaserCoordinates
{
};

class Laser : public GameEntity
{
public:
    Laser(LaserCanon& _laserCanon);
    Laser(Alien& _alien);
    void shootLaser();
    void moveLaserWithCanon(LaserCanon& _laserCanon);
    void moveLaserWithAlien(Alien& _alien);
    virtual void move(Direction _direction);

private:
};

#endif // LASER_H_INCLUDED