#include "GameEntity.h"

GameEntity::GameEntity(int x, int y, int speed, bool life) : _coordinates{EntityCoordinates{x,y}}
{
    _entitySpeed = speed;
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

void GameEntity::setEntityLife(bool life)
{
    _life = life;
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


