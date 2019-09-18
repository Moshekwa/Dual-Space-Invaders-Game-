#include "MovingEntity.h"

MovingEntity::MovingEntity(int xPosition, int yPosition, int entitySpeed, bool life)
    : GameEntity{ xPosition, yPosition, entitySpeed, life }
{
}