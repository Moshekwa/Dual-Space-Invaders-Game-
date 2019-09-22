#ifndef LASERCANON_H_INCLUDED
#define LASERCANON_H_INCLUDED
#include "MovingEntity.h"

class InvalidLaserCanonCoordinates
{
};

class LaserCanon : public MovingEntity
{
public:
    LaserCanon(int x, int y, int canonNumber, int numberOfLives);
    virtual void move(Direction _direction);

private:
     bool lifeLost;
};

#endif // LASERCANON_H_INCLUDED