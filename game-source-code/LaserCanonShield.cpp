#include "LaserCanonShield.h"

LaserCanonShield::LaserCanonShield(int xPosition, int yPosition, bool life)
    : GameEntity{ xPosition, yPosition, 0, life }
{
}

void LaserCanonShield::shoot()
{
    giveEntityLife();
}