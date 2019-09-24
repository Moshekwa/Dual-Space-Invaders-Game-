#ifndef COLLISIONDETECTOR_H_INCLUDED
#define COLLISIONDETECTOR_H_INCLUDED
#include "Alien.h"
#include "Laser.h"
#include "LaserCanon.h"
#include "LaserCanonShield.h"
#include <tuple>
using namespace std;

class CollisionDetector
{
public:
    CollisionDetector();
    
    void LaserAlienCollision(Laser& _laser1, Laser& _laser2, Alien& _alien, LaserCanon& _laserCanon1, LaserCanon& _laserCanon2);
    tuple<bool, int> LaserCanonLaserCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Laser& _laser1, Laser& _laser2);
    tuple<bool, int> LaserCanonAlienLaserCollision(LaserCanon& _laserCanon1, LaserCanon& _laserCanon2, Laser& _alienLaser);
    void LaserCanonShieldAlienLaserCollision(LaserCanonShield& _laserCanonShield, Laser& _alienLaser);
    void LaserCanonShieldLaserCollission(LaserCanonShield& _laserCanonShield, Laser& _laser1, Laser& _laser2);
    void Laser1Laser2Collision(Laser& _laser1, Laser& _laser2);
    void LaserAliensLaserCollision(Laser& _laser1, Laser& _laser2, Laser& _alienLaser);

private:
    int laserWidth = 4;
    int laserHeight = 6;
    int alienWidth = 20;
    int alienHeight = 20;
    int laserCanonWidth = 20;
    int laserCanonHeight = 20;
    int LaserCanonShieldWidth = 40;
    int LaserCanonShieldHeight = 20;
};

#endif // COLLISIONDETECTOR_H_INCLUDED