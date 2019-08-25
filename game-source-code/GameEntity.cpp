#include "GameEntity.h"

GameEntity::GameEntity(int x, int y)
{
    xPosition = x;
    yPosition = y;
}

void GameEntity::setXposition(int x)
{
    xPosition = x;
}

void GameEntity::setYposition(int y)
{
    yPosition = y;
}

int GameEntity::getXposition() const
{
    return xPosition;
}

int GameEntity::getYposition() const
{
    return yPosition;
}

int GameEntity::getEntitySpeed() const
{
    return speed;
}