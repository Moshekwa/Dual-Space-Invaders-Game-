#ifndef COLLISIONDETECTOR_H_INCLUDED
#define COLLISIONDETECTOR_H_INCLUDED
#include "EntityShape.h"
#include <tuple>
using namespace std;

class CollisionDetector
{
public:
    CollisionDetector();

    tuple<bool, bool> LaserAlienCollision(Laser& _laser1, Laser& _laser2, Alien& _alien);
    tuple<bool, int>
    LaserCanonLaserCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Laser& _laser1, Laser& _laser2);
    tuple<bool, int>
    LaserCanonAlienLaserCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Laser& _alienLaser);
    bool LaserCanonShieldAlienLaserCollision(LaserCanonShield& _laserCanonShield, Laser& _alienLaser);
    tuple<bool, bool>
    LaserCanonShieldLaserCollission(LaserCanonShield& _laserCanonShield, Laser& _laser1, Laser& _laser2);
    bool Laser1Laser2Collision(Laser& _laser1, Laser& _laser2);
    tuple<bool, bool> LaserAliensLaserCollision(Laser& _laser1, Laser& _laser2, Laser& _alienLaser);

private:
    EntityShape _entityShape;
};

#endif // COLLISIONDETECTOR_H_INCLUDED