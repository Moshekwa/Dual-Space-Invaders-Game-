/**
 * @file LaserCanonLife.h
 * @class LaserCanonLife
 * @brief This class is defining objects that depict the remaining lives of the laser canons.
 * @bug No Known Bugs.
 * @version 3.0
 * @date 25/09/2019
 */

#ifndef LASERCANONLIFE_H_INCLUDED
#define LASERCANONLIFE_H_INCLUDED
#include "GameEntity.h"
#include "LaserCanon.h"

class LaserCanonLife : public GameEntity
{
public:
    LaserCanonLife(int xPosition, int yPosition, bool life, int numberOfLives);
    ~LaserCanonLife(){};

private:
};

#endif // LASERCANONLIFE_H_INCLUDED