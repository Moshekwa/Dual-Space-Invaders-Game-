#include "MovingEntity.h"

MovingEntity::MovingEntity(int xPosition, int yPosition, int entitySpeed, bool life)
    : GameEntity{ xPosition, yPosition, life }
{
    _entitySpeed = entitySpeed;
}

int MovingEntity::getEntitySpeed() const
{
    return _entitySpeed;
}