#ifndef LASER_H_INCLUDED
#define LASER_H_INCLUDED
#include "EntityCoordinates.h"
#include "GameEntity.h"
#include "LaserCanon.h"

class InvalidLaserCoordinates
{
};

class Laser : public GameEntity
{
public:
    Laser(LaserCanon& _laserCanon);
    void shootLaser();
    void moveLaserWithCanon(LaserCanon& _laserCanon);
    virtual void move(Direction _direction);

private:
};

#endif // LASER_H_INCLUDED