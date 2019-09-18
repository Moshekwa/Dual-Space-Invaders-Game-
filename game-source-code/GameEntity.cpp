#include "GameEntity.h"

GameEntity::GameEntity(int xPosition, int yPosition, int entitySpeed, bool life)
    : _coordinates{ EntityCoordinates{ xPosition, yPosition } }
{
    _entitySpeed = entitySpeed;
    _life = life;
}

void GameEntity::setXposition(int x)
{
    _coordinates.setXposition(x);
}

void GameEntity::setYposition(int y)
{
    _coordinates.setYposition(y);
}

void GameEntity::giveEntityLife()
{
   _life = true;
}

void GameEntity::destroyEntity()
{
    _life = false;
}

bool GameEntity::isAlive() const
{
    return _life;
}

EntityCoordinates GameEntity::getEntityCoordinates() const
{
    return _coordinates;
}

int GameEntity::getEntitySpeed() const
{
    return _entitySpeed;
}
