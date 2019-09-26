/**
 * @file LaserCanonShield.h
 * @class LaserCanonShield
 * @brief This class is gives information about a shield that protects a laser canon.
 * @bug No Known Bugs.
 * @version 3.0
 * @date 25/09/2019
 */

#ifndef LASERCANONSHIELD_H_INCLUDED
#define LASERCANONSHIELD_H_INCLUDED
#include "GameEntity.h"

class InvalidShieldPosition
{
};

class LaserCanonShield : public GameEntity
{
public:
    LaserCanonShield(int xPosition, int yPosition, bool life, int numberOfLives);
    static int getNumberOfShields();

private:
    const static int numberOfShields;
};

#endif // LASERCANONSHIELD_H_INCLUDED