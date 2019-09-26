#include "MovingEntity.h"

MovingEntity::MovingEntity(int xPosition, int yPosition, int entitySpeed, bool life, int numberOfLives)
    : GameEntity{ xPosition, yPosition, life, numberOfLives }
{
    if(entitySpeed > 0){
    _entitySpeed = entitySpeed;
    } else{
        throw EntitySpeedCannotBeZero{};
    }
}

int MovingEntity::getEntitySpeed() const
{
    return _entitySpeed;
}

void MovingEntity::setEntitySpeed(int speed)
{
    _entitySpeed = speed;
}

void MovingEntity::setMovementBoundaries(int left, int right, int upper, int bottom)
{
    leftBoundary = left;
    rightBoundary = right;
    upperBoundary = upper;
    bottomBoundary = bottom;
}

tuple<int, int, int, int> MovingEntity::getMovementBoundaries()
{
    return { leftBoundary, rightBoundary, upperBoundary, bottomBoundary };
}