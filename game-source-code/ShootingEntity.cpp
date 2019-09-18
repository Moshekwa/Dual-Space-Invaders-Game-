#include "ShootingEntity.h"

ShootingEntity::ShootingEntity(int xPosition, int yPosition, int entitySpeed, bool life)
    : GameEntity{ xPosition, yPosition, entitySpeed, life }
{
}

void ShootingEntity::shoot()
{
    giveEntityLife();
}