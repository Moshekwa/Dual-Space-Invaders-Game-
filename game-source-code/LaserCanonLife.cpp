#include "LaserCanonLife.h"

LaserCanonLife::LaserCanonLife(int xPosition, int yPosition, bool life)
    : GameEntity{ xPosition, yPosition, life }
{
}

LaserCanonLife::~LaserCanonLife()
{
}

void LaserCanonLife::setEntityLife()
{
    giveEntityLife();
}

int LaserCanonLife::getNumberOfLives()
{
    return numberOfLives;
}

const int LaserCanonLife::numberOfLives{ 3 };