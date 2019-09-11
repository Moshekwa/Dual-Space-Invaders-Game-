#ifndef COLLISIONDETECTOR_H_INCLUDED
#define COLLISIONDETECTOR_H_INCLUDED
#include "Alien.h"
#include "LaserCanon.h"

class CollisionDetector
{
public:
    CollisionDetector();
    void LaserAlienCollision(LaserCanon& _laser1, LaserCanon& _laser2, Alien& _alien);
	void LaserCanonLaserCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2);
	
private:
    int laserRadius = 3;
    int alienRadius = 10;
	int laserCanonRadius = 10;
};

#endif // COLLISIONDETECTOR_H_INCLUDED