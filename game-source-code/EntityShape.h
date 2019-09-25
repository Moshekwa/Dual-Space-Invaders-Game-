/**
 * @file EntityShape.h
 * @class EntityShape
 * @brief This class is responsible for keeping track of the position ranges an object occupies.
 * @bug No Known Bugs.
 * @version 3.0
 * @date 25/09/2019
 */

#ifndef ENTITYSHAPE_H_INCLUDED
#define ENTITYSHAPE_H_INCLUDED
#include "Alien.h"
#include "Laser.h"
#include "LaserCanon.h"
#include "LaserCanonShield.h"
#include <tuple>
using namespace std;

class EntityShape
{
public:
    EntityShape();
    tuple<int, int, int, int> laser1Shape(Laser& _laser1);
    tuple<int, int, int, int> laser2Shape(Laser& _laser2);
    tuple<int, int, int, int> alienLaserShape(Laser& _alienLaser);
    tuple<int, int, int, int> laserCanon1Shape(LaserCanon& _laserCanon1);
    tuple<int, int, int, int> laserCanon2Shape(LaserCanon& _laserCanon2);
    tuple<int, int, int, int> alienShape(Alien& _alien);
    tuple<int, int, int, int> laserCanonShieldShape(LaserCanonShield& _shield);
    ~EntityShape();

private:
    int laserWidth = 5;
    int laserHeight = 10;
    int alienWidth = 20;
    int alienHeight = 20;
    int laserCanonWidth = 20;
    int laserCanonHeight = 20;
    int LaserCanonShieldWidth = 40;
    int LaserCanonShieldHeight = 20;
};

#endif // ENTITYSHAPE_H_INCLUDED