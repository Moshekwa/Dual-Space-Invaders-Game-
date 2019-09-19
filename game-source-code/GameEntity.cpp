#include "GameEntity.h"

GameEntity::GameEntity(int xPosition, int yPosition, bool life, int numberOfLives)
    : _coordinates{ EntityCoordinates{ xPosition, yPosition } }
    , _life{ life }
    , _numberOfLives{ numberOfLives }
{
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
    if(getNumberOfLives() != 0) {
        _numberOfLives = _numberOfLives - 1;
        if(getNumberOfLives() == 0) {
            _life = false;
        }
    } else{
        _life = false;
    } 
}

bool GameEntity::isAlive() const
{
    return _life;
}

int GameEntity::getNumberOfLives() const
{
    return _numberOfLives;
}

EntityCoordinates GameEntity::getEntityCoordinates() const
{
    return _coordinates;
}
