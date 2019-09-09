#ifndef COLLISIONDETECTOR_H_INCLUDED
#define COLLISIONDETECTOR_H_INCLUDED
#include "Alien.h"
#include "Laser.h"
#include "LaserCanon.h"

class CollisionDetector
{
public:
    CollisionDetector();
    void LaserAlienCollision(LaserCanon& _laser1, LaserCanon& _laser2, Alien& _alien);

private:
    int laserRadius = 3;
    int alienRadius = 10;
};

#endif // COLLISIONDETECTOR_H_INCLUDED