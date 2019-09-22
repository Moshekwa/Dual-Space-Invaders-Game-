#include "LaserCanonShield.h"

LaserCanonShield::LaserCanonShield(int xPosition, int yPosition, bool life, int numberOfLives)
    : GameEntity{ xPosition, yPosition, life, numberOfLives }
{
}

const int LaserCanonShield::numberOfShields{6};

int LaserCanonShield::getNumberOfShields()
{
    return numberOfShields;
}