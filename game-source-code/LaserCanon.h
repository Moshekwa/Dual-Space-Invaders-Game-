#ifndef LASERCANON_H_INCLUDED
#define LASERCANON_H_INCLUDED
#include "MovingEntity.h"
#include <tuple>

class InvalidLaserCanonCoordinates
{
};


class LaserCanon : public MovingEntity
{
public:
    LaserCanon(int x, int y, int canonNumber, int numberOfLives);
    virtual void move(Direction _direction);

private:

};

#endif // LASERCANON_H_INCLUDED