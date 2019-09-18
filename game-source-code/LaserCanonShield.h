#ifndef LASERCANONSHIELD_H_INCLUDED
#define LASERCANONSHIELD_H_INCLUDED
#include "GameEntity.h"

class LaserCanonShield : public GameEntity
{
public:
    LaserCanonShield(int xPosition, int yPosition, bool life);
    void shoot();
    static int getNumberOfShields();
    
private:
    const static int numberOfShields;
};

#endif // LASERCANONSHIELD_H_INCLUDED