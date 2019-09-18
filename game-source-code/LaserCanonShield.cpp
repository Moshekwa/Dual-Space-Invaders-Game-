#include "LaserCanonShield.h"

LaserCanonShield::LaserCanonShield(int xPosition, int yPosition, bool life)
    : GameEntity{ xPosition, yPosition, life }
{
}

void LaserCanonShield::shoot()
{
    giveEntityLife();
}

const int LaserCanonShield::numberOfShields{6};

int LaserCanonShield::getNumberOfShields()
{
    return numberOfShields;
}