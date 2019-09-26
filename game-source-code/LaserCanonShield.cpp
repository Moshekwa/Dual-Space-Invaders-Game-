#include "LaserCanonShield.h"

LaserCanonShield::LaserCanonShield(int xPosition, int yPosition, bool life, int numberOfLives)
    : GameEntity{ xPosition, yPosition, life, numberOfLives }
{
    if(yPosition != 70 && yPosition != 450){
        throw InvalidShieldPosition{};
    }
}

const int LaserCanonShield::numberOfShields{6};

int LaserCanonShield::getNumberOfShields()
{
    return numberOfShields;
}