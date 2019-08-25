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

int GameEntity::getXposition()
{
    return xPosition;
}

int GameEntity::getYposition()
{
    return yPosition;
}