#ifndef LASERCANONSHIELD_H_INCLUDED
#define LASERCANONSHIELD_H_INCLUDED
#include "GameEntity.h"

class LaserCanonShield : public GameEntity
{
public:
    LaserCanonShield(int xPosition, int yPosition, bool life);
    void shoot();
};

#endif // LASERCANONSHIELD_H_INCLUDED