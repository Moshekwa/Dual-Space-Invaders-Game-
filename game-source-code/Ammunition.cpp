#include "Ammunition.h"

Ammunition::Ammunition(int xPosition, int yPosition, int entitySpeed, bool life, int numberOfLives)
    : MovingEntity(xPosition, yPosition, entitySpeed, life, numberOfLives)
{
}

void Ammunition::shoot()
{
    giveEntityLife();
}