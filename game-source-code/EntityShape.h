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
    /**
     * @brief keeps track of a rectangular shape around the sprite of the laser object
     * @param _laser
     * @return
     */
    tuple<int, int, int, int> laserShape(Laser& _laser);
    /**
     * @brief keeps track of a rectangular shape around the sprite of an alien laser object
     * @param _alienLaser
     * @return
     */
    tuple<int, int, int, int> alienLaserShape(Laser& _alienLaser);
    /**
     * @brief keeps track of a rectangular shape around the sprite of the laser canon object
     * @param _laserCanon
     * @return
     */
    tuple<int, int, int, int> laserCanonShape(LaserCanon& _laserCanon);
    /**
     * @brief keeps track of a rectangular shape around the sprite of the alien object
     * @param _alien
     * @return
     */
    tuple<int, int, int, int> alienShape(Alien& _alien);
    /**
     * @brief keeps track of a rectangular shape around the sprite of the laser canon shield object
     * @param _shield
     * @return
     */
    tuple<int, int, int, int> laserCanonShieldShape(LaserCanonShield& _shield);
    ~EntityShape(){};

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